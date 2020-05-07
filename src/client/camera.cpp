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

    camera::~camera()
    {
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

    glm::mat4 camera::view_matrix() const
    {
        return glm::lookAt(_position, _position + _forward, _up);
    }

    glm::mat4 camera::projection_matrix() const
    {
        return glm::perspective(glm::radians(_fov), _aspect_ratio, 0.01f, 1000.0f);
    }

    void camera::set_fov(const float& fov)
    {
        _fov = fov;
    }

    void camera::set_aspect_ratio(const float& aspect_ratio)
    {
        _aspect_ratio = aspect_ratio;
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
