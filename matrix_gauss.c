//
// Created by evarist on 01.06.23.
//

#include "matrix_gauss.h"
#include "matrix_mod.h"

matrix *Gauss(matrix *m, matrix *b, matrix *x) {
    if(!x || !m || !b) return NULL;
    size_t j = 0, i = 0, k = 0;
    double p;

    for(; k < matrix_get_rows(m); ++k) {
        while (*matrix_get(m, i, j) == 0 && i < matrix_get_rows(m)) {
            ++i;

            if(*matrix_get(m, i, j) == 0 && i == matrix_get_rows(m) - 1) {
                ++j;
                i = 0;
            }
        }
        if(i != matrix_get_rows(m)) {
            matrix_mod_perm_rows(m, k, i);
            matrix_mod_perm_rows(b, k, i);
            for(i = k + 1; i < matrix_get_rows(m); ++i) {
                if(*matrix_get(m, i, j) != 0) {
                    p = *matrix_get(m, i, j);
                    matrix_mod_mult_row_scal(m, i, - *matrix_get(m, k, j));
                    matrix_mod_mult_row_scal(b, i,- *matrix_get(m, k, j));
                    matrix_mod_sum_rows(m, i, k, p);
                    matrix_mod_sum_rows(b, i, k, p);
                }
            }
        }
        j = k +1; i = k + 1;
    }


    if(*matrix_get(m, matrix_get_rows(m) - 1, matrix_get_cols(m) - 1) == 0) {
        return NULL;
    }

    for(j = matrix_get_cols(m) - 1; j > 0; --j) {
        for(i = 0; i < j; ++i) {
            p = *matrix_get(m, i, j);
            matrix_mod_mult_row_scal(m, i,- *matrix_get(m, j, j));
            matrix_mod_mult_row_scal(b, i, - *matrix_get(m, j, j));
            matrix_mod_sum_rows(m, i, j, p);
            matrix_mod_sum_rows(b, i, j, p);
        }
    }


    for(i = 0; i < matrix_get_rows(x); ++i) {
        p = *matrix_get(m, i, i);
        *matrix_get(m, i, i) /= p;
        *matrix_get(b, i, 0) /= p;
    }

    x = matrix_assign(x, b);

    return x;
}
