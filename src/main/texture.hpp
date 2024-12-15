#ifndef MAIN_TEXTURE_HPP_
#define MAIN_TEXTURE_HPP_

#include <vector>
#include <string>

#define STB_IMAGE_IMPLEMENTATION
#include "../lib/stb_image.h"

class Texture {
        unsigned int id;
        std::vector<int> image;
        void load_tga(std::string _path);

public:
        Texture(std::string _path);

};

#endif