cmake_minimum_required(VERSION 3.21)

project(leetcode-cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

add_compile_options(
    -Wall
    -Wextra
    -Wpedantic
    -Werror
)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS "src/*.cpp")

foreach(SRC ${SOURCE_FILES})
    get_filename_component(TARGET_NAME ${SRC} NAME_WE)
    add_executable(${TARGET_NAME} ${SRC})
    target_include_directories(${TARGET_NAME}
        PRIVATE
        ${CMAKE_SOURCE_DIR}/include
    )
endforeach()
