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
 * @brief returns a rows of a matrix
 * @param m - pointer to an initialized matrix
 * @return number of a rows
 */
size_t matrix_get_rows(matrix *m);

/**
 * @brief returns a rows of a const matrix
 * @param m - pointer to an initialized const matrix
 * @return number of a rows
 */
size_t matrix_cget_rows(const matrix *m);

/**
 * @brief returns a cols of a matrix
 * @param m - pointer to an initialized matrix
 * @return number of a cols
 */
size_t matrix_get_cols(matrix *m);

/**
 * @brief returns a cols of a const matrix
 * @param m - pointer to an initialized const matrix
 * @return number of a cols
 */
size_t matrix_cget_cols(const matrix *m);

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
 * @brief safely sets the element of matrix
 * @param m - pointer to the initialised matrix
 * @param i - row of the element
 * @param j - column of the element
 * @param value - an inserting value to matrix or
 *        NULL if inserting is impossible
 */
void *matrix_sset(matrix *m, size_t i, size_t j, double value);

/**
 * @brief fills the matrix with zeros
 * @param m - pointer to initialized matrix
 * @return this matrix filled by zeros
 */
matrix *matrix_set_zero(matrix *m);

/**
 * @brief allocates and fills the matrix with zeros
 * @param h - rows of the matrix
 * @param w - columns of the matrix
 * @return pointer to zero-matrix or
 *         NULL if allocation was failed
 *
 *@note need a matrix_free call
 */
matrix *matrix_alloc_zero(size_t h, size_t w);

/**
 * @brief fills the matrix by zeros with ones on the main diagonal
 * @param m - pointer to initialized matrix
 * @return this matrix filled by zeros with ones on the main diagonal
 *         or NULL if matrix is non-square
 */
matrix *matrix_set_sqr_one(matrix *m);

/**
 * @brief allocates and fills the matrix with zeros with ones on the main diagonal
 * @param h - rows of the matrix
 * @return pointer to zero-matrix with ones on the main diagonal
 *         or NULL if matrix is non-square
 *
 *@note need a matrix_free call
 */
matrix *matrix_alloc_sqr_one(size_t h);

/**
 * @brief assigns m2 to m1
 * @param m1 - pointer to matrix from which assigns
 * @param m2 - pointer to matrix to which assigns
 * @return pointer to m1 or
 *         NULL if assignment is impossible (matrixes have different sizes)
 */
matrix *matrix_assign(matrix *m1, const matrix *m2);

/**
 * @brief prints the matrix by rows
 * @param m - matrix to print
 */
void matrix_print(const matrix *m);



#endif //INC_23_MATRIX_H
