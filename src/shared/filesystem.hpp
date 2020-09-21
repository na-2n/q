#pragma once

#include <string>

namespace q {
namespace shared {
namespace filesystem {
    unsigned int bin_dir(std::string& out);

    void read_file(const std::string& fn, std::string& out);
}
namespace fs = filesystem;
}
}
