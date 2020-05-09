#include "chunk_manager.hpp"

namespace q {
namespace shared {
    std::optional<std::reference_wrapper<chunk>> chunk_manager::chunk_at(const glm::ivec3& pos) const
    {
        const auto& search = _chunks.find(pos);

        if (search != _chunks.end()) {
            return search->second;
        }

        return {};
    }

    chunk::block_type chunk_manager::block_at(const glm::ivec3& world_pos) const
    {
        const auto& pos = world_pos / chunk::size;

        const auto& maybe_chunk = chunk_at(pos);

        if (maybe_chunk.has_value()) {
            const auto& chunk = maybe_chunk.value().get();

            return chunk.block_at(world_pos - pos * chunk::size);
        }

        return 0;
    }
}
}
