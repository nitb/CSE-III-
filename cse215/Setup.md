# Documentation
##Setup

OpenGL is used as static library.

Make sure you have all the packages installed properly.


For Linux Based system:

* Ubuntu/Debian:

For GLFW support:
`sudo apt-get install  libglfw3-dev`

For GLEW support:`sudo apt-get install libglew-dev`

For OpenGL mathematic  Library: `sudo apt-get install libglm-dev`

For portable framework:
`sudo apt-get install libglfw3`

Set your build tools: `sudo apt-get install cmake make g++ libx11-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxrandr-dev libxext-dev`

* Arch Linux:

For GLFW support:
`sudo pacman -S  libglfw3-dev`

For portable framework:
`sudo pacman -S libglfw3`

Set your build tools: `sudo pacman -S cmake make g++ libx11-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxrandr-dev libxext-dev`

* Mac:

Set your build tools: `sudo yum install cmake make g++ libx11-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxrandr-dev libxext-dev`

----
#####Note:
 This is not based on Win32 API for windows, X11 API on Linux, and Cocoa API on MAC, or another library like SFML, FreeGLUT, SDL, and so on.  
