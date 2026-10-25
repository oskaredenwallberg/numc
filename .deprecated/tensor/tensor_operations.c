// tensor_operations.c

// ...











// #include "tensor.h"
// #include "tensor_operations.h"
// #include "tensor_utils.h"
// #include "tensor_factory.h"

// // void tensor_perform_unary_operation(Number* values1, Number* values2, Number* destination, char operation) {

// // }

// /*************************************************************
//  *                      UNARY OPERATIONS                     *
//  *************************************************************/

// void tensor_abs(Tensor *pT) {
//     switch (pT->dtype) {
//         case TENSOR_SHORT:  MACRO_TENSOR_ABS(tensor_short); break;
//         case TENSOR_USHORT: MACRO_TENSOR_ABS(tensor_ushort); break;
//         case TENSOR_INT:    MACRO_TENSOR_ABS(tensor_int); break;
//         case TENSOR_UINT:   MACRO_TENSOR_ABS(tensor_uint); break;
//         case TENSOR_LONG:   MACRO_TENSOR_ABS(tensor_long); break;
//         case TENSOR_ULONG:  MACRO_TENSOR_ABS(tensor_ulong); break;
//         case TENSOR_FLOAT:  MACRO_TENSOR_ABS(tensor_float); break;
//         case TENSOR_DOUBLE: MACRO_TENSOR_ABS(tensor_double); break;
//         default: 
//             fprintf(stderr, "Error: Invalid number type for absolute value. \n");
//             exit(EXIT_FAILURE);
//             break;
//     }
// }

// void tensor_exp(Tensor *pT, int pow) {
//     switch (pT->dtype) {
//         case TENSOR_SHORT:  MACRO_TENSOR_EXP(tensor_short); break;
//         case TENSOR_USHORT: MACRO_TENSOR_EXP(tensor_ushort); break;
//         case TENSOR_INT:    MACRO_TENSOR_EXP(tensor_int); break;
//         case TENSOR_UINT:   MACRO_TENSOR_EXP(tensor_uint); break;
//         case TENSOR_LONG:   MACRO_TENSOR_EXP(tensor_long); break;
//         case TENSOR_ULONG:  MACRO_TENSOR_EXP(tensor_ulong); break;
//         case TENSOR_FLOAT:  MACRO_TENSOR_EXP(tensor_float); break;
//         case TENSOR_DOUBLE: MACRO_TENSOR_EXP(tensor_double); break;
//         default:
//             fprintf(stderr, "Error: Invalid number type for absolute value. \n");
//             exit(EXIT_FAILURE);
//             break;
//     }
// }


// void tensor_sin(Tensor *pT) {
//     switch (pT->dtype) {
//         case TENSOR_SHORT:  MACRO_TENSOR_SIN(tensor_short); break;
//         case TENSOR_USHORT: MACRO_TENSOR_SIN(tensor_ushort); break;
//         case TENSOR_INT:    MACRO_TENSOR_SIN(tensor_int); break;
//         case TENSOR_UINT:   MACRO_TENSOR_SIN(tensor_uint); break;
//         case TENSOR_LONG:   MACRO_TENSOR_SIN(tensor_long); break;
//         case TENSOR_ULONG:  MACRO_TENSOR_SIN(tensor_ulong); break;
//         case TENSOR_FLOAT:  MACRO_TENSOR_SIN(tensor_float); break;
//         case TENSOR_DOUBLE: MACRO_TENSOR_SIN(tensor_double); break;
//         default:
//             fprintf(stderr, "Error: Invalid number type for absolute value. \n");
//             exit(EXIT_FAILURE);
//             break;
//     }
// }

