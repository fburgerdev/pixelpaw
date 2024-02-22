#pragma once
#include "matrixstruct.hpp"

namespace Math {
    // Generic
    template<typename T>
    using Mat2 = Matrix<T, 2>;
    template<typename T>
    using Mat3 = Matrix<T, 3>;
    template<typename T>
    using Mat4 = Matrix<T, 4>;
    template<typename T>
    using Mat2x3 = Matrix<T, 2, 3>;
    template<typename T>
    using Mat2x4 = Matrix<T, 2, 4>;
    template<typename T>
    using Mat3x2 = Matrix<T, 3, 2>;
    template<typename T>
    using Mat3x4 = Matrix<T, 3, 4>;
    template<typename T>
    using Mat4x2 = Matrix<T, 4, 2>;
    template<typename T>
    using Mat4x3 = Matrix<T, 4, 3>;
    // Float
    using Mat2f = Mat2<float>;
    using Mat3f = Mat3<float>;
    using Mat4f = Mat4<float>;
    using Mat2x3f = Mat2x3<float>;
    using Mat2x4f = Mat2x4<float>;
    using Mat3x2f = Mat3x2<float>;
    using Mat3x4f = Mat3x4<float>;
    using Mat4x2f = Mat4x2<float>;
    using Mat4x3f = Mat4x3<float>;
    // Double
    using Mat2d = Mat2<double>;
    using Mat3d = Mat3<double>;
    using Mat4d = Mat4<double>;
    using Mat2x3d = Mat2x3<double>;
    using Mat2x4d = Mat2x4<double>;
    using Mat3x2d = Mat3x2<double>;
    using Mat3x4d = Mat3x4<double>;
    using Mat4x2d = Mat4x2<double>;
    using Mat4x3d = Mat4x3<double>;
    // Int
    using Mat2i = Mat2<int>;
    using Mat3i = Mat3<int>;
    using Mat4i = Mat4<int>;
    using Mat2x3i = Mat2x3<int>;
    using Mat2x4i = Mat2x4<int>;
    using Mat3x2i = Mat3x2<int>;
    using Mat3x4i = Mat3x4<int>;
    using Mat4x2i = Mat4x2<int>;
    using Mat4x3i = Mat4x3<int>;
    // Uint
    using Mat2u = Mat2<uint>;
    using Mat3u = Mat3<uint>;
    using Mat4u = Mat4<uint>;
    using Mat2x3u = Mat2x3<uint>;
    using Mat2x4u = Mat2x4<uint>;
    using Mat3x2u = Mat3x2<uint>;
    using Mat3x4u = Mat3x4<uint>;
    using Mat4x2u = Mat4x2<uint>;
    using Mat4x3u = Mat4x3<uint>;
}