#pragma once

#include <glm/glm.hpp>

namespace q {
namespace shared {
namespace math {
    inline int mod_sign(const int& a, const int& b)
    {
        return (b + (a % b)) % b;
    }

namespace vec3 {
    const glm::ivec3 unit_x{1, 0, 0};
    const glm::ivec3 unit_y{0, 1, 0};
    const glm::ivec3 unit_z{0, 0, 1};
}
}
}
}
