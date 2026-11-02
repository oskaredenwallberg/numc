#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>

#include "scalar_math.h"

Scalar scalar_abs(Scalar x) {
    return (x < 0) ? -x : x;
}


static inline Scalar maclaurin_ln_xp1(Scalar x, Size iter) {
    assert(iter >= 1);
    assert((-0.5 < x) && (x < 0.5));
    Scalar ln_xp1 = 0.0;
    Scalar xn = 1.0;
    Scalar sign = -1.0;
    for (Size i = 1.0; i < iter; i++) {
        sign *= -1;
        xn *= x;
        ln_xp1 += sign * 1.0/i * xn;
    }
    return ln_xp1;
}

Scalar scalar_log(Scalar x) {
    // ln(x) = ln(m2^k) = ln(m) + ln(2^k) = ln(m) + kln(2)
    // Approximate ln(2) once really good
    // We use base 2 because of fast bit arithmetic, identifying the two powers of 2 that x must lie between
    // Bit anatomy of a double : 1 s | 11 E | 52 f
    // 1 bit for sign, 11 bits for exponent, 52 bits for floating point decimal
    // double x = (-1)^s (1 + f) 2^{E - 1023}
    if (x == 1.0) return 0.0;
    if (x <= 0.0) return NAN;
    if (x != x) return NAN;
    if (x == INFINITY) return INFINITY;

    uint64_t bits64;
    uint64_t exponent;
    uint64_t fraction;
    uint64_t exponent_mask =   0b011111111111ULL << 52;
    uint64_t fraction_mask = ~(0b111111111111ULL << 52);
    memcpy(&bits64, &x, sizeof(x));
    exponent = bits64 & exponent_mask;
    fraction = bits64 & fraction_mask;

    int bias = 0b001111111111ULL;  // 1023

    // subnormal: double x = (-1)^s    f  2^{ -1022}
    // otherwise: double x = (-1)^s (1+f) 2^{E-1023}
    Scalar m;
    bool subnormal = (exponent == 0);
    if (subnormal) {
        Size counter = 0;  // num leading zeros
        for (Size i = 52; i-- > 0;) {
            if (fraction >> i == 0b1) break;
            counter++;
        }
        fraction <<= counter + 1;  // +1 to shift beyond 1.0.
        fraction &= ~(0b1ULL << 52);
        fraction |= 0b001111111111ULL << 52;  // representing the 1.0
        bias += counter;
        memcpy(&m, &fraction, sizeof(fraction));
    } else {
        Scalar lower;
        memcpy(&lower, &exponent, sizeof(exponent));
        m = x / lower;
    }

    int k = (exponent >> 52) - bias;
    if (m > 4.0 / 3.0) {
        m /= 2;
        k += 1;
    }
    Scalar f = m - 1.0;
    Scalar lnm = maclaurin_ln_xp1(f, 100);
    Scalar lnx = lnm + k * LN2;
    return lnx;
}





// Scalar scalar_exp(Scalar x) {
//     // 0: 1/0! * (x-a)^0 e^x
//     // 1: 1/1! * (x-a)^1 e^x
//     // 2: 1/2! * (x-a)^2 e^x
//     // ...
//     // e^x = e^a ( 1 + (x-a) + 1/2(x-a)^2 + ... )

// }



// Scalar scalar_pow(Scalar x, Scalar n) {
//     // x^y = e^ln(x^y) = e^(yln(x))
// }


// 1.41421356237309504880  real
// 1.41421356237309492343  approximated   10 iter
// 1.41421356237309492343  approximated 1000 iter
void approximate_sqrt2() {  // Newton's method
    Scalar g = 1.5;  // initial guess
    Scalar r2 = 2.0;
    Scalar p;
    for (Size i = 0; i < 10; i++) {
        p = r2/g;
        g = 0.5 * (g + p);  // take average between guess and 2.0/guess, iterate.
    }
    printf("%.20f\n", g);
}


// 0.69314718055994530941  real
// 0.69314718055994561929  approximated  100 iter
// 0.69314718055994561929  approximated 1000 iter
void approximate_ln2() {
    Scalar ln_sqrt2 = maclaurin_ln_xp1(SQRT2-1.0, 100);  // ln(x+1) = ln(sqrt(2)) ==> x = sqrt(2) - 1
    Scalar ln2 = 2 * ln_sqrt2;
    printf("%.20lf", ln2);
}
