#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "tensor.h"

static Size tensor_size(const Size shape[], Size ndim) {
    assert(shape != NULL);
    assert(ndim >= 1);
    assert(ndim <= SIZE_MAX / sizeof(Size));

    Size size = 1;
    for (Index d = 0; d < ndim; d++) {
        assert(shape[d] >= 1);
        assert(size <= SIZE_MAX / shape[d]);
        size *= shape[d];
    };

    assert(size <= SIZE_MAX / sizeof(Scalar));
    return size;
}

static Scalar* alloc_full(Scalar val, Size n) {
    Scalar *data = malloc(n * sizeof *data);
    assert(data != NULL);
    for (Index i = 0; i < n; i++) {
        data[i] = val;
    }
    return data;
}

static void *alloc_copy(const void *arr, Size bytes) {
    void *copy = malloc(bytes);
    assert(copy != NULL);
    memcpy(copy, arr, bytes);
    return copy;
}

Tensor tensor_array(const Scalar data[], const Size shape[], Size ndim) {
    Size size = tensor_size(shape, ndim);

    Tensor t = {
        .data  = alloc_copy(data,  size * sizeof *data ),
        .shape = alloc_copy(shape, ndim * sizeof *shape),
        .size  = size,
        .ndim  = ndim
    };

    return t;
}

Tensor tensor_full(const Size shape[], Size ndim, Scalar value) {
    Size size = tensor_size(shape, ndim);

    Tensor t = {
        .data  = alloc_full(value, size),
        .shape = alloc_copy(shape, ndim * sizeof *shape),
        .size  = size,
        .ndim  = ndim
    };

    return t;
}

Tensor tensor_zeros(const Size shape[], Size ndim) {
    return tensor_full(shape, ndim, 0.0);
}

Tensor tensor_ones(const Size shape[], Size ndim) {
    return tensor_full(shape, ndim, 1.0);
}

void tensor_free(Tensor *t) {
    free(t->data);
    free(t->shape);
    t->data  = NULL;
    t->shape = NULL;
    t->size  = 0;
    t->ndim  = 0;
}