// // void tensor_cos(Tensor *pT) {
// //     switch (pT->dtype) {
// //         case TENSOR_SHORT:  MACRO_TENSOR_COS(tensor_short); break;
// //         case TENSOR_USHORT: MACRO_TENSOR_COS(tensor_ushort); break;
// //         case TENSOR_INT:    MACRO_TENSOR_COS(tensor_int); break;
// //         case TENSOR_UINT:   MACRO_TENSOR_COS(tensor_uint); break;
// //         case TENSOR_LONG:   MACRO_TENSOR_COS(tensor_long); break;
// //         case TENSOR_ULONG:  MACRO_TENSOR_COS(tensor_ulong); break;
// //         case TENSOR_FLOAT:  MACRO_TENSOR_COS(tensor_float); break;
// //         case TENSOR_DOUBLE: MACRO_TENSOR_COS(tensor_double); break;
// //         default:
// //             fprintf(stderr, "Error: Invalid number type for absolute value. \n");
// //             exit(EXIT_FAILURE);
// //             break;
// //     }
// // }

// /*************************************************************
//  *                      BINARY OPERATIONS                    *
//  *************************************************************/


// #define MACRO_BINARY_OPERATION(NUMBER_MEMBER) \
//     static inline void _##NUMBER_MEMBER##_add(Tensor *p_src1, Tensor *p_src2, Tensor *p_dest) { \
//         for (Uint i = 0; i < p_dest->size; i++) p_dest->values[i].NUMBER_MEMBER = p_src1->values[i].NUMBER_MEMBER + p_src2->values[i].NUMBER_MEMBER; \
//     } \
//     static inline void _##NUMBER_MEMBER##_sub(Tensor *p_src1, Tensor *p_src2, Tensor *p_dest) { \
//         for (Uint i = 0; i < p_dest->size; i++) p_dest->values[i].NUMBER_MEMBER = p_src1->values[i].NUMBER_MEMBER - p_src2->values[i].NUMBER_MEMBER; \
//     } \
//     static inline void _##NUMBER_MEMBER##_mul(Tensor *p_src1, Tensor *p_src2, Tensor *p_dest) { \
//         for (Uint i = 0; i < p_dest->size; i++) p_dest->values[i].NUMBER_MEMBER = p_src1->values[i].NUMBER_MEMBER * p_src2->values[i].NUMBER_MEMBER; \
//     } \
//     static inline void _##NUMBER_MEMBER##_div(Tensor *p_src1, Tensor *p_src2, Tensor *p_dest) { \
//         for (Uint i = 0; i < p_dest->size; i++) { \
//             if (p_src2->values[i].NUMBER_MEMBER == 0) { \
//                 fprintf(stderr, "Error: Division by zero is undefined. \n"); \
//                 exit(EXIT_FAILURE); \
//             } \
//             p_dest->values[i].NUMBER_MEMBER = p_src1->values[i].NUMBER_MEMBER / p_src2->values[i].NUMBER_MEMBER; \
//         } \
//     }
// MACRO_BINARY_OPERATION(tensor_short);
// MACRO_BINARY_OPERATION(tensor_ushort);
// MACRO_BINARY_OPERATION(tensor_int);
// MACRO_BINARY_OPERATION(tensor_uint);
// MACRO_BINARY_OPERATION(tensor_long);
// MACRO_BINARY_OPERATION(tensor_ulong);
// MACRO_BINARY_OPERATION(tensor_float);
// MACRO_BINARY_OPERATION(tensor_double);

// BinaryOperation binary_operation_table[8][4] = {
//     { _tensor_short_add, _tensor_short_sub, _tensor_short_mul, _tensor_short_div },         // binary_operation_table[TENSOR_SHORT][ADDITION... SUBTRACTION...];
//     { _tensor_ushort_add, _tensor_ushort_sub, _tensor_ushort_mul, _tensor_ushort_div },     // binary_operation_table[TESNOR_USHORT][ADDITION... SUBTRACTION...];
//     { _tensor_int_add, _tensor_int_sub, _tensor_int_mul, _tensor_int_div },                 // ...
//     { _tensor_uint_add, _tensor_uint_sub, _tensor_uint_mul, _tensor_uint_div },
//     { _tensor_long_add, _tensor_long_sub, _tensor_long_mul, _tensor_long_div },
//     { _tensor_ulong_add, _tensor_ulong_sub, _tensor_ulong_mul, _tensor_ulong_div },
//     { _tensor_float_add, _tensor_float_sub, _tensor_float_mul, _tensor_float_div },
//     { _tensor_double_add, _tensor_double_sub, _tensor_double_mul, _tensor_double_div }
// };

// void tensor_add(Tensor *pT_1, Tensor *pT_2, Tensor *pT_res) {
//     Tensor tensor_bc1, tensor_bc2; // broadcasted versions of tensors 1 & 2
//     _broadcast_init(pT_1, pT_2, pT_res, &tensor_bc1, &tensor_bc2);
//     BinaryOperation _tensor_add = binary_operation_table[pT_res->dtype][ADDITION];
//     _tensor_add(&tensor_bc1, &tensor_bc2, pT_res);
// }

// void tensor_sub(Tensor *pT_1, Tensor *pT_2, Tensor *pT_res) {
//     Tensor tensor_bc1, tensor_bc2; // broadcasted versions of tensors 1 & 2
//     _broadcast_init(pT_1, pT_2, pT_res, &tensor_bc1, &tensor_bc2);
//     BinaryOperation _tensor_sub = binary_operation_table[pT_res->dtype][SUBTRACTION];
//     _tensor_sub(&tensor_bc1, &tensor_bc2, pT_res);
// }

// void tensor_mul(Tensor *pT_1, Tensor *pT_2, Tensor *pT_res) {
//     Tensor tensor_bc1, tensor_bc2; // broadcasted versions of tensors 1 & 2
//     _broadcast_init(pT_1, pT_2, pT_res, &tensor_bc1, &tensor_bc2);
//     BinaryOperation _tensor_mul = binary_operation_table[pT_res->dtype][MULTIPLICATION];
//     _tensor_mul(&tensor_bc1, &tensor_bc2, pT_res);
// }

// void tensor_div(Tensor *pT_1, Tensor *pT_2, Tensor *pT_res) {
//     Tensor tensor_bc1, tensor_bc2; // broadcasted versions of tensors 1 & 2
//     _broadcast_init(pT_1, pT_2, pT_res, &tensor_bc1, &tensor_bc2);
//     BinaryOperation _tensor_div = binary_operation_table[pT_res->dtype][DIVISION];
//     _tensor_div(&tensor_bc1, &tensor_bc2, pT_res);
// }

// void _broadcast_init(Tensor *pT_1, Tensor *pT_2, Tensor *pT_res, Tensor *pT_bc1, Tensor *pT_bc2) {
//     // broadcasting init function:
//     Uint dim_bc = (pT_1->dim > pT_2->dim) ? pT_1->dim : pT_2->dim;
//     Uint shape_bc[dim_bc];
//     _tensor_init_broadcast_shape(pT_1, pT_2, shape_bc, dim_bc);

//     _tensor_init_metadata(pT_bc1, dim_bc, shape_bc, pT_1->dtype);
//     _tensor_init_metadata(pT_bc2, dim_bc, shape_bc, pT_2->dtype);
//     _tensor_init_metadata(pT_res, dim_bc, shape_bc, pT_1->dtype);

//     _tensor_broadcast_values(pT_1, pT_bc1);
//     _tensor_broadcast_values(pT_2, pT_bc2);
// }

// void _tensor_init_broadcast_shape(Tensor *pT_1, Tensor *pT_2, Uint shape_bc[], Uint dim_bc) {
//     Uint dim_shift1 = dim_bc - pT_1->dim;
//     Uint dim_shift2 = dim_bc - pT_2->dim;
//     //  0  1  2
//     // (1){2, 1}    <- example of pad for missing axis
//     // {2, 1, 3}
//     for (Uint axis = 0; axis < dim_bc; axis++) {
//         Uint t1_axis_len = (axis < dim_shift1) ? 1 : pT_1->shape[axis-dim_shift1]; // pad with 1 for missing axis
//         Uint t2_axis_len = (axis < dim_shift2) ? 1 : pT_2->shape[axis-dim_shift2]; // -//-
//         if (t1_axis_len%t2_axis_len != 0 && t2_axis_len%t1_axis_len != 0) {
//             fprintf(stderr, "Error: Incompatible shapes for broadcasting. \n");
//             exit(EXIT_FAILURE);
//         }
//         shape_bc[axis] = (t1_axis_len>t2_axis_len) ? t1_axis_len : t2_axis_len;
//     }
// }

// void _tensor_broadcast_values(Tensor *pT, Tensor *pT_bc) {
//     Uint dim_shift = pT_bc->dim - pT->dim;  // shift for lower dim axis
//     Number temp_values[pT_bc->size];        // temporary values for pT_bc
//     memcpy(temp_values, pT->values, pT->size*sizeof(Number)); // start with values of pT

//     Uint temp_size = pT->size;  // temp values size
//     Uint sequence = pT->size;   // len of sequence being replicated
//     Uint segments;      // num of segments to be replicated 
//     Uint replicas;      // num of replicas to make for each segment

//     for (Uint axis = 0; axis < pT_bc->dim; axis++) {
//         Uint axis_len = (axis < dim_shift) ? 1 : pT->shape[axis-dim_shift]; // shift axis for lower dim tensor
//         replicas = pT_bc->shape[axis] / axis_len;   // len of pT_bc axis over pT axis
//         segments = temp_size / sequence;

//         for (Uint s = 0; s < segments; s++) {
//             for (Uint r = 0; r < replicas; r++) {
//                 Number *p_tgt = pT_bc->values + s*sequence*replicas + r*sequence;
//                 Number *p_src = temp_values + s*sequence;
//                 memcpy(p_tgt, p_src, sequence*sizeof(Number));
//             }
//         }
//         temp_size *= replicas;
//         memcpy(temp_values, pT_bc->values, temp_size*sizeof(Number)); // update temp values
//         sequence /= pT->shape[axis]; // divide by 'prev' axis len to get current cumprod
//     }
// }




// /**
//  *  REDUCTION OPERATIONS
//  */

// /**
//  * @brief Collapse tensor to min value along specified axis. 
//  * 
//  * ...
//  * 
//  * @param pT (Tensor*) - A pointer to a tensor
//  * @param axis (int) - Index of axis to find min value along
//  * 
//  * @return void
//  */
// void tensor_min(Tensor *pT, int axis, Tensor *pT_res) {
//     // [1, 2, 3, 4, 5, 6, 7, 8]
//     // {2, 2, 2}
//     if (axis >= pT->dim) {
//         fprintf(stderr, "Error: Axis argument out of bounds. \n");
//         exit(EXIT_FAILURE);
//     }

//     int index = pT->dim-1-axis;
//     Uint num_args = pT->shape[index]; // num elements to select min from
//     Uint skip = 1;                    // num of skips to reach next element along axis
//     for (Uint i = index+1; i < pT->dim; i++) skip *= pT->shape[i]; // cumsum of inner axes


//     Uint new_size = pT->size / num_args;
//     Number values[num_args]; 
//     for (Uint i = 0; i < skip; i++) {
//         for (Uint j = 0; j < num_args; j++) {
//             values[j] = pT->values[j*skip+i];
//         }

//     }

// }

// // NOTE NOTE MAKE THIS MACRO WITH .number_member and add switch case statement in tensor_min
// Number array_min(Number values[], Uint length) {
//     Number min = values[0];
//     for (Uint i = 1; i < length; i++) {
//         if (values[i] < min) min = values[i];
//     }
// }

// // [[[1 2]
// //   [3 4]]
// //  [[5 6]
// //   [7 8]]]





/**
 * BROADCASTING ACCORDING TO NUMPY STANDARDS
 * 
 * align shapes from right 
 * broadcasting possible if:
 * - same shape
 * - one shape is 1
 * - missing shapes du to lower dim can be padded with 1
 * e.g.
 * Possible:
 * {2, 3, 1, 4}
 * (1){1, 1, 4}
 * Not Possible:
 * {2, 3, 1, 4}
 * (1){2, 1, 4}
 * 
 * 
 * Broadcasting example
 * [[[1]
 *   [2]]]
 * T1:
 *  :shape: {1, 2, 1}
 * 
 * [[[1 2 3]]
 *  [[4 5 6]]]
 * T2:
 *  :shape: {2, 1, 3}
 * 
 * T1+T2 =>
 * [[[1 1 1]
 *   [2 2 2]]
 *  [[1 1 1]
 *   [2 2 2]]]
 * +
 * [[[1 2 3]
 *   [1 2 3]]
 *  [[4 5 6]
 *   [4 5 6]]]
 * 
 * for the right most axis to the left most:
 * Every 1 element of T1 should be trippeled (x3)
 * Every 3x1=3 elements of T2 should be doubeled (x2)
 * Every 2x3=6 elements of T1 should be doubeled (x2)
 * 
 * T3 will have shape 2x2x3 = 12
 * 
 * tot_mult = 2     (1*2*1=2)
 * int T1_broadcast_values[2x2x3];
 * create broadcast values for T1:
 *  for axis in range(dimensions):
 *      T2_shape[axis] == 1: continue;
 *      m = T2_shape[aixs]/T1_shape[axis]  
 *      for i in range(tot_mult):
 *          for j in range(T2_shape[axis]):
 *              T1
 *      tot_mult *= m;
 *              
 *          
 *      
 * 
 * 
 * T3:
 *  :shape: {2, 2, 3}
*/



/******************** Depricated ********************/

// #define BROADCAST_VALUES(NUMBERTYPE, BROADCAST_VALUES, TEMPORARY_VALUES, SEGMENTS, REPLICAS, SEQUENCE) \
//     for (Uint i = 0; i < (SEGMENTS); i++) { \
//         for (Uint j = 0; j < (REPLICAS); j++) { \
//             for (Uint k = 0; k < (SEQUENCE); k++) { \
//                 (BROADCAST_VALUES)[i*(SEQUENCE)*(REPLICAS)+j*(SEQUENCE)+k].(NUMBERTYPE) = (TEMPORARY_VALUES)[i*(SEQUENCE)+k].(NUMBERTYPE); \
//             } \
//         } \
//     } 


// void _tensor_broadcast_values2(Tensor *pT_original, Tensor *pT_broadcast) {
//     Uint broadcast_size = 1;

//     // final size of broadcasted and summed tensors
//     for (Uint axis = 0; axis < pT_broadcast->dim; axis++) {
//         broadcast_size *= pT_broadcast->shape[axis];
//     }

//     Uint temporary_size = pT_original->size;     // update shape as tensors are broadcasted
//     Uint sequence = 1;                  // the length of each sequence being replicated (broadcasted)
//     Uint replicas;                      // the number of times each segment should be replicated
//     Uint segments;                      // the number of segments to be processed

//     Number temporary_values[broadcast_size];      // only need one of these, can be overwritten

//     for (Uint i = 0; i < temporary_size; i++) temporary_values[i] = pT_original->values[i];

//     for (Uint axis = pT_broadcast->dim-1;; axis--) {

//         replicas = pT_broadcast->shape[axis] / pT_original->shape[axis];     // we want the fill the broadcast axes and need to replicate the segments to fill the current axis
//         segments = temporary_size/sequence;                     // naturally the number of segments will be the tensor's current size divided by the current sequence length

//         printf("axis: %d\n", axis);
//         printf("segments: %d, replicas: %d, sequence: %d\n", segments, replicas, sequence);

//         for (Uint i = 0; i < segments; i++) {
//             for (Uint j = 0; j < replicas; j++) {
//                 for (Uint k = 0; k < sequence; k++) {
//                     Uint index_tgt = i*sequence*replicas+j*sequence+k;
//                     Uint index_src = i*sequence+k;
//                     pT_broadcast->values[index_tgt] = temporary_values[index_src];
//                 }
//             }
//         }

//         temporary_size *= replicas;             // increase the temporary size according to the numer of replicas along the current axis
//         sequence *= pT_broadcast->shape[axis];      // each sequence considered next iteration increases by the length of the current axis
        
//         for (Uint i = 0; i < broadcast_size; i++) temporary_values[i] = pT_broadcast->values[i];    // transfer temporary values to the broadcast array
//         if (axis == 0) break;       // Needed! since axis is Uint (odd interaction with decrements below zero)
//     } 
// }



// /**
//  * @brief Elementwise addition of two tensors. 
//  * 
//  * Supports broadcasting. Inner shapes must align (from right) and the one of lower 
//  * dimensionality will be broadcasted across the axes of the higher dim tensor.
//  * 
//  * @param pT_1 A pointer to an initialised instance of type `Tensor`
//  * @param pT_2 A pointer to an initialised instance of type `Tensor` (may be same as pT_1)
//  * @param pT_res A pointer to a declared instance of type `Tensor` (NOT SAME AS pT_1 OR pT_2!)
//  * 
//  * @return void
// */
// void tensor_add2(Tensor *pT_1, Tensor *pT_2, Tensor *pT_res) {
//     // broadcasting operation

//     NumberType dtype;
//     if (pT_1->dtype != pT_2->dtype) {
//         //raise error incompatible dtypes
//         exit(0);
//     }

//     /******** SCALAR CASE ********/
//     // if one is a scalar => add that values to all of the others values
//     // if (max_dimensionality == 0) {
//             // for i in range(pT_2->size)
//             // pT_2->values[i] += pT_1->values[0]   //with switch case
//     // }

//     dtype = pT_1->dtype; // same as pT_2->dtype
//     Uint broadcast_dimensionality = (pT_1->dim > pT_2->dim) ? pT_1->dim : pT_2->dim;
//     // final size of broadcasted and summed tensors
//     Uint broadcasted_shape[broadcast_dimensionality];
    
//     for (Uint axis = broadcast_dimensionality-1;; axis--) {
//         Uint length_axis_t1 = (pT_1->dim < axis) ? 1 : pT_1->shape[axis];
//         Uint length_axis_t2 = (pT_2->dim < axis) ? 1 : pT_2->shape[axis];
//         broadcasted_shape[axis] = (length_axis_t1 > length_axis_t2) ? length_axis_t1 : length_axis_t2;

//         if (length_axis_t1 != 1 && length_axis_t2 != 1 && length_axis_t1 != length_axis_t2) {
//             //raise error incompatible shapes
//         }
//         if (axis == 0) break;
//     }

//     Tensor tensor1_broadcasted; 
//     Tensor tensor2_broadcasted;

//     _tensor_init_metadata(&tensor1_broadcasted, broadcast_dimensionality, broadcasted_shape, dtype);
//     _tensor_init_metadata(&tensor2_broadcasted, broadcast_dimensionality, broadcasted_shape, dtype);    // some segemntation fault here
//     _tensor_init_metadata(pT_res, broadcast_dimensionality, broadcasted_shape, pT_1->dtype);

//     /***** BROADCATING T1 VALUES *****/
//     _tensor_broadcast_values(pT_1, &tensor1_broadcasted);   // <-- change to pointer
    
//     /***** BROADCATING T2 VALUES *****/
//     _tensor_broadcast_values(pT_2, &tensor2_broadcasted);

//     _tensor_binary_operation(ADDITION, &tensor1_broadcasted, &tensor2_broadcasted, pT_res);



