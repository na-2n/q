#pragma once

#include <unordered_map>
#include <functional>

#include <glm/glm.hpp>
#include <glm/gtx/hash.hpp>

#include "mesh.hpp"

#include "shared/chunk.hpp"
#include "shared/chunk_manager.hpp"

namespace q {
namespace client {
    class chunk_mesher {
    public:
        chunk_mesher(const shared::chunk_manager& chunk_mgr);

        void gen_mesh(const glm::ivec3& pos);

    private:
        using mesh_map = std::unordered_map<glm::ivec3, std::reference_wrapper<mesh>>;

        const shared::chunk_manager& _chunk_mgr;
        mesh_map _meshes;
    };
}
}
