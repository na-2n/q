#pragma once

#include <glad/glad.h>

namespace q {
namespace gl {
namespace util {
    template<typename T>
    constexpr GLenum get_gl_type();
}
}
}

#include "util.inl"
