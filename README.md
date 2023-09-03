# 2dautomata

# TODO: 
- Add Cunit and write some tests
- Add more cell types
- Add menu for selecting cell types
- Take density into account when checking if possible to move cell

## How to build
Run the program with the command `make run`.
Build the binary with the the command `make all`.
Clean build artifacts with the command `make clean`.

# How to install [Raylib](https://www.raylib.com/) on Linux (and maybe also WSL)
## Install Basic Tools like Make, Git and Gcc
`sudo apt install build-essential git`
## Install libraries required by raylib
sudo apt install libasound2-dev libx11-dev libxrandr-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxcursor-dev libxinerama-dev
## Clone the raylib repository and compile it
`git clone https://github.com/raysan5/raylib.git raylib
cd raylib/src/
make PLATFORM=PLATFORM_DESKTOP # To make the static version. (This is the one you want!)
make PLATFORM=PLATFORM_DESKTOP RAYLIB_LIBTYPE=SHARED # To make the dynamic shared version.
make PLATFORM=PLATFORM_WEB # To make web version.`
## Install the library in the standard directories
`sudo make install # Static version. (This one should be enough!)
sudo make install RAYLIB_LIBTYPE=SHARED # Dynamic shared version.`

## If this does not work on Windows/WSL, look [here](https://github.com/raysan5/raylib/wiki/Working-on-Windows)

### Finally, learn by looking at the [examples](https://www.raylib.com/examples.html)!
