#pragma once
#if defined(WINDOWAPI_GLFW)
#include "glfwwindow.hpp"
#include "glfwkeylayout.hpp"
namespace PixelPaw {
    using Window = Window_GLFW;
}
#elif
#error "No WindowAPI specified! Options: 'WINDOWAPI_GLFW'"
#endif