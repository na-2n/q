#pragma once

#include <vector>

#include <glad/glad.h>

#include "vertex_attribute.hpp"

namespace q {
namespace gl {
    class vertex_array_object {
    public:
        vertex_array_object();

        ~vertex_array_object();

        void set_attributes(const std::vector<vertex_attribute::pointer_base>& attrPtrs);

        const vertex_attribute& attribute_at(const int& index) const;

        void bind() const;

        static void unbind();

    private:
        unsigned int _handle;
        std::vector<vertex_attribute> _attrs;
    };
}
}
