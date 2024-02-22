#pragma once
#include "matrixstruct.hpp"

namespace Math {
    // Generic
    template<typename T, address N>
    using Vector = Matrix<T, N, 1>;
    template<typename T>
    using Vec2 = Vector<T, 2>;
    template<typename T>
    using Vec3 = Vector<T, 3>;
    template<typename T>
    using Vec4 = Vector<T, 4>;
    // Float
    using Vec2f = Vec2<float>;
    using Vec3f = Vec3<float>;
    using Vec4f = Vec4<float>;
    // Double
    using Vec2d = Vec2<double>;
    using Vec3d = Vec3<double>;
    using Vec4d = Vec4<double>;
    // Int
    using Vec2i = Vec2<int32>;
    using Vec3i = Vec3<int32>;
    using Vec4i = Vec4<int32>;
    // Uint
    using Vec2u = Vec2<uint32>;
    using Vec3u = Vec3<uint32>;
    using Vec4u = Vec4<uint32>;
}