#include "GLUtils.h"

extern std::map<char, Character> Characters;
extern int _fpsCount;
extern int fps;
extern std::chrono::time_point<std::chrono::steady_clock> lastTime;

glm::vec3 hexToVec3(uint32_t hex) {
    float r = ((hex >> 16) & 0xFF) / 255.0f;
    float g = ((hex >> 8) & 0xFF) / 255.0f;
    float b = (hex & 0xFF) / 255.0f;
    return glm::vec3(r, g, b);
}

glm::vec4 hexToVec4(uint32_t hex) {
    float a = ((hex >> 24) & 0xFF) / 255.0f;
    float r = ((hex >> 16) & 0xFF) / 255.0f;
    float g = ((hex >> 8) & 0xFF) / 255.0f;
    float b = (hex & 0xFF) / 255.0f;
    return glm::vec4(r, g, b, a);
}

float GetTextWidth(const std::string& text, float scale)
{
    float width = 0.0f;

    for (char c : text)
    {
        Character ch = Characters[c];
        width += (ch.Advance >> 6) * scale; // Advance is in 1/64th pixels, so shift right by 6
    }

    return width;
}

float GetTextHeight(const std::string& text, float scale)
{
    float maxHeight = 0.0f;

    for (char c : text)
    {
        Character ch = Characters[c];
        float height = ch.Size.y * scale;
        if (height > maxHeight)
            maxHeight = height;
    }

    return maxHeight;
}

void setClearColor(uint32_t hex) {
	float r = ((hex >> 16) & 0xFF) / 255.0f;
	float g = ((hex >> 8) & 0xFF) / 255.0f;
	float b = (hex & 0xFF) / 255.0f;
	glClearColor(r, g, b, 1.0f);
}

void CalculateFrameRate() {
    auto currentTime = std::chrono::steady_clock::now();

    const auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(currentTime - lastTime).count();
    ++_fpsCount;

    if (elapsedTime > 1000000000) {
        lastTime = currentTime;
        fps = _fpsCount;
        _fpsCount = 0;
    }
}



