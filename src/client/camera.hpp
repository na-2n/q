#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace q {
namespace client {
    class camera {
    public:
        camera(const glm::vec3& position, const float& aspect_ratio, const float& fov = 45);

        void move(const glm::vec3& offset);

        void rotate(const glm::vec2& offset);

        inline glm::mat4 view_matrix() const
        {
            return glm::lookAt(_position, _position + _forward, _up);
        }

        inline glm::mat4 projection_matrix() const
        {
            return glm::perspective(glm::radians(_fov), _aspect_ratio, 0.01f, 100.0f);
        }

        inline void set_fov(const float& fov)
        {
            _fov = fov;
        }

        inline void set_aspect_ratio(const float& aspect_ratio)
        {
            _aspect_ratio = aspect_ratio;
        }

    private:
        glm::vec3 _position;
        glm::vec2 _rotation;
        glm::vec3 _up;
        glm::vec3 _forward;
        glm::vec3 _right;
        glm::vec3 _world_up;
        glm::vec3 _world_forward;

        float _fov;
        float _aspect_ratio;

        void _update_vectors();
    };
}
}
