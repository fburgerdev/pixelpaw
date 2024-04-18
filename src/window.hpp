#pragma once
#if defined(WINDOWAPI_GLFW) or true
#include "glfwwindow.hpp"
#include "glfwkeylayout.hpp"
namespace Wndw {
    using Window = Window_GLFW;
}
#elif
#error "No WindowAPI specified! Options: 'WINDOWAPI_GLFW'"
#endif