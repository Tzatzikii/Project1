#ifndef MAIN_OBJECT_HPP_
#define MAIN_OBJECT_HPP_

#include "mesh.hpp"

class Object {
        Mesh * mesh;
        float rotation_angle;
        vec3 rotation_axis;
        vec3 translation;

};

#endif