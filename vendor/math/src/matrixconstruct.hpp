#pragma once
#include "arithmetic.hpp"
#include "matrixstruct.hpp"

namespace Math {
    // Identity
    template<typename T, address N>
    Matrix<T, N, N> identity() {
        Matrix<T, N, N> out;
        for (address n = 0; n < N; ++n) {
            out.at(n, n) = (T)1;
        }
        return out;
    }
    // Transpose
    template<typename T, address N, address M>
    Matrix<T, M, N> transposed(const Matrix<T, N, M>& mat) {
        Matrix<T, M, N> out;
        for (address n = 0; n < N; ++n) {
            for (address m = 0; m < N; ++m) {
                out.at(N * m + n) = mat.at(M * n + m);
            }
        }
        return out;
    }
    template<typename T, address N>
    Matrix<T, N>& transpose(Matrix<T, N>& mat) {
        mat = transposed(mat);
        return mat;
    }
    // Resize
    template<typename T, address N1, address M1, address N2, address M2>
    Matrix<T, N1, M1>& insert(Matrix<T, N1, M1>& dest, const Matrix<T, N2, M2>& src, const Matrix<address, 2, 1>& where) {
        for (address n = 0; n < min(N1 - where.x, N2); ++n) {
            for (address m = 0; m < min(M1 - where.y, M2); ++m) {
                dest.at(where.x + n, where.y + m) = src.at(n, m);
            }
        }
        return dest;
    }
    template<typename T, address N1, address M1, address N2, address M2>
    Matrix<T, N1, M1>& insert(Matrix<T, N1, M1>& dest, const Matrix<T, N2, M2>& src) {
        return insert(dest, src, Matrix<address, 2, 1>(0, 0));
    }
    // Resize
    template<typename T, address N1, address M1, address N2, address M2>
    Matrix<T, N1, M1> resize(const Matrix<T, N2, M2>& mat, const Matrix<address, 2, 1>& where) {
        Matrix<T, N1, M1> out;
        insert(out, mat, where);
        return out;
    }
    template<typename T, address N1, address M1, address N2, address M2>
    Matrix<T, N1, M1> resize(const Matrix<T, N2, M2>& mat) {
        return resize<T, N1, M1>(mat, Matrix<address, 2, 1>());
    }
}