cmake_minimum_required(VERSION 3.20)

#########################
###### hellowWindow #####
#########################
project(hellowWindow)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(${PROJECT_NAME} 
            ${CMAKE_SOURCE_DIR}/src/1.getting_started/1.1.hello_window/main.cpp
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


#########################
##### helloTriangle #####
#########################
project(helloTriangle)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)


add_executable(${PROJECT_NAME} 
            ${CMAKE_SOURCE_DIR}/src/1.getting_started/1.2.hello_Triangle/main.cpp
            ${CMAKE_SOURCE_DIR}/external/glad/src/glad.c
            ${CMAKE_SOURCE_DIR}/include/shader.hpp
            )

target_include_directories(${PROJECT_NAME} 
    PUBLIC 
        ${CMAKE_SOURCE_DIR}/external/GLFW/include #glfw
        ${CMAKE_SOURCE_DIR}/external/glad/include #glad
        ${CMAKE_SOURCE_DIR}/include #m
        )

target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/external/GLFW)

target_link_libraries(${PROJECT_NAME} 
    glfw
)
