//
// Created by evarist on 04.03.23.
//

#include <malloc.h>
#include <memory.h>
#include "matrix.h"

struct matrix {
    size_t rows;
    size_t cols;
    double *data;
};

matrix *matrix_alloc(size_t h, size_t w) {
    matrix *mat = (matrix*) malloc(sizeof(matrix));
    if (mat == NULL) {
        return NULL;
    }
    double *m = (double*) malloc(sizeof(double) * h * w);
    if (m == NULL) {
        free(mat);
        return NULL;
    }

    mat->cols = h;
    mat->rows = w;
    mat->data = m;

    return mat;
}

void matrix_free(matrix *m) {
    free(m->data);
    free(m);
}

matrix *matrix_clone(const matrix *m) {
    matrix* new = matrix_alloc(m->cols, m->rows);
    if (new == NULL) {
        return NULL;
    }
    memcpy(new->data, m->data, m->cols * m->rows * sizeof(double));
    return new;
}

matrix *matrix_resize(matrix *m, size_t h, size_t w) {
    matrix *new = matrix_alloc(h, w);
    if (new == NULL) {
        return NULL;
    }
    else {
        matrix_free(m);
        return new;
    }
}

double *matrix_get(matrix *m, size_t i, size_t j) {
    return m->data + i * m->rows + j;
}

const double *matrix_cget(const matrix *m, size_t i, size_t j) {
    return m->data + i * m->rows + j;
}

void *matrix_set(matrix *m, size_t i, size_t j, double value) {
    *(m->data + i * m->rows + j) = value;
}
