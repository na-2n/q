#pragma once

#include <vector>

#include <glm/glm.hpp>

#include "gl/buffer_object.hpp"
#include "gl/vertex_array_object.hpp"
#include "gl/vertex_attribute.hpp"

#include "mesh_builder.hpp"

namespace q {
namespace client {
    class mesh {
    public:
        mesh();

        void load_data(mesh_builder& builder);

        void load_data(const std::vector<glm::vec3>& vertices,
                       const std::vector<unsigned int>& indices);

        void draw();

        inline bool has_data() const
        {
            return _indices > 0;
        }

    private:
        gl::vertex_buffer_object _vbo;
        gl::vertex_array_object _vao;
        gl::element_buffer_object _ebo;
        unsigned int _indices;
    };
}
}
