cmake_minimum_required(VERSION 3.20)

project(Getting_Started)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)


add_executable(${PROJECT_NAME} 
            main.cpp
            ${CMAKE_SOURCE_DIR}/external/glad/src/glad.c)

target_include_directories(${PROJECT_NAME} 
    PUBLIC 
        ${CMAKE_SOURCE_DIR}/external/GLFW/include #glfw
        ${CMAKE_SOURCE_DIR}/external/glad/include #glad
        )

target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/external/GLFW)

target_link_libraries(${PROJECT_NAME} 
    glfw
)
