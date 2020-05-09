#pragma once

#include <vector>
#include <functional>

#include <glm/glm.hpp>

#include "gl/buffer_object.hpp"

namespace q {
namespace client {
    class mesh_builder {
    public:
        using vertex_type = float;

        mesh_builder();

        void add_face(const std::vector<glm::vec3>& face_verts, const glm::vec3& face_pos = glm::vec3{0});

        unsigned int build(gl::vertex_buffer_object& vbo, gl::element_buffer_object& ebo);

    private:
        std::vector<vertex_type> _vertices;
        std::vector<unsigned int> _indices;
        unsigned int _indices_offset;
    };
}
}
