#include "texture.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "../lib/stb_image.h"

u_int Texture::cpu_id_counter = 1; // gpu starts counting from 1 as well

u_char * Texture::read_texture(std::string _path) {
        x = 0, y = 0;
        int comp = 0;
        u_char * image = stbi_load(_path.c_str(), &x, &y, &comp, 0);
        if(!image) {
                std::cout << "Error while loading image >" << cpu_id << std::endl;
                return NULL;
        }
        return image;
}
void Texture::load_texture() {
        glGenTextures(1, &gpu_id);
        glBindTexture(GL_TEXTURE_2D, gpu_id);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, x, y, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        stbi_image_free(data);
}

Texture::Texture(std::string _path) {
        cpu_id = cpu_id_counter;
        data = read_texture(_path);
        load_texture();
        cpu_id_counter++;
}
