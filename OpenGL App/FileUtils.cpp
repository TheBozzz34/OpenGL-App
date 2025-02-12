#include "FileUtils.h"
#include <fstream>
#include <windows.h>
#include "resources.h"
#include <iostream>

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

int setupResources() {
	// Create resources folder
	CreateDirectoryA("resources", NULL);
	// Extract resources
	extractFile("resources\\Antonio-Bold.ttf", Antonio_Bold_ttf, Antonio_Bold_ttf_len);
	extractFile("resources\\text.vs", text_vs, text_vs_len);
	extractFile("resources\\text.fs", text_fs, text_fs_len);
    if (GetFileAttributesA("resources\\Antonio-Bold.ttf") == INVALID_FILE_ATTRIBUTES || GetFileAttributesA("resources\\text.vs") == INVALID_FILE_ATTRIBUTES || GetFileAttributesA("resources\\text.fs") == INVALID_FILE_ATTRIBUTES) {
        std::cout << "ERROR::MAIN: Failed to extract resources" << std::endl;
        return -1;
	}
    else {
        return 0;
    }
}
