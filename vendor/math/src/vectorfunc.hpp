#pragma once
#include "vectoralias.hpp"

namespace Math {
    // Dot
    template<typename T, address N>
    T dot(const Vector<T, N>& v) {
        return dot(v, v);
    }
    template<typename T, address N>
    T dot(const Vector<T, N>& vec1, const Vector<T, N>& vec2) {
        T out = 0;
        for (address n = 0; n < N; ++n) {
            out += vec1.at(n) * vec2.at(n);
        }
        return out;
    }
    // Cross
    template<typename T>
    Vec3<T> cross(const Vec3<T>& v1, const Vec3<T>& v2) {
        return Vec3<T>(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x);
    }
}