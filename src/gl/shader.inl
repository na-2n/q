#include <stdexcept>
#include <vector>
#include <string>

namespace q {
namespace gl {
    template<GLenum Type>
    shader<Type>::shader(const std::string& source)
        : _handle{glCreateShader(Type)}
    {
        const auto& str = source.c_str();
        const auto& len = static_cast<int>(source.size());

        glShaderSource(_handle, 1, &str, &len);
    }

    template<GLenum Type>
    shader<Type>::~shader()
    {
        glDeleteShader(_handle);
    }

    template<GLenum Type>
    void shader<Type>::build()
    {
        glCompileShader(_handle);

        int success;
        glGetShaderiv(_handle, GL_COMPILE_STATUS, &success);

        if (!success) {
            int log_size;
            glGetShaderiv(_handle, GL_INFO_LOG_LENGTH, &log_size);

            std::vector<char> log(log_size);

            int actual_size;
            glGetShaderInfoLog(_handle, log_size, &actual_size, log.data());

            if (actual_size < log_size)
            {
                log.resize(actual_size);
            }

            throw std::runtime_error{std::string{log.begin(), log.end()}};
        }

        _built = true;
    }
}
}
