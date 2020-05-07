#pragma once

#include <glad/glad.h>

namespace q {
namespace gl {
    class vertex_attribute {
    public:
        struct pointer_base {
            const int count;
            const int size;
            const GLenum gl_type;

            constexpr pointer_base(const int& count_, const int& size_, const GLenum& gl_type_);
        };

        template<typename T, int Count, int Size = sizeof(T)>
        struct pointer : public pointer_base {
            using type = T;

            constexpr pointer();
        };

        vertex_attribute(const unsigned int& index, const int& size, const GLenum& type,
                         const int& stride, const void*& ptr, const bool& normalized = false);

        void enable() const;

        void disable() const;

    private:
        unsigned int _index;
    };
}
}

#include "vertex_attribute.inl"
