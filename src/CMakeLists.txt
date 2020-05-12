cmake_minimum_required(VERSION 3.1)

add_subdirectory("gl")
add_subdirectory("shared")
add_subdirectory("client")
add_subdirectory("server")

set(q_LIBRARIES q-client)
set(q_SOURCES main.cpp)
set(q_HEADERS)

add_executable(q-game ${q_SOURCES} ${q_HEADERS})

target_link_libraries(q-game PRIVATE ${q_LIBRARIES})
