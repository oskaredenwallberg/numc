#ifndef TENSOR_BINARY_H
#define TENSOR_BINARY_H

#include "../tensor.h"

// binary ops (w/ broadcasting)
Tensor tensor_add(const Tensor *t1, const Tensor *t2);
Tensor tensor_sub(const Tensor *t1, const Tensor *t2);
Tensor tensor_mul(const Tensor *t1, const Tensor *t2);
Tensor tensor_div(const Tensor *t1, const Tensor *t2);

// note : the callee is responsible for crashing the program if something goes wrong

#endif
