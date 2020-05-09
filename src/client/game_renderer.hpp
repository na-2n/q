#pragma once

#include <memory>

#include "gl/buffer_object.hpp"
#include "gl/vertex_array_object.hpp"
#include "gl/shader_program.hpp"
#include "shared/chunk_manager.hpp"

#include "camera.hpp"
#include "mesh.hpp"
#include "chunk_mesher.hpp"

namespace q {
namespace client {
    class game_renderer {
    public:
        game_renderer();

        void draw(const double& delta_time, camera& cam);

    private:
        shared::chunk_manager _chunk_mgr;
        gl::shader_program _shader;
        mesh _mesh;
        chunk_mesher _mesher;
    };
}
}
