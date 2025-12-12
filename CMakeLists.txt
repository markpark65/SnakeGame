cmake_minimum_required(VERSION 3.10)
project(SnakeGame VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Source files
set(SOURCES
    main.cpp
    Game.cpp
    Map.cpp
    Snake.cpp
)

# Header files (for IDE support)
set(HEADERS
    Game.h
    Map.h
    Snake.h
    ConsoleUtils.h
)

add_executable(SnakeGame ${SOURCES} ${HEADERS})
