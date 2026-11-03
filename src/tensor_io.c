#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#include "tensor.h"
#include "tensor_io.h"


static inline void putchar_repeat(const char c, Size n) {
    for (Index j = 0; j < n; j++) putchar(c);
}

static inline void tensor_print_row(const Tensor *t, Size cols, Index i) {
    for (Index j = 0; j < cols; j++) {
        if (j == MAX_COLS) printf(".. ");
        if ((MAX_COLS < j) && (j+MAX_COLS <= cols)) continue;
        printf("%f ", t->data[cols*i+j]);
    }
}

static inline Size integer_print_width(int x) {
    Size width = (x < 0) ? 2 : 1;
    for (; x <= -10 || x >= 10; width++) x /= 10;
    return width;
}


void tensor_print(const Tensor *t) {
    Size ndim = t->ndim;
    Size cols = t->shape[ndim-1];
    Size rows = t->size / cols;
    Size width = integer_print_width(rows-1);

    for (Index i = 0; i < rows; i++) {
        PrintAction action = VALS;
        Size lb = 1;
        Size rb = 1;
        Size stride = 1;

        for (Index d = ndim-1; d-- > 0;) {
            Size axislength = t->shape[d];
            Size k = (i / stride) % axislength;  // coordinate along axis
            Size limit = (d == t->ndim - 2) ? MAX_ROWS : 1;
            bool truncate  = (axislength > 2 * limit);
            bool in_bound  = (limit <= k) && (k < axislength - limit);
            bool first_sub = (limit == k);       // first block (subarray) to omit
            bool first_row = (i % stride == 0);  // first row of subarray
            if (truncate && in_bound)
                action = (first_sub && first_row) ? DOTS : SKIP;

            stride *= axislength;
            if ( i    % stride == 0) lb++;
            if ((i+1) % stride == 0) rb++;
        }

        Size ls = ndim - lb;
        Size rs = ndim - rb;
        if (action == SKIP) continue;
        if (action == DOTS) {
            putchar_repeat(' ', ls);
            puts("...");
            continue;
        }

        putchar_repeat(' ', ls);
        putchar_repeat('[', lb);
        putchar(' ');
        tensor_print_row(t, cols, i);
        putchar_repeat(']', rb);
        putchar_repeat(' ', rs+1);
        printf("%*zu\n", (int)width, i);
    }
}


// static inline PrintAction tensor_action(const Tensor *t, Index i) {
//     Size stride = 1;
//     PrintAction action = COLS;
//     for (Index d = t->ndim-1; d-- > 0;) {
//         Size limit = (d == t->ndim - 2) ? MAX_ROWS : 1;
//         Size axislength = t->shape[d];
//         Size k = (i / stride) % axislength;  // coordinate along axis
//         bool truncate  = (axislength > 2 * limit);
//         bool in_bound  = (limit <= k) && (k < axislength - limit);
//         bool first_sub = (limit == k);       // first block (subarray) to omit
//         bool first_row = (i % stride == 0);  // first row of subarray
//         if (                  truncate  && in_bound ) action = SKIP;
//         if (action == SKIP && first_sub && first_row) action = DOTS;
//         stride *= axislength;
//     }
//     return action;
// }

// void tensor_print(const Tensor *t) {
//     Size ndim = t->ndim;
//     Size cols = t->shape[ndim-1];
//     Size rows = t->size / cols;
//     for (Index i = 0; i < rows; i++) {
//         PrintAction action = tensor_action(t, i);
//         if (action == SKIP) continue;
//         Size lb = 1;
//         Size rb = 1;
//         Size cumsum = 1;
//         for (Index d = ndim-1; d-- > 0;) {
//             cumsum *= t->shape[d];
//             if ( i    % cumsum == 0) lb++;
//             if ((i+1) % cumsum == 0) rb++;
//         }
//         Size ls = ndim - lb;
//         Size rs = ndim - rb;
//         if (action == DOTS) {
//             putchar_repeat(' ', ls);
//             puts("...");
//             continue;
//         }
//         putchar_repeat(' ', ls);
//         putchar_repeat('[', lb);
//         putchar(' ');
//         tensor_print_row(t, cols, i);
//         putchar_repeat(']', rb);
//         putchar_repeat(' ', rs+1);
//         printf("%zu\n", i);
//     }
// }



// shape: {  2, 2, 4, c }, c is number of columns
// cusum: { 16, 8, 4, c }
// i   % buffer[d] == 0  lb++;
// i+1 % buffer[d] == 0  rb++;

// 0 0 0 <<<<      >        0
// 0 0 1    <      >        1
// 0 0 2    <      >        2
// 0 0 3    <      >>       3
// 0 1 0   <<      >        4
// 0 1 1    <      >        5
// 0 1 2    <      >        6
// 0 1 3    <      >>>      7
// 1 0 0  <<<      >        8
// 1 0 1    <      >        9
// 1 0 2    <      >       10
// 1 0 3    <      >>      11
// 1 1 0   <<      >       12
// 1 1 1    <      >       13
// 1 1 2    <      >       14
// 1 1 3    <      >>>>    15

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




// void tensor_print(const Tensor *t) {
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

// void tensor_print(const Tensor *t) {
//     Size ndim = t->ndim;
//     Size cols = t->shape[ndim-1];
//     Size rows = t->size / cols;
//     Size buffer[ndim];  // shape buffer, odometer
//     memset(buffer, 0, sizeof buffer);

//     for (Index i = 0; i < rows; i++) {
//         Size lb = 1;
//         Size rb = 1;
//         bool count_l = true;
//         bool count_r = true;
//         bool carry   = true;
//         for (Index d = ndim-1; d-- > 0;) {
//             Size a = t->shape[d];
//             if (buffer[d] == 0   && count_l) lb++; else count_l = false;
//             if (buffer[d] == a-1 && count_r) rb++; else count_r = false;
//             if (carry) {
//                 buffer[d]++;
//                 if (buffer[d] == a) buffer[d] = 0; else carry = false;
//             }
//         }
//         Size ls = ndim - lb;
//         for (Index s = 0; s < ls; s++) printf(" ");
//         for (Index b = 0; b < lb; b++) printf("[");
//         printf(" ");
//         for (Index j = 0; j < cols; j++) printf("%f ", t->data[cols*i+j]);
//         for (Index b = 0; b < rb; b++) printf("]");
//         printf("\n");
//     }
// }
