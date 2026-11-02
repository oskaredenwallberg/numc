#ifndef SCALAR_MATH_H
#define SCALAR_MATH_H

#include <string.h>
#include "tensor.h"

// mathematical constants
#define E        2.71828182845904523536  // Euler's number, `e`
#define PI       3.14159265358979323846  // Pi, `π`
#define SQRT2    1.414213562373095       // Sqrt2, `√2`
#define LN2      0.693147180559945       // Ln2, `ln(2)`
#define INF_BITS 0b0111111111110000000000000000000000000000000000000000000000000000ULL

// scalar operations
Scalar scalar_abs(Scalar x);
Scalar scalar_log(Scalar x);
Scalar scalar_exp(Scalar x);
Scalar scalar_pow(Scalar x, Scalar n);

Scalar scalar_cos(Scalar x);
Scalar scalar_sin(Scalar x);

Scalar scalar_pdf_gaussian(Scalar mu, Scalar sigmoid, Scalar x);

void approximate_sqrt2();
void approximate_ln2();

#endif
