namespace q {
namespace client {
    template<GLenum Type>
    gl::shader<Type> asset_loader::load_shader(const std::string& path)
    {
        std::string str;

        shared::filesystem::read_file(_dir / "shaders" / path, str);

        gl::shader<Type> shader{str};

        return shader;
    }
}
}

