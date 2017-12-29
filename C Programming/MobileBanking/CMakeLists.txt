cmake_minimum_required(VERSION 3.0)
project("MobileBanking")
# set(HEADER_FILE "logic.h")
# set(SOURCE main.cpp ${HEADER_FILE})
set (SOURCE main.cpp)
# set(TEST_PATH test.cpp ${HEADER_FILE})

add_executable(${PROJECT_NAME} ${SOURCE})
# add_executable(Test ${TEST_PATH})

# enable_testing()
# add_test(UnitTest Test)