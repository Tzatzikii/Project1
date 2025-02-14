#include "material.hpp"

Material::Material(std::string _path) {
        read_wavefront(_path);
}

void Material::read_wavefront(std::string _path) {
        std::ifstream file(_path);
        if(!file.is_open()) {
                std::cout << "Unable to read model material at @ " << _path;
                exit(1);
        }
        std::stringstream data;
        data << file.rdbuf();
        char linebuf[250];
        while(!data.eof()) {
                data.getline(linebuf, 250, '\n');
                std::stringstream line(linebuf);
                switch(linebuf[0]) {
                        case 'K': {
                                line.seekg(2);
                                switch(linebuf[1]) {
                                        case 'a':{
                                                ((line >> ka.x).ignore(1) >> ka.y).ignore(1) >> ka.z;
                                                break;
                                        }
                                        case 'd':{
                                                ((line >> kd.x).ignore(1) >> kd.y).ignore(1) >> kd.z;
                                                break;
                                        }
                                        case 's':{
                                                ((line >> ks.x).ignore(1) >> ks.y).ignore(1) >> ks.z;
                                                break;
                                        }
                                        case 'e':{
                                                ((line >> ke.x).ignore(1) >> ke.y).ignore(1) >> ke.z;
                                                break;
                                        }
                                        default: break;
                                }
                                break;
                        }
                        case 'N':{
                                line.seekg(2);
                                if(linebuf[1] == 's'){
                                        line >> ns;
                                }
                                else {
                                        line >> ni;
                                }
                                break;
                        }
                        case 'd':{
                                line.seekg(1);
                                line >> d;
                                break;
                        }
                        case 'T':{
                                line.seekg(2);
                                line >> d;
                                d = 1 - d;
                                break;
                        }
                        default: break;
                }
                
        }
}