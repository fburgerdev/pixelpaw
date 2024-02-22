#include "window.hpp"
#include <iostream>

using namespace PixelPaw;
int main() {
    // Window
    Window window("Untitled Window", 1080, 720);
    // Callback
    // Callback :: Mouseclick
    window.addMouseclickCallback([&](MouseButton button, MouseState state) {
        std::cout << "MousePress: " << (int)button << " " << (int)state << std::endl;
    });
    // Callback :: MouseMove
    window.addMousemoveCallback([&](Math::Vec2i pos) {
        std::cout << "MouseMove: " << pos.x << ", " << pos.y << std::endl;
    });
    // Callback :: Keypress
    window.addKeypressCallback([&](KeyCode code, KeyState state) {
        std::cout << "Keypress: " << (int)code << " " << (int)state << std::endl;
    });
    // Callback :: CloseRequest
    window.addCloseRequestCallback([&]() {
        std::cout << "Closing Window..." << std::endl;
        window.close();
    });
    // Loop
    while (window.isOpen()) {
        // Events
        window.pollEvents();
    }
    return EXIT_SUCCESS;
}