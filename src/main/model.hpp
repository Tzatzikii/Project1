#ifndef MAIN_MODEL_HPP_
#define MAIN_MODEL_HPP_

#include "mesh.hpp"
#include "material.hpp"
#include <string>

struct Model {
        Mesh * mesh;
        Material * material;

        Model(std::string _name);
        ~Model();
};

#endif