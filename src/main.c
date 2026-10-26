#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tensor.h"
#include "tensor_io.h"

int main() {
    // create a tensor
    Tensor t = tensor_zeros((Size[]){ 2, 2, 4, 3 }, 4);
    
    // print the tensor
    tensor_print(&t);

    // free the tensor
    tensor_free(&t);

    return 0;
};
