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

    template<GLenum Target>
    template<GLenum Usage>
    void buffer_object<Target>::set_data(const void* data, const unsigned int& size)
    {
        glBufferData(Target, size, data, Usage);
    }

    template<GLenum Target>
    template<typename T, GLenum Usage>
    void buffer_object<Target>::set_data(const std::vector<T>& vec, const unsigned int& size)
    {
        glBufferData(Target, size, vec.data(), Usage);
    }

    template<GLenum Target>
    void buffer_object<Target>::bind() const
    {
        glBindBuffer(Target, _handle);
    }

    template<GLenum Target>
    void buffer_object<Target>::unbind()
    {
        glBindBuffer(Target, 0);
    }
}
}
