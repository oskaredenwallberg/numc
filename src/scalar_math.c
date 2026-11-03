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

Scalar maclaurin_ln_xp1_div_xm1(Scalar x, Size iter) {
    assert(iter >= 1);
    assert((-0.5 < x) && (x < 0.5));
    Scalar ln_xp1_div_xm1 = 0.0;
    Scalar xn = x;
    Scalar x2 = x*x;
    for (Size i = 1; i < 2*iter; i+=2) {
        ln_xp1_div_xm1 += xn/i;
        xn *= x2;
    }
    return 2.0*ln_xp1_div_xm1;
}

static inline Size leading_zero_count(uint64_t bits) {
    Size count = 0;
    for (Size i = 64; i-- > 0;) {
        if (bits >> i == 0b1) break;
        count++;
    }
    return count;
}

Scalar scalar_log(Scalar x) {
    if (x == 1.0)      return 0.0;
    if (x <= 0.0)      return NAN;
    if (x != x)        return NAN;
    if (x == INFINITY) return INFINITY;

    uint64_t bits;
    memcpy(&bits, &x, sizeof(x));
    uint64_t exponent = bits & EXPONENT_MASK;
    uint64_t fraction = bits & FRACTION_MASK;

    Scalar m;
    int k;
    Size zeros = 0;

    // subnormal: double x = (-1)^s    f  2^{ -1022}
    // otherwise: double x = (-1)^s (1+f) 2^{E-1023}
    if (exponent == 0) {
        zeros = leading_zero_count(fraction) - 12;  // ignore non-f bits
        fraction <<= zeros + 1;       // shift f beyond 1.0
    }
    fraction |= EXPONENT_BIAS << 52;  // reset bias (2^{E-1023} = 2^0 = 1)
    memcpy(&m, &fraction, sizeof(fraction));
    k = (int)(exponent >> 52) - (int)EXPONENT_BIAS - (int)zeros;
    
    if (m >  4.0 / 3.0) {
        m /= 2.0;
        k += 1;
    }
    Scalar lnm = maclaurin_ln_xp1_div_xm1((m-1.0)/(m+1.0), 10);
    Scalar lnx = lnm + k*LN2;  // ln(x) = ln(m2^k) = ln(m) + kln(2)
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
    Scalar ln2 = maclaurin_ln_xp1_div_xm1(1.0/3.0, 100);
    printf("%.20lf\n", ln2);
}

// Scalar ln_sqrt2 = maclaurin_ln_xp1(SQRT2-1.0, 100);  // ln(x+1) = ln(sqrt(2)) ==> x = sqrt(2) - 1
// static inline Scalar maclaurin_ln_xp1(Scalar x, Size iter) {
//     assert(iter >= 1);
//     assert((-0.5 < x) && (x < 0.5));
//     Scalar ln_xp1 = 0.0;
//     Scalar xn = 1.0;
//     Scalar sign = -1.0;
//     for (Size i = 1; i < iter; i++) {
//         sign *= -1;
//         xn *= x;
//         ln_xp1 += sign * 1.0/i * xn;
//     }
//     return ln_xp1;
// }
