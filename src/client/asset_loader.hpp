#pragma once

#include <string>
#include <filesystem>

#include "gl/shader.hpp"

#include "shared/filesystem.hpp"

namespace q {
namespace client {
    class asset_loader {
    public:
        asset_loader();

        asset_loader(const std::string& dir);

        template<GLenum Type>
        gl::shader<Type> load_shader(const std::string& path);

        inline gl::vertex_shader load_vertex_shader(const std::string& path)
        {
            return load_shader<GL_VERTEX_SHADER>(path);
        }

        inline gl::fragment_shader load_fragment_shader(const std::string& path)
        {
            return load_shader<GL_FRAGMENT_SHADER>(path);
        }

    private:
        std::filesystem::path _dir;
    };
}
}

#include "asset_loader.inl"
