#include "object.hpp"

Object::Object(const Mesh& _mesh, const Texture& _texture, const Shader& _shader):
        mesh(&_mesh), texture(&_texture), shader(&_shader) {

}

