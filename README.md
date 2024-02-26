# Description
C++ library for graphical windows

## Features
- window class, utility functions and event callbacks
- mouse, keyboard and window-state events

# System-Support
- linux: supported, tested, prebuild binaries
- others: not-supported

# Dependancies
- OPENGL (Mostly Included)
- GLFW
- GLEW

## Resolve on Linux
``` console
sudo apt install libglfw3-dev libglew-dev
```

# Use Library
- add "PATH_TO_REPO/include" to your include directories
- define macro "WINDOWAPI_GLFW"

## Prebuild Binaries
- add "PATH_TO_REPO/lib/CONFIG" to your library directories
- add libraries "pixelpaw", "glfw", "GLEW", "GLU, "GL"

## Or Build Yourself