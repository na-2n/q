#pragma once

#include <string>
#include <memory>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "game_renderer.hpp"
#include "input_manager.hpp"
#include "camera.hpp"

namespace q {
namespace client {
    GLFWwindow* create_window(const std::string& title);

    class game_window {
    public:
        game_window(GLFWwindow*& win);

        ~game_window();

        inline void make_current() const
        {
            glfwMakeContextCurrent(_win);
        }

        void run_loop();

    private:
        game_renderer _renderer;
        input_manager _input;
        camera _cam;

        GLFWwindow* _win;
        double _last_frame;

        void _on_resize(int width, int height);

        static inline void _glfw_resize_cb(GLFWwindow* win, int width, int height)
        {
            auto self = static_cast<game_window*>(glfwGetWindowUserPointer(win));

            self->_on_resize(width, height);
        }
    };
}
}
