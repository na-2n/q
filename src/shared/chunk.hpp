#pragma once

#include <array>
#include <glm/glm.hpp>

namespace q {
namespace shared {
    class chunk {
    public:
        using block_type = unsigned short;

        static const int size = 16;
        static constexpr int size_squared = size * size;
        static constexpr int size_cubic = size * size * size;

        chunk(const block_type& initial = 0);

        block_type& block_at(const glm::ivec3& pos);

    private:
        std::array<block_type, size * size * size> _blocks;
    };
}
}
