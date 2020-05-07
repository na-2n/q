#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace q {
namespace gl {
    template<GLenum Type>
    void shader_program::attach(const shader<Type>& obj)
    {
        obj.attach_to(_handle);
    }

    template<GLenum Type>
    void shader_program::detach(const shader<Type>& obj)
    {
        obj.detach_from(_handle);
    }
}
}
