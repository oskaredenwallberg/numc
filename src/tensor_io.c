#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#include "tensor.h"
#include "tensor_io.h"

// void tensor_print(const Tensor *t) {
    // prints a truncated tensor
// }

void tensor_print(const Tensor *t) {  // convert to tensor_print_full
    Size ndim = t->ndim;
    Size cols = t->shape[ndim-1];
    Size rows = t->size / cols;
    Size buffer[ndim];
    memset(buffer, 0, sizeof buffer);

    for (Index i = 0; i < rows; i++) {
        Size lb = 1;
        Size rb = 1;
        bool count_l = true;
        bool count_r = true;
        bool carry   = true;
        for (Index d = ndim-1; d-- > 0;) {
            Size a = t->shape[d];
            if (buffer[d] == 0   && count_l) lb++; else count_l = false;
            if (buffer[d] == a-1 && count_r) rb++; else count_r = false;
            if (carry) {
                buffer[d]++;
                if (buffer[d] == a) buffer[d] = 0; else carry = false;
            }
        }
        Size ls = ndim - lb;
        for (Index s = 0; s < ls; s++) printf(" ");
        for (Index b = 0; b < lb; b++) printf("[");
        printf(" ");
        for (Index j = 0; j < cols; j++) printf("%f ", t->data[cols*i+j]);
        for (Index b = 0; b < rb; b++) printf("]");
        printf("\n");
    }
}





// shape: { 2, 2, 4, c }, c is number of columns

// 0 0 0 <<<<   >
// 0 0 1 <      >
// 0 0 2 <      >
// 0 0 3 <      >>
// 0 1 0 <<     >
// 0 1 1 <      >
// 0 1 2 <      >
// 0 1 3 <      >>>
// 1 0 0 <<<    >
// 1 0 1 <      >
// 1 0 2 <      >
// 1 0 3 <      >>
// 1 1 0 <<     >
// 1 1 1 <      >
// 1 1 2 <      >
// 1 1 3 <      >>>>

// [[[[ 0 0 .. 0 ]
//    [ 0 0 .. 0 ]
//    [ 0 0 .. 0 ]
//    [ 0 0 .. 0 ]]
//   [[ 0 0 .. 0 ]
//    [ 0 0 .. 0 ]
//    [ 0 0 .. 0 ]
//    [ 0 0 .. 0 ]]]
//  [[[ 0 0 .. 0 ]
//    [ 0 0 .. 0 ]
//    [ 0 0 .. 0 ]
//    [ 0 0 .. 0 ]]
//   [[ 0 0 .. 0 ]
//    [ 0 0 .. 0 ]
//    [ 0 0 .. 0 ]
//    [ 0 0 .. 0 ]]]]


// void tensor_print2(const Tensor *t) {
//     Size cols = t->shape[t->ndim-1];
//     Size rows = t->size / cols;

//     Size num_brackets[rows];
//     for (Index i = 0; i < rows; i++) {
//         num_brackets[i] = 1;
//         Size cumprd = 1;
//         if (t->ndim == 1) break;
//         for (Index d = t->ndim-2;; d--) {
//             cumprd *= t->shape[d];
//             if ((i % cumprd) == 0) num_brackets[i]++;
//             if (d == 0) break;
//         }
//     }

//     for (Index i = 0; i < rows; i++) {
//         Size lb = num_brackets[i];
//         Size rb = num_brackets[rows-1-i];
//         Size ls = t->ndim - lb;
//         for (Index s = 0; s < ls; s++) printf(" ");
//         for (Index b = 0; b < lb; b++) printf("[");
//         printf(" ");
//         for (Index j = 0; j < cols; j++) printf("%f ", t->data[cols*i+j]);
//         for (Index b = 0; b < rb; b++) printf("]");
//         printf("\n");
//     }
// }