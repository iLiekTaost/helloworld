cmake_minimum_required(VERSION 3.28)

project(hello_world)
message(STATUS "Build tree starts at: ${CMAKE_BINARY_DIR}")

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/mylibs)

add_executable(hw main.cpp)
target_include_directories(hw PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/mylibs)
target_link_directories(hw PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/mylibs)
target_link_libraries(hw PUBLIC mylib)

install(TARGETS hw mylib)
