#include "arithmetic.hpp"
#include <math.h>

namespace Math {
    // Abs
    int8 abs(int8 x) {
        return x < 0 ? -x : x;
    }
    int16 abs(int16 x) {
        return x < 0 ? -x : x;
    }
    int32 abs(int32 x) {
        return x < 0 ? -x : x;
    }
    int64 abs(int64 x) {
        return x < 0 ? -x : x;
    }
    float abs(float x) {
        return x < 0 ? -x : x;
    }
    double abs(double x) {
        return x < 0 ? -x : x;
    }
    // Sqrt
    float sqrt(float x) {
        return std::sqrt(x);
    }
    double sqrt(double x) {
        return std::sqrt(x);
    }
    // Sin / Cos / Tan
    float sin(float x) {
		return std::sin(x);
	}
    double sin(double x) {
		return std::sin(x);
	}
    float cos(float x) {
		return std::cos(x);
	}
    double cos(double x) {
		return std::cos(x);
	}
    float tan(float x) {
		return std::tan(x);
	}
    double tan(double x) {
		return std::tan(x);
	}
    float asin(float x) {
		return std::asin(x);
	}
    double asin(double x) {
		return std::asin(x);
	}
    float acos(float x) {
		return std::acos(x);
	}
    double acos(double x) {
		return std::acos(x);
	}
    float atan(float x) {
		return std::atan(x);
	}
    double atan(double x) {
		return std::atan(x);
	}
    // Exp / Log
    float exp(float x) {
		return std::exp(x);
	}
    double exp(double x) {
		return std::exp(x);
	}
    float ln(float x) {
		return std::log(x);
	}
    double ln(double x) {
		return std::log(x);
	}
    float log2(float x) {
        return std::log2(x);
    }
    double log2(double x) {
        return std::log2(x);
    }
    float log10(float x) {
        return std::log10(x);
    }
    double log10(double x) {
        return std::log10(x);
    }
    float pow(float base, float exponent) {
        return std::pow(base, exponent);
    }
    double pow(double base, double exponent) {
        return std::pow(base, exponent);
    }
    float pow2(float x) {
        return x * x;
    }
    double pow2(double x) {
        return x * x;
    }
    float pow3(float x) {
        return x * x * x;
    }
    double pow3(double x) {
        return x * x * x;
    }
}