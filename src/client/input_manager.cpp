#include "input_manager.hpp"

#include <cmath>

#include <glm/glm.hpp>

#include "shared/math.hpp"
#include "shared/chunk.hpp"

namespace q {
namespace client {
    input_manager::input_manager(GLFWwindow*& win, game_world& world)
        : _win{win}, _world{world}
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
            velocity *= 4;
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

        // mouse buttons

        if (glfwGetMouseButton(_win, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
            auto maybe_hit = _world.chunk_mgr().cast_ray(cam.position(), cam.direction());

            if (maybe_hit.has_value()) {
                const auto& pos = maybe_hit->pos;
                const glm::ivec3 local = glm::mod(glm::vec3{pos}, glm::vec3{shared::chunk::size});
                const auto chunk_pos = (pos - local) / shared::chunk::size;

                maybe_hit->block = 0;

                _world.needs_update(chunk_pos);

                const int bound = shared::chunk::size - 1;

                if (local.x == 0) {
                    _world.needs_update(chunk_pos - shared::math::vec3::unit_x);
                }

                if (local.x == bound) {
                    _world.needs_update(chunk_pos + shared::math::vec3::unit_x);
                }

                if (local.y == 0) {
                    _world.needs_update(chunk_pos - shared::math::vec3::unit_y);
                }

                if (local.y == bound) {
                    _world.needs_update(chunk_pos + shared::math::vec3::unit_y);
                }

                if (local.z == 0) {
                    _world.needs_update(chunk_pos - shared::math::vec3::unit_z);
                }

                if (local.z == bound) {
                    _world.needs_update(chunk_pos + shared::math::vec3::unit_z);
                }
            }
        }
    }
}
}
