#pragma once
// #include <...> (HPPMERGE)
#include <memory>
#include <string>
#include <string_view>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <map>
#include <set>
#include <unordered_map>
#include <functional>
// #include "..." (HPPMERGE)
#include "math.hpp"

// #include "window.hpp" (HPPMERGE)
#if defined(WINDOWAPI_GLFW) or true

// #include "common.hpp" (HPPMERGE)
namespace Wndw {
    // Types
    // Types :: address
    using address = std::size_t;
    // Types :: int
    using int8 = std::int8_t;
    using int16 = std::int16_t;
    using int32 = std::int32_t;
    using int64 = std::int64_t;
    // Types :: uint
    using uint8 = std::uint8_t;
    using uint16 = std::uint16_t;
    using uint32 = std::uint32_t;
    using uint64 = std::uint64_t;
    // Types :: string
    using string = std::string;
    // Types :: string_view
    using string_view = std::string_view;
    // Container
    // Container :: Sequence
    template<typename T, address N>
    using Array = std::array<T, N>;
    template<typename T>
    using List = std::vector<T>;
    template<typename T>
    using Stack = std::stack<T>;
    template<typename T>
    using Queue = std::queue<T>;
    template<typename T>
    using Deque = std::deque<T>;
    // Container :: Tree
    template<typename T>
    using Set = std::set<T>;
    template<typename Key, typename Value>
    using Map = std::map<Key, Value>;
    // Container :: Hash
    template<typename T>
    using HashSet = std::unordered_set<T>;
    template<typename Key, typename Value>
    using HashMap = std::unordered_map<Key, Value>;
}
// #include "event.hpp" (HPPMERGE)
#if defined(WINDOWAPI_GLFW) or true

// #include "glfwkeylayout.hpp" (HPPMERGE)
namespace Wndw {
    // KeyCode
// #include "glfwkeycodes.hpp" (HPPMERGE)
enum class KeyCode_GLFW {
    // German-Layout
    GER_ESZETT = -2,
    GER_UMLAUT_U = -3,
    GER_UMLAUT_O = -4,
    GER_UMLAUT_A = -5,
    GER_ALT_GR = -6,
    PLUS = -7,
    HASH = -8,
    // GLFW-Keycodes
    UNKNOWN = -1, // NONE
    // GLFW-Keycodes :: ASCII
    // GLFW-Keycodes :: ASCII :: Alphabet
    A = 65,
    B = 66,
    C = 67,
    D = 68,
    E = 69,
    F = 70,
    G = 71,
    H = 72,
    I = 73,
    J = 74,
    K = 75,
    L = 76,
    M = 77,
    N = 78,
    O = 79,
    P = 80,
    Q = 81,
    R = 82,
    S = 83,
    T = 84,
    U = 85,
    V = 86,
    W = 87,
    X = 88,
    Y = 89,
    Z = 90,
    // GLFW-Keycodes :: ASCII :: Digits
    Digit_0 = 48, 
    Digit_1 = 49, 
    Digit_2 = 50, 
    Digit_3 = 51, 
    Digit_4 = 52, 
    Digit_5 = 53, 
    Digit_6 = 54, 
    Digit_7 = 55, 
    Digit_8 = 56, 
    Digit_9 = 57, 
    // GLFW-Keycodes :: ASCII :: Special
    SPACE = 32, 
    APOSTROPHE = 39, 
    COMMA = 44, 
    MINUS = 45, 
    PERIOD = 46, 
    SLASH = 47, 
    SEMICOLON = 59, 
    EQUAL = 61, 
    LEFT_BRACKET = 91, 
    BACKSLASH = 92, 
    RIGHT_BRACKET = 93, 
    GRAVE_ACCENT = 96, 
    // GLFW-Keycodes :: Numpad
    NUMPAD_0 = 320,
    NUMPAD_1 = 321,
    NUMPAD_2 = 322,
    NUMPAD_3 = 323,
    NUMPAD_4 = 324,
    NUMPAD_5 = 325,
    NUMPAD_6 = 326,
    NUMPAD_7 = 327,
    NUMPAD_8 = 328,
    NUMPAD_9 = 329,
    NUMPAD_DECIMAL = 330,
    NUMPAD_DIV = 331,
    NUMPAD_MULT = 332,
    NUMPAD_MINUS = 333,
    NUMPAD_PLUS = 334,
    NUMPAD_ENTER = 335,
    NUMPAD_EQUAL = 336,
    // GLFW-Keycodes :: F-Keys
    F1 = 290,
    F2 = 291,
    F3 = 292,
    F4 = 293,
    F5 = 294,
    F6 = 295,
    F7 = 296,
    F8 = 297,
    F9 = 298,
    F10 = 299,
    F11 = 300,
    F12 = 301,
    F13 = 302,
    F14 = 303,
    F15 = 304,
    F16 = 305,
    F17 = 306,
    F18 = 307,
    F19 = 308,
    F20 = 309,
    F21 = 310,
    F22 = 311,
    F23 = 312,
    F24 = 313,
    F25 = 314,
    // GLFW-Keycodes :: Special
    WORLD_1 = 161, 
    WORLD_2 = 162, 
    ESCAPE = 256,
    ENTER = 257,
    TAB = 258,
    BACKSPACE = 259,
    INSERT = 260,
    DELETE = 261,
    RIGHT = 262,
    LEFT = 263,
    DOWN = 264,
    UP = 265,
    PAGE_UP = 266,
    PAGE_DOWN = 267,
    HOME = 268,
    END = 269,
    CAPS_LOCK = 280,
    SCROLL_LOCK = 281,
    NUM_LOCK = 282,
    PRINT_SCREEN = 283,
    PAUSE = 284,
    LEFT_SHIFT = 340,
    LEFT_CONTROL = 341,
    LEFT_ALT = 342,
    LEFT_SUPER = 343,
    RIGHT_SHIFT = 344,
    RIGHT_CONTROL = 345,
    RIGHT_ALT = 346,
    RIGHT_SUPER = 347,
    MENU = 348
};
    // US-Layout
    KeyCode_GLFW toUSLayout(KeyCode_GLFW code);
    // German-Layout
    KeyCode_GLFW toGermanLayout(KeyCode_GLFW code);
}
#endif

namespace Wndw {
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
    #if defined(WINDOWAPI_GLFW) or true
    using KeyCode = KeyCode_GLFW;
    #endif
}

// #include "glfwwindow.hpp" (HPPMERGE)
namespace Wndw {
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
namespace Wndw {
    using Window = Window_GLFW;
}
#elif
#error "No WindowAPI specified! Options: 'WINDOWAPI_GLFW'"
#endif