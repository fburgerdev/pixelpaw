#pragma once
#include "matrixstruct.hpp"

namespace Math {
    // -
    template<typename T, address N, address M>
    Matrix<T, N, M> operator-(const Matrix<T, N, M>& mat) {
        Matrix<T, N, M> out;
        for (address i = 0; i < N * M; ++i) {
            out.at(i) = -mat.at(i);
        }
        return out;
    }
    // +=
    template<typename T, address N, address M>
    Matrix<T, N, M>& operator+=(Matrix<T, N, M>& mat, const Matrix<T, N, M>& other) {
        for (address i = 0; i < N * M; ++i) {
            mat.at(i) += other.at(i);
        }
        return mat;
    }
    // -=
    template<typename T, address N, address M>
    Matrix<T, N, M>& operator-=(Matrix<T, N, M>& mat, const Matrix<T, N, M>& other) {
        for (address i = 0; i < N * M; ++i) {
            mat.at(i) -= other.at(i);
        }
        return mat;
    }
    // *= (Scalar)
    template<typename T, address N, address M>
    Matrix<T, N, M>& operator*=(Matrix<T, N, M>& mat, T scalar) {
        for (address i = 0; i < N * M; ++i) {
            mat.at(i) *= scalar;
        }
        return mat;
    }
    // /= (Scalar)
    template<typename T, address N, address M>
    Matrix<T, N, M>& operator/=(Matrix<T, N, M>& mat, T scalar) {
        for (address i = 0; i < N * M; ++i) {
            mat.at(i) /= scalar;
        }
        return mat;
    }
    // +
    template<typename T, address N, address M>
    Matrix<T, N, M> operator+(const Matrix<T, N, M>& mat, const Matrix<T, N, M>& other) {
        Matrix<T, N, M> out(mat);
        out += other;
        return out;
    }
    // -
    template<typename T, address N, address M>
    Matrix<T, N, M> operator-(const Matrix<T, N, M>& mat, const Matrix<T, N, M>& other) {
        Matrix<T, N, M> out(mat);
        out -= other;
        return out;
    }
    // * (Scalar)
    template<typename T, address N, address M>
    Matrix<T, N, M> operator*(const Matrix<T, N, M>& mat, T scalar) {
        Matrix<T, N, M> out(mat);
        out *= scalar;
        return out;
    }
    // / (Scalar)
    template<typename T, address N, address M>
    Matrix<T, N, M> operator/(const Matrix<T, N, M>& mat, T scalar) {
        Matrix<T, N, M> out(mat);
        out /= scalar;
        return out;
    }
    // * 
    template<typename T, address N, address M, address L>
    Matrix<T, N, L> operator*(const Matrix<T, N, M>& mat1, const Matrix<T, M, L>& mat2) {
        Matrix<T, N, L> out;
        for (address n = 0; n < N; ++n) {
            for (address l = 0; l < L; ++l) {
                for (address m = 0; m < M; ++m) {
                    out.at(n, l) += mat1.at(n, m) * mat2.at(m, l);
                }
            }
        }
        return out;
    }
    // *=
    template<typename T, address N>
    Matrix<T, N>& operator*=(Matrix<T, N>& mat1, const Matrix<T, N>& mat2) {
        mat1 = mat1 * mat2;
        return mat1;
    }
}