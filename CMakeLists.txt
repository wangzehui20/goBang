cmake_minimum_required(VERSION 3.15)
project(goBang)

set(CMAKE_CXX_STANDARD 14)

add_executable(goBang GAME.cpp AI.h AI.cpp FORBIDDEN.h FORBIDDEN.cpp KEYBOARD.h KEYBOARD.cpp MODE.h MODE.cpp PLAY.h PLAY.cpp PLAYER.h PLAYER.cpp)