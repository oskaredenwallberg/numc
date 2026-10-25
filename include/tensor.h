// tensor.h

#ifndef TENSOR_H
#define TENSOR_H

#include <stddef.h>

typedef size_t Size;        // unsigned integer sizes, 64 bit
typedef ptrdiff_t Stride;   // signed integer offsets, 64 bit
typedef double Scalar;      // double-precision floating point, 64 bit

typedef struct {
    Size   ndim;
    Size   size;
    Size   *shape;
    Stride *strides;
    Scalar *data;
} Tensor;

#endif
