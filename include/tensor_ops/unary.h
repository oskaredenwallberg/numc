#ifndef TENSOR_UNARY_H
#define TENSOR_UNARY_H

#include "../tensor.h"

// unary ops
Tensor tensor_abs(const Tensor *t);
Tensor tensor_sin(const Tensor *t);
Tensor tensor_cos(const Tensor *t);
Tensor tensor_exp(const Tensor *t);
Tensor tensor_log(const Tensor *t);
Tensor tensor_pow(const Tensor *t, int pow);

// inplace
// ...

#endif
