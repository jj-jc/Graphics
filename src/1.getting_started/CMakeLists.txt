cmake_minimum_required(VERSION 3.20)

#########################
###### hellowWindow #####
#########################
project(hellowWindow)

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

#########################
##### helloTexture  #####
#########################
project(helloTexture)

add_executable(${PROJECT_NAME} 
            ${CMAKE_SOURCE_DIR}/src/1.getting_started/1.3.hello_Texture/main.cpp
            ${CMAKE_SOURCE_DIR}/external/glad/src/glad.c
            ${CMAKE_SOURCE_DIR}/external/stb_image/src/stb_image.cpp
            ${CMAKE_SOURCE_DIR}/include/shader.hpp
            )

target_include_directories(${PROJECT_NAME} 
    PUBLIC 
        ${CMAKE_SOURCE_DIR}/external/GLFW/include #glfw
        ${CMAKE_SOURCE_DIR}/external/glad/include #glad
        ${CMAKE_SOURCE_DIR}/external/stb_image/include #glad
        ${CMAKE_SOURCE_DIR}/include #m
        )

target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/external/GLFW)

target_link_libraries(${PROJECT_NAME} 
    glfw
    #glad library is directly added by .c file
    #stb_image is directly added by .c file
)

#########################
## Coordinate Systems  ##
#########################
project(coordinateSystems)

add_executable(${PROJECT_NAME}
            ${CMAKE_SOURCE_DIR}/src/1.getting_started/1.4.coordinate_Systems/main.cpp
            ${CMAKE_SOURCE_DIR}/external/glad/src/glad.c
            ${CMAKE_SOURCE_DIR}/external/stb_image/src/stb_image.cpp
            ${CMAKE_SOURCE_DIR}/include/shader.hpp
            )

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_SOURCE_DIR}/external/GLFW/include # glfw
        ${CMAKE_SOURCE_DIR}/external/glad/include # glad
        ${CMAKE_SOURCE_DIR}/external/stb_image/include # stb_image
        ${CMKAE_SOURCE_DIR}/external/glm # glm
        ${CMAKE_SOURCE_DIR}/include # own
        )

target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/external/GLFW)
target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/external/glm)

target_link_libraries(${PROJECT_NAME}
    glfw
    #glad library is directly added by .c file
    #stb_image is directly added by .c file
    glm
)