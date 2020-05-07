#pragma once

#include <string>

#include <glad/glad.h>

namespace q {
namespace gl {
    template<GLenum Type>
    class shader {
    public:
        static const GLenum type = Type;

        shader(const std::string& source);

        ~shader();

        void attach_to(const unsigned int& program) const;

        void detach_from(const unsigned int& program) const;

        void build();

        const bool& is_built() const;

    private:
        unsigned int _handle;
        bool _built;
    };

    using vertex_shader = shader<GL_VERTEX_SHADER>;
    using fragment_shader = shader<GL_FRAGMENT_SHADER>;
    using geometry_shader = shader<GL_GEOMETRY_SHADER>;
    using compute_shader = shader<GL_COMPUTE_SHADER>;
}
}

#include "shader.inl"
