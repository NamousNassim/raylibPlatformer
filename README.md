## Platformer game using raylib c++

# goal 
- game should have a player that can move and jump, platforms, collisions, collectibles, and a simple menu.

# note
- also this project was made to help me switch my carrer into system engineer c++ or a game dev my dream was always been to make my own engine

# How to build and run

## Requirements (Windows)
- [raylib](https://www.raylib.com/) installed at `C:\raylib` (the default location of the Windows installer)
- [MSYS2](https://www.msys2.org/) with the UCRT64 GCC compiler. After installing MSYS2, open the **MSYS2 UCRT64** terminal and run:
  ```
  pacman -S mingw-w64-ucrt-x86_64-gcc
  ```
- [CMake](https://cmake.org/download/) 3.10 or newer
- Add `C:\msys64\ucrt64\bin` to your Windows `PATH`

> raylib is installed somewhere else? Change `RAYLIB_DIR` at the top of `CMakeLists.txt`, or pass `-DRAYLIB_DIR=your/path/to/raylib` when configuring.

## Option 1: VS Code (easiest)
1. Install the **C/C++** and **CMake Tools** extensions.
2. Open this folder in VS Code and pick the `GCC ... (ucrt64)` preset when asked.
3. Press **F7** to build, then **Shift+F5** to run.

## Option 2: Command line
From the project folder:
```
cmake --preset "GCC 16.2.0 x86_64-w64-mingw32 (ucrt64)"
cmake --build "out/build/GCC 16.2.0 x86_64-w64-mingw32 (ucrt64)"
```
Then run the game:
```
"out/build/GCC 16.2.0 x86_64-w64-mingw32 (ucrt64)/raylibPlatformer.exe"
```

The first build is slower because raylib is compiled from source. After that, builds are fast.

## Troubleshooting
- **"missing DLL" error when starting the .exe** → `C:\msys64\ucrt64\bin` is not in your `PATH`.
- **CMake can't find raylib** → check that `C:\raylib\raylib\CMakeLists.txt` exists, or set `RAYLIB_DIR` (see above).
- **Different GCC version** → the preset file points to `C:/msys64/ucrt64/bin/gcc.exe`, so it works with any version installed there. Only the preset name mentions 16.2.0.
