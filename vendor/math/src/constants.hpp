#pragma once
#include "common.hpp"

namespace Math {
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
}