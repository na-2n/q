cmake_minimum_required(VERSION 3.1)

set(OpenGL_GL_PREFERENCE GLVND)

find_package(OpenGL REQUIRED)

set(q_gl_LIBRARIES OpenGL::GL glm::glm glad)

set(q_gl_SOURCES util.cpp buffer_object.cpp vertex_attribute.cpp
    vertex_array_object.cpp shader.cpp shader_program.cpp)

set(q_gl_HEADERS util.hpp buffer_object.hpp vertex_attribute.hpp
    vertex_array_object.hpp shader.hpp shader_program.hpp)

add_library(q-gl ${q_gl_SOURCES} ${q_gl_HEADERS})

target_link_libraries(q-gl ${q_gl_LIBRARIES})
