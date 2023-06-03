#include <stdio.h>
#include "matrix.h"
#include "matrix_mod.h"
#include "matrix_exp.h"

int main() {
    matrix *matrix1 = matrix_alloc_zero(3, 3);
    matrix_sset(matrix1, 0, 0, 1);
    matrix_sset(matrix1, 1, 1, 2);
    matrix_sset(matrix1, 2, 2, -1);
    matrix *matrix2 = matrix_alloc(3, 3);

    matrix_exp(matrix1, matrix2, 0.001);

    matrix_print(matrix2);

    matrix_free(matrix1);
    matrix_free(matrix2);
}
