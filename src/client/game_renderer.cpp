#include "game_renderer.hpp"

#include <vector>

#include "gl/shader.hpp"

namespace {
    const std::vector<float> triangle{
        -0.5f, -0.5f, 0.5f,
         0.5f, -0.5f, 0.5f,
         0.0f,  0.5f, 0.5f
    };

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
        : _shader{}, _vbo{}, _vao{}, _ebo{}
    {
        gl::vertex_shader vert{vert_str};
        gl::fragment_shader frag{frag_str};

        vert.build();
        frag.build();

        _shader.attach(vert);
        _shader.attach(frag);
        _shader.build();

        _vbo.bind();
        _vbo.set_data(::triangle);

        _vao.bind();
        _vao.set_attributes(
            std::vector<gl::vertex_attribute::pointer_base>{
                gl::vertex_attribute::pointer<float, 3>{}
            }
        );
    }

    void game_renderer::draw(const double& delta_time)
    {
        _shader.set_uniform("view_mat", _cam->view_matrix());
        _shader.set_uniform("proj_mat", _cam->projection_matrix());

        _shader.bind();
        _vao.bind();

        glDrawArrays(GL_TRIANGLES, 0, 3);

        _vao.unbind();
    }

    void game_renderer::set_camera(const std::shared_ptr<camera>& cam)
    {
        _cam = cam;
    }
}
}
