//matrix operations
extern void   matrix_multiplication(Tensor *pA, Tensor *pB, Tensor *pC);
extern void   matrix_transpose(Tensor *pA);
extern double matrix_determinant(Tensor *pA);
extern void   matrix_inverse(Tensor *pA);

//vector operations
extern double vector_inner(Tensor *pu, Tensor *pv);
extern void   vector_outer(Tensor *pu, Tensor *pv);

//linear algebra function
// extern ... matrix_eigenvalues(...);
// extern ... matrix_eigenvectors(...);
// extern ... singluar_value_decomposition(...);
// QR decomposition ??
