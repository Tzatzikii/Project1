#ifndef MAIN_TEXTURE_HPP_
#define MAIN_TEXTURE_HPP_

#include <GL/glew.h>
#include <iostream>
#include <vector>
#include <string>
#include <string.h>

struct Texture {
        static u_int cpu_id_counter;
        u_int gpu_id, cpu_id;
        int x, y;
        u_char * data;
        u_char * read_texture(std::string _path);
        void load_texture();

        Texture(std::string _path);
};

#endif