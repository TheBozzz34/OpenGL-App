#include "FileUtils.h"
#include <fstream>
#include <windows.h>

void extractFile(const std::string& path, unsigned char* data, unsigned int length) {
    std::ofstream file(path, std::ios::binary);
    if (file.is_open()) {
        file.write(reinterpret_cast<const char*>(data), length);
        file.close();
    }
}

std::string getFullPath(const std::string& filename) {
    char buffer[MAX_PATH];
    DWORD result = GetFullPathNameA(filename.c_str(), MAX_PATH, buffer, nullptr);
    if (result == 0) {
        return ""; // Error occurred
    }
    return std::string(buffer, result);
}
