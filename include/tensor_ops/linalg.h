#ifndef TENSOR_LINALG_H
#define TENSOR_LINALG_H

#include "../tensor.h"

// matrix ops
Tensor matrix_mul(const Tensor *a, Tensor *b);
Tensor matrix_inv(const Tensor *a);
Scalar matrix_det(const Tensor *a);
Tensor matrix_diag(const Tensor *a);

// vector ops 
Scalar vector_inner(const Tensor *pu, const Tensor *pv);
Tensor vector_outer(const Tensor *pu, const Tensor *pv);

typedef struct {
    Tensor val;
    Tensor vec;
} ResultEigen;

typedef struct {
    Tensor u;
    Tensor s;
    Tensor vt;  // transposed
} ResultSVD;

typedef struct {
    Tensor q;
    Tensor r;
} ResultQR;

// decomposition
ResultEigen matrix_eigh(const Tensor *t);
ResultSVD   matrix_svd(const Tensor *t);
ResultQR    matrix_qr(const Tensor *t);
Tensor      matrix_cholesky(const Tensor *t);

#endif
