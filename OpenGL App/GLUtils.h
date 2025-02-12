#ifndef GLUTILS_H
#define GLUTILS_H

#include <glm/glm.hpp>
#include <cstdint>

// Convert a 24-bit hex color (0xRRGGBB) to glm::vec3 (RGB)
glm::vec3 hexToVec3(uint32_t hex);

// Convert a 32-bit hex color (0xAARRGGBB) to glm::vec4 (RGBA)
glm::vec4 hexToVec4(uint32_t hex);

#endif // GLUTILS_H
