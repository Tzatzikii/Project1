#ifndef MAIN_GEOMETRY_HPP_
#define MAIN_GEOMETRY_HPP_

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "../math/mathdef.hpp"

struct VertexData {
        vec4 position, normal;
        vec2 texcoord;
};

class Geometry {

//      attribs

        unsigned int vao, vbo;
        std::vector<VertexData> vertices;

public:


//      methods
        Geometry();
/*
        binds the vao and vbo and draws GL_TRIANGLES
*/
        void draw();

        void push(const VertexData& _vd){
                vertices.push_back(_vd);
        }
};

#endif