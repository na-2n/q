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

        template<GLenum Usage = GL_STATIC_DRAW>
        inline void set_data(const void* data, const unsigned int& size) const
        {
            glBufferData(Target, size, data, Usage);
        }

        template<GLenum Usage = GL_STATIC_DRAW>
        inline void set_data(const void* data) const
        {
            set_data(data, sizeof(data));
        }

        template<typename T, GLenum Usage = GL_STATIC_DRAW>
        inline void set_data(const std::vector<T>& vec, const unsigned int& size) const
        {
            glBufferData(Target, size, vec.data(), Usage);
        }

        template<typename T, GLenum Usage = GL_STATIC_DRAW>
        inline void set_data(const std::vector<T>& vec) const
        {
            set_data(vec, vec.size() * sizeof(T));
        }

        inline void bind() const
        {
            glBindBuffer(Target, _handle);
        }

        inline static void unbind()
        {
            glBindBuffer(Target, 0);
        }

    private:
        unsigned int _handle;
    };

    using vertex_buffer_object = buffer_object<GL_ARRAY_BUFFER>;
    using element_buffer_object = buffer_object<GL_ELEMENT_ARRAY_BUFFER>;
}
}

#include "buffer_object.inl"
