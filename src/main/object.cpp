#include "object.hpp"

Object::Object(Mesh * _mesh, Texture * _texture, Shader * _shader):
        mesh(_mesh), texture(_texture), shader(_shader),
        translation(vec3(1)), rotation_angle(0), rotation_axis(vec3(1)), scaling(vec3(1)) {
}
mat4 Object::m() const {
        return glm::translate(mat4(1), translation) * glm::rotate(mat4(1), rotation_angle, rotation_axis) * glm::scale(mat4(1), scaling);
}

void Object::draw(RenderState _state) {
        _state.m = this->m();
        _state.texture = texture;
        shader->use();
        shader->bind(_state);
        mesh->draw();
}

Object::~Object() {
        delete mesh;
        delete texture;
        delete shader;
}


