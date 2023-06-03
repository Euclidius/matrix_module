//
// Created by evarist on 05.03.23.
//

#include "matrix_mod.h"
#include "matrix.h"

void matrix_mod_mult_row_scal(matrix *m, size_t i, double scal) {
    for (int elem = 0; elem < matrix_get_cols(m); ++elem) {
        matrix_sset(m, i, elem, *matrix_get(m, i, elem) * scal);
    }
}

void matrix_mod_sum_rows(matrix *m, size_t from, size_t to, double p) {
    for (int elem = 0; elem < matrix_get_cols(m); ++elem) {
        matrix_sset(m, to, elem, *matrix_get(m, to, elem) + *matrix_get(m, from, elem) * p);
    }
}

void matrix_mod_perm_rows(matrix *m, size_t i, size_t j) {
    double temp;
    for (int elem = 0; elem < matrix_get_cols(m); ++elem) {
        temp = *matrix_get(m, i, elem);
        matrix_sset(m, i, elem, *matrix_get(m, j, elem));
        matrix_sset(m, j, elem, temp);
    }
}

void matrix_mod_mult_scal(matrix *m, double scal) {
    for (int row = 0; row < matrix_get_rows(m); ++row) {
        matrix_mod_mult_row_scal(m, row, scal);
    }
}

matrix *matrix_mod_add(matrix *m1, const matrix *m2) {
    if (matrix_get_cols(m1) != matrix_cget_cols(m2) || matrix_get_rows(m1) != matrix_cget_rows(m2)) {
        return NULL;
    }
    for (int row = 0; row < matrix_get_rows(m1); ++row) {
        for (int col = 0; col < matrix_get_cols(m1); ++col) {
            matrix_sset(m1, row, col, *matrix_get(m1, row, col) + *matrix_cget(m2, row, col));
        }
    }
    return m1;
}

matrix *matrix_mod_transp_sq(matrix *m1) {
    if (matrix_get_cols(m1) != matrix_get_rows(m1)) {
        return NULL;
    }
    for (int row = 0; row < matrix_get_rows(m1); ++row) {
        for (int col = row; col < matrix_get_cols(m1); ++col) {
            double *tmp = matrix_get(m1, row, col);
            matrix_sset(m1, row, col, *matrix_get(m1, col, row));
            matrix_sset(m1, col, row, *tmp);
        }
    }
    return m1;
}

matrix *matrix_mod_mult_t(matrix *m, const matrix *m1, const matrix *m2) {
    double h;

    if (!m || !m1 || !m2  || matrix_cget_rows(m1) != matrix_cget_cols(m2)) return NULL;
    if (matrix_cget_cols(m1) != matrix_cget_cols(m) || matrix_cget_rows(m) != matrix_cget_rows(m2)) m = matrix_resize(m,
                                                                                                                      matrix_cget_rows(m1),
                                                                                                                      matrix_cget_cols(m2));
    for (size_t i = 0; i < matrix_get_rows(m); ++i) {
        for (size_t j = 0; j < matrix_get_cols(m); ++j) {
            h = 0;
            for (size_t k = 0; k < matrix_cget_rows(m1); ++k) {
                h += *matrix_cget(m1, i, k) * *matrix_cget(m2, k , j);
            }
            matrix_sset(m, i, j, h);
        }
    }
    return m;
}

matrix *matrix_mod_mult(matrix *m1, const matrix *m2) {
    matrix *y;
    if (!m1 || !m2  || matrix_cget_rows(m1) != matrix_cget_cols(m2)) return NULL;

    y = matrix_alloc(matrix_get_cols(m1), matrix_cget_rows(m2));
    y = matrix_mod_mult_t(y, m1, m2);
    if (matrix_get_rows(m1) != matrix_get_cols(y) || matrix_get_rows(m1) != matrix_get_rows(y)) m1 = matrix_resize(m1,
                                                                                                                   matrix_get_cols(y),
                                                                                                                   matrix_get_rows(y));
    m1 = matrix_assign(m1, y);
    return m1;

}

matrix *matrix_mod_reverse(matrix *m, matrix *res) {
    if (!m || !res) return NULL;
    size_t i = 0, j = 0, k = 0;
    double p;

    for (int a = 0; a < matrix_get_rows(res); ++a) {
        for (int b = 0; b < matrix_get_cols(res); ++b) {
            if (a == b) matrix_sset(res, a, b, 1);
            else matrix_sset(res, a, b, 0);
        }
    }

    for (; k< matrix_cget_cols(m); ++k) {
        while (*matrix_cget(m, i, j) == 0 && i < matrix_cget_rows(m)) {
            ++i;
            if (*matrix_cget(m, i, j) == 0 && i == matrix_cget_rows(m) - 1) {
                ++j;
                i = 0;
            }
        }
        if (i != matrix_cget_rows(m)) {
            matrix_mod_perm_rows(m, k, i);
            matrix_mod_perm_rows(res, k ,i);

            for (i = k + 1; i < matrix_get_rows(m); ++i) {
                if (*matrix_get(m, i, j) != 0) {
                    p = *matrix_get(m, i, j);
                    matrix_mod_mult_row_scal(m, i, -*matrix_get(m, k, j));
                    matrix_mod_mult_row_scal(res, i, -*matrix_get(m, k, j));
                    matrix_mod_sum_rows(m, i, k, p);
                    matrix_mod_sum_rows(res, i, k, p);

                }
            }
        }
        j = k + 1; i = k + 1;
    }
    if (*matrix_get(m, matrix_get_rows(m) - 1, matrix_get_cols(m) - 1) == 0) {
        return NULL;
    }
    for(j = matrix_get_rows(m) - 1; j > 0; --j)
    {
        for(i = 0; i < j; ++i)                                                         //��������� ����� ���� ������
        {
            p = *matrix_get(m, i, j);
            matrix_mod_mult_row_scal(m, i, - *matrix_get(m, j, j));
            matrix_mod_mult_row_scal(res, i, - *matrix_get(m, j, j));
            matrix_mod_sum_rows(m, i, j, p);
            matrix_mod_sum_rows(res, i, j, p);
        }
    }


    for(i = 0; i < matrix_get_rows(m); ++i)
    {
        p = *matrix_get(m, i, i);
        *matrix_get(m, i, i) /= p;
        matrix_mod_mult_row_scal(res, i, 1/p);                                          //�������� �� ���������
    }
    return res;
}
