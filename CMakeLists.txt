cmake_minimum_required(VERSION 3.10)
project(OpenFantasyThrone)

option (FORCE_COLORED_OUTPUT "Always produce ANSI-colored output (GNU/Clang only)." TRUE)
if (${FORCE_COLORED_OUTPUT})
    if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
       add_compile_options (-fdiagnostics-color=always)
    elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
       add_compile_options (-fcolor-diagnostics)
    endif ()
endif ()

# Add source files
file(GLOB_RECURSE SOURCE_FILES
  ${CMAKE_SOURCE_DIR}/src/*.cpp)

# Add header files
file(GLOB_RECURSE HEADER_FILES
  ${CMAKE_SOURCE_DIR}/include/*.hpp)


get_filename_component(full_path_main_cpp ${CMAKE_SOURCE_DIR}/src/main.cpp ABSOLUTE)
LIST(REMOVE_ITEM SOURCE_FILES ${full_path_main_cpp})

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/thirdparty)

add_executable(${PROJECT_NAME}
  ${CMAKE_SOURCE_DIR}/src/main.cpp
  ${HEADER_FILES}
  ${SOURCE_FILES})

# Find required packages and libraries
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
# OpenGL
find_package(OpenGL REQUIRED)

# GLM
find_package(GLM REQUIRED)
message(STATUS "GLM included at ${GLM_INCLUDE_DIR}")

# GLFW
find_package(GLFW3 REQUIRED)
message(STATUS "GLFW3 included at ${GLFW3_INCLUDE_DIR}")
message(STATUS "GLFW3 library found at ${GLFW3_LIBRARY}")

# GLEW
find_package(GLEW)
if(NOT GLEW_FOUND)
  message(STATUS "GLEW is not found by default script, setting it manually (works for Windows only)")
  set(GLEW_LIBRARY "${CMAKE_SOURCE_DIR}/lib/glew32.lib")
endif()

if (NOT WIN32)
  target_link_libraries(${PROJECT_NAME} GLEW::GLEW)
endif()

# Assimp
find_package(ASSIMP REQUIRED)
message(STATUS "ASSIMP included at ${GLFW3_INCLUDE_DIR}")

set(LIBS
  ${GLFW3_LIBRARY}
  ${OPENGL_LIBRARY}
  ${GLEW_LIBRARY}
  ${ASSIMP_LIBRARIES}
  )

target_link_libraries(${PROJECT_NAME} ${LIBS})

set(CMAKE_CXX_FLAGS, "${CMAKE_CXX_FLAGS} -Wall -g")
set(CXX_STANDARD 20)

