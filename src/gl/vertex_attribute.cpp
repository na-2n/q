#include "vertex_attribute.hpp"

namespace q {
namespace gl {
    vertex_attribute::vertex_attribute(const unsigned int& index, const int& size,
                                       const GLenum& type, const int& stride,
                                       const void*& ptr, const bool& normalized)
        : _index{index}
    {
        glVertexAttribPointer(index, size, type, normalized, stride, ptr);
    }

    void vertex_attribute::enable() const
    {
        glEnableVertexAttribArray(_index);
    }

    void vertex_attribute::disable() const
    {
        glDisableVertexAttribArray(_index);
    }
}
}
