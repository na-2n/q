#include "game_world.hpp"

#include "shared/math.hpp"

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

    void game_world::update_block(const glm::ivec3& pos)
    {
        constexpr int bound = shared::chunk::size - 1;

        const glm::ivec3 local = glm::mod(glm::vec3{pos}, glm::vec3{shared::chunk::size});
        const auto chunk_pos = (pos - local) / shared::chunk::size;

        needs_update(chunk_pos);

        if (local.x == 0) {
            needs_update(chunk_pos - shared::math::vec3::unit_x);
        }

        if (local.x == bound) {
            needs_update(chunk_pos + shared::math::vec3::unit_x);
        }

        if (local.y == 0) {
            needs_update(chunk_pos - shared::math::vec3::unit_y);
        }

        if (local.y == bound) {
            needs_update(chunk_pos + shared::math::vec3::unit_y);
        }

        if (local.z == 0) {
            needs_update(chunk_pos - shared::math::vec3::unit_z);
        }

        if (local.z == bound) {
            needs_update(chunk_pos + shared::math::vec3::unit_z);
        }
    }
}
}
