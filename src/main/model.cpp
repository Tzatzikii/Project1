#include "model.hpp"

Model::Model(std::string _name) {
        mesh = new Mesh("res/models/" + _name + ".obj");
        material = new Material("res/models/" + _name + ".mtl");
}

Model::~Model() {
        delete material;
        delete mesh;
}