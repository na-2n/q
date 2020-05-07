#pragma once

#include <glm/glm.hpp>

namespace q {
namespace client {
    class camera {
    public:
        camera(const glm::vec3& position, const float& aspect_ratio, const float& fov = 45);

        ~camera();

        void move(const glm::vec3& offset);

        void rotate(const glm::vec2& offset);

        glm::mat4 view_matrix() const;

        glm::mat4 projection_matrix() const;

        void set_fov(const float& fov);

        void set_aspect_ratio(const float& aspect_ratio);

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
