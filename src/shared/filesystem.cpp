#include "filesystem.hpp"

#include <fstream>
#include <streambuf>
#include <filesystem>

#include <cstdio>

#ifdef __WIN32
#include <libloaderapi.h>
#else
#include <unistd.h>
#endif

namespace q {
namespace shared {
    unsigned int filesystem::bin_dir(std::string& out)
    {
        char path[FILENAME_MAX];
        unsigned int bytes_read = 0;

#ifdef __WIN32
        bytes_read = GetModuleFileNameA(NULL, path, sizeof(path));
#else
        bytes_read = std::min(readlink("/proc/self/exe", path, sizeof(path)),
                static_cast<ssize_t>(sizeof(path) - 1));

        if (bytes_read >= 0) {
            path[bytes_read] = '\0';
        }
#endif

        std::filesystem::path dir{path};

        dir.remove_filename();

        out.assign(dir);

        return bytes_read;
    }

    void filesystem::read_file(const std::string& fn, std::string& out)
    {
        std::ifstream fs{fn};

        fs.exceptions(fs.badbit | fs.failbit);

        out.assign(std::istreambuf_iterator<char>{fs}, std::istreambuf_iterator<char>{});
    }
}
}
