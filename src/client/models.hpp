#pragma once

#include <vector>

#include <glm/glm.hpp>

namespace q {
namespace client {
namespace models {
    const std::vector<glm::vec3> block_left{
        {0, 1, 1}, {-1, 0, 0},
        {0, 1, 0}, {-1, 0, 0},
        {0, 0, 0}, {-1, 0, 0},
        {0, 0, 1}, {-1, 0, 0},
    };

    const std::vector<glm::vec3> block_right{
        {1, 1, 0}, {1, 0, 0},
        {1, 1, 1}, {1, 0, 0},
        {1, 0, 1}, {1, 0, 0},
        {1, 0, 0}, {1, 0, 0},
    };

    const std::vector<glm::vec3> half_block_left{
        {0, 0.5f, 1}, {-1, 0, 0},
        {0, 0.5f, 0}, {-1, 0, 0},
        {0,    0, 0}, {-1, 0, 0},
        {0,    0, 1}, {-1, 0, 0},
    };

    const std::vector<glm::vec3> block_front{
        {1, 1, 1}, {0, 0, 1},
        {0, 1, 1}, {0, 0, 1},
        {0, 0, 1}, {0, 0, 1},
        {1, 0, 1}, {0, 0, 1},
    };

    const std::vector<glm::vec3> block_back{
        {0, 1, 0}, {0, 0, -1},
        {1, 1, 0}, {0, 0, -1},
        {1, 0, 0}, {0, 0, -1},
        {0, 0, 0}, {0, 0, -1},
    };

    const std::vector<glm::vec3> block_top{
        {1, 1, 0}, {0, 1, 0},
        {0, 1, 0}, {0, 1, 0},
        {0, 1, 1}, {0, 1, 0},
        {1, 1, 1}, {0, 1, 0},
    };

    const std::vector<glm::vec3> block_bottom{
        {0, 0, 0}, {0, -1, 0},
        {1, 0, 0}, {0, -1, 0},
        {1, 0, 1}, {0, -1, 0},
        {0, 0, 1}, {0, -1, 0},
    };
}
}
}
