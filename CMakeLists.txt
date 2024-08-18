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

# Set the output directory for the build files
set(CMAKE_BINARY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/build")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# Copy resources into the output directory so they can be found at runtime by the executable. This is for debugging purposes only.
add_custom_command(
    OUTPUT "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/resources"
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_CURRENT_SOURCE_DIR}/resources" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/resources"
    COMMENT "Copying resources"
    VERBATIM
)
add_custom_target(copy_resources ALL DEPENDS "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/resources")


# Compile libraries if needed
add_subdirectory(external/GLFW)
add_subdirectory(external/glm)
# add_subdirectory(external/FFmpeg)

add_subdirectory(src/1.getting_started)

include_directories(${CMAKE_SOURCE_DIR}/includes)