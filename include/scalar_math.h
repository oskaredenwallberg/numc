#ifndef SCALAR_MATH_H
#define SCALAR_MATH_H

#include <string.h>
#include "tensor.h"

// mathematical constants
#define E        2.71828182845904523536  // Euler's number, `e`
#define PI       3.14159265358979323846  // Pi, `π`
#define SQRT2    1.414213562373095       // Sqrt2, `√2`
#define LN2      0.69314718055994531     // Ln2, `ln(2)`

// double bit anatomy
// Bit anatomy of a double : 1 s | 11 E | 52 f
// 1 bit for sign, 11 bits for exponent, 52 bits for floating point decimal
// #define EXPONENT_BITS   11
// #define FRACTION_BITS   52
#define EXPONENT_BIAS   0b001111111111ULL
#define EXPONENT_MASK  (0b011111111111ULL << 52)
#define FRACTION_MASK ~(0b111111111111ULL << 52)


// scalar operations
Scalar scalar_abs(Scalar x);
Scalar scalar_log(Scalar x);
Scalar scalar_exp(Scalar x);
Scalar scalar_pow(Scalar x, Scalar n);

Scalar scalar_cos(Scalar x);
Scalar scalar_sin(Scalar x);

Scalar scalar_pdf_gaussian(Scalar mu, Scalar sigmoid, Scalar x);

Scalar maclaurin_ln_xp1_div_xm1(Scalar x, Size iter);
void approximate_sqrt2();
void approximate_ln2();

#endif
