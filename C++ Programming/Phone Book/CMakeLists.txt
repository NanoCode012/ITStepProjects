cmake_minimum_required(VERSION 3.0)
project("PhoneBook")

set(INC Subscriber.h Subscriber_inline.h Database.h Misc.h)
set(SRC Subscriber.cpp Database.cpp Misc.cpp)
set(SOURCE main.cpp ${INC} ${SRC})

add_executable(${PROJECT_NAME} ${SOURCE})
