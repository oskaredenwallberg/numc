// tensor.h

#ifndef TENSOR_H
#define TENSOR_H

#include <stddef.h>
#include <stdbool.h>

typedef size_t Index;       // unsigned integer index, 64 bit
typedef size_t Size;        // unsigned integer sizes, 64 bit
typedef double Scalar;      // double-precision floating point, 64 bit
// typedef ptrdiff_t Stride;   // signed integer offsets, 64 bit

typedef struct {
    Size   ndim;
    Size   size;
    Size   *shape;
    Scalar *data;
    // Stride *strides;
} Tensor;

// factory
Tensor tensor_array(const Scalar data[], const Size shape[], Size ndim);
Tensor tensor_zeros(const Size shape[], Size ndim);
Tensor tensor_ones(const Size shape[], Size ndim);

// release
void tensor_free(Tensor *t);  // free allocated data and reset members

// shape (inplace)
void tensor_reshape(Tensor *t, Size ndim, const Size *shape);
void tensor_flatten(Tensor *t);
void tensor_squeeze(Tensor *t, Index axis);
void tensor_unsqueeze(Tensor *t, Index axis);
void tensor_transpose(Tensor *t, Index axis1, Index axis2);

// access
Tensor tensor_slice(const Tensor *t, Index axis, Index start, Index stop);
Scalar tensor_index(const Tensor *t, const Index index[]);

// combine
Tensor tensor_concatenate(const Tensor t[], Size count, Index axis);

// memory layout
// bool tensor_packed(const Tensor *t);  // is continguous
// void tensor_pack(Tensor *t);          // make contiguous

#endif
