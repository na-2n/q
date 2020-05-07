#include "vertex_array_object.hpp"

namespace q {
namespace gl {
    vertex_array_object::vertex_array_object()
        : _attrs{}
    {
        glGenVertexArrays(1, &_handle);
    }

    vertex_array_object::~vertex_array_object()
    {
        glDeleteVertexArrays(1, &_handle);
    }

    void vertex_array_object::set_attributes(const std::vector<vertex_attribute::pointer_base>& attrPtrs)
    {
        int stride = 0;
        int accum = 0;

        _attrs.reserve(attrPtrs.size());

        for (const auto& ptr : attrPtrs) {
            stride += ptr.count * ptr.size;
        }

        for (int i = 0; i < attrPtrs.size(); i++) {
            const auto& ptr = attrPtrs[i];
            const void* start = reinterpret_cast<void*>(accum);

            // TODO: maybe use lookup table for this ?
            accum += ptr.count * ptr.size;

            _attrs.push_back({static_cast<unsigned int>(i), ptr.count, ptr.gl_type, stride, start});
        }

        for (const auto& attr : _attrs) {
            attr.enable();
        }
    }

    const vertex_attribute& vertex_array_object::attribute_at(const int& index) const
    {
        return _attrs[index];
    }

    void vertex_array_object::bind() const
    {
        glBindVertexArray(_handle);
    }

    void vertex_array_object::unbind()
    {
        glBindVertexArray(0);
    }
}
}
