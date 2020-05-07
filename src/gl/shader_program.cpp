#include "shader_program.hpp"

#include <stdexcept>
#include <vector>
#include <string>

#include <glm/gtc/type_ptr.hpp>

namespace q {
namespace gl {
    shader_program::shader_program()
        : _handle{glCreateProgram()}
    {
    }

    shader_program::~shader_program()
    {
        glDeleteProgram(_handle);
    }

    void shader_program::set_uniform(const std::string& name, const glm::mat4& value)
    {
        glUniformMatrix4fv(_get_uniform_location(name), 1, false, glm::value_ptr(value));
    }

    void shader_program::set_uniform(const std::string& name, const glm::vec3& value)
    {
        glUniform3fv(_get_uniform_location(name), 1, glm::value_ptr(value));
    }

    const bool& shader_program::is_built() const
    {
        return _built;
    }

    void shader_program::build()
    {
        glLinkProgram(_handle);

        int success;
        glGetProgramiv(_handle, GL_LINK_STATUS, &success);

        if (!success) {
            int log_size;
            glGetProgramiv(_handle, GL_INFO_LOG_LENGTH, &log_size);

            std::vector<char> log(log_size);

            int actual_size;
            glGetProgramInfoLog(_handle, log_size, &actual_size, log.data());

            if (actual_size < log_size) {
                log.resize(actual_size);
            }

            throw std::runtime_error{std::string{log.begin(), log.end()}};
        }

        _built = true;
    }



    void shader_program::bind() const
    {
        glUseProgram(_handle);
    }

    void shader_program::unbind()
    {
        glUseProgram(0);
    }
}
}
