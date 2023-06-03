//
// Created by evarist on 05.03.23.
//

#ifndef INC_23_MATRIX_MOD_H
#define INC_23_MATRIX_MOD_H

#include "matrix.h"

/**
 * @brief multiplies a row of a matrix by the given value
 * @param m - pointer to the initialized matrix
 * @param i - number of a string which would be multiplied
 * @param scal - a value, which row will be multiplied
 */
void matrix_mod_mult_row_scal(matrix *m, size_t i, double scal);

/**
 * @brief replaces two rows of the matrix
 * @param m - pointer to the initialized matrix
 * @param i - first string
 * @param j - second string
 */
void matrix_mod_perm_rows(matrix *m, size_t i, size_t j);

/**
 * @breif sums two strings of a matrix
 * @param m - pointer to the initialized matrix
 * @param from - number of string WHICH WOULD BE ADDED TO
 * @param to - number of string TO BE ADDED
 */
void matrix_mod_sum_rows(matrix *m, size_t from, size_t to, double p);

/**
 * @breif selects a submatrix of a given matrix
 * @param m - pointer to the initialized matrix
 * @param i - number of rows in the submatrix
 * @param j - number of cols in the submatrix
 * @return pointer to the new submatrix or
 *         NULL if getting was failed
 */
matrix* matrix_mod_get_submatrix(matrix *m, size_t i, size_t j);

/**
 * @brief multiples the matrix on the scalar
 * @param m - matrix
 * @param scal - scalar
 */
void matrix_mod_mult_scal(matrix *m, double scal);

/**
 * @breif operation of matrix adding
 * @param m1 - matrix 1
 * @param m2 - matrix 2
 * @return m1 + m2 if adding was successful or
 *         NULL if adding was failed
 */
matrix *matrix_mod_add(matrix *m1, const matrix *m2);

/**
 * @brief operation of matrix multiplication
 * @param m1 - matrix 1
 * @param m2 - matrix 2
 * @return m1*m2 if multiplying was successful or
 *         NULL if multiplying was failed
 */
matrix *matrix_mod_mult(matrix *m1, const matrix *m2);

/**
 * @brief operation of matrix multiplication
 * @param m - matrix
 * @param m1 - matrix
 * @param m2 - matrix
 * @return m = m1 * m2 or
 *         NULL if multiplying was failed
 */
matrix *matrix_mod_mult_t(matrix *m, const matrix *m1, const matrix *m2);

/**
 * @brief transposes the square matrix
 * @param m1 - square matrix
 * @return Tm1 if transposing was successful or
 *         NULL if transposing was failed
 */
matrix *matrix_mod_transp_sq(matrix *m1);

/**
 * @brief calculates the determinant of square matrix
 * @param m1 - square matrix
 * @return determinant of m1
 */
double matrix_mod_det(const matrix *m1);

/**
 * @param m - matrix
 * @param res - matrix
 * @return res = m^-1
 */
matrix *matrix_mod_reverse(matrix *m, matrix *res);


#endif //INC_23_MATRIX_MOD_H
