#pragma once
#include "common.hpp"

namespace Math {
    // Abs
    int8 abs(int8 x);
    int16 abs(int16 x);
    int32 abs(int32 x);
    int64 abs(int64 x);
    float abs(float x);
    double abs(double x);
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
}