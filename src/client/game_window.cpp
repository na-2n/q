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
        : _win{win}, _input{_win}, _renderer{},
          _cam{
              new camera{glm::vec3{0}, static_cast<float>(::win_width) / static_cast<float>(::win_height)}
          }
    {
        make_current();

        _input.set_cursor_visible(false);
        _input.set_camera(_cam);
        _renderer.set_camera(_cam);
    }

    game_window::~game_window()
    {
        if (_win) {
            glfwDestroyWindow(_win);
        }

        glfwTerminate();
    }

    void game_window::make_current() const
    {
        glfwMakeContextCurrent(_win);
    }

    void game_window::run_loop()
    {
        while (!glfwWindowShouldClose(_win)) {
            const auto frame = glfwGetTime();
            const auto delta_time = frame - _last_frame;
            _last_frame = frame;

            _check_win_size();
            _input.process(delta_time);

            glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            _renderer.draw(delta_time);

            glfwSwapBuffers(_win);
            glfwPollEvents();
        }

        glfwTerminate();
    }

    void game_window::_check_win_size()
    {
        int width = 0;
        int height = 0;

        glfwGetFramebufferSize(_win, &width, &height);


        if (width != _win_width || height != _win_height) {
            _win_width = width;
            _win_height = height;

            glViewport(0, 0, width, height);

            _cam->set_aspect_ratio(static_cast<float>(width) / static_cast<float>(height));
        }
    }
}
}
