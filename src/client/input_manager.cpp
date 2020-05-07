#include "input_manager.hpp"

#include <cmath>

#include <glm/glm.hpp>

namespace q {
namespace client {
    input_manager::input_manager(GLFWwindow*& win) : _win{win}
    {
        _cam = nullptr;
        _sensitivity = 0.05f;
    }

    input_manager::~input_manager()
    {
    }

    void input_manager::process(const double& delta_time)
    {
        if (_is_focused()) {
            process_cursor(delta_time);
            process_keyboard(delta_time);
        }
    }

    void input_manager::process_keyboard(const double& delta_time)
    {
        float velocity = 1 * delta_time;
        glm::vec3 offset{0};

        if (_is_pressed(GLFW_KEY_LEFT_SHIFT)) {
            velocity *= 2;
        }

        if (_is_pressed(GLFW_KEY_W)) {
            offset.z += velocity;
        }

        if (_is_pressed(GLFW_KEY_A)) {
            offset.x -= velocity;
        }

        if (_is_pressed(GLFW_KEY_S)) {
            offset.z -= velocity;
        }

        if (_is_pressed(GLFW_KEY_D)) {
            offset.x += velocity;
        }

        if (_is_pressed(GLFW_KEY_SPACE)) {
            offset.y += velocity;
        }

        if (_is_pressed(GLFW_KEY_LEFT_CONTROL)) {
            offset.y -= velocity;
        }

        _cam->move(offset);
    }

    void input_manager::process_cursor(const double& delta_time)
    {
        int win_width;
        int win_height;

        glfwGetWindowSize(_win, &win_width, &win_height);

        const int center_x = win_width / 2;
        const int center_y = win_height / 2;

        double cursor_x;
        double cursor_y;

        glfwGetCursorPos(_win, &cursor_x, &cursor_y);

        if (cursor_x != center_x || cursor_y != center_y) {
            glfwSetCursorPos(_win, center_x, center_y);

            const auto offset_x = cursor_x - center_x;
            const auto offset_y = center_y - cursor_y;

            if (_cam) {
                _cam->rotate(glm::vec2{offset_x, offset_y} * _sensitivity);
            }
        }
    }

    void input_manager::set_cursor_visible(const bool& state)
    {
        glfwSetInputMode(_win, GLFW_CURSOR, state ? GLFW_CURSOR_NORMAL : GLFW_CURSOR_HIDDEN);
    }

    void input_manager::set_camera(const std::shared_ptr<camera>& cam)
    {
        _cam = cam;
    }
}
}
