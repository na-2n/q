cmake_minimum_required(VERSION 3.1)

set(q_shared_LIBRARIES glm::glm)

set(q_shared_SOURCES chunk.cpp chunk_manager.cpp ray.cpp math.cpp filesystem.cpp)

set(q_shared_HEADERS chunk.hpp chunk_manager.hpp ray.hpp math.hpp filesystem.hpp)

add_library(q-shared ${q_shared_SOURCES} ${q_shared_HEADERS})

target_link_libraries(q-shared ${q_shared_LIBRARIES})
