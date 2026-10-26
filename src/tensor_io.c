#include <string.h>
#include <stdio.h>
#include <assert.h>

#include "tensor.h"
#include "tensor_io.h"

void tensor_print(const Tensor *t) {
    Size cols = t->shape[t->ndim-1];
    Size rows = t->size / cols;

    // add slice array
    // add cumsum
    // first i mod d tells how many brackets

    Size num_brackets[rows];
    memset(num_brackets, 0, sizeof num_brackets);
    for (Index i = 0; i < rows; i++) {
        num_brackets[i]++;
        for (Index d = 1; d < t->ndim-1; d++) {
            if ((i % t->shape[d]) == 0) num_brackets[i]++;
        }
        // printf("%li\n", num_brackets[i]);
    }

    for (Index i = 0; i < rows; i++) {
        Size lb = num_brackets[i];
        Size rb = num_brackets[rows-1-i];
        Size ls = t->ndim-1 - lb;
        for (Index s = 0; s < ls; s++) printf(" ");
        for (Index b = 0; b < lb; b++) printf("[");
        printf(" ");
        for (Index j = 0; j < cols; j++) printf("%f ", t->data[cols*i+j]);
        for (Index b = 0; b < rb; b++) printf("]");
        printf("\n");        
    }
}

void tensor_print2(const Tensor *t) {
    Size buffer[t->ndim];
    memset(buffer, 0, sizeof buffer);

    for (Index e = 0; e < t->size; e++) {
        
        // left spaces
        if (buffer[t->ndim - 1] == 0) {
            Index d = t->ndim;
            while (d > 0 && buffer[d - 1] == 0)
                d--;
            for (Index s = 0; s < d; s++)
                printf(" ");
        }

        // Open brackets
        for (Index d = t->ndim; d > 0; d--) {
            if (buffer[d-1] != 0) break;
            printf("[");
        }

        printf("%f ", t->data[e]);

        // Increment indices and close brackets on overflow
        for (Index d = t->ndim; d > 0; d--) {
            buffer[d-1]++;
            if (buffer[d-1] < t->shape[d-1]) break;
            buffer[d-1] = 0;
            printf("]");
        }

        if (buffer[t->ndim-1] == 0)
            printf("\n");
    }
}


// void tensor_print(const Tensor *t) {
//     // Size cols = t->shape[t->ndim-1];
//     // Size rows = t->size / cols;

//     Size buffer[t->ndim];
//     memset(buffer, 0, sizeof buffer);

//     for (Index e = 0; e < t->size; e++) {
//         // printf("%f ", t->data[e]);
//         buffer[t->ndim-1]++;
//         for (int d = t->ndim-1; d > -1; d--) {
//             printf("%li ", buffer[d]);
//             if (buffer[d] == t->shape[d]) {
//                 buffer[d] = 0;
//                 buffer[d-1]++;
//             }
//         }
//         printf("\n");
//     }
// }

// {2, 4, 3}
// [[ 0 0 0 ]
//  [ 0 0 0 ]
//  [ 0 0 0 ]
//  [ 0 0 0 ]]
// [[ 0 0 0 ]
//  [ 0 0 0 ]
//  [ 0 0 0 ]
//  [ 0 0 0 ]]
