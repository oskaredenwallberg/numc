//tensor_utils.h

#ifndef TENSOR_UTILS_H
#define TENSOR_UTILS_H

#include "tensor.h"


//math functions

extern double scalar_pdf_gaussian(double mu, double sigmoid, double x);

extern double scalar_cos(double x);
extern double scalar_sin(double x);

extern double scalar_ln(double x);
extern double scalar_exp(double x);
extern double scalar_abs(double x);
extern double scalar_power_n(double x, int n);


extern void array_cos(Number values[], NumberType dtype); 


//convert integer value to type Number

extern Number cast_int_to_number(int integer_value, NumberType dtype);


//printing tensor in terminal

extern void print_tensor_shape(Tensor *pT);
extern void print_tensor_dtype(Tensor *pT);
extern void print_tensor_metadata(Tensor *pT);
extern void print_tensor_values_1d(Number values[], Uint size);
extern void print_tensor(Tensor *pT);

extern void print_1d_array(Uint* array, Uint size);

//saving and loading tensors (serializing)

extern void save_tensor(char* path, Tensor *pT);
extern void load_tensor(char* path, Tensor *pT);



#define MACRO_TENSOR_ABS(number_member) { \
    for (Uint i = 0; i < pT->size; i++) { \
        pT->values[i].number_member = (pT->values[i].number_member >= 0) ? pT->values[i].number_member : -pT->values[i].number_member; \
    } \
}

#define MACRO_TENSOR_EXP(number_member) { \
    for (Uint i = 0; i < pT->size; i++) { \
        if (pT->values[i].number_member == 0 & pow == 0) { \
            fprintf(stderr, "Error: Zero to the power of zero (0^0) is undefined. \n"); \
            exit(EXIT_FAILURE); \
        } \
        Number result; \
        result.number_member = 1; \
        for (Uint p = (pow > 0) ? pow : -pow; p > 0; p--) { \
            result.number_member *= pT->values[i].number_member; \
        } \
        pT->values[i].number_member = (pow > 0) ? result.number_member : 1/(result.number_member); \
    } \
}

// NOTE - Only intended for approximations of x close to 0 (Since Maclaurin Series stem from x=0)
// sin(0) = 0
// sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ... (Taylor Approx. / Maclaurin Series for sin(x))
#define MACRO_TENSOR_SIN(number_member) { \
    for (Uint i = 0; i < pT->size; i++) { \
        if (pT->values[i].number_member == 0) continue; \
        Number x; \
        x.number_member = pT->values[i].number_member; \
        Number result; \
        result.number_member = x.number_member; \
        Number term_t; \
        term_t.number_member = x.number_member; \
        for (Uint t = 1; t < TAYLOR_APPROX_MAX_ITER; t++) { \
            term_t.number_member *= x.number_member*x.number_member * 1/(2*t+1); \
            result.number_member += (t%2 == 0) ? -term_t.number_member : term_t.number_member; \
        } \
        pT->values[i].number_member = result.number_member; \
    } \
}


#define MACRO_TENSOR_MODULO(x, number_member) { \
}


// // cos(0) = 1
// // cos(x) = 1 - x^2/2! + x^4/4! - x^6/6! + ... (Taylor Approx. / Maclaurin Series for cos(x))
// #define MACRO_TENSOR_COS(number_member) { \
//     for (Uint i = 0; i < pT->size; i++) { \
//         if (pT->values[i].number_member == 0) {
//             pT->values[i].number_member = 1;
//             continue
//         }; \
//         Number x; \
//         x.number_member = pT->values[i].number_member; \
//         Number result; \
//         result.number_member = 1; \
//         Number term_t; \
//         term_t.number_member = 1; \
//         for (Uint t = 1; t < TAYLOR_APPROX_MAX_ITER; t++) { \
//             term_t.number_member *= x.number_member*x.number_member * 1/(2*t); \
//             if (-TAYLOR_APPROX_TOLERANCE < term_t.number_member && term_t.number_member < TAYLOR_APPROX_TOLERANCE) break; \
//             result.number_member += (t%2 == 0) ? -term_t.number_member : term_t.number_member; \
//         } \
//         pT->values[i].number_member = result.number_member; \
//     } \
// }



#endif //TENSOR_UTILS_H