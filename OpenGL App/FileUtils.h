#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <string>

// Extracts a file and writes binary data to it
void extractFile(const std::string& path, unsigned char* data, unsigned int length);

// Gets the full path of a file
std::string getFullPath(const std::string& filename);

#endif // FILEUTILS_H
