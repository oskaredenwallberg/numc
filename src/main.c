#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tensor.h"
#include "tensor_io.h"

int main() {
    // create a tensor
    Tensor t = tensor_zeros((Size[]){ 2, 2, 4, 3 }, 4);
    Tensor u = tensor_full((Size[]){ 2, 2, 3 }, 3, 4.456767987986532732178 );
    Tensor v = tensor_array(
        (Scalar[]){ 1, 2, 3, 4, 5, 6 }, 
        (Size[]){ 2, 3 }, 2
    );

    // print the tensor
    tensor_print(&t);
    tensor_print(&u);
    tensor_print(&v);

    // free the tensor
    tensor_free(&t);
    tensor_free(&u);
    tensor_free(&v);

    return 0;
};
