cmake_minimum_required (VERSION 3.20)

project(Graphics VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17) # this does nothing for MSVC, use target_compile_options below
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # this generate a compilation database

IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
ENDIF(NOT CMAKE_BUILD_TYPE)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

# Compile libraries if needed
add_subdirectory(external/GLFW)
add_subdirectory(external/glm)
add_subdirectory(external/FFmpeg)

add_subdirectory(src/1.getting_started)

include_directories(${CMAKE_SOURCE_DIR}/includes)