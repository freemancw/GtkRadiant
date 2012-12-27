/*!
 *  @file Matrix.h
 *  @author Clinton Freeman
 *  @date 12/26/2012
 */

#ifndef MATRIX_H
#define MATRIX_H

#include <assert.h>
#include <math.h>

namespace RAD
{

//============================================================================
// Interfaces
//============================================================================

template<typename T, const size_t NROWS, const size_t NCOLS>
class Matrix
{
public:
    Matrix();
    explicit Matrix(const Matrix<T, NROWS, NCOLS>& values);

    template<const size_t _NCOLS>
    Matrix<T, NROWS, _NCOLS> operator*(const Matrix<T, NCOLS, _NCOLS>& rhs) 
        const;

protected:
    T elts[NROWS][NCOLS];
};

//============================================================================
// Inline Implementations
//============================================================================

template<typename T, const size_t NROWS, const size_t NCOLS>
inline Matrix<T, NROWS, NCOLS>::Matrix() 
{
    for(size_t i = 0; i < NROWS; ++i)
        for(size_t j = 0; j < NCOLS; ++j)
            elts[i][j] = 0.0;
}

} // namespace RAD

#endif // MATRIX_H