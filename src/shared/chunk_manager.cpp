#include "chunk_manager.hpp"

#include "ray.hpp"

namespace q {
namespace shared {
    chunk_manager::chunk_manager()
        : _chunks{}
    {
    }

    std::optional<std::reference_wrapper<chunk>> chunk_manager::chunk_at(
            const glm::ivec3& pos)
    {
        const auto& search = _chunks.find(pos);

        auto x = pos;

        if (search != _chunks.end()) {
            return search->second;
        }

        return {};
    }

    std::optional<std::reference_wrapper<chunk::block_type>> chunk_manager::block_at(
            const glm::ivec3& world_pos)
    {
        const glm::ivec3 pos =
            glm::floor(glm::vec3{world_pos} / static_cast<float>(chunk::size));

        auto maybe_chunk = chunk_at(pos);

        if (maybe_chunk.has_value()) {
            auto& chunk = maybe_chunk.value().get();

            return chunk.block_at(world_pos - pos * chunk::size);
        }

        return {};
    }

    std::optional<chunk_manager::block_hit> chunk_manager::cast_ray(
            const glm::vec3& pos, const glm::vec3& dir, const float& max,
            const bool& step_back)
    {
        ray raycast{pos, dir, max};

        while (!raycast.is_complete()) {
            const auto& block_pos = glm::floor(raycast.step_forward());
            auto maybe_block = block_at(block_pos);

            if (maybe_block.has_value()) {
                auto& block = maybe_block->get();

                if (block) {
                    if (step_back) {
                        const auto& block_pos_back = glm::floor(raycast.step_backward());
                        auto maybe_block_back = block_at(block_pos_back);

                        if (maybe_block_back.has_value()) {
                            return chunk_manager::block_hit{
                                maybe_block_back->get(), block_pos
                            };
                        }
                    } else {
                        return chunk_manager::block_hit{block, block_pos};
                    }
                }
            }
        }

        return {};
    }
}
}
