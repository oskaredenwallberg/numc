#ifndef TENSOR_IO_H
#define TENSOR_IO_H

#include "tensor.h"

typedef enum {
    VALS,
    DOTS,
    SKIP,
} PrintAction;

#define MAX_ROWS 4
#define MAX_COLS 3

// printing
void tensor_print(const Tensor *t);
void tensor_print_data(const Tensor *t);
void tensor_print_shape(const Tensor *t);
// extern void print_1d_array(Uint* array, Uint size);

// save and load
// void save_tensor(char* path, Tensor *t);
// void load_tensor(char* path, Tensor *t);

#endif
