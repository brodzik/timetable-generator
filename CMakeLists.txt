cmake_minimum_required(VERSION 3.0)
project(timetable-generator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wextra -Weffc++ -pedantic")

set(HEADER_FILES
    include/course.hpp
    include/generator.hpp
)

set(SOURCE_FILES
    src/main.cpp
)

include_directories(include)

add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})
