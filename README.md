# C++ Console Snake Game

A Modern C++ implementation of the classic Snake game for the console. Refactored to demonstrate modern C++ practices and clean architecture.

## Features
- **Modern C++ (C++17)**: Uses `std::unique_ptr`, `std::mt19937`, and standard containers.
- **Object-Oriented Design**: Clean separation of concerns (`Game`, `Snake`, `Map`, `ConsoleUtils`).
- **Smooth Gameplay**: Optimized rendering logic to prevent flickering.
- **Cross-Platform Foundation**: Logic is separated from platform-specific console drawing (currently Windows).

## Requirements
- Windows OS (for `conio.h` and `windows.h`)
- C++17 compatible compiler (MSVC, GCC, Clang)
- CMake (optional, for building)

## How to Build

### Using CMake
1. Create a build directory:
   ```bash
   mkdir build
   cd build
   ```
2. Generate project files:
   ```bash
   cmake ..
   ```
3. Build:
   ```bash
   cmake --build .
   ```

### Manual Build (g++)
```bash
g++ -o SnakeGame main.cpp Game.cpp Snake.cpp Map.cpp -std=c++17
```

## How to Play
- **W / A / S / D**: Move Up / Left / Down / Right
- **Q**: Quit Game

## Code Structure
- `Game`: Manages game loop, input, and score.
- `Snake`: Handles snake body data, movement logic, and self-collision.
- `Map`: Manages rendering and food spawning.
- `ConsoleUtils`: Wrapper for Windows console API calls.