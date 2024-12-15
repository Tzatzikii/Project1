#ifndef MAIN_TEXTURE_HPP_
#define MAIN_TEXTURE_HPP_

#include <vector>
#include <string>

#define STB_IMAGE_IMPLEMENTATION
#include "../lib/stb_image.h"

class Texture {
        unsigned int id;
        std::vector<int> image;
        void load_tga(std::string _path) {
                int x = 0, y = 0;
                stbi__result_info result;
                stbi__context context;
                stbi_load(_path.c_str(), &x, &y, NULL, 0);
                stbi__tga_load(&context, &x, &y, NULL, 0, &result);
        }

public:
        Texture(std::string _path) { 
                load_tga(_path);
        }

};

#endif