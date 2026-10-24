cmake_minimum_required(VERSION 3.21)

project(leetcode-cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()
set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS Debug Release RelWithDebInfo MinSizeRel)

include(CTest)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS "src/*.cpp")

foreach(SRC ${SOURCE_FILES})
    get_filename_component(TARGET_NAME ${SRC} NAME_WE)
    add_executable(${TARGET_NAME} ${SRC})

    target_include_directories(${TARGET_NAME}
        PRIVATE
        ${CMAKE_SOURCE_DIR}/include
    )

    if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        target_compile_options(${TARGET_NAME}
            PRIVATE
            -Wall
            -Wextra
            -Wpedantic
            -Werror
        )
    endif()

    if (BUILD_TESTING)
        add_test(NAME ${TARGET_NAME} COMMAND ${TARGET_NAME})
        set_tests_properties(${TARGET_NAME} PROPERTIES TIMEOUT 10)
    endif()
endforeach()
