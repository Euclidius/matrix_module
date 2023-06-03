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

    mat->rows = h;
    mat->cols = w;
    mat->data = m;

    return mat;
}

void matrix_free(matrix *m) {
    free(m->data);
    free(m);
}

inline size_t matrix_get_rows(matrix *m) {
    return m->rows;
}

inline size_t matrix_cget_rows(const matrix *m) {
    return m->rows;
}

inline size_t matrix_get_cols(matrix *m) {
    return m->cols;
}

inline size_t matrix_cget_cols(const matrix *m) {
    return m->cols;
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
    m->data = realloc(m->data, h * w * sizeof(double));
    if (m == NULL) {
        return NULL;
    }
    else {
        m->rows = h;
        m->cols = w;
        return m;
    }
}

inline double *matrix_get(matrix *m, size_t i, size_t j) {
    return m->data + i * m->cols + j;
}

inline const double *matrix_cget(const matrix *m, size_t i, size_t j) {
    return m->data + i * m->cols + j;
}

void *matrix_sset(matrix *m, size_t i, size_t j, double value) {
    if (matrix_get_rows(m) <= i || matrix_get_cols(m) <= j) {
        return NULL;
    }
    *(m->data + i * m->cols + j) = value;
}

matrix *matrix_set_zero(matrix *m) {
    for (int i = 0; i < matrix_get_rows(m); ++i) {
        for (int j = 0; j < matrix_get_cols(m); ++j) {
            matrix_sset(m, i, j, 0);
        }
    }
    return m;
}

matrix *matrix_alloc_zero(size_t h, size_t w) {
    matrix *m = matrix_alloc(h, w);
    if (m == NULL) {
        return NULL;
    }
    return matrix_set_zero(m);
}

matrix *matrix_set_sqr_one(matrix *m) {
    if (matrix_get_rows(m) != matrix_get_cols(m)) {
        return NULL;
    }
    for (int i = 0; i < matrix_get_rows(m); ++i) {
        for (int j = 0; j < matrix_get_cols(m); ++j) {
            if (i == j) {
                matrix_sset(m, i, j, 1);
            } else {
                matrix_sset(m, i, j, 0);
            }
        }
    }
    return m;
}

matrix *matrix_alloc_sqr_one(size_t h) {
    matrix *m = matrix_alloc(h, h);
    if (m == NULL) {
        return NULL;
    }
    return matrix_set_sqr_one(m);
}

matrix *matrix_assign(matrix *m1, const matrix *m2) {
    if (matrix_get_rows(m1) != matrix_cget_rows(m2) || matrix_get_cols(m1) != matrix_cget_cols(m2)) {
        return NULL;
    }
    for (int i = 0; i < matrix_cget_rows(m1); ++i) {
        for (int j = 0; j < matrix_cget_cols(m1); ++j) {
            matrix_sset(m1, i, j, *matrix_cget(m2, i, j));
        }
    }
    return m1;
}

void matrix_print(const matrix *m) {
    for (int i = 0; i < matrix_cget_rows(m); ++i) {
        for (int j = 0; j < matrix_cget_cols(m); ++j) {
            printf("%lf ", *matrix_cget(m, i, j));
        }
        printf("\n");
    }
}


}