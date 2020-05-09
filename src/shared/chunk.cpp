#include "chunk.hpp"

namespace q {
namespace shared {
    const chunk::block_type& chunk::block_at(const glm::ivec3& pos) const
    {
        return _blocks[pos.x + pos.y * chunk::size * chunk::size + pos.z * chunk::size];
    }
}
}
