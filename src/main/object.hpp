#ifndef MAIN_OBJECT_HPP_
#define MAIN_OBJECT_HPP_

#include "glm_math_includes.hpp"
#include "model.hpp"
#include "render_state.hpp"
#include "shader.hpp"

class Object {
        Model * model;
        Texture * texture;
        Shader * shader;
        float rotation_angle;
        vec3 rotation_axis;
        vec3 translation;
        vec3 scaling;

public:
        Object(Model * _model, Texture * _texture, Shader * _shader);
        mat4 m() const;
        mat4 m_inv() const;
        void draw(RenderState _state);
        void translate(vec3 _xyz);
        void scale(vec3 _xyz);
        ~Object();
};

#endif