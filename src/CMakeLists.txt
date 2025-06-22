cmake_minimum_required(VERSION 3.28)

# project settings
project(hello_world)
message(STATUS "Build tree starts at: ${CMAKE_BINARY_DIR}")

# CMakeLists tree
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/mylibs)

# main executable
add_executable(hw main.cpp)
# target compiles with a library built in this tree (from source)
target_include_directories(hw PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/mylibs)
# target_link_directories(hw PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/mylibs)
target_link_libraries(hw PUBLIC mylib)  # looks like we can link lib w/o

install(TARGETS hw mylib)
