#pragma once

namespace PixelPaw {
    // KeyCode
    #include "glfwkeycodes.hpp"
    // US-Layout
    KeyCode_GLFW toUSLayout(KeyCode_GLFW code);
    // German-Layout
    KeyCode_GLFW toGermanLayout(KeyCode_GLFW code);
}