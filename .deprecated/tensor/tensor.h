// //tensor.h

// #ifndef TENSOR_H
// #define TENSOR_H

// #include "../config.h"

// /** NumberType typedef:
//  * @brief Enumerated types for logical check of the type of NumberValue stored in tensor.
//  * 
//  * Provides a semantic way of asserting the `NumberType` of `NumberValues` in tensors.
//  * 
//  * @param TENSOR_SHORT 0
//  * @param TENSOR_USHORT 1
//  * @param TENSOR_INT 2
//  * @param TENSOR_UINT 3
//  * @param TENSOR_LONG 4
//  * @param TENSOR_ULONG 5
//  * @param TENSOR_FLOAT 6
//  * @param TENSOR_DOUBLE 7
//  * 
// */
// typedef enum 
// {   
//     TENSOR_SHORT,
//     TENSOR_USHORT,
//     TENSOR_INT,
//     TENSOR_UINT,
//     TENSOR_LONG,
//     TENSOR_ULONG,
//     TENSOR_FLOAT,
//     TENSOR_DOUBLE,
// } NumberType;

// /** Number typedef:
//  * @brief Allowed datatypes of values stored in a tensor.
//  * 
//  * The size of `Number` values will be arg max(union members) 
//  * plus any padding according to the systems alignment requirements.
//  * 
//  * @param tensor_short Number of type `short`
//  * @param tensor_ushort Number of type `Ushort` (unsigned short)
//  * @param tensor_int Number of type `int`
//  * @param tensor_uint Number of type `Uint` (unsigned int)
//  * @param tensor_long Number of type `long`
//  * @param tensor_ulong Number of type `Ulong` (unsigned long)
//  * @param tensor_float Number of type `float`
//  * @param tensor_double Number of type `double`
// */
// typedef union 
// {
//     short tensor_short;
//     Ushort tensor_ushort;
//     int tensor_int;
//     Uint tensor_uint;
//     long tensor_long;
//     Ulong tensor_ulong;
//     float tensor_float;
//     double tensor_double;
// } Number;


// /** Tensor typedef:
//  * @brief A generalisation of dimensional array objects.
//  * 
//  * Can store up to `MAXIMUM_DIMENSION` dimensional arrays with meta data for shape,
//  * size, datatype and dimension of the tensor.
//  * 
//  * @param dim The number of dimensions `Uint` the tensor spans
//  * @param size The number of values `Uint` stored in the tensor
//  * @param shape An array of dimensional lengths `Uint [MAXIMUM_DIMENSIONS]` for the values
//  * @param dtype The datatype `NumberType` of the numeric values stored in the tensor
//  * @param values An array of values `Number [MAXIMUM_LENGTH]` stored in the tensor
// */
// typedef struct Tensor 
// {   
//     Uint dim;                    // The number of dimensions the tensor spans
//     Uint size;                              // The number of values `NumberValues` stored in the `.values` member
//     Uint shape[MAXIMUM_DIMENSION];          // An array of the length the tensor values stretch in each dimension
//     NumberType dtype;                       // The datatype of the numeric values stored in the `.values` member
//     Scalar values[MAXIMUM_LENGTH];          // The values contained by the tensor
// } Tensor;

// #endif //TENSOR_H
