#ifndef SCALAR_MATH_H
#define SCALAR_MATH_H

#include "tensor.h"

// mathematical constants
#define E       2.71828182845904523536  // Euler's number, `e`
#define PI      3.14159265358979323846  // Pi, `π`

// scalar operations
extern Scalar scalar_pdf_gaussian(Scalar mu, Scalar sigmoid, Scalar x);

extern Scalar scalar_cos(Scalar x);
extern Scalar scalar_sin(Scalar x);

extern Scalar scalar_ln(Scalar x);
extern Scalar scalar_exp(Scalar x);
extern Scalar scalar_abs(Scalar x);
extern Scalar scalar_power_n(Scalar x, int n);


#endif