//     print_1d_array(broadcasted_shape, broadcast_dimensionality);

//     printf("Broadcasted values T1: \n");
//     print_tensor(&tensor1_broadcasted);

//     printf("Broadcasted values T2: \n");
//     print_tensor(&tensor2_broadcasted);

//     printf("Broadcasted values SUM (T1 + T2): \n");
//     print_tensor(pT_res);
// }



// _tensor_binary_operation(ADDITION, &tensor_bc1, &tensor_bc2, pT_res);

// // raise error div by zero... if division and denominator is 0. NOTE More error handling will be added
// #define MACRO_PERFORM_BINARY_NUMBER_OPERATION(OPERATION, PTR_SRC1, PTR_SRC2, PTR_DEST, NUMBER_MEMBER) \
//     for (Uint i = 0; i < (PTR_DEST)->size; i++) { \
//         if ((PTR_SRC2)->values[i].NUMBER_MEMBER == 0 && OPERATION == DIVISION) break; \
//              if ((OPERATION) == ADDITION)       (PTR_DEST)->values[i].NUMBER_MEMBER = (PTR_SRC1)->values[i].NUMBER_MEMBER + (PTR_SRC2)->values[i].NUMBER_MEMBER; \
//         else if ((OPERATION) == SUBTRACTION)    (PTR_DEST)->values[i].NUMBER_MEMBER = (PTR_SRC1)->values[i].NUMBER_MEMBER - (PTR_SRC2)->values[i].NUMBER_MEMBER; \
//         else if ((OPERATION) == MULTIPLICATION) (PTR_DEST)->values[i].NUMBER_MEMBER = (PTR_SRC1)->values[i].NUMBER_MEMBER * (PTR_SRC2)->values[i].NUMBER_MEMBER; \
//         else if ((OPERATION) == DIVISION)       (PTR_DEST)->values[i].NUMBER_MEMBER = (PTR_SRC1)->values[i].NUMBER_MEMBER / (PTR_SRC2)->values[i].NUMBER_MEMBER; \
//     }  

// void _tensor_binary_operation(BinaryOperator operation, Tensor *pT_src1, Tensor *pT_src2, Tensor *pT_dest) {
//     switch (pT_dest->dtype)
//     {
//     case TENSOR_SHORT:  MACRO_PERFORM_BINARY_NUMBER_OPERATION(operation, pT_src1, pT_src2, pT_dest, tensor_short);  break;
//     case TENSOR_USHORT: MACRO_PERFORM_BINARY_NUMBER_OPERATION(operation, pT_src1, pT_src2, pT_dest, tensor_ushort); break;
//     case TENSOR_INT:    MACRO_PERFORM_BINARY_NUMBER_OPERATION(operation, pT_src1, pT_src2, pT_dest, tensor_int);    break;
//     case TENSOR_UINT:   MACRO_PERFORM_BINARY_NUMBER_OPERATION(operation, pT_src1, pT_src2, pT_dest, tensor_uint);   break;
//     case TENSOR_LONG:   MACRO_PERFORM_BINARY_NUMBER_OPERATION(operation, pT_src1, pT_src2, pT_dest, tensor_long);   break;
//     case TENSOR_ULONG:  MACRO_PERFORM_BINARY_NUMBER_OPERATION(operation, pT_src1, pT_src2, pT_dest, tensor_ulong);  break;
//     case TENSOR_FLOAT:  MACRO_PERFORM_BINARY_NUMBER_OPERATION(operation, pT_src1, pT_src2, pT_dest, tensor_float);  break;
//     case TENSOR_DOUBLE: MACRO_PERFORM_BINARY_NUMBER_OPERATION(operation, pT_src1, pT_src2, pT_dest, tensor_double); break;
//     default:
//         fprintf(stderr, "Error: Not a valid Number type. \n");
//         exit(EXIT_FAILURE);
//         break;
//     }
// }