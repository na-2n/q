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

        void make_current() const;

        void run_loop();

    private:
        std::shared_ptr<camera> _cam;
        game_renderer _renderer;
        input_manager _input;

        GLFWwindow* _win;
        double _last_frame;
        int _win_width;
        int _win_height;

        void _check_win_size();
    };
}
}
