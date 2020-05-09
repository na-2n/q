#include "camera.hpp"

#include <cmath>

#include <glm/gtc/matrix_transform.hpp>

namespace q {
namespace client {
    camera::camera(const glm::vec3& position, const float& aspect_ratio, const float& fov)
        : _position{position},
          _rotation{/* yaw */ -90, /* pitch */ 0},
          _world_up{0, 1, 0},
          _fov{fov},
          _aspect_ratio{aspect_ratio}
    {
        _update_vectors();
    }

    void camera::move(const glm::vec3& offset)
    {
        if (offset.x) {
            _position += _right * offset.x;
        }

        if (offset.y) {
            _position += _world_up * offset.y;
        }

        if (offset.z) {
            _position += _world_forward * offset.z;
        }

        _update_vectors();
    }

    void camera::rotate(const glm::vec2& offset)
    {
        _rotation += offset;

        if (_rotation.y > 89) {
            _rotation.y = 89;
        }

        if (_rotation.y < -89) {
            _rotation.y = -89;
        }

        _update_vectors();
    }

    void camera::_update_vectors()
    {
        const glm::vec3 dir{
            std::cos(glm::radians(_rotation.x)) * std::cos(glm::radians(_rotation.y)),
            std::sin(glm::radians(_rotation.y)),
            std::sin(glm::radians(_rotation.x)) * std::cos(glm::radians(_rotation.y))
        };

        const glm::vec3 world_dir{
            std::cos(glm::radians(_rotation.x)),
            0,
            std::sin(glm::radians(_rotation.x))
        };

        _world_forward = glm::normalize(world_dir);
        _forward = glm::normalize(dir);
        _right = glm::normalize(glm::cross(_forward, _world_up));
        _up = glm::normalize(glm::cross(_right, _forward));
    }
}
}
