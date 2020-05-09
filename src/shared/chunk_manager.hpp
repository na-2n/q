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
        std::optional<std::reference_wrapper<chunk>> chunk_at(const glm::ivec3& pos) const;

        chunk::block_type block_at(const glm::ivec3& world_pos) const;

    private:
        using chunk_map = std::unordered_map<glm::ivec3, std::reference_wrapper<chunk>>;

        chunk_map _chunks;
    };
}
}
