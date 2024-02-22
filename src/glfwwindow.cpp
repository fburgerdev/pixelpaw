#include "glfwwindow.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <mutex>

namespace PixelPaw {
    // Mutex
    static std::mutex s_WindowCreation;
    static std::mutex s_WindowContext;
    // GLFWWindow-Table
    static Map<void*, Window_GLFW*> s_HandleMap;
    static Map<void*, List<std::function<void(MouseButton, MouseState)>>> s_MouseclickCallbacks;
    static Map<void*, List<std::function<void(Math::Vec2i)>>> s_MousemoveCallbacks;
    static Map<void*, List<std::function<void(KeyCode_GLFW, KeyState)>>> s_KeypressCallbacks;
    static Map<void*, List<std::function<void(Math::Vec2u)>>> s_ResizeCallbacks;
    static Map<void*, List<std::function<void(bool)>>> s_FocusCallbacks;
    static Map<void*, List<std::function<void(bool)>>> s_MinimizeCallbacks;
    static Map<void*, List<std::function<void(bool)>>> s_MaximizeCallbacks;
    static Map<void*, List<std::function<void()>>> s_CloseRequestCallbacks;
    // Key-Layout
    static KeyboardLayout s_KeyLayout = KeyboardLayout::US;
    void setKeyboardLayout(KeyboardLayout layout) {
        s_KeyLayout = layout;
    }
    // Window
    // Constructor
    Window_GLFW::Window_GLFW(const string& title, uint32 width, uint32 height) 
        : m_Title(title), m_Handle(nullptr) {
        std::scoped_lock creationlock(s_WindowCreation);
        // Init GLFW
        if (!glfwInit()) {
            return;
        }
        // Context
        glfwWindowHint(GLFW_RESIZABLE, 0);
        // Create Handle
        m_Handle = (void*)glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
        if (!m_Handle) {
            glfwTerminate();
            return;
        }
        // Callback
        // Callback :: Mouseclick
        glfwSetMouseButtonCallback((GLFWwindow*)m_Handle, [](GLFWwindow* window, int button, int action, int mods) {
            for (auto& callback : s_MouseclickCallbacks[window]) {
                if (button == GLFW_MOUSE_BUTTON_LEFT) {
                    if (action == GLFW_PRESS) {
                        callback(MouseButton::Left, MouseState::Press);
                    }
                    else if (action == GLFW_RELEASE) {
                        callback(MouseButton::Left, MouseState::Release);
                    }
                }
                else if (button == GLFW_MOUSE_BUTTON_MIDDLE) {
                    if (action == GLFW_PRESS) {
                        callback(MouseButton::Middle, MouseState::Press);
                    }
                    else if (action == GLFW_RELEASE) {
                        callback(MouseButton::Middle, MouseState::Release);
                    }
                }
                else if (button == GLFW_MOUSE_BUTTON_RIGHT) {
                    if (action == GLFW_PRESS) {
                        callback(MouseButton::Middle, MouseState::Press);
                    }
                    else if (action == GLFW_RELEASE) {
                        callback(MouseButton::Middle, MouseState::Release);
                    }
                }
            }
        });
        // Callback :: Mousemove
        glfwSetCursorPosCallback((GLFWwindow*)m_Handle, [](GLFWwindow* window, double x, double y) {
            for (auto& callback : s_MousemoveCallbacks[window]) {
                callback(Math::Vec2i(int32(x), int32(y)));
            }
        });
        // Callback :: Keypress
        glfwSetKeyCallback((GLFWwindow*)m_Handle, [](GLFWwindow *window, int key, int scancode, int action, int mods) {
            KeyCode_GLFW code = (KeyCode_GLFW)key;
            if (s_KeyLayout == KeyboardLayout::US) {
                code = toUSLayout(code);
            }
            else if (s_KeyLayout == KeyboardLayout::GER) {
                code = toGermanLayout(code);
            }
            for (auto& callback : s_KeypressCallbacks[window]) {
                if (action == GLFW_PRESS) {
                    callback(code, KeyState::Press);
                }
                else if (action == GLFW_REPEAT) {
                    callback(code, KeyState::Repeat);
                }
                else if (action == GLFW_RELEASE) {
                    callback(code, KeyState::Release);
                }
            }
        });
        // Callback :: Resize
        glfwSetWindowSizeCallback((GLFWwindow*)m_Handle, [](GLFWwindow* window, int width, int height) {
            for (auto& callback : s_ResizeCallbacks[window]) {
                callback(Math::Vec2u((uint32)width, (uint32)height));
            }
        });
        // Callback :: Focus
        glfwSetWindowFocusCallback((GLFWwindow*)m_Handle, [](GLFWwindow* window, int state) {
            for (auto& callback : s_FocusCallbacks[window]) {
                callback(state == GLFW_TRUE);
            }
        });
        // Callback :: Minimize
        glfwSetWindowIconifyCallback((GLFWwindow*)m_Handle, [](GLFWwindow* window, int state) {
            for (auto& callback : s_MinimizeCallbacks[window]) {
                callback(state == GLFW_TRUE);
            }
        });
        // Callback :: Maximize
        glfwSetWindowMaximizeCallback((GLFWwindow*)m_Handle, [](GLFWwindow* window, int state) {
            for (auto& callback : s_MaximizeCallbacks[window]) {
                callback(state == GLFW_TRUE);
            }
        });
        // Callback :: CloseRequest
        glfwSetWindowCloseCallback((GLFWwindow*)m_Handle, [](GLFWwindow* window) {
            for (auto& callback : s_CloseRequestCallbacks[window]) {
                callback();
            }
        });
        // Bind
        bind([&] () {
            // Framerate
            glfwSwapInterval(1);
            // Init GLEW
            GLenum err = glewInit();
            if (err != GLEW_OK) {
                return;
            }
        });
        // Default Callback
        addFocusCallback([&](bool hasFocus) {
            m_HasFocus = hasFocus;
        });
        addMinimizeCallback([&](bool isMinimized) {
            m_IsMinimized = isMinimized;
        });
        addMaximizeCallback([&](bool isMaximized) {
            m_IsMaximized = isMaximized;
        });
        // HandleMap
        s_HandleMap[m_Handle] = this;
    }
    // Destructor
    Window_GLFW::~Window_GLFW() {
        s_HandleMap.erase(m_Handle);
        s_MouseclickCallbacks.erase(m_Handle);
        s_MousemoveCallbacks.erase(m_Handle);
        s_KeypressCallbacks.erase(m_Handle);
        s_ResizeCallbacks.erase(m_Handle);
        s_FocusCallbacks.erase(m_Handle);
        s_MinimizeCallbacks.erase(m_Handle);
        s_MaximizeCallbacks.erase(m_Handle);
        s_CloseRequestCallbacks.erase(m_Handle);
        glfwDestroyWindow((GLFWwindow*)m_Handle);
        m_Handle = nullptr;
    }
    // Title
    const string& Window_GLFW::getTitle() const {
        return m_Title;
    }
    void Window_GLFW::setTitle(const string& title) {
        m_Title = title;
        glfwSetWindowTitle((GLFWwindow*)m_Handle, title.c_str());
    }
    // IsOpen / Close
    bool Window_GLFW::isOpen() const {
        return m_IsOpen;
    }
    void Window_GLFW::close() {
        m_IsOpen = false;
    }
    // Size
    Math::Vec2u Window_GLFW::getSize() const {
        int width, height;
        glfwGetWindowSize((GLFWwindow*)m_Handle, &width, &height);
        return Math::Vec2u(uint32(width), uint32(height));
    }
    void Window_GLFW::setSize(Math::Vec2u size) {
        glfwSetWindowSize((GLFWwindow*)m_Handle, int(size.x), int(size.y));
    }
    // Focus
    bool Window_GLFW::hasFocus() const {
        return m_HasFocus;
    }
    void Window_GLFW::focus() {
        glfwFocusWindow((GLFWwindow*)m_Handle);
    }
    // Minimize / Maximize
    bool Window_GLFW::isMinimized() const {
        return m_IsMinimized;
    }
    void Window_GLFW::minimize() {
        glfwIconifyWindow((GLFWwindow*)m_Handle);
    }
    bool Window_GLFW::isMaximized() const {
        return m_IsMaximized;
    }
    void Window_GLFW::maximize() {
        glfwMaximizeWindow((GLFWwindow*)m_Handle);
    }
    // Cursor
    // Cursor :: Pos
    Math::Vec2i Window_GLFW::getCursorPos() const {
        double x_pos, y_pos;
        glfwGetCursorPos((GLFWwindow*)m_Handle, &x_pos, &y_pos);
        return Math::Vec2i(Math::floor(x_pos), Math::floor(y_pos));
    }
    void Window_GLFW::setCursorPos(const Math::Vec2i& pos) {
        glfwSetCursorPos((GLFWwindow*)m_Handle, (double)pos.x, (double)pos.y);
    }
    // Cursor :: Shape
    CursorShape Window_GLFW::getCursorShape() const {
        return m_CursorShape;
    }
    void Window_GLFW::setCursorShape(CursorShape shape) {
        m_CursorShape = shape;
        switch (shape) {
            case CursorShape::Arrow: return glfwSetCursor((GLFWwindow*)m_Handle, glfwCreateStandardCursor(GLFW_ARROW_CURSOR));
            case CursorShape::Hand: return glfwSetCursor((GLFWwindow*)m_Handle, glfwCreateStandardCursor(GLFW_HAND_CURSOR));
            case CursorShape::IBeam: return glfwSetCursor((GLFWwindow*)m_Handle, glfwCreateStandardCursor(GLFW_IBEAM_CURSOR));
        }
    }
    // Cursor :: Mode
    CursorMode Window_GLFW::getCursorMode() {
        int32 mode = glfwGetInputMode((GLFWwindow*)m_Handle, GLFW_CURSOR);
        switch (mode) {
            case GLFW_CURSOR_NORMAL: return CursorMode::Normal;
            case GLFW_CURSOR_HIDDEN: return CursorMode::Hidden;
            case GLFW_CURSOR_DISABLED: return CursorMode::Disabled;
        }
        return (CursorMode)-1;
    }
    void Window_GLFW::setCursorMode(CursorMode mode) {
        switch (mode) {
            case CursorMode::Normal: return glfwSetInputMode((GLFWwindow*)m_Handle, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
            case CursorMode::Hidden: return glfwSetInputMode((GLFWwindow*)m_Handle, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
            case CursorMode::Disabled: return glfwSetInputMode((GLFWwindow*)m_Handle, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        }
    }
    // Callback
    // Callback :: Mouseclick
    void Window_GLFW::addMouseclickCallback(std::function<void(MouseButton, MouseState)> callback) {
        s_MouseclickCallbacks[m_Handle].push_back(callback);
    }
    // Callback :: Mousemove
    void Window_GLFW::addMousemoveCallback(std::function<void(Math::Vec2i)> callback) {
        s_MousemoveCallbacks[m_Handle].push_back(callback);
    }
    // Callback :: Keypress
    void Window_GLFW::addKeypressCallback(std::function<void(KeyCode_GLFW, KeyState)> callback) {
        s_KeypressCallbacks[m_Handle].push_back(callback);
    }
    // Callback :: Resize
    void Window_GLFW::addResizeCallback(std::function<void(Math::Vec2u)> callback) {
        s_ResizeCallbacks[m_Handle].push_back(callback);
    }
    // Callback :: Focus
    void Window_GLFW::addFocusCallback(std::function<void(bool)> callback) {
        s_FocusCallbacks[m_Handle].push_back(callback);
    }
    // Callback :: Minimize
    void Window_GLFW::addMinimizeCallback(std::function<void(bool)> callback) {
        s_MinimizeCallbacks[m_Handle].push_back(callback);
    }
    // Callback :: Maximize
    void Window_GLFW::addMaximizeCallback(std::function<void(bool)> callback) {
        s_MaximizeCallbacks[m_Handle].push_back(callback);
    }
    // Callback :: CloseRequest
    void Window_GLFW::addCloseRequestCallback(std::function<void()> callback) {
        s_CloseRequestCallbacks[m_Handle].push_back(callback);
    }
    // Bind
    void Window_GLFW::bind(std::function<void()> onbind) {
        std::scoped_lock contextlock(s_WindowContext);
        glfwMakeContextCurrent((GLFWwindow*)m_Handle);
        onbind();
    }
    // PollEvents
    void Window_GLFW::pollEvents() {
        bind([]() {
            glfwPollEvents();
        });
    }
    // Swap
    void Window_GLFW::swap() {
        glfwSwapBuffers((GLFWwindow*)m_Handle);
    }
}