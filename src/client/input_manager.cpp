#include "input_manager.hpp"

#include <cmath>

#include <glm/glm.hpp>

namespace q {
namespace client {
    input_manager::input_manager(GLFWwindow*& win)
        : _win{win}
    {
        _wireframe = false;
        _sensitivity = 0.05f;
    }

    void input_manager::process(const double& delta_time, camera& cam)
    {
        if (_is_focused()) {
            process_cursor(delta_time, cam);
            process_keyboard(delta_time, cam);
        }
    }

    void input_manager::process_keyboard(const double& delta_time, camera& cam)
    {
        float velocity = 1 * delta_time;
        glm::vec3 offset{0};

        if (_is_pressed(GLFW_KEY_F)) {
            _wireframe = !_wireframe;

            glPolygonMode(GL_FRONT_AND_BACK, _wireframe ? GL_LINE : GL_FILL);
        }

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

        cam.move(offset);
    }

    void input_manager::process_cursor(const double& delta_time, camera& cam)
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

            cam.rotate(glm::vec2{offset_x, offset_y} * _sensitivity);
        }
    }
}
}
