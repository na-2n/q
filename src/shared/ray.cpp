#include "ray.hpp"

namespace q {
namespace shared {
    ray::ray(const glm::vec3& pos, const glm::vec3& dir, const float& max_distance, const unsigned int& samples)
        : _ray_dir{glm::normalize(dir)}, _ray_pos{pos}, _max_distance{max_distance}, _samples{samples}, _is_complete{false}
    {
    }

    glm::vec3 ray::step_cast()
    {
        if (_max_distance <= 0) {
            return _ray_pos;
        }

        float offset = INFINITY;

        for (auto i = 0; i < 3; i++) {
            float unit_dist = glm::fract(_ray_pos[i]);

            if (_ray_dir[i] < 0) {
                unit_dist = 1 - unit_dist;
            }

            if (unit_dist == 0) {
                unit_dist = 1;
            }

            if (unit_dist < offset) {
                offset = unit_dist;
            }
        }

        if (_samples > 1) {
            offset /= _samples;
        }

        _max_distance -= offset;

        if (_max_distance > 0) {
            _ray_pos += _ray_dir * offset;
        } else {
            _is_complete = true;
        }

        return _ray_pos;
    }
}
}
