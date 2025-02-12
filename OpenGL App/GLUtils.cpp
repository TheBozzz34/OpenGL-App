#include "GLUtils.h"

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
