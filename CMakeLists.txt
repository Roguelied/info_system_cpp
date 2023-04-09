cmake_minimum_required(VERSION 3.23)
project(info_system_cpp)


set(CMAKE_CXX_STANDARD 23)



set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS} -static -lws2_32")
link_libraries(ws2_32 wsock32)


add_executable(info_system_cpp main.cpp UserInterface.cpp UserInterface.h Client.cpp Client.h Server.cpp Server.h Utility.cpp Utility.h Database.cpp Database.h)
