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
