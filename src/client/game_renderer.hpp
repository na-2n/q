#pragma once

#include <memory>

#include "camera.hpp"

#include "gl/buffer_object.hpp"
#include "gl/vertex_array_object.hpp"
#include "gl/shader_program.hpp"

namespace q {
namespace client {
    class game_renderer {
    public:
        game_renderer();

        void set_camera(const std::shared_ptr<camera>& cam);

        void draw(const double& delta_time);

    private:
        std::shared_ptr<camera> _cam;
        gl::shader_program _shader;
        gl::vertex_array_object _vao;
        gl::vertex_buffer_object _vbo;
        gl::element_buffer_object _ebo;
    };
}
}
