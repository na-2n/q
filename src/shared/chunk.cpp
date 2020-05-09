#include "chunk.hpp"

namespace q {
namespace shared {
    chunk::chunk(const chunk::block_type& initial)
        : _blocks{}
    {
        if (initial) {
            for (auto i = 0; i < chunk::size_cubic; i++) {
                _blocks[i] = initial;
            }
        }
    }

    chunk::block_type& chunk::block_at(const glm::ivec3& pos)
    {
        return _blocks[pos.x + pos.y * chunk::size_squared + pos.z * chunk::size];
    }
}
}
