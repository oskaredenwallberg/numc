// tensor_factory.c

// ...















// /*****************************************************************************
//  *                               INCLUDES                                    *
//  *****************************************************************************/

// #include "tensor.h"
// #include "tensor_factory.h"
// #include "tensor_utils.h"


// /*****************************************************************************
//  *                                HELPER                                     *
//  *****************************************************************************/
// /**
//  * @internal
//  * @brief Initialise tensor metadata. 
//  * 
//  * Setup tensor dimensionality, shape, dtype however not values. 
//  * 
//  * @param pT
//  * @param dimensionality
//  * @param shape
//  * @param dtype 
//  * 
//  * @return void
//  * 
//  * @note This is a library-private function used for internal initialisation of 
//  * metadata for tensor factory functions. Not intended to be used by external users.
// */
// void _tensor_init_metadata(Tensor *pT, Uint dimensionality, Uint* shape, NumberType dtype) {
//     if (dimensionality > MAXIMUM_DIMENSION) {    // assert allowed dimension 
//         fprintf(stderr, "Error: Maximum dimensionality exceeded. \n");
//         exit(EXIT_FAILURE);
//     }

//     pT->dim = dimensionality;
//     pT->size = 1;
//     pT->dtype = dtype;

//     // initialise tensor shape and size
//     for (Uint axis = 0; axis < dimensionality; axis++) {
//         if (shape[axis] <= 0) {
//             fprintf(stderr, "Error: Negative value in shape encountered. \n");
//             exit(EXIT_FAILURE);
//         }
//         pT->shape[axis] = shape[axis];
//         pT->size *= shape[axis];
//     }
// }

// /**
//  * @brief Initialise all tensor values from a single value input
//  * 
//  * Setup tensor values. `pVal` can be pointer to values of type: 
//  * `short`, `Ushort`, `int`, `Uint`, `long`, `Ulong`, `float` or `double`
//  * 
//  * @param pT A pointer to a tensor `Tensor` instance
//  * @param pVal A pointer to the single value `void` to initialise all tensor values as. 
//  * 
//  * @note This is a library-private function used for internal initialisation of 
//  * values for tensor factory functions. Not intended for external use.
// */
// void _tensor_init_values_from_single(Tensor *pT, void *pVal) {
//     switch ((pT)->dtype)
//         {
//         case TENSOR_SHORT:
//             for (Uint i = 0; i < (pT)->size; i++) (pT)->values[(i)].tensor_short = *(short*)pVal; 
//             break;  
//         case TENSOR_USHORT:
//             for (Uint i = 0; i < (pT)->size; i++) (pT)->values[(i)].tensor_ushort = *(Ushort*)pVal; 
//             break;  
//         case TENSOR_INT:
//             for (Uint i = 0; i < (pT)->size; i++) (pT)->values[(i)].tensor_int = *(int*)pVal; 
//             break;  
//         case TENSOR_UINT:
//             for (Uint i = 0; i < (pT)->size; i++) (pT)->values[(i)].tensor_uint = *(Uint*)pVal; 
//             break;  
//         case TENSOR_LONG:
//             for (Uint i = 0; i < (pT)->size; i++) (pT)->values[(i)].tensor_long = *(long*)pVal; 
//             break;  
//         case TENSOR_ULONG:
//             for (Uint i = 0; i < (pT)->size; i++) (pT)->values[(i)].tensor_ulong = *(Ulong*)pVal; 
//             break;  
//         case TENSOR_FLOAT:
//             for (Uint i = 0; i < (pT)->size; i++) (pT)->values[(i)].tensor_float = *(float*)pVal; 
//             break;  
//         case TENSOR_DOUBLE:
//             for (Uint i = 0; i < (pT)->size; i++) (pT)->values[(i)].tensor_double = *(double*)pVal; 
//             break;  
                                                      
//         default: 
//             for (Uint i = 0; i < (pT)->size; i++) memset(&((pT)->values[i]), 0, sizeof(Number));          
//         }
// }

