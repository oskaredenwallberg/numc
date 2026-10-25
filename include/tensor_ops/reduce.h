//reduction operations
extern void tensor_min(Tensor *pT, int axis, Tensor *pT_res);
extern void tensor_max(Tensor *pT, int axis);
extern void tensor_sum(Tensor *pT, int axis);
extern void tensor_mean(Tensor *pT, int axis);
extern void tensor_stddev(Tensor *pT, int axis);
extern void tensor_variance(Tensor *pT, int axis);
extern void tensor_median(Tensor *pT, int axis);
