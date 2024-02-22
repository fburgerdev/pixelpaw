#include "tostring.hpp"
#include "matrixconstruct.hpp"
#include "matrixarithmetic.hpp"
#include "matrixalias.hpp"
#include "vectoralias.hpp"
#include "matrixfunc.hpp"
#include "vectorfunc.hpp"

using namespace Math;
int main() {
    Mat4f mat({ 
        1, 2, 0, 0,
        0, 1, 3, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    });
    std::cout << transposed(mat) * mat<< std::endl;
    Vec4f vec(1, 2, 3, 4);
    std::cout << dot(vec) << std::endl;
    return EXIT_SUCCESS;
}