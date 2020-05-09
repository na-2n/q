#include "mesh_builder.hpp"

namespace q {
namespace client {
    mesh_builder::mesh_builder()
        : _indices_offset{0}
    {
    }

    void mesh_builder::add_face(const std::vector<glm::vec3>& face_verts, const glm::vec3& face_pos)
    {
        const int cube_face_verts = 4;

        for (auto i = 0; i < cube_face_verts; i++) {
            const auto& vert = face_verts[i];
            const auto pos = vert + face_pos;

            _vertices.push_back(pos.x);
            _vertices.push_back(pos.y);
            _vertices.push_back(pos.z);
        }

        _indices.push_back(_indices_offset);
        _indices.push_back(_indices_offset + 1);
        _indices.push_back(_indices_offset + 2);

        _indices.push_back(_indices_offset + 2);
        _indices.push_back(_indices_offset + 3);
        _indices.push_back(_indices_offset);

        _indices_offset += 4;
    }

    unsigned int mesh_builder::build(gl::vertex_buffer_object& vbo, gl::element_buffer_object& ebo)
    {
        vbo.set_data(_vertices);
        ebo.set_data(_indices);

        return _indices.size();
    }
}
}
