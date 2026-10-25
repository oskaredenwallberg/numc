// // errors.h

// #ifndef _ERRORS_H_
// #define _ERRORS_H_

// #include <stdio.h>
// #include <stdlib.h>
// #include "config.h"

// #define EXIT_SUCCESS 0              // System exit was success (convention in C)
// #define EXIT_INCOMPATIBLE_SHAPE 1   // System exit due to vectors having different shapes (lengths)
// #define EXIT_MAX_LENGTH_EXCEEDED 2  // System exit due to vector input exceeding allowed `MAXIMUM_LENGTH`
// #define EXIT_DIV_BY_ZERO 3          // System exit due to undefined division by zero

// #define ERROR_MESSAGE_FORMAT 



// extern void raise_error_incompatible_shape(int line, const char* func, const char* file, 
//                                            const char* message, int* shape1, int* shape2);

// extern void raise_error_max_length_exceeded(int line, const char* func, const char* file,
//                                             const char* message, int size);

// extern void raise_error_div_by_zero(int line, const char* func, const char* file,
//                                     const char* message);


// #endif  // _ERRORS_H_
