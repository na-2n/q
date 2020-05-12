#pragma once

#include <cmath>

#include <glm/glm.hpp>

namespace q {
namespace shared {
    class ray {
    public:
        ray(const glm::vec3& pos, const glm::vec3& dir,
            const float& max_distance = INFINITY, const unsigned int& samples = 1);

        glm::vec3 step_cast();

        inline const bool& is_complete() const
        {
            return _is_complete;
        }

        inline const glm::vec3& position() const
        {
            return _ray_pos;
        }

    private:
        glm::vec3 _ray_dir;
        glm::vec3 _ray_pos;
        float _max_distance;
        unsigned int _samples;
        bool _is_complete;
    };
}
}
