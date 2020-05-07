#include "util.hpp"

namespace q {
namespace gl {
    template<typename T, int Count, int Size>
    constexpr vertex_attribute::pointer<T, Count, Size>::pointer()
        : vertex_attribute::pointer_base{Count, Size, util::get_gl_type<T>()}
    {
    }
}
}
