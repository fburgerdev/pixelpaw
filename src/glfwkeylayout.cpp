#include "glfwkeylayout.hpp"

namespace Wndw {
    // US-Layout
    KeyCode_GLFW toUSLayout(KeyCode_GLFW code) {
        return code;
    }
    // German-Layout
    KeyCode_GLFW toGermanLayout(KeyCode_GLFW code) {
        switch (code) {
            case KeyCode_GLFW::Y: return KeyCode_GLFW::Z;
            case KeyCode_GLFW::Z: return KeyCode_GLFW::Y;
            case KeyCode_GLFW::MINUS: return KeyCode_GLFW::GER_ESZETT;
            case KeyCode_GLFW::EQUAL: return KeyCode_GLFW::APOSTROPHE;
            case KeyCode_GLFW::LEFT_BRACKET: return KeyCode_GLFW::GER_UMLAUT_U;
            case KeyCode_GLFW::BACKSLASH: return KeyCode_GLFW::HASH;
            case KeyCode_GLFW::RIGHT_BRACKET: return KeyCode_GLFW::PLUS;
            case KeyCode_GLFW::SEMICOLON: return KeyCode_GLFW::GER_UMLAUT_O;
            case KeyCode_GLFW::APOSTROPHE: return KeyCode_GLFW::GER_UMLAUT_A;
            case KeyCode_GLFW::SLASH: return KeyCode_GLFW::MINUS;
            case KeyCode_GLFW::RIGHT_ALT: return KeyCode_GLFW::GER_ALT_GR;
            default: return code;
        }
    }
}