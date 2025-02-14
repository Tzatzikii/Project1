#ifndef MAIN_MATERIAL_HPP_
#define MAIN_MATERIAL_HPP_

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "glm_math_includes.hpp"

struct Material {
        vec3 ka, kd, ks, ke;
        float ns, ni, d;
        
        Material(std::string _path);
        void read_wavefront(std::string _path);


};

#endif