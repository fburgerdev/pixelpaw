#pragma once
#include "arithmetic.hpp"
#include "matrixstruct.hpp"

namespace Math {
    // Length
    template<typename T, address N, address M>
    T length(const Matrix<T, N, M>& mat) {
        T out = 0;
        for (address i = 0; i < N * M; ++i) {
            out += mat.at(i) * mat.at(i);
        }
        return sqrt(out);
    }
    // Dist
    template<typename T, address N, address M>
    T distance(const Matrix<T, N, M>& mat1, const Matrix<T, N, M>& mat2) {
        return length(mat2 - mat1);
    }
    // Normalize
    template<typename T, address N, address M>
    Matrix<T, N, M>& normalize(Matrix<T, N, M>& mat) {
        mat /= length(mat);
        return mat;
    }
    template<typename T, address N, address M>
    Matrix<T, N, M> normalized(const Matrix<T, N, M>& mat) {
        return normalize(Matrix<T, N, M>(mat));
    }
}