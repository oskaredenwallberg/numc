// tensor_utils.c

// ...









// #include "tensor_utils.h"
// #include "tensor.h"

// /**
//  * Debugging print for 1d arrays
// */
// void print_1d_array(Uint* array, Uint size) {
//     printf("[ ");
//     for (Uint i = 0; i < size; i++) {
//         printf("%d ", array[i]);
//     }
//     printf("]\n");
// }

// /**
//  * Debugging print for 1d arrays
// */
// void print_tensor_values_1d(Number values[], Uint size) {
//     printf("[ ");
//     for (Uint i = 0; i < size; i++) {
//         printf("%u ", values[i].tensor_uint);
//     }
//     printf("]\n");
// }





// /**
//  * @brief Print visual representation of tensor.
//  * Brackets denote delimiter for axis.
//  * 
//  * @param pT pointer to a tensor `Tensor`
//  * @return void
//  */
// void print_tensor(Tensor *pT) {
//     Uint dim = pT->dim;

//     // create cumulative products of of first dim-1 number of shape values
//     // {a, b, c, d} -> {abc, bc, c, 1}  for any dimensionality
//     Uint cumulative_shape[dim];
//     cumulative_shape[dim-1] = 1;        // set last element (for columns) to 1

//     for (Uint axis_i = 0; axis_i < dim-1; axis_i++) {                       // for first dim-1 elements
//         cumulative_shape[axis_i] = 1;                                       // initialise cumulative product to 1
//         for (Uint prev_axis = axis_i; prev_axis < dim-1; prev_axis++) {     // cumulative product i is product of elements i to dim-2
//             cumulative_shape[axis_i] *= pT->shape[prev_axis];
//         }
//     }

//     const Uint cols = pT->shape[dim-1];
//     const Uint lines = cumulative_shape[0];     // number of lines to print
//     Uint num_brackets[lines];

//     // fill num_brackets array
//     for (Uint line = 0; line < lines; line++) {
//         for (Uint axis = 0; axis < dim; axis++) {
//             if (line % cumulative_shape[axis] == 0) {
//                 num_brackets[line] = dim-axis;
//                 break;                          // break at first found axis
//             }
//         }
//     }

//     // DEBUG PRINT
//     // print_1darray(num_brackets, lines);
//     // after building the list of number of brackets for each row printed...
//     // use symmetry of print pattern, ending brackets (on right side) follows same pattern as left ones but in opposite order

//     Uint spaces;
//     Uint left_brackets, right_brackets;
//     for (Uint line = 0; line < lines; line++) {
//         left_brackets = num_brackets[line];
//         spaces = dim-left_brackets;
//         right_brackets = num_brackets[lines-1-line];    // begin from other end
//         // line print
//         for (Uint s = 0; s < spaces; s++) printf(" ");
//         for (Uint lb = 0; lb < left_brackets; lb++) printf("[");
//         printf(" ");
//         for (Uint j = 0; j < cols; j++) {
//             switch (pT->dtype) {
//                 case TENSOR_SHORT: printf("%hd ", pT->values[line*cols+j].tensor_short); break;
//                 case TENSOR_USHORT: printf("%hu ", pT->values[line*cols+j].tensor_ushort); break;
//                 case TENSOR_INT: printf("%d ", pT->values[line*cols+j].tensor_int); break;
//                 case TENSOR_UINT: printf("%u ", pT->values[line*cols+j].tensor_uint); break;
//                 case TENSOR_LONG: printf("%ld ", pT->values[line*cols+j].tensor_long); break;
//                 case TENSOR_ULONG: printf("%lu ", pT->values[line*cols+j].tensor_ulong); break;
//                 case TENSOR_FLOAT: printf("%g ", pT->values[line*cols+j].tensor_float); break;   // %g uses shortest of %f (fixed-point notation) and %e (scientific notation) break;
//                 case TENSOR_DOUBLE: printf("%lg ", pT->values[line*cols+j].tensor_double); break; // %lg uses shortest of %lf and %le (see float) break;
//                 default: printf("* "); break;
//             }
//         }
//         for (Uint rb = 0; rb < right_brackets; rb++) printf("]");
//         printf("\n");
//     }
//     print_tensor_metadata(pT);
// }



// /**
//  * @brief Print metadata about tensor.
//  * 
//  * Displays shape and datatype.
//  * 
//  * @param pT A pointer to a tensor `Tensor`
//  * 
//  * @return void
// */
// void print_tensor_metadata(Tensor *pT) {
//     printf("Tensor (%ud) \n", pT->dim);
//     printf(" :shape: "); print_tensor_shape(pT);
//     printf("\n");
//     printf(" :dtype: "); print_tensor_dtype(pT);
//     printf("\n");
// }


// /**
//  * @brief Print the shape `Uint [dimensionality]` of a tensor.
//  * 
//  * No newline included.
//  * 
//  * @param pT A pointer to a tensor `Tensor`
//  * 
//  * @return void
// */
// void print_tensor_shape(Tensor *pT) {
//     printf("{");
//     for (Uint axis = 0; axis < pT->dim; axis++) {
//         printf("%u", pT->shape[axis]);
//         if (axis != pT->dim-1) printf(", ");
//     }
//     printf("}");
// }


// /**
//  * @brief Print the data type `NumberType` of a tensor.
//  * No newline included.
//  * 
//  * @param pT A pointer to a tensor `Tensor`
//  * @return void
// */
// void print_tensor_dtype(Tensor *pT) {
//     switch (pT->dtype)
//     {
//     case TENSOR_SHORT: printf("short"); break;
//     case TENSOR_USHORT: printf("Ushort (unsigned short)"); break;
//     case TENSOR_INT: printf("int"); break;
//     case TENSOR_UINT: printf("Uint (unsigned int)"); break;
//     case TENSOR_LONG: printf("long"); break;
//     case TENSOR_ULONG: printf("Ulong (unsigned long)"); break;
//     case TENSOR_FLOAT: printf("float"); break;
//     case TENSOR_DOUBLE: printf("double"); break;
    
//     default: printf("UNKNOWN"); break;
//     }
// }



// /**
//  * @brief Maclaurin Series approximation of ln(x) = ±ln(1+t). 
//  * 
//  * Converges for `|x| < 1`. 
//  * Computed as `ln(1+x) = x - x^2/2 + x^3/3 - x^4/4 - ...`. 
//  * Leverages the fact that `ln(x) = -ln(1/x)`.
//  * if x < 1.0: `ln(x) = ln(1 + (x-1)) = ln(1 + t), t = x-1`
//  * if x > 1.0: `ln(x) = -ln(1/x) = -ln(1 + (1/x - 1)) = -ln(1 + t), t = 1/x - 1`
//  * 
//  * @param x
//  * 
//  * @return ~ln(x) `double`
//  * 
//  * @note Better precision for small x, avoid x larger than 100.
// */
// double scalar_ln(double x) {
//     if (x <= 0.0) {
//         // raise error div by zero
//     }

//     int should_negate = 0;
//     double t;
//     if (x >= 1.0) {
//         t = (1.0 / x) - 1.0;
//         should_negate = 1;
//     } else {
//         t = x - 1.0;
//     }

//     double result = 0.0;
//     double term_i = 1.0;

//     printf("%lf \n", t);

//     for (Uint i = 1; i < 10000; i++) {
//         term_i *= t;
//         result += (i % 2 == 0) ? -term_i / i : term_i / i;  // every other term is negative
//     }

//     return (should_negate == 1) ? -result : result;
// }


// /**
//  * @brief Maclaurin Series approximation of cos(x). 
//  * 
//  * `cos(x) = 1 - x^2/2! + x^4/4! - x^6/6! + ...`
//  * 
//  * @param x A scalar value `double`
//  * 
//  * @return ~cos(x) `double`
// */
// double scalar_cos(double x) {
//     if (x == 0.0) return 1.0;
    
//     double result = 1.0;        // approximation of sin(x), initialised to 0 (sin(0))
//     double term_i = 1.0;        // first term is 1.0

//     for (Uint i = 1; i < TAYLOR_APPROX_MAX_ITER; i++) {
//         term_i *= x*x/(2*i);                  // sin(0) == 0, only cosine terms remain
//         if (scalar_abs(term_i) < TAYLOR_APPROX_TOLERANCE) break;
//         if (i%2!=0) term_i = -term_i;           // every other term is negative
//         result += term_i;
//     }

//     return result;
// }



// /**
//  * @brief Maclaurin Series approximation of sin(x). 
//  * 
//  * `sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ...`
//  * 
//  * @param x A scalar value `double`
//  * 
//  * @return ~sin(x) `double`
// */
// double scalar_sin(double x) {
//     if (x == 0.0) return 0.0;

//     double result = x;        // approximation of sin(x), initialised to 0 (sin(0))
//     double term_i = x;          // first term is x

//     for (Uint i = 1; i < TAYLOR_APPROX_MAX_ITER; i++) {
//         term_i *= ((x*x)/(2*i+1));                  // sin(0) == 0, only cosine terms remain
//         // if (scalar_abs(term_i) < TAYLOR_APPROX_TOLERANCE) break;
//         printf("%f  \n", (i%2==0) ? -term_i : term_i);
//         result += (i%2==0) ? -term_i : term_i;    // every other term is negative
//     }

//     return result;
// }   


// /**
//  * @brief Maclaurin approximation of e^x.
//  * 
//  * Maclaurin Polynominal series is the Taylor Polynomial series approximated for function around a = 0. 
//  * Accurate up to 12 decimal points. 
//  * 
//  * @param x A scalar value `double`
//  * 
//  * @return ~e^x `double`
// */
// double scalar_exp(double x) {
//     if (x == 0.0) return 1.0;    

//     double result = 1.0;        // approximation of e^x, initialised to 1 (e^0)
//     double term_i = 1.0;

//     for (Uint i = 1; i < TAYLOR_APPROX_MAX_ITER; i++) {
//         term_i *= x / i;
//         if (scalar_abs(term_i) < TAYLOR_APPROX_TOLERANCE) break;
//         result += term_i;
//     }

//     return result;
// }
 
 
// /**
//  * @brief The absolute value of a scalar x.
//  * 
//  * ...
//  * 
//  * @param x A scalar value `double`
//  * 
//  * @return |x| `double`. 
//  * 
//  * @note ALREADY IMPLEMENTED AS `int abs(int)` UNDER /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdlib.h:132:6
// */
// double scalar_abs(double x) {
//     return (x < 0) ? -x : x;
// }


// /**
//  * @brief A scalar x raised to an integer power n. 
//  * 
//  * ...
//  * 
//  * @param x A scalar value `double` as the base
//  * @param n An integer value `int` as the exponent
//  * 
//  * @return x^n `double`
// */
// double scalar_power_n(double x, int n) {
//     if (x == 0.0 && n == 0) {
//         // raise error undefined expression
//     }
//     double result = 1.0;
//     for (int i = 0; i < scalar_abs(n); i++) {
//         result *= x;
//     }
//     if (n < 0) return 1.0/result;
//     else return result;
// }



// /**
//  * @brief The probability mass of a gaussian probability distribution function at a given point x. 
//  * 
//  * `N(µ, σ)`
//  * `PDF_gaussian(x) = 1/(σ√(2π)) * e^-(1/(2σ)(x-µ)^2)`
//  * 
//  * @param mu The mean value and location of the distribution
//  * @param sigmoid The standard deviation of the distribution
//  * 
//  * @return The probability mass `double` of a gaussian probability distribution function at a given point x. 
// */
// double scalar_pdf_gaussian(double mu, double sigmoid, double x) {
//     double result = 1.0/(sigmoid*SQRT_2*SQRT_PI) * scalar_exp(-1/(2*sigmoid*scalar_power_n((x-mu), 2)));
//     return result;
// }



// // 3d tensor visualisation (2, 2, 3)
// // 
// // [[[1, 2, 3],
// //   [4, 5, 6]],
// //  [[1, 2, 3],
// //   [4, 5, 6]]]
// // Tensor
// //  :shape: {2, 2, 3}
// //  :dtype: int
// // 
// // 4d tensor visualisation (3, 2, 2, 3)
// // 
// // [[[[1, 2, 3]
// //    [4, 5, 6]]
// //   [[1, 2, 3]
// //    [4, 5, 6]]]
// //  [[[1, 2, 3]
// //    [4, 5, 6]]
// //   [[1, 2, 3]
// //    [4, 5, 6]]]
// //  [[[1, 2, 3]
// //    [4, 5, 6]]
// //   [[1, 2, 3]
// //    [4, 5, 6]]]]
// // 
// // cumulative shape products : (12, 4, 2, 3)



// // /**
// //  * @brief Cast an integer value `int` to the type `Number`.
// //  * 
// //  * Due to the integer being casted as another numeric datatype some precision may be lost.
// //  * However this is usually safe for smaller integer values (up until 2^12 is safe, even 2^15 for some systems). 
// //  * 
// //  * @param value An integer value `int` to be cast to a Number
// //  * @param dtype The numeric type `NumberType` the integer value should be casted as
// //  * 
// //  * @return A number `Number` with the specified value (potentually truncated) of the specified enum NumberType
// // */
// // Number cast_int_to_number(int integer_value, NumberType dtype) {
// //     Number number;
// //     switch (dtype) 
// //     {
// //         case TENSOR_SHORT: number.tensor_short = (short) integer_value; break;
// //         case TENSOR_USHORT: number.tensor_ushort = (Ushort) integer_value; break;
// //         case TENSOR_INT: number.tensor_int = integer_value; break;          // no casting needed
// //         case TENSOR_UINT: number.tensor_uint = (Uint) integer_value; break;
// //         case TENSOR_LONG: number.tensor_long = (long) integer_value; break;
// //         case TENSOR_ULONG: number.tensor_ulong = (Ulong) integer_value; break;
// //         case TENSOR_FLOAT: number.tensor_float = (float) integer_value; break;
// //         case TENSOR_DOUBLE: number.tensor_double = (double) integer_value; break;
// //         default: memset(&number, 0, sizeof(number)); break;  
// //     }

// //     return number;
// // }




// // // treat pN as x in the original scalar_cos function and write to the NUMBER_TYPE member
// // #define MACRO_TENSOR_COS(NUMBER_MEMBER) { \
// //     if (pN->NUMBER_MEMBER = 0) break; \
// //     Number result; \
// //     result.NUMBER_MEMBER = pN->NUMBER_MEMBER; \
// //     Number term_i; \
// //     term_i.NUMBER_MEMBER = pN->NUMBER_MEMBER; \
// //     for (Uint i = 0; i < TAYLOR_APPROX_MAX_ITER; i++) { \
// //         term_i.NUMBER_MEMBER *= pN->NUMBER_MEMBER * pN->NUMBER_MEMBER / (2*i+1); \
// //         if (term_i.NUMBER_MEMBER < TAYLOR_APPROX_TOLERANCE) break; \
// //         result.NUMBER_MEMBER += term_i.NUMBER_MEMBER; \
// //     } \
// //     pN->NUMBER_MEMBER = result.NUMBER_MEMBER; \
// // }

// // /**
// //  * 
// //  */
// // static inline void array_cos(Number values[], NumberType dtype) {
// //     switch (dtype)
// //     {
// //     case TENSOR_SHORT:  MACRO_TENSOR_COS(tensor_short); break;
// //     case TENSOR_USHORT: MACRO_TENSOR_COS(tensor_ushort); break;
// //     case TENSOR_INT:    MACRO_TENSOR_COS(tensor_int); break;
// //     case TENSOR_UINT:   MACRO_TENSOR_COS(tensor_uint); break;
// //     case TENSOR_LONG:   MACRO_TENSOR_COS(tensor_long); break;
// //     case TENSOR_ULONG:  MACRO_TENSOR_COS(tensor_ulong); break;
// //     case TENSOR_FLOAT:  MACRO_TENSOR_COS(tensor_float); break;
// //     case TENSOR_DOUBLE: MACRO_TENSOR_COS(tensor_double); break;
// //     default: 
// //         fprintf(stderr, "Error: Invalid number type for absolute value. \n");
// //         exit(EXIT_SUCCESS);
// //         break;
// //     }
// // }