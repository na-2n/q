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
        struct block_hit {
            chunk::block_type& block;
            glm::ivec3 pos;
        };

        chunk_manager();

        inline void add_chunk(const glm::ivec3& pos)
        {
            _chunks.emplace(pos, 1);
        }

        inline bool chunk_exists(const glm::ivec3& pos)
        {
            const auto& search = _chunks.find(pos);

            return search != _chunks.end();
        }

        std::optional<std::reference_wrapper<chunk>> chunk_at(const glm::ivec3& pos);

        std::optional<std::reference_wrapper<chunk::block_type>> block_at(
                const glm::ivec3& world_pos);

        std::optional<block_hit> cast_ray(const glm::vec3& pos, const glm::vec3& dir,
                                          const float& max = 5,
                                          const bool& step_back = false);

    private:
        using chunk_map = std::unordered_map<glm::ivec3, chunk>;

        chunk_map _chunks;
    };
}
}
