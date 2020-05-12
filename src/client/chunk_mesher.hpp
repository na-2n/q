#pragma once

#include <unordered_map>
#include <functional>

#include <glm/glm.hpp>
#include <glm/gtx/hash.hpp>

#include "mesh.hpp"

#include "shared/chunk.hpp"
#include "shared/chunk_manager.hpp"
#include "gl/shader_program.hpp"

namespace q {
namespace client {
    class chunk_mesher {
    public:
        chunk_mesher(shared::chunk_manager& chunk_mgr);

        void gen_with_neighbors(const glm::ivec3& pos);

        void gen_mesh(const glm::ivec3& pos);

        void draw_chunks(gl::shader_program& shader);

        inline const mesh& mesh_at(const glm::ivec3& pos) const
        {
            return _meshes.at(pos);
        }

    private:
        using mesh_map = std::unordered_map<glm::ivec3, mesh>;

        shared::chunk_manager& _chunk_mgr;
        mesh_map _meshes;

        inline bool _should_render_face(const glm::ivec3& world_pos)
        {
            const auto& block = _chunk_mgr.block_at(world_pos);

            return !block.has_value() || !*block;
        }
    };
}
}
