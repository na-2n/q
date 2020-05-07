cmake_minimum_required(VERSION 3.1)

find_package(Threads REQUIRED)

set(q_server_LIBRARIES Threads::Threads glm::glm)

set(q_server_SOURCES server.cpp)

set(q_server_HEADERS server.hpp)

add_library(q-server ${q_server_SOURCES} ${q_server_HEADERS})

target_link_libraries(q-server PRIVATE ${q_server_LIBRARIES})
