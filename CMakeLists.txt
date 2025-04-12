cmake_minimum_required(VERSION 3.10)
project(Tetris VERSION 0.1.0 LANGUAGES CXX)

# Find OpenGL
find_package(OpenGL REQUIRED)

set(MUSIC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Music")
add_definitions(-DMUSIC_DIR="${MUSIC_DIR}")
# Include headers and sources
file(GLOB_RECURSE HEADERS "headers/*.h")
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Create the executable
add_executable(Tetris ${SOURCES})

# Include headers directory
target_include_directories(Tetris PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/headers)

# Link the libraries (platform-independent)
target_link_libraries(Tetris PRIVATE freeglut ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY} winmm)