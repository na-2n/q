#pragma once

#include <array>
#include <glm/glm.hpp>

namespace q {
namespace shared {
    class chunk {
    public:
        using block_type = unsigned short;

        static const int size = 255;

        const block_type& block_at(const glm::ivec3& pos) const;

    private:
        std::array<block_type, size * size * size> _blocks;
    };
}
}
