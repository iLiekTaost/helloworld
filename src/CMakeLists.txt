cmake_minimum_required(VERSION 3.28)
set(VERBOSE 1)

# project settings
project(hello_world VERSION 1.0 DESCRIPTION "Hello World!" LANGUAGES CXX)
message(STATUS "Build tree starts at: ${CMAKE_BINARY_DIR}")
# release mode as default
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build." FORCE)
endif()
# build shared libs by default
set(BUILD_SHARED_LIBS ON)

# CMakeLists tree
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/mylibs)

# main executable
add_executable(hw main.cpp)
# target compiles with a library built in this tree (from source)
target_include_directories(hw PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/mylibs)
# target_link_directories(hw PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/mylibs)
# looks like we can link lib w/o linking the directory
target_link_libraries(hw PUBLIC mylib)  # TODO what if this is PRIVATE?

install(TARGETS hw mylib)
