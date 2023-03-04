//
// Created by evarist on 04.03.23.
//

#ifndef INC_23_MATRIX_H
#define INC_23_MATRIX_H

#include <stddef.h>

/**
 * @brief main structure
 */
typedef struct matrix matrix;

/**
 * @brief allocates the memory for matrix
 * @param h - rows in matrix
 * @param w - columns in matrix
 * @return pointer to the allocated matrix
 */
matrix *matrix_alloc(size_t h, size_t w);

/**
 * @brief returns the allocated memory
 * @param m - pointer to the initialized matrix
 */
void matrix_free(matrix* m);

/**
 * @brief copies the matrix
 * @param m pointer to matrix, which we want to copy
 * @return pointer to the new matrix or
 *         NULL if cloning was failed
 */
matrix *matrix_clone(const matrix *m);

/**
 * @brief changes the size of given matrix
 * @param m - pointer to the initialized matrix
 * @param h - rows in new matrix
 * @param w - columns in new matrix
 * @return pointer to the new matrix or
 *         NULL if reallocation was failed
 */
matrix *matrix_resize(matrix *m, size_t h, size_t w);

/**
 * @brief gets the element of matrix
 * @param m - pointer to the initialised matrix
 * @param i - row of the element
 * @param j - column of the element
 * @return m[i,j]
 */
double *matrix_get(matrix *m, size_t i, size_t j);

/**
 * @brief gets the element of const matrix
 * @param m - pointer to the initialised const matrix
 * @param i - row of the element
 * @param j - column of the element
 * @return m[i,j]
 */
const double *matrix_cget(const matrix *m, size_t i, size_t j);

/**
 * @brief sets the element of matrix
 * @param m - pointer to the initialised matrix
 * @param i - row of the element
 * @param j - column of the element
 * @param value - an inserting value to matrix
 */
void *matrix_set(matrix *m, size_t i, size_t j, double value);

#endif //INC_23_MATRIX_H
