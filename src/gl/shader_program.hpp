#pragma once

#include <cstddef>
#include <string>
#include <map>

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "shader.hpp"

namespace q {
namespace gl {
    class shader_program {
    public:
        shader_program();

        ~shader_program();

        const bool& is_built() const;

        template<GLenum Type>
        void attach(const shader<Type>& obj);

        template<GLenum Type>
        void detach(const shader<Type>& obj);

// metaprogramming bad sorry
#define SET_UNIFORM(T) \
        void set_uniform(const std::string& name, const T& value)

        SET_UNIFORM(glm::mat4);
        SET_UNIFORM(glm::vec3);

#undef  SET_UNIFORM

        void build();

        void bind() const;

        static void unbind();

    private:
        std::map<std::string, int> _uniform_locations;
        unsigned int _handle;
        bool _built;

        const int& _get_uniform_location(const std::string& name)
        {
            const auto& search = _uniform_locations.find(name);

            if (search != _uniform_locations.end())  {
                return search->second;
            }

            const auto& location = glGetUniformLocation(_handle, name.c_str());

            _uniform_locations[name] = location;

            return location;
        }
    };
}
}

#include "shader_program.inl"
