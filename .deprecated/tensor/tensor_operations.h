//tensor_operations.h

#ifndef TENSOR_OPERATIONS_H
#define TENSOR_OPERATIONS_H


typedef void (*BinaryOperation)(Tensor*, Tensor*, Tensor*);

#include "tensor.h"

//broadcasting values
extern void _broadcast_init(Tensor *pT_1, Tensor *pT_2, Tensor *pT_res, Tensor *pT_bc1, Tensor *pT_bc2);
extern void _tensor_broadcast_values(Tensor *pT_original, Tensor *pT_broadcast);
extern void _tensor_init_broadcast_shape(Tensor *pT_1, Tensor *pT_2, Uint shape_bc[], Uint dim_bc);
extern void _tensor_validate_axis_broadcasting(Uint t1_axis_len, Uint t2_axis_len);

extern void _tensor_binary_operation(BinaryOperator operation, Tensor *pT_src1, Tensor *pT_src2, Tensor *pT_dest);

//element wise operations (w/ broadcasting)
extern void tensor_add(Tensor *pT_1, Tensor *pT_2, Tensor *pT_res);
extern void tensor_sub(Tensor *pT_1, Tensor *pT_2, Tensor *pT_res);
extern void tensor_mul(Tensor *pT_1, Tensor *pT_2, Tensor *pT_res);
extern void tensor_div(Tensor *pT_1, Tensor *pT_2, Tensor *pT_res);

//unary operations (inplace)
extern void tensor_abs(Tensor *pT);
extern void tensor_sin(Tensor *pT);
extern void tensor_cos(Tensor *pT);
extern void tensor_exp(Tensor *pT, int pow);
extern void tensor_log(Tensor *pT);

//reduction operations
extern void tensor_min(Tensor *pT, int axis, Tensor *pT_res);
extern void tensor_max(Tensor *pT, int axis);
extern void tensor_sum(Tensor *pT, int axis);
extern void tensor_mean(Tensor *pT, int axis);
extern void tensor_stddev(Tensor *pT, int axis);
extern void tensor_variance(Tensor *pT, int axis);
extern void tensor_median(Tensor *pT, int axis);

//matrix operations
extern void matrix_multiplication(Tensor *pA, Tensor *pB, Tensor *pC);
extern void matrix_transpose(Tensor *pA);
extern double matrix_determinant(Tensor *pA);
extern void matrix_inverse(Tensor *pA);

//vector operations
extern double vector_dot_product(Tensor *pU, Tensor *pV);

//tensor reshaping
extern void tensor_reshape(Tensor *pT, int *shape, Tensor *pT_res);
extern void tensor_squeeze(Tensor *pT, Tensor *pT_res);         //remove dimension of size 1
extern void tensor_unsqueeze(Tensor *pT, Tensor *pT_res);       //add dimension of size 1
extern void tensor_flatten(Tensor *pT, Tensor *pT_res);

//indexing and slicing
extern void tensor_slice(Tensor *pT, int axis, int start, int stop, Tensor *pT_res);
extern double tensor_index(Tensor *pT, int *index);     //index is array of indicies

//tensor concatenation and splitting
extern void tensor_concatenate(Tensor *pT_1, Tensor *pT_2, int axis, Tensor *pT_res);
extern void tensor_split(Tensor *pT_in, Tensor *pT_1, Tensor *pT_2);

//linear algebra function
// extern ... matrix_eigenvalues(...);
// extern ... matrix_eigenvectors(...);
// extern ... singluar_value_decomposition(...);
// QR decomposition ??

//convolutional operations - usually for image and signal processing

//gradient computation - ml applications

//random tensor generation





#endif //TENSOR_OPERATIONS_H



/** 
 * Broadcasting demonstrated
 * Requires both tensors to have same dimension but different shapes
 * 
 * Dimension Compatible when both
 *  - have same dimension
 *  - one have multiple of other's dimension
 * 
 * A = [[10, 10, 10],
 *      [20, 20, 20],
 *      [30, 30, 30]]
 * 
 * B = [[1, 2, 3]]     #(1,3)
 * 
 * C = A + B
 * 
 * >>> [[11, 12, 13],
 *      [21, 22, 23],
 *      [31, 32, 33]]
 * 
 * 
 * or:
 * 
 * A = [[10, 10, 10],
 *      [20, 20, 20],
 *      [30, 30, 30]]
 * 
 * B = [[1],           #(3, 1)
 *      [2],
 *      [3]]     
 * 
 * C = A + B
 * 
 * >>> [[11, 11, 11],
 *      [22, 22, 22],
 *      [33, 33, 33]]
 * 
 * 
 */