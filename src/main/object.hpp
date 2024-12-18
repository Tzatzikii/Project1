#ifndef MAIN_OBJECT_HPP_
#define MAIN_OBJECT_HPP_

#include "glm_math_includes.hpp"
#include "mesh.hpp"
#include "shader.hpp"

class Object {
        const Mesh * mesh;
        const Texture * texture;
        const Shader * shader;
        float rotation_angle;
        glm::vec3 rotation_axis;
        glm::vec3 translation;

public:

        Object::Object(const Mesh& _mesh, const Texture& _texture, const Shader& _shader);

};

#endif