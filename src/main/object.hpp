#ifndef MAIN_OBJECT_HPP_
#define MAIN_OBJECT_HPP_

#include "glm_math_includes.hpp"
#include "mesh.hpp"

class Object {
        Mesh * mesh;
        float rotation_angle;
        glm::vec3 rotation_axis;
        glm::vec3 translation;

};

#endif