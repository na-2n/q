#pragma once

#include <memory>
#include <map>

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "camera.hpp"

namespace q {
namespace client {
    class input_manager {
    public:
        input_manager(GLFWwindow*& win);

        void process(const double& delta_time, camera& cam);

        void process_keyboard(const double& delta_time, camera& cam);

        void process_cursor(const double& delta_time, camera& cam);

        inline void set_cursor_visible(const bool& state)
        {
            glfwSetInputMode(_win, GLFW_CURSOR, state ? GLFW_CURSOR_NORMAL : GLFW_CURSOR_HIDDEN);
        }

    private:
        std::map<unsigned int, bool> _key_states;
        GLFWwindow*& _win;
        float _sensitivity;
        bool _wireframe;

        inline bool _should_handle(const int& key)
        {
            const auto& search = _key_states.find(key);
            const auto& state = _key_state(key);

            if (search != _key_states.end()) {
                const auto& last_state = search->second;

                if (!last_state && state == GLFW_PRESS) {
                    return true;
                }

                if (last_state && state == GLFW_RELEASE) {
                    _key_states[key] = false;
                }

                return false;
            }

            return _key_states[key] = state == GLFW_PRESS;
        }

        inline bool _is_focused()
        {
            return static_cast<bool>(glfwGetWindowAttrib(_win, GLFW_FOCUSED));
        }

        inline int _key_state(const int& key)
        {
            return glfwGetKey(_win, key);
        }

        inline bool _is_pressed(const int& key)
        {
            return _key_state(key) == GLFW_PRESS;
        }
    };
}
}
