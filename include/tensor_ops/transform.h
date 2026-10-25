//tensor reshaping
extern void tensor_reshape(Tensor *pT, int *shape, Tensor *pT_res);
extern void tensor_squeeze(Tensor *pT, Tensor *pT_res);         //remove dimension of size 1
extern void tensor_unsqueeze(Tensor *pT, Tensor *pT_res);       //add dimension of size 1
extern void tensor_flatten(Tensor *pT, Tensor *pT_res);

//tensor concatenation and splitting
extern void tensor_concatenate(Tensor *pT_1, Tensor *pT_2, int axis, Tensor *pT_res);
extern void tensor_split(Tensor *pT_in, Tensor *pT_1, Tensor *pT_2);
extern void tensor_slice(Tensor *pT, int axis, int start, int stop, Tensor *pT_res);
