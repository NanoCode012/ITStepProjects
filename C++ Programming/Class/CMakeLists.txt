cmake_minimum_required(VERSION 3.0)
project("Class")
set(SOURCE main.cpp Test.cpp Point.h Point.cpp Student.cpp Fraction.h Fraction.cpp)
add_executable(${PROJECT_NAME} ${SOURCE})