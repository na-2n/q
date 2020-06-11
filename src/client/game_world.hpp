#pragma once

#include <vector>

#include <glm/glm.hpp>

#include "gl/shader_program.hpp"
#include "shared/chunk_manager.hpp"

#include "chunk_mesher.hpp"
#include "camera.hpp"

namespace q {
namespace client {
    class game_world {
    public:
        game_world();

        void check_chunks();

        void update_block(const glm::ivec3& pos);

        inline void draw(gl::shader_program& shader)
        {
            _mesher.draw_chunks(shader);
        }

        inline void needs_update(const glm::ivec3& pos)
        {
            //if (_chunk_mgr.chunk_exists(pos)) {
            _chunk_updates.push_back(pos);
            //}
        }

        inline void new_chunk(const glm::ivec3& pos)
        {
            _chunk_mgr.add_chunk(pos);

            needs_update(pos);
        }

        inline shared::chunk_manager& chunk_mgr()
        {
            return _chunk_mgr;
        }

    private:
        std::vector<glm::ivec3> _chunk_updates;
        shared::chunk_manager _chunk_mgr;
        chunk_mesher _mesher;
    };
}
}
