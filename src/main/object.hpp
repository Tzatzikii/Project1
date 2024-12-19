#ifndef MAIN_OBJECT_HPP_
#define MAIN_OBJECT_HPP_

#include "glm_math_includes.hpp"
#include "mesh.hpp"
#include "render_state.hpp"
#include "shader.hpp"

class Object {
        Mesh * mesh;
        Texture * texture;
        Shader * shader;
        float rotation_angle;
        vec3 rotation_axis;
        vec3 translation;
        vec3 scaling;

public:
        Object(Mesh * _mesh, Texture * _texture, Shader * _shader);
        mat4 m() const;
        void draw(RenderState _state);
        ~Object();
};

#endif