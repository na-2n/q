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

        template<GLenum Type>
        inline void attach(const shader<Type>& obj) const
        {
            obj.attach_to(_handle);
        }

        template<GLenum Type>
        inline void detach(const shader<Type>& obj) const
        {
            obj.detach_from(_handle);
        }

// metaprogramming bad sorry
#define SET_UNIFORM(T) \
        void set_uniform(const std::string& name, const T& value)

        SET_UNIFORM(glm::mat4);
        SET_UNIFORM(glm::vec3);

#undef  SET_UNIFORM

        void build();

        inline void bind() const
        {
            glUseProgram(_handle);
        }

        inline static void unbind()
        {
            glUseProgram(0);
        }

        inline const bool& is_built() const
        {
            return _built;
        }

    private:
        std::map<std::string, int> _uniform_locations;
        unsigned int _handle;
        bool _built;

        int _get_uniform_location(const std::string& name)
        {
            const auto& search = _uniform_locations.find(name);

            if (search != _uniform_locations.end())  {
                return search->second;
            }

            const auto location = glGetUniformLocation(_handle, name.c_str());

            _uniform_locations[name] = location;

            return location;
        }
    };
}
}
