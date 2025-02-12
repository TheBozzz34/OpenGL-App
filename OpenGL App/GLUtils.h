#ifndef GLUTILS_H
#define GLUTILS_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <string>
#include <map>
#include <cstdint>
#include <chrono>

// Convert a 24-bit hex color (0xRRGGBB) to glm::vec3 (RGB)
glm::vec3 hexToVec3(uint32_t hex);

// Convert a 32-bit hex color (0xAARRGGBB) to glm::vec4 (RGBA)
glm::vec4 hexToVec4(uint32_t hex);

float GetTextWidth(const std::string& text, float scale);
float GetTextHeight(const std::string& text, float scale);

void setClearColor(uint32_t hex);

void CalculateFrameRate();

struct Character {
	unsigned int TextureID; // ID handle of the glyph texture
	glm::ivec2   Size;      // Size of glyph
	glm::ivec2   Bearing;   // Offset from baseline to left/top of glyph
	unsigned int Advance;   // Horizontal offset to advance to next glyph
};

#endif // GLUTILS_H
