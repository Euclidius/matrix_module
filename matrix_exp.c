//
// Created by evarist on 29.05.23.
//

#include "matrix_exp.h"
#include "matrix_norm.h"
#include "matrix_mod.h"

struct matrix {
    size_t rows;
    size_t cols;
    double *data;
};

matrix *matrix_exp(const matrix *m, matrix *res, double eps) {
    matrix *a = matrix_alloc(matrix_cget_rows(m), matrix_cget_cols(m));
    double n = 1, k;

    if (!m || !res || matrix_cget_rows(m) != matrix_get_cols(res)) return NULL;

    if (matrix_get_rows(res) != matrix_cget_rows(m) || matrix_get_cols(res) != matrix_cget_cols(m))
        res = matrix_resize(res, matrix_cget_rows(m), matrix_cget_cols(m));

    for (int i = 0; i < matrix_get_rows(a); ++i) {
        for (int j = 0; j < matrix_get_cols(a); ++j) {
            if (i == j) matrix_sset(a, i, j, 1);
            else matrix_sset(a, i, j, 0);
        }
    }

    for (int i = 0; i < matrix_get_rows(res); ++i) {
        for (int j = 0; j < matrix_get_cols(res); ++j) {
            if (i == j) matrix_sset(res, i, j, 1);
            else matrix_sset(res, i, j, 0);
        }
    }

    do {
        k = 1.0/n;
        a = matrix_mod_mult(a, m);
        matrix_mod_mult_scal(a, k);
        res = matrix_mod_add(res, a);
        ++n;
    } while (matrix_norm(a) >= eps);

    matrix_free(a);

    return res;
}