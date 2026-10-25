#ifndef TENSOR_IO_H
#define TENSOR_IO_H

#include "./tensor.h"

// printing
void tensor_print(const Tensor *t);
void tensor_print_data(const Tensor *t);
void tensor_print_shape(const Tensor *t);
// extern void print_1d_array(Uint* array, Uint size);

// save and load
// void save_tensor(char* path, Tensor *t);
// void load_tensor(char* path, Tensor *t);

#endif
