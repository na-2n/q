#pragma once

#include <memory>

#include "gl/buffer_object.hpp"
#include "gl/vertex_array_object.hpp"
#include "gl/shader_program.hpp"

#include "game_world.hpp"
#include "camera.hpp"

namespace q {
namespace client {
    class game_renderer {
    public:
        game_renderer(game_world& world);

        void draw(const double& delta_time, camera& cam);

    private:
        game_world& _world;
        gl::shader_program _shader;
    };
}
}
