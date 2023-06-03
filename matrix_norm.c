//
// Created by evarist on 29.05.23.
//
#include <math.h>

#include "matrix_norm.h"

double matrix_norm(const matrix *m1) {
    if (!m1) return -1;
    size_t i = 0, j = 0;
    double sum = 0, norm = 0;

    for (j = 0; j < matrix_cget_cols(m1); ++j) {
        norm += *matrix_cget(m1, i, j);
    }

    for (i = 1; i < matrix_cget_rows(m1); ++i) {
        for (j = 0; j < matrix_cget_cols(m1); ++j) {
            sum += fabs(*matrix_cget(m1, i, j));
        }
        if (sum > norm) norm = sum;
        sum = 0;
    }
    return norm;
}