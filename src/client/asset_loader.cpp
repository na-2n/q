#include "asset_loader.hpp"

namespace q {
namespace client {
    asset_loader::asset_loader()
    {
        std::string str;

        shared::fs::bin_dir(str);

        _dir = str;
        _dir /= "assets";
    }

    asset_loader::asset_loader(const std::string& dir)
        : _dir{dir}
    {
    }
}
}

