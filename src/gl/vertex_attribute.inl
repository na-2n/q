#include "util.hpp"

namespace q {
namespace gl {
    constexpr vertex_attribute::pointer_base::pointer_base(const int& count_, const int& size_, const GLenum& gl_type_)
        : count{count_}, size{size_}, gl_type{gl_type_}
    {
    }

    template<typename T, int Count, int Size>
    constexpr vertex_attribute::pointer<T, Count, Size>::pointer()
        : vertex_attribute::pointer_base{Count, Size, util::get_gl_type<T>()}
    {
    }
}
}
