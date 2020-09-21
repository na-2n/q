#pragma once

#include <memory>

#include "gl/buffer_object.hpp"
#include "gl/vertex_array_object.hpp"
#include "gl/shader_program.hpp"

#include "asset_loader.hpp"
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
        asset_loader _loader;
        gl::shader_program _shader;
    };
}
}
