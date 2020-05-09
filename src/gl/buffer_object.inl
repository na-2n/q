namespace q {
namespace gl {
    template<GLenum Target>
    buffer_object<Target>::buffer_object()
    {
        glGenBuffers(1, &_handle);
    }

    template<GLenum Target>
    buffer_object<Target>::~buffer_object()
    {
        glDeleteBuffers(1, &_handle);
    }
}
}