// /**
//  * @brief Initialise all tensor values from an array input
//  * 
//  * Setup tensor values. `values` can be array of values of type: 
//  * `short`, `Ushort`, `int`, `Uint`, `long`, `Ulong`, `float` or `double`
//  * 
//  * @param pT A pointer to an instance of 
//  * @param values An array `void [pT->size]` of values to initialise tensor values as. 
//  * 
//  * @note This is a library-private function used for internal initialisation of 
//  * values for tensor factory functions. Not intended for external use.
// */
// void _tensor_init_values_from_array(Tensor *pT, void* values) {
//     switch ((pT)->dtype)
//         {
//         case TENSOR_SHORT:
//             for (Uint i = 0; i < (pT)->size; i++) (pT)->values[(i)].tensor_short = ((short*)values)[i]; 
//             break;  
//         case TENSOR_USHORT:
//             for (Uint i = 0; i < (pT)->size; i++) (pT)->values[(i)].tensor_ushort = ((Ushort*)values)[i]; 
//             break;  
//         case TENSOR_INT:
//             for (Uint i = 0; i < (pT)->size; i++) (pT)->values[(i)].tensor_int = ((int*)values)[i]; 
//             break;  
//         case TENSOR_UINT:
//             for (Uint i = 0; i < (pT)->size; i++) (pT)->values[(i)].tensor_uint = ((Uint*)values)[i]; 
//             break;  
//         case TENSOR_LONG:
//             for (Uint i = 0; i < (pT)->size; i++) (pT)->values[(i)].tensor_long = ((long*)values)[i]; 
//             break;  
//         case TENSOR_ULONG:
//             for (Uint i = 0; i < (pT)->size; i++) (pT)->values[(i)].tensor_ulong = ((Ulong*)values)[i]; 
//             break;  
//         case TENSOR_FLOAT:
//             for (Uint i = 0; i < (pT)->size; i++) (pT)->values[(i)].tensor_float = ((float*)values)[i]; 
//             break;  
//         case TENSOR_DOUBLE:
//             for (Uint i = 0; i < (pT)->size; i++) (pT)->values[(i)].tensor_double = ((double*)values)[i]; 
//             break;  
                                                      
//         default: 
//             for (Uint i = 0; i < (pT)->size; i++) memset(&((pT)->values[i]), 0, sizeof(Number));          
//         }
// }



// /*****************************************************************************
//  *                                CREATE                                     *
//  *****************************************************************************/

// /**
//  * @brief Declare and initialize (create) tensor varaible.
//  * 
//  * Requires no pre declared tensor. 
//  * 
//  * @param dimensionality The number `Uint` of dimensions the tensor spans
//  * @param shape An array `Uint [dimensionality]` of the length the tensor values stretch in each dimension
//  * @param dtype The datatype of the numeric values stored in the `.values` member
//  * 
//  * @return A tensor `Tensor` instance.
// */
// Tensor create_tensor(Uint dimensionality, Uint* shape, NumberType dtype) {
//     Tensor tensor;
//     _tensor_init_metadata(&tensor, dimensionality, shape, dtype);
//     memset(tensor.values, 0, tensor.size * sizeof(Number));         // each byte initialised to 0
//     return tensor;
// }

// /**
//  * @brief Declare and initialize (create) tensor varaible.
//  * 
//  * Requires no pre declared tensor. 
//  * 
//  * @param dimensionality The number `Uint` of dimensions the tensor spans
//  * @param shape An array `Uint [dimensionality]` of the length the tensor values stretch in each dimension
//  * @param dtype The datatype of the numeric values stored in the `.values` member
//  * 
//  * @return A tensor `Tensor` instance.
// */
// Tensor create_tensor_single_value(Uint dimensionality, Uint* shape, NumberType dtype, void *pVal) {
//     Tensor tensor;
//     _tensor_init_metadata(&tensor, dimensionality, shape, dtype);
//     _tensor_init_values_from_single(&tensor, pVal);
//     return tensor;
// }

// /**
//  * @brief Declare and initialize (create) tensor varaible.
//  * 
//  * Requires no pre declared tensor. 
//  * 
//  * @param dimensionality The number `Uint` of dimensions the tensor spans
//  * @param shape An array `Uint [dimensionality]` of the length the tensor values stretch in each dimension
//  * @param dtype The datatype of the numeric values stored in the `.values` member
//  * 
//  * @return A tensor `Tensor` instance.
// */
// Tensor create_tensor_from_array(Uint dimensionality, Uint* shape, NumberType dtype, void* values) {
//     Tensor tensor;
//     _tensor_init_metadata(&tensor, dimensionality, shape, dtype);
//     _tensor_init_values_from_array(&tensor, values);
//     return tensor;
// }




// /*****************************************************************************
//  *                                DEFINE                                     *
//  *****************************************************************************/

// /**
//  * @brief Initliaze (define) an already declared tensor variable.
//  * 
//  * Intialize the members of an already declared Tensor varaible. 
//  * This method of initializing a tensor is more efficient, especially 
//  * for large tensors, since it avoids copying and returning a complete 
//  * tensor object.
//  * 
//  * @param dimension
//  * @param shape
//  * @param dtype
//  * @param pT A pointer to a declared but not initialized tensor `Tensor`
//  * 
//  * @return Void
// */
// void define_tensor(Tensor *pT, Uint dimensionality, Uint* shape, NumberType dtype) {
//     _tensor_init_metadata(pT, dimensionality, shape, dtype);
//     memset(pT->values, 0, pT->size * sizeof(Number));           // each byte initialised to 0
// }

