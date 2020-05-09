#pragma once

#include <unordered_map>
#include <functional>
#include <optional>
#include <memory>

#include <glm/glm.hpp>
#include <glm/gtx/hash.hpp>

#include "chunk.hpp"

namespace q {
namespace shared {
    class chunk_manager {
    public:
        chunk_manager();

        inline void add_chunk(const glm::ivec3& pos)
        {
            _chunks.emplace(pos, 1);
        }

        std::optional<std::reference_wrapper<chunk>> chunk_at(const glm::ivec3& pos);

        chunk::block_type block_at(const glm::ivec3& world_pos);

    private:
        using chunk_map = std::unordered_map<glm::ivec3, chunk>;

        chunk_map _chunks;
    };
}
}
