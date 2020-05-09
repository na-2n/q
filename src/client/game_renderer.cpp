#include "game_renderer.hpp"

#include <vector>

#include "gl/shader.hpp"
#include "shared/chunk_manager.hpp"

#include "models.hpp"
#include "mesh_builder.hpp"
#include "chunk_mesher.hpp"

namespace {
    const std::string vert_str{
        R"GLSL(
        #version 430
        in vec3 vert_pos;

        uniform mat4 proj_mat;
        uniform mat4 view_mat;

        void main()
        {
            gl_Position = proj_mat * view_mat * vec4(vert_pos, 1);
        }
        )GLSL"
    };

    const std::string frag_str{
        R"GLSL(
        #version 430
        out vec4 frag_color;

        void main()
        {
            frag_color = vec4(1, 1, 1, 1);
        }
        )GLSL"
    };
}

namespace q {
namespace client {
    game_renderer::game_renderer()
        : _shader{}, _mesh{}, _chunk_mgr{}, _mesher{_chunk_mgr}
    {
        gl::vertex_shader vert{::vert_str};
        gl::fragment_shader frag{::frag_str};

        vert.build();
        frag.build();

        _shader.attach(vert);
        _shader.attach(frag);
        _shader.build();

        _chunk_mgr.add_chunk(glm::ivec3{0});
        _chunk_mgr.add_chunk(glm::ivec3{1, 0, 0});
        _chunk_mgr.add_chunk(glm::ivec3{0, -1, 0});
        _chunk_mgr.add_chunk(glm::ivec3{0, 0, 1});

        _mesher.gen_mesh(glm::ivec3{0});

        _mesh = _mesher.mesh_at(glm::ivec3{0});
    }

    void game_renderer::draw(const double& delta_time, camera& cam)
    {
        _shader.set_uniform("view_mat", cam.view_matrix());
        _shader.set_uniform("proj_mat", cam.projection_matrix());

        _shader.bind();

        if (_mesh.has_data()) {
            _mesh.draw();
        }
    }
}
}
