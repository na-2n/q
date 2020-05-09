#include "chunk_manager.hpp"

#include <cmath>

namespace q {
namespace shared {
    chunk_manager::chunk_manager()
        : _chunks{}
    {
    }

    std::optional<std::reference_wrapper<chunk>> chunk_manager::chunk_at(const glm::ivec3& pos)
    {
        const auto& search = _chunks.find(pos);

        auto x = pos;

        if (search != _chunks.end()) {
            return search->second;
        }

        return {};
    }

    chunk::block_type chunk_manager::block_at(const glm::ivec3& world_pos)
    {
        const auto size_f = static_cast<float>(chunk::size);
        const glm::ivec3 pos{
            std::floor(world_pos.x / size_f),
            std::floor(world_pos.y / size_f),
            std::floor(world_pos.z / size_f)
        };

        auto maybe_chunk = chunk_at(pos);

        if (maybe_chunk.has_value()) {
            auto& chunk = maybe_chunk.value().get();

            return chunk.block_at(world_pos - pos * chunk::size);
        }

        return 0;
    }
}
}
