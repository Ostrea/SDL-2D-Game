cmake_minimum_required(VERSION 2.8.4)
project(coursework_third_try)

set(SOURCE_FILES main.cpp game.cpp functions.cpp staticgraphicalelement.cpp background.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(SDL REQUIRED)
find_package(SDL_image REQUIRED)
find_package(SDL_ttf REQUIRED)

link_libraries(${SDL_LIBRARY} ${SDLIMAGE_LIBRARY} ${SDLTTF_LIBRARY})

add_executable(coursework_third_try ${SOURCE_FILES})