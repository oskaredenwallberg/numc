// errors.c

// ... ?


















// #include "errors.h"

// /**
//  * @brief Raise error message for two vectors `Vector` having incompatible shapes to perform operation.
//  * 
//  * ...
//  * 
//  * @param line The number of the current line `__LINE__`
//  * @param func The name of the current function `__func__`
//  * @param file The name of the current file `__FILE__`
//  * @param message A descriptive message `char str[]` of why the error was raised
//  * @param shape1 The shape member `u.shape` of the first vector 
//  * @param shape2 The shape member `v.shape` of the second vector
//  * 
//  * @return `void`
// */
// void raise_error_incompatible_shape(int line, const char* func, const char* file, 
//                                     const char* message, int* shape1, int* shape2) 
// {
//     const char default_message[] = "Vectors have incompatible shapes to perform operation";
//     message = (message == NULL || message[0] == '\0') ? default_message : message;

//     fprintf(stderr, "\n Error: line %i in %s() -f %s \n %s : (%i,) with (%i,) \n\n", 
//             line, func, file,
//             message, shape1[0], shape2[0]);
    
//     exit(EXIT_INCOMPATIBLE_SHAPE);
// }



// /**
//  * @brief Raise error message for maximum values (array) length exceeded.
//  * 
//  * ...
//  * 
//  * @param line The number of the current line `__LINE__`
//  * @param file The name of the current file `__FILE__`
//  * @param func The name of the current function `__func__`
//  * @param message A descriptive message `char str[]` of why the error was raised
//  * @param size The size that exceeded the limit
//  * 
//  * @return `void`
// */
// void raise_error_max_length_exceeded(int line, const char* func, const char* file,
//                                      const char* message, int size) 
// {
//     const char default_message[] = "Vector size exceeded maximum length";
//     message = (message == NULL || message[0] == '\0') ? default_message : message;

//     fprintf(stderr, "\n Error: line %i in %s() -f %s \n %s : %i > %i \n\n", 
//             line, func, file,
//             message, size, MAXIMUM_LENGTH);

//     exit(EXIT_MAX_LENGTH_EXCEEDED);
// }


// /**
//  * @brief Raise error message for tried to divide by zero.
//  * 
//  * ...
//  * 
//  * @param line The number of the current line `__LINE__`
//  * @param file The name of the current file `__FILE__`
//  * @param func The name of the current function `__func__`
//  * @param message A descriptive message `char str[]` of why the error was raised
//  * 
//  * @return `void`
// */
// void raise_error_div_by_zero(int line, const char* func, const char* file,
//                              const char* message)
// {
//     const char default_message[] = "Vector size exceeded maximum length";
//     message = (message == NULL || message[0] == '\0') ? default_message : message;

//     fprintf(stderr, "\n Error: line %i in %s() -f %s \n %s \n\n", 
//             line, func, file,
//             message);
//     exit(EXIT_DIV_BY_ZERO);
// }