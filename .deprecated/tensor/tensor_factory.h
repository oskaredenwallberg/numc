//tensor_factory.h

#ifndef TENSOR_FACTORY_H
#define TENSOR_FACTORY_H

#include "tensor.h"

// internal helper functions for DRY code

extern void _tensor_init_metadata(Tensor *pT, Uint dimensionality, Uint* shape, NumberType dtype);
extern void _tensor_init_values_from_single(Tensor *pT, void *pVal);
extern void _tensor_init_values_from_array(Tensor *pT, void* values);

// deterministic tensor factory functions
// create

extern Tensor create_tensor(Uint dimensionality, Uint* shape, NumberType dtype);                   //return Tensor object (declare and initialize)
extern Tensor create_tensor_single_value(Uint dimensionality, Uint* shape, NumberType dtype, void *pVal);
extern Tensor create_tensor_from_array(Uint dimensionality, Uint* shape, NumberType dtype, void* values);

// define

extern void define_tensor(Tensor *pT, Uint dimensionality, Uint* shape, NumberType dtype);         //initialise and define input Tensor varaible
extern void define_tensor_single_value(Tensor *pT, Uint dimensionality, Uint*shape, NumberType dtype, void *pVal);
extern void define_tensor_from_array(Tensor *pT, Uint dimensionality, Uint* shape, NumberType dtype, void* values);


// random tensor factory functions (uses srand w. time and rand)

extern Tensor create_tensor_uniform(Uint dimensionality, Uint* shape, NumberType dtype, int min, int max);
extern Tensor create_tensor_gaussian(Uint dimensionality, Uint* shape,  NumberType dtype, int mean, int std);



#endif //TENSOR_FACTORY_H