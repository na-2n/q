#pragma once

#include <cmath>
#include <stack>

#include <glm/glm.hpp>

namespace q {
namespace shared {
    class ray {
    public:
        ray(const glm::vec3& pos, const glm::vec3& dir,
            const float& max_distance = INFINITY, const unsigned int& samples = 1);

        glm::vec3 step_forward();

        inline glm::vec3 step_backward()
        {
            const float& offset = _steps.top();

            if (_max_distance > 0) {
                _ray_pos -= _ray_dir * offset;
            }

            _max_distance -= offset;

            _steps.pop();

            return position();
        }

        inline const bool& is_complete() const
        {
            return _is_complete;
        }

        inline const glm::vec3& position() const
        {
            return _ray_pos;
        }

    private:
        std::stack<float> _steps;
        glm::vec3 _ray_dir;
        glm::vec3 _ray_pos;
        float _max_distance;
        unsigned int _samples;
        bool _is_complete;
    };
}
}
