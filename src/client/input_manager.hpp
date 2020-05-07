#pragma once

#include <memory>

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "camera.hpp"

namespace q {
namespace client {
    class input_manager {
    public:
        input_manager(GLFWwindow*& win);

        ~input_manager();

        void process(const double& delta_time);

        void process_keyboard(const double& delta_time);

        void process_cursor(const double& delta_time);

        void set_cursor_visible(const bool& state);

        void set_camera(const std::shared_ptr<camera>& cam);

    private:
        GLFWwindow*& _win;
        std::shared_ptr<camera> _cam;
        float _sensitivity;

        inline bool _is_focused()
        {
            return static_cast<bool>(glfwGetWindowAttrib(_win, GLFW_FOCUSED));
        }

        inline bool _is_pressed(const int& key)
        {
            return glfwGetKey(_win, key) == GLFW_PRESS;
        }
    };
}
}
