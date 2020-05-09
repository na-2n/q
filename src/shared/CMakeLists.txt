cmake_minimum_required(VERSION 3.1)

find_package(Threads REQUIRED)

set(q_shared_LIBRARIES Threads::Threads glm::glm)

set(q_shared_SOURCES chunk.cpp chunk_manager.cpp)

set(q_shared_HEADERS chunk.hpp chunk_manager.hpp)

add_library(q-shared ${q_shared_SOURCES} ${q_shared_HEADERS})

target_link_libraries(q-shared ${q_shared_LIBRARIES})
