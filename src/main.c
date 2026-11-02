#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tensor.h"
#include "tensor_io.h"
#include "scalar_math.h"

int main() {
    // create a tensor
    // Tensor t = tensor_zeros((Size[]){ 2, 2, 4, 3 }, 4);
    // Tensor u = tensor_full((Size[]){ 2, 2, 3 }, 3, 4.456767987986532732178 );
    Tensor v = tensor_array(
        (Scalar[]){ 1, 2, 3, 4, 5, 6 }, 
        (Size[]){ 2, 3 }, 2
    );

    // print the tensor
    // tensor_print(&t);
    // tensor_print(&u);
    tensor_print(&v);

    // free the tensor
    // tensor_free(&t);
    // tensor_free(&u);
    tensor_free(&v);

    // approximate_sqrt2();
    // approximate_ln2();
    Scalar lnx = scalar_log(1e32);
    printf("%.20f\n", lnx);
    //  0.99999999999999955591  approximated ln(e)
    //  1.09861228866810969140  real ln(3)
    //  1.09861228866810911597  approximated ln(3)
    // -0.69314718055994530942  real ln(0.5)
    // -0.69314718055994495316  approximated ln(0.5)

    return 0;
};
