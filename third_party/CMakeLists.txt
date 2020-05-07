cmake_minimum_required(VERSION 3.1)

# GLFW
set(GLFW_BUILD_DOCS     OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS    OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory("glfw")

# GLM
set(GLM_TEST_ENABLE OFF CACHE BOOL "" FORCE)

add_subdirectory("glm")

# GLAD
set(GLAD_PROFILE "core"   CACHE STRING "" FORCE)
set(GLAD_API     "gl=4.3" CACHE STRING "" FORCE)

add_subdirectory("glad")