// /**
//  * @brief Initliaze (define) an already declared tensor variable.
//  * 
//  * Intialize the members of an already declared Tensor varaible. 
//  * 
//  * @param dimension
//  * @param shape
//  * @param dtype
//  * @param pT A pointer to a declared but not initialized tensor `Tensor`
//  * 
//  * @return Void
// */
// void define_tensor_single_value(Tensor *pT, Uint dimensionality, Uint* shape, NumberType dtype, void *pVal) {
//     _tensor_init_metadata(pT, dimensionality, shape, dtype);
//     _tensor_init_values_from_single(pT, pVal);
// }

// /**
//  * @brief Initliaze (define) an already declared tensor variable.
//  * 
//  * Intialize the members of an already declared Tensor varaible. 
//  * 
//  * @param dimension
//  * @param shape
//  * @param dtype
//  * @param pT A pointer to a declared but not initialized tensor `Tensor`
//  * 
//  * @return Void
// */
// void define_tensor_from_array(Tensor *pT, Uint dimensionality, Uint* shape, NumberType dtype, void* values) {
//     _tensor_init_metadata(pT, dimensionality, shape, dtype);
//     _tensor_init_values_from_array(pT, values);
// }



// /*****************************************************************************
//  *                                RANDOM                                     *
//  *****************************************************************************/

// /**
//  * @brief Declare and initialize (create) tensor varaible with random uniformly distributed values.
//  * 
//  * ...
//  * 
//  * @param dimensionality
//  * @param shape 
//  * @param dtype
//  * 
//  * @return A tensor `Tensor` instance.
// */
// Tensor create_tensor_uniform(Uint dimensionality, Uint* shape, NumberType dtype, int min, int max) {
//     if (min == max) {
//         // raise error div by zero ... (due to %0)
//     } 
//     Tensor tensor;
//     _tensor_init_metadata(&tensor, dimensionality, shape, dtype);
//     // create array of uniform values
//     int uniform_values[tensor.size];
//     for (Uint i = 0; i < tensor.size; i++) uniform_values[i] = rand() % (max - min) + min;
//     _tensor_init_values_from_array(&tensor, uniform_values);
//     return tensor;
// }


// // NOTE Requeries ln function... Have semi working ln approximating funcion in tensor utils.
// // /**
// //  * @brief Declare and initialize (create) tensor varaible with random gaussian-distributed values.
// //  * 
// //  * ...
// //  * 
// //  * @param dimensionality
// //  * @param shape 
// //  * @param dtype
// //  * 
// //  * @return A tensor `Tensor` instance.
// // */
// // Tensor create_tensor_gaussian(Uint dimensionality, Uint* shape, NumberType dtype, int mean, int std) {
// //     Tensor tensor;
// //     _tensor_metadata_setup(&tensor, dimensionality, shape, dtype);

// //     // initialise tensor values
// //     for (Uint i = 0; i < tensor.size; i++) {
// //         int uniform_random = rand() % (max - min) + min;
// //         INITIALIZE_TENSOR_VALUE_I(&tensor, cast_int_to_number(uniform_random, dtype), i);
// //     }

// //     return tensor;
// // }






// /*****************************************************************************
//  *                              DEPRECATED                                   *
//  *****************************************************************************/


// // #define INITIALIZE_TENSOR_VALUE_I(pT, value, i)                         \
// //     switch ((pT)->dtype)                                                \
// //         {                                                               \
// //         case TENSOR_SHORT:                                              \
// //             (pT)->values[(i)].tensor_short = (value).tensor_short;      \
// //             break;                                                      \
// //         case TENSOR_USHORT:                                             \
// //             (pT)->values[(i)].tensor_ushort = (value).tensor_ushort;    \
// //             break;                                                      \
// //         case TENSOR_INT:                                                \
// //             (pT)->values[(i)].tensor_int = (value).tensor_int;          \
// //             break;                                                      \
// //         case TENSOR_UINT:                                               \
// //             (pT)->values[(i)].tensor_uint = (value).tensor_uint;        \
// //             break;                                                      \
// //         case TENSOR_LONG:                                               \
// //             (pT)->values[(i)].tensor_long = (value).tensor_long;        \
// //             break;                                                      \
// //         case TENSOR_ULONG:                                              \
// //             (pT)->values[(i)].tensor_ulong = (value).tensor_ulong;      \
// //             break;                                                      \
// //         case TENSOR_FLOAT:                                              \
// //             (pT)->values[(i)].tensor_float = (value).tensor_float;      \
// //             break;                                                      \
// //         case TENSOR_DOUBLE:                                             \
// //             (pT)->values[(i)].tensor_double = (value).tensor_double;    \
// //             break;                                                      \
// //         default:                                                        \
// //             memset(&((pT)->values[i]), 0, sizeof(Number));              \
// //         }