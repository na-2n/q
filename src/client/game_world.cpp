#include "game_world.hpp"

namespace q {
namespace client {
    game_world::game_world()
        : _chunk_updates{}, _chunk_mgr{}, _mesher{_chunk_mgr}
    {
        new_chunk(glm::vec3{0, 0, 0});
        new_chunk(glm::vec3{1, 0, 0});
        new_chunk(glm::vec3{0, -1, 0});
        new_chunk(glm::vec3{0, 0, 1});
    }

    void game_world::check_chunks()
    {
        while (!_chunk_updates.empty()) {
            const auto& pos = _chunk_updates.back();

            _mesher.gen_mesh(pos);

            _chunk_updates.pop_back();
        }
    }
}
}
