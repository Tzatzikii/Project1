#include "texture.hpp"

void Texture::load_tga(std::string _path) {
         int x = 0, y = 0;
        stbi__result_info result;
        stbi__context context;
        stbi_load(_path.c_str(), &x, &y, NULL, 0);
        stbi__tga_load(&context, &x, &y, NULL, 0, &result);
}

Texture::Texture(std::string _path) {
        load_tga(_path);
}