cmake_minimum_required(VERSION 3.1)

if(UNIX)
    set(OpenGL_GL_PREFERENCE GLVND)
endif()

find_package(OpenGL REQUIRED)
find_package(Threads REQUIRED)

set(q_client_LIBRARIES OpenGL::GL Threads::Threads glm::glm glfw glad)

set(q_client_SOURCES game_window.cpp camera.cpp input_manager.cpp
    game_renderer.cpp)

set(q_client_HEADERS game_window.hpp camera.hpp input_manager.hpp
    game_renderer.hpp)

add_library(q-client ${q_client_SOURCES} ${q_client_HEADERS})

target_include_directories(q-client PUBLIC "../")
target_link_libraries(q-client ${q_client_LIBRARIES} q-gl)
