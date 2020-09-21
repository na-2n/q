#include "game_renderer.hpp"

namespace q {
namespace client {
    game_renderer::game_renderer(game_world& world)
        : _shader{}, _world{world}, _loader{}
    {
        auto vert = _loader.load_vertex_shader("chunk.vert");
        auto frag = _loader.load_fragment_shader("chunk.frag");

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
