#pragma once
#include "event.hpp"
#include "glfwkeylayout.hpp"
#include "math/include/math.hpp"

namespace PixelPaw {
    // Key-Layout
    enum class KeyboardLayout {
        US, GER
    };
    void setKeyboardLayout(KeyboardLayout layout);
    // Window
    class Window_GLFW {
    public:
        // Constructor / Assignment / Destructor
        Window_GLFW(const string& title, uint32 width, uint32 height);
        Window_GLFW(const Window_GLFW&) = delete;
        Window_GLFW(Window_GLFW&& other) = default;
        Window_GLFW& operator=(const Window_GLFW&) = delete;
        Window_GLFW& operator=(Window_GLFW&& other) = default;
        ~Window_GLFW();
        // Title
        const string& getTitle() const;
        void setTitle(const string& title);
        // IsOpen / Close
        bool isOpen() const;
        void close();
        // Size
        Math::Vec2u getSize() const;
        void setSize(Math::Vec2u size);
        // Focus
        bool hasFocus() const;
        void focus();
        // Minimize / Maximize
        bool isMinimized() const;
        void minimize();
        bool isMaximized() const;
        void maximize();
        // Cursor
        // Cursor :: Pos
        Math::Vec2i getCursorPos() const;
        void setCursorPos(const Math::Vec2i& pos);
        // Cursor :: Shape
        CursorShape getCursorShape() const;
        void setCursorShape(CursorShape shape);
        // Cursor :: Mode
        CursorMode getCursorMode();
        void setCursorMode(CursorMode mode);
        // Callback
        // Callback :: Mouseclick
        void addMouseclickCallback(std::function<void(MouseButton, MouseState)> callback);
        // Callback :: Mousemove
        void addMousemoveCallback(std::function<void(Math::Vec2i)> callback);
        // Callback :: Keypress
        void addKeypressCallback(std::function<void(KeyCode_GLFW, KeyState)> callback);
        // Callback :: Resize
        void addResizeCallback(std::function<void(Math::Vec2u)> callback);
        // Callback :: Focus
        void addFocusCallback(std::function<void(bool)> callback);
        // Callback :: Minimize
        void addMinimizeCallback(std::function<void(bool)> callback);
        // Callback :: Maximize
        void addMaximizeCallback(std::function<void(bool)> callback);
        // Callback :: CloseRequest
        void addCloseRequestCallback(std::function<void()> callback);
        // Bind
        void bind(std::function<void()> onbind = []() {});
        // Update
        void pollEvents();
        void swap();
    private:
        // Member
        string m_Title;
        CursorShape m_CursorShape = CursorShape::Arrow;
        bool m_IsOpen = true;
        bool m_HasFocus = true;
        bool m_IsMinimized = false;
        bool m_IsMaximized = false;
        void* m_Handle;
    };
}