#pragma once
#include "common.hpp"
#if defined(WINDOWAPI_GLFW)
#include "glfwkeylayout.hpp"
#endif

namespace PixelPaw {
    // Mouse
    // Mouse :: Button
    enum class MouseButton {
        Left, Middle, Right
    };
    // Mouse :: State
    enum class MouseState {
        Press, Release
    };
    // Cursor
    // Cursor :: Shape
    enum class CursorShape {
        Arrow, Hand, IBeam 
    };
    // Cursor :: Mode
    enum class CursorMode {
        Normal, Hidden, Disabled 
    };
    // Key
    // Key :: State
    enum class KeyState {
        Press, Release, Repeat
    };
    // Key :: Code
    #if defined(WINDOWAPI_GLFW)
    using KeyCode = KeyCode_GLFW;
    #endif
}