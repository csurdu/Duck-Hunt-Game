#pragma once

#include <string>

#include "core/gpu/mesh.h"
#include "utils/glm_utils.h"


namespace object2D
{
    // Create square with given bottom left corner, length and color
    Mesh* CreatePamant(const std::string &name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = true);
    Mesh* CreatePunctajUpgrade(const std::string& name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = true);
    Mesh* CreateScore(const std::string& name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false);
    Mesh* CreateGloante(const std::string& name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = true);
    Mesh* CreateTriangle(const std::string& name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = true);
    Mesh* CreateTriangleBody(const std::string& name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = true);
    Mesh* CreateCircle(const std::string& name, glm::vec3 centre, float lengthX, glm::vec3 color);
    Mesh* CreateCioc(const std::string& name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = true);
    Mesh* CreateFundal(const std::string& name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = true);
}
