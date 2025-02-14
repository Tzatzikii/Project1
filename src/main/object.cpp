#include "object.hpp"

Object::Object(Model * _model, Texture * _texture, Shader * _shader):
        model(_model), texture(_texture), shader(_shader),
        translation(vec3(1)), rotation_angle(0), rotation_axis(vec3(1)), scaling(vec3(1)) {
}
mat4 Object::m() const {
        return glm::translate(mat4(1), translation) * glm::rotate(mat4(1), rotation_angle, rotation_axis) * glm::scale(mat4(1), scaling);
}

mat4 Object::m_inv() const {
        return glm::scale(mat4(1), -scaling) * glm::rotate(mat4(1), -rotation_angle, rotation_axis) * glm::translate(mat4(1), -translation);
}
void Object::translate(vec3 _xyz) {
        this->translation += _xyz;
}
void Object::scale(vec3 _xyz) {
        this->scaling *= _xyz;
}
void Object::draw(RenderState _state) {
        _state.m = this->m();
        _state.m_inv = this->m_inv();
        _state.texture = texture;
        _state.material = model->material;
        shader->use();
        shader->bind(_state);
        model->mesh->draw();
}

Object::~Object() {
        delete model;
        delete texture;
        delete shader;
}


