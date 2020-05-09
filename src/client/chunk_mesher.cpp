#include "chunk_mesher.hpp"

namespace q {
namespace client {
    chunk_mesher::chunk_mesher(const shared::chunk_manager& chunk_mgr)
        : _chunk_mgr{chunk_mgr}
    {
    }

    void chunk_mesher::gen_mesh(const glm::ivec3& pos)
    {
        const auto& maybe_chunk = _chunk_mgr.chunk_at(pos);

        if (!maybe_chunk.has_value()) {
            return;
        }

        std::vector<std::reference_wrapper<glm::ivec3>> vertices;
        std::vector<unsigned int> indices;
        unsigned int indices_len = 0;

        const auto& chunk = maybe_chunk.value().get();

        for (auto x = 0; x < shared::chunk::size; x++) {
            for (auto y = 0; y < shared::chunk::size; y++) {
                for (auto z = 0; z < shared::chunk::size; z++) {
                    const auto& block = chunk.block_at(glm::vec3{x, y, z});

                    if (block) {
                    }
                }
            }
        }

        const auto& search = _meshes.find(pos);

        if (search != _meshes.end()) {
            const auto& m = search->second.get();
        }
    }
}
}
