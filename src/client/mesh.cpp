#include "mesh.hpp"

namespace q {
namespace client {
    mesh::mesh()
        : _vbo{}, _vao{}, _ebo{}, _indices{0}
    {
        _vbo.bind();
        _vao.bind();

        _vao.set_attributes(
            std::vector<gl::vertex_attribute::pointer_base>{
                gl::vertex_attribute::pointer<float, 3>{}, // position
                gl::vertex_attribute::pointer<float, 3>{}, // normal
            }
        );
    }

    mesh::mesh(mesh_builder& builder)
        : mesh::mesh{}
    {
        load_data(builder);
    }

    void mesh::load_data(mesh_builder& builder)
    {
        _vbo.bind();
        _ebo.bind();

        _indices = builder.build(_vbo, _ebo);
    }

    void mesh::load_data(const std::vector<glm::vec3>& vertices,
                         const std::vector<unsigned int>& indices)
    {
        std::vector<float> actual_verts(vertices.size() * 3);

        for (const auto& vertex : vertices) {
            actual_verts.push_back(vertex.x);
            actual_verts.push_back(vertex.y);
            actual_verts.push_back(vertex.z);
        }

        _vbo.set_data(actual_verts);
        _ebo.set_data(indices);

        _indices = indices.size();
    }

    void mesh::draw() const
    {
        _vbo.bind();
        _vao.bind();
        _ebo.bind();

        glDrawElements(GL_TRIANGLES, _indices, GL_UNSIGNED_INT, 0);

        _ebo.unbind();
        _vao.unbind();
        _vbo.unbind();
    }
}
}
