#pragma once

#include <vector>

#include <glad/glad.h>

namespace q {
namespace gl {
    template<GLenum Target>
    class buffer_object {
    public:
        static const GLenum target = Target;

        buffer_object();

        ~buffer_object();

        template<typename T, GLenum Usage = GL_STATIC_DRAW>
        void set_data(const std::vector<T>& vec, const unsigned int& size);

        template<typename T, GLenum Usage = GL_STATIC_DRAW>
        inline void set_data(const std::vector<T>& vec)
        {
            set_data(vec, vec.size() * sizeof(T));
        }

        void bind() const;

        static void unbind();

    private:
        unsigned int _handle;
    };

    using vertex_buffer_object = buffer_object<GL_ARRAY_BUFFER>;
    using element_buffer_object = buffer_object<GL_ELEMENT_ARRAY_BUFFER>;
}
}

#include "buffer_object.inl"
