# Description
C++ library for graphical windows

## Features
- Window Class, Utility Functions and Event Callbacks
- Mouse, Keyboard and Window-State Events

## Support
- Linux (native)
- Windows (not supported)

# Usage
## Installation
At your desired location, type this command into the console.
``` console
git clone git@github.com:fburgerdev/window.git
```
## Dependancies
- OpenGL (Mostly Included)
- GLFW
- GLEW

To resolve all dependancies, execute this command in the console
``` console
sudo apt-get install libglfw3-dev libglew-dev
```

## Project Settings
- Add include directory: "PATH_TO_REPO/include" 
- Add library directory: "PATH_TO_REPO/lib/CONFIG/" 
- Link libraries: "window", "glfw", "GLEW", "GLU, "GL"

## Build Yourself (Optional)
In the _build_ folder, execute the following command in the console
``` console
make config=CONFIG
```
If you have not installed _make_, execute this command in the console first
``` console
sudo apt-get install make -y
```

__Note:__ Make sure you have the _Desktop developement with C++_ workload installed.