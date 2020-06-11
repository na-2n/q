#include "game_window.hpp"

#include <stdexcept>

#include <glad/glad.h>
#include <glm/glm.hpp>

namespace {
    const int win_width = 800;
    const int win_height = 600;
}

namespace q {
namespace client {
    GLFWwindow* create_window(const std::string& title)
    {
        if (!glfwInit()) {
            throw std::runtime_error{"Failed to initialize GLFW"};
        }

        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

        auto win = glfwCreateWindow(::win_width, ::win_height, title.c_str(), nullptr, nullptr);

        if (!win) {
            glfwTerminate();

            throw std::runtime_error("Failed to create GLFW window");
        }

        glfwMakeContextCurrent(win);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            glfwTerminate();

            throw std::runtime_error("Failed to load OpenGL library");
        }

        return win;
    }

    game_window::game_window(GLFWwindow*& win)
        : _win{win},
          _cam{glm::vec3{0}, static_cast<float>(::win_width) / static_cast<float>(::win_height)},
          _world{}, _renderer{_world}, _input{_win, _world}
    {
        make_current();

        glfwSetWindowUserPointer(_win, this);
        glfwSetFramebufferSizeCallback(_win, _glfw_resize_cb);

        glEnable(GL_DEPTH_TEST);
        glEnable(GL_CULL_FACE);
        glCullFace(GL_FRONT);
        glFrontFace(GL_CW);

        _input.set_cursor_visible(false);
    }

    game_window::~game_window()
    {
        if (_win) {
            glfwDestroyWindow(_win);
        }

        glfwTerminate();
    }

    void game_window::run_loop()
    {
        while (!glfwWindowShouldClose(_win)) {
            const auto frame = glfwGetTime();
            const auto delta_time = frame - _last_frame;
            _last_frame = frame;

            _input.process(delta_time, _cam);

            glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            _renderer.draw(delta_time, _cam);

            glfwSwapBuffers(_win);
            glfwPollEvents();
        }

        glfwTerminate();
    }

    void game_window::_on_resize(int width, int height)
    {
        glViewport(0, 0, width, height);

        _cam.set_aspect_ratio(static_cast<float>(width) / static_cast<float>(height));
    }
}
}
