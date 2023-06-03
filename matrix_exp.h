//
// Created by evarist on 29.05.23.
//
#ifndef INC_23_MATRIX_EXP_H
#define INC_23_MATRIX_EXP_H

#include "matrix.h"
typedef struct matrix matrix;

/**
 * @brief calculates e^(m1) by Teilor's series
 * @param m - matrix
 * @param res - matrix, res write to
 * @param eps - error
 * @return e^(m1)
 */
matrix *matrix_exp(const matrix *m, matrix *res, double eps);


#endif //INC_23_MATRIX_EXP_H
