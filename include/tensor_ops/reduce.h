#ifndef TENSOR_REDUCE_H
#define TENSOR_REDUCE_H

#include "tensor.h"

// reduction
Tensor tensor_min(const Tensor *t, Index axis);
Tensor tensor_max(const Tensor *t, Index axis);
Tensor tensor_sum(const Tensor *t, Index axis);
Tensor tensor_std(const Tensor *t, Index axis);
Tensor tensor_var(const Tensor *t, Index axis);
Tensor tensor_mean(const Tensor *t, Index axis);
Tensor tensor_median(const Tensor *t, Index axis);

#endif
