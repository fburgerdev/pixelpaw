#pragma once
// #include "common.hpp"
#include <memory> // address, int, uint
#include <string> // string
#include <string_view> // string_view
#include <vector> // List
#include <stack> // Stack
#include <queue> // Queue
#include <unordered_set> // Set 
#include <set> // OrderedSet
#include <unordered_map> // Map
#include <map> // OrderedMap

namespace Math {
    // Types
    // Types :: address
    using address = std::size_t;
    // Types :: int
    using int8 = std::int8_t;
    using int16 = std::int16_t;
    using int32 = std::int32_t;
    using int64 = std::int64_t;
    // Types :: uint
    using uint8 = std::uint8_t;
    using uint16 = std::uint16_t;
    using uint32 = std::uint32_t;
    using uint64 = std::uint64_t;
    // Types :: string
    using string = std::string;
    // Types :: string_view
    using string_view = std::string_view;
    // Structures
    template<typename T>
    using List = std::vector<T>;
    template<typename T>
    using Stack = std::stack<T>;
    template<typename T>
    using Queue = std::queue<T>;
    template<typename T>
    using Set = std::unordered_set<T>;
    template<typename T>
    using OrderedSet = std::set<T>;
    template<typename Key, typename Value>
    using Map = std::unordered_map<Key, Value>;
    template<typename Key, typename Value>
    using OrderedMap = std::map<Key, Value>;
// #include "constants.hpp"
    // Pi
    inline constexpr float PI = 3.1415926f;
    inline constexpr float PI_HALFS = PI / 2;
    inline constexpr float TAU = 2 * PI;
    // Deg
    inline constexpr float DEG_0 = 0;
    inline constexpr float DEG_90 = PI / 2;
    inline constexpr float DEG_180 = PI / 2;
    inline constexpr float DEG_270 = 5 * PI / 4;
    inline constexpr float DEG_360 = 2 * PI;
    // Euler
    inline constexpr float EULER = 2.7182818f;
    inline constexpr float EULER_HALFS = EULER / 2;
    // Golden-Ratio
    inline constexpr float GOLDEN_RATIO = 1.618033f;
// #include "arithmetic.hpp"
    // Abs
    int8 abs(int8 x);
    int16 abs(int16 x);
    int32 abs(int32 x);
    int64 abs(int64 x);
    float abs(float x);
    double abs(double x);
    // Floor / Ceil
    float floor(float x);
    double floor(double x);
    float ceil(float x);
    double ceil(double x);
    // Sqrt
    float sqrt(float x);
    double sqrt(double x);
    // Sin / Cos / Tan
    float sin(float x);
    double sin(double x);
    float cos(float x);
    double cos(double x);
    float tan(float x);
    double tan(double x);
    float asin(float x);
    double asin(double x);
    float acos(float x);
    double acos(double x);
    float atan(float x);
    double atan(double x);
    // Exp / Log
    float exp(float x);
    double exp(double x);
    float ln(float x);
    double ln(double x);
    float log2(float x);
    double log2(double x);
    float log10(float x);
    double log10(double x);
    float pow(float base, float exponent);
    double pow(double base, double exponent);
    float pow2(float x);
    double pow2(double x);
    float pow3(float x);
    double pow3(double x);
    // Max / Min
    template<typename T1, typename T2, typename... Rest>
    auto max(T1 val1, T2 val2, Rest... rest) {
        if constexpr(sizeof...(Rest) == 0) {
            return val1 < val2 ? val2 : val1;
        }
        else {
            return max(val1 < val2 ? val2 : val1, rest...);
        }
    }
    template<typename T1, typename T2, typename... Rest>
    auto min(T1 val1, T2 val2, Rest... rest) {
        if constexpr(sizeof...(Rest) == 0) {
            return val2 < val1 ? val2 : val1;
        }
        else {
            return max(val2 < val1 ? val2 : val1, rest...);
        }
    }
// #include "matrixstruct.hpp"
    // Matrix N x M
    template<typename T, address N, address M = N>
    class Matrix {
    public:
        // Constructor
        Matrix() {
            for (address i = 0; i < N * M; ++i) {
                m_Data[i] = (T)0;
            } 
        }
        Matrix(T (&values)[N * M]) {
            for (address i = 0; i < N * M; ++i) {
                m_Data[i] = values[i];
            }
        }
        Matrix(T (&&values)[N * M]) {
            for (address i = 0; i < N * M; ++i) {
                m_Data[i] = values[i];
            }
        }
        Matrix(T (&values)[N][M]) {
            for (address n = 0; n < N; ++n) {
                for (address m = 0; m < M; ++m) {
                    m_Data[M * n + m] = values[n][m];
                }
            }
        }
        Matrix(T (&&values)[N][M]) {
            for (address n = 0; n < N; ++n) {
                for (address m = 0; m < M; ++m) {
                    m_Data[M * n + m] = values[n][m];
                }
            }
        }
        // Cast
        template<typename TOther>
        Matrix(const Matrix<TOther, N, M>& mat) {
            for (address i = 0; i < N * M; ++i) {
                m_Data[i] = (T)mat.at(i);
            }
        }
        // Access
        // :: at
        T& at(address index) {
            return m_Data[index];
        }
        const T& at(address index) const {
            return m_Data[index];
        }
        T& at(address n, address m) {
            return m_Data[M * n + m];
        }
        const T& at(address n, address m) const {
            return m_Data[M * n + m];
        }
        // :: data
        T* data() {
            return m_Data;
        }
        const T* data() const {
            return m_Data;
        }
    private:
        // Member
        T m_Data[N * M];
    };
    // Matrix 2 x 1
    template<typename T>
    class Matrix<T, 2, 1> {
    public:
        // Constructor
        Matrix()
            : Matrix((T)0) {}
        Matrix(T value)
            : Matrix(value, value) {}
        Matrix(T x, T y)
            : x(x), y(y) {}
        // Cast
        template<typename TOther, address N>
        Matrix(const Matrix<TOther, 2, 1>& vec)
            : Matrix((T)vec.at(0), (T)vec.at(1)) {}
        // Access
        T& at(address index) {
            return index == 0 ? x : y;
        }
        const T& at(address index) const {
            return index == 0 ? x : y;
        }
        T& at(address n, address m) {
            return at(n);
        }
        const T& at(address n, address m) const {
            return at(n);
        }
        // Member
        T x, y;
    };
    // Matrix 3 x 1
    template<typename T>
    class Matrix<T, 3, 1> {
    public:
        // Constructor
        Matrix()
            : Matrix((T)0) {}
        Matrix(T value)
            : Matrix(value, value, value) {}
        Matrix(T x, T y, T z)
            : x(x), y(y), z(z) {}
        Matrix(const Matrix<T, 2, 1>& xy, T z)
            : Matrix(xy.x, xy.y, z) {}
        Matrix(T x, const Matrix<T, 2, 1>& yz)
            : Matrix(x, yz.x, yz.y) {}
        // Cast
        template<typename TOther>
        Matrix(const Matrix<TOther, 2, 1>& vec)
            : Matrix((T)vec.at(0), (T)vec.at(1), (T)0) {}
        template<typename TOther>
        Matrix(const Matrix<TOther, 3, 1>& vec)
            : Matrix((T)vec.at(0), (T)vec.at(1), (T)vec.at(2)) {}
        // Access
        T& at(address index) {
            return index == 0 ? x : (index == 1 ? y : z);
        }
        const T& at(address index) const {
            return index == 0 ? x : (index == 1 ? y : z);
        }
        T& at(address n, address m) {
            return at(n);
        }
        const T& at(address n, address m) const {
            return at(n);
        }
        // Member
        T x, y, z;
    };
    // Matrix 4 x 1
    template<typename T>
    class Matrix<T, 4, 1> {
    public:
        // Constructor
        Matrix()
            : Matrix((T)0) {}
        Matrix(T value)
            : Matrix(value, value, value, value) {}
        Matrix(T x, T y, T z, T w)
            : x(x), y(y), z(z), w(w) {}
        Matrix(const Matrix<T, 2, 1>& xy, T z, T w)
            : Matrix(xy.x, xy.y, z, w) {}
        Matrix(T x, const Matrix<T, 2, 1>& yz, T w)
            : Matrix(x, yz.x, yz.y, w) {}
        Matrix(T x, T y, const Matrix<T, 2, 1>& zw)
            : Matrix(x, y, zw.x, zw.y) {}
        Matrix(const Matrix<T, 2, 1>& xy, const Matrix<T, 2, 1>& yz)
            : Matrix(xy.x, xy.y, yz.x, yz.y) {}
        Matrix(const Matrix<T, 3, 1>& xyz, T w)
            : Matrix(xyz.x, xyz.y, xyz.z, w) {}
        Matrix(T x, const Matrix<T, 3, 1>& yzw)
            : Matrix(x, yzw.x, yzw.y, yzw.z) {}
        // Cast
        template<typename TOther>
        Matrix(const Matrix<TOther, 2, 1>& vec)
            : Matrix((T)vec.at(0), (T)vec.at(1), (T)0, (T)0) {}
        template<typename TOther, address N>
        Matrix(const Matrix<TOther, 3, 1>& vec)
            : Matrix((T)vec.at(0), (T)vec.at(1), (T)vec.at(2), (T)0) {}
        template<typename TOther, address N>
        Matrix(const Matrix<TOther, 4, 1>& vec)
            : Matrix((T)vec.at(0), (T)vec.at(1), (T)vec.at(2), (T)vec.at(3)) {}
        // Access
        T& at(address index) {
            return index == 0 ? x : (index == 1 ? y : (index == 2 ? z : w));
        }
        const T& at(address index) const {
            return index == 0 ? x : (index == 1 ? y : (index == 2 ? z : w));
        }
        T& at(address n, address m) {
            return at(n);
        }
        const T& at(address n, address m) const {
            return at(n);
        }
        // Member
        T x, y, z, w;
    };
// #include "matrixalias.hpp"
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
// #include "matrixarithmetic.hpp"
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
// #include "matrixconstruct.hpp"
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
// #include "matrixfunc.hpp"
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
// #include "vectoralias.hpp"
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
// #include "vectorfunc.hpp"
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