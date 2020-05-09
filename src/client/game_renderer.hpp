#pragma once

#include <memory>

#include "gl/buffer_object.hpp"
#include "gl/vertex_array_object.hpp"
#include "gl/shader_program.hpp"

#include "camera.hpp"
#include "mesh.hpp"

namespace q {
namespace client {
    class game_renderer {
    public:
        game_renderer();

        void draw(const double& delta_time, camera& cam);

    private:
        gl::shader_program _shader;
        mesh _mesh;
    };
}
}
