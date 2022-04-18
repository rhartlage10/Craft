cmake_minimum_required(VERSION 2.8)

project(craft)

FILE(GLOB SOURCE_FILES src/*.c)

add_executable(
    craft
    ${SOURCE_FILES}
    deps/glew/src/glew.c
    deps/lodepng/lodepng.c
    deps/noise/noise.c
    deps/sqlite/sqlite3.c
    deps/tinycthread/tinycthread.c)

add_definitions(-std=c99 -O3)

add_subdirectory(deps/glfw)
include_directories(deps/glew/include)
include_directories(deps/glfw/include)
include_directories(deps/lodepng)
include_directories(deps/noise)
include_directories(deps/sqlite)
include_directories(deps/tinycthread)

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/e2239ee6043f73722e7aa812a459f54a28552929.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(example example.cpp)
target_link_libraries(example gtest_main)
add_test(NAME example_test COMMAND example)

if(MINGW)
    set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH}
        "C:/Program Files/CURL/lib" "C:/Program Files (x86)/CURL/lib")
    set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH}
        "C:/Program Files/CURL/include" "C:/Program Files (x86)/CURL/include")
endif()

find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})

if(APPLE)
    target_link_libraries(craft glfw
        ${GLFW_LIBRARIES} ${CURL_LIBRARIES})
endif()

if(UNIX)
    target_link_libraries(craft dl glfw
        ${GLFW_LIBRARIES} ${CURL_LIBRARIES})
endif()

if(MINGW)
    target_link_libraries(craft ws2_32.lib glfw
        ${GLFW_LIBRARIES} ${CURL_LIBRARIES})
endif()
