#include "game_renderer.hpp"

#include <string>

#include "gl/shader.hpp"

namespace {
    const std::string vert_str{
        R"GLSL(
        #version 430
        in vec3 vert_pos;
        in vec3 vert_normal;

        out vec3 frag_pos;
        out vec3 frag_normal;

        uniform mat4 proj_mat;
        uniform mat4 view_mat;
        uniform vec3 chunk_pos;

        void main()
        {
            frag_pos = vert_pos + chunk_pos;
            frag_normal = vert_normal + chunk_pos;

            gl_Position = proj_mat * view_mat * vec4(frag_pos, 1);
        }
        )GLSL"
    };

    const std::string frag_str{
        R"GLSL(
        #version 430
        in vec3 frag_pos;
        in vec3 frag_normal;

        out vec4 frag_color;

        uniform vec3 light_pos = vec3(32, 32, 32);
        uniform vec3 light_color = vec3(1, 1, 1);

        void main()
        {
            vec3 color = vec3(1, 1, 1);
            vec3 norm = normalize(frag_normal);
            vec3 light_dir = normalize(light_pos - frag_pos);

            float diffuse_factor = max(dot(norm, light_dir), 0);
            vec3 diffuse = diffuse_factor * light_color;

            frag_color = vec4(diffuse * color, 1);
        }
        )GLSL"
    };
}

namespace q {
namespace client {
    game_renderer::game_renderer(game_world& world)
        : _shader{}, _world{world}
    {
        gl::vertex_shader vert{::vert_str};
        gl::fragment_shader frag{::frag_str};

        vert.build();
        frag.build();

        _shader.attach(vert);
        _shader.attach(frag);
        _shader.build();
    }

    void game_renderer::draw(const double& delta_time, camera& cam)
    {
        _world.check_chunks();

        _shader.bind();

        _shader.set_uniform("view_mat", cam.view_matrix());
        _shader.set_uniform("proj_mat", cam.projection_matrix());

        _world.draw(_shader);
    }
}
}
