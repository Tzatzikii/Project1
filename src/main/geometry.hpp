#ifndef MAIN_GEOMETRY_HPP_
#define MAIN_GEOMETRY_HPP_

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "glm_math_includes.hpp"

struct VertexData {
        glm::vec4 position, normal;
        glm::vec2 texcoord;
};

class Geometry {

protected:
        unsigned int vao, vbo;

public:
        Geometry();
        virtual void draw() const = 0;
};

#endif