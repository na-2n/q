#include "chunk_mesher.hpp"

#include "mesh_builder.hpp"
#include "models.hpp"

namespace q {
namespace client {
    chunk_mesher::chunk_mesher(shared::chunk_manager& chunk_mgr)
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

        auto& chunk = maybe_chunk.value().get();

        mesh_builder mb;

        for (auto x = 0; x < shared::chunk::size; x++) {
            for (auto y = 0; y < shared::chunk::size; y++) {
                for (auto z = 0; z < shared::chunk::size; z++) {
                    const glm::ivec3 block_pos{x, y, z};
                    const auto& block = chunk.block_at(block_pos);

                    const auto world_pos = block_pos + pos * shared::chunk::size;

                    if (block) {
                        const glm::ivec3 unit_x{1, 0, 0};
                        const glm::ivec3 unit_y{0, 1, 0};
                        const glm::ivec3 unit_z{0, 0, 1};

                        // left
                        if (_should_render_face(world_pos - unit_x)) {
                            mb.add_face(models::block_left, block_pos);
                        }

                        // right
                        if (_should_render_face(world_pos + unit_x)) {
                            mb.add_face(models::block_right, block_pos);
                        }

                        // bottom
                        if (_should_render_face(world_pos - unit_y)) {
                            mb.add_face(models::block_bottom, block_pos);
                        }

                        // top
                        if (_should_render_face(world_pos + unit_y)) {
                            mb.add_face(models::block_top, block_pos);
                        }

                        // back
                        if (_should_render_face(world_pos - unit_z)) {
                            mb.add_face(models::block_back, block_pos);
                        }

                        // front
                        if (_should_render_face(world_pos + unit_z)) {
                            mb.add_face(models::block_front, block_pos);
                        }
                    }
                }
            }
        }

        const auto& search = _meshes.find(pos);

        if (search != _meshes.end()) {
            auto& m = search->second;

            m.load_data(mb);
        } else {
            _meshes.emplace(pos, mb);
        }
    }
}
}
