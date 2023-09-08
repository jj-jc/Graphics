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

link_directories(${CMAKE_SOURCE_DI}/lib)

set(CHAPTERS
    1.getting_started
    )

set(1.getting_started
    1.1.hello_window)

# add_library(STB_IMAGE "src/stb_image.cpp")
# set(LIBS ${LIBS} STB_IMAGE)

add_library(GLAD "src/glad.c")
set(LIBS ${LIBS} GLAD)

function(create_project_from_sources chapter demo)
    file(GLOB SOURCE
        "src/${chapter}/${demo}/*.hpp"
        "src/${chapter}/${demo}/*.cpp"
        "src/${chapter}/${demo}/*.vs"
        "src/${chapter}/${demo}/*.fs"
        "src/${chapter}/${demo}/*.gs"
        "src/${chapter}/${demo}/*.cs"
    )
    if(demo STREQUAL "")
        SET(replaced "")
        string(REPLACE "/" "_" replaced ${chapter}
        set(NAME ${replaced}))
    else()
        set(NAME "${chapeter}_${demo}")
    endif()
    add_executable(${NAME} ${SOURCE})
    target_link_libraries(${NAME} ${LIBS})
    if(UNIX AND NOT APPLE)
        set_target_properties(${NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/${chapter}")
    endif()

    # copy shader files to build directory
    file(GLOB SHADERS
    "src/${chapter}/${demo}/*.vs"
    "src/${chapter}/${demo}/*.fs"
    "src/${chapter}/${demo}/*.gs"
    "src/${chapter}/${demo}/*.cs"
    )
    foreach(SHADER ${SHADERS})
        file(COPY ${SHADER} DESTINATION ${CMAKE_SOURCE_DIR}/bin/${chapter})
    endforeach(SHADER)
endfunction()

# then create a project file per tutorial
foreach(CHAPTER ${CHAPTERS})
    foreach(DEMO ${${CHAPTER}})
		create_project_from_sources(${CHAPTER} ${DEMO})
    endforeach(DEMO)
endforeach(CHAPTER)

include_directories(${CMAKE_SOURCE_DIR}/includes)