# NumC
NumC is a tensor library implemented in C. It mimics Pthons's NumPy. NumC implements the general data type `Tensor` (similar to `NDArray`) and covers funationality such as broadcasting, linear algebra operations, unary and binary operations, transposing, reshaping and more. It is meant as a personal learning project to better understand memory layout, efficient and stable numerical computation, mathematics translated to code, data manipulation, and algorithms.

## Repository layout

```
include/
 |- tensor_ops/
 |   |- binary.h
 |   |- linalg.h
 |   |- reduce.h
 |   |- unary.h
 |- scalar_math.h
 |- tensor_io.h
 |- tensor.h
src/
 |- tensor_ops/
 |   |- binary.c
 |   |- linalg.c
 |   |- reduce.c
 |   |- unary.c
 |- main.c
 |- scalar_math.c
 |- tensor_io.c
 |- tensor.c
.gitignore
Makefile
README.md
```

## Setup

...
