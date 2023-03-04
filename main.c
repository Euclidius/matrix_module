#include <stdio.h>
#include "matrix.h"

int main() {
    matrix *matrix1 = matrix_alloc(5, 3);
//    matrix *matrix2 = matrix_alloc(2, 3);

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 3; ++j) {
            matrix_set(matrix1, i, j, i + j);
        }
    }

    matrix *matrix2 = matrix_clone(matrix1);

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%lf ", *matrix_get(matrix2, i, j));
        }
        puts("");
    }

    matrix_free(matrix1);
    matrix_free(matrix2);
}
