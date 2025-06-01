cmake_minimum_required(VERSION 3.30)
project(Bonus_01_Task C)

set(CMAKE_C_STANDARD 11)

# Client
add_executable(centralLogClient centralLogClient.c)
target_link_libraries(centralLogClient ws2_32)

# Server
add_executable(centralLogServer centralLogServer.c)
target_link_libraries(centralLogServer ws2_32)
