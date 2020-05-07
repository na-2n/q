namespace q {
namespace gl {
namespace util {
    template<>
    constexpr GLenum get_gl_type<char>()
    {
        return GL_BYTE;
    }

    template<>
    constexpr GLenum get_gl_type<unsigned char>()
    {
        return GL_UNSIGNED_BYTE;
    }

    template<>
    constexpr GLenum get_gl_type<short>()
    {
        return GL_SHORT;
    }

    template<>
    constexpr GLenum get_gl_type<unsigned short>()
    {
        return GL_UNSIGNED_SHORT;
    }

    template<>
    constexpr GLenum get_gl_type<int>()
    {
        return GL_INT;
    }

    template<>
    constexpr GLenum get_gl_type<unsigned int>()
    {
        return GL_UNSIGNED_INT;
    }

    template<>
    constexpr GLenum get_gl_type<float>()
    {
        return GL_FLOAT;
    }

    template<>
    constexpr GLenum get_gl_type<double>()
    {
        return GL_DOUBLE;
    }
}
}
}
