#ifndef MAIN_MESH_HPP_
#define MAIN_MESH_HPP_

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "geometry.hpp"

enum data_type{ POSITION, NORMAL, TEXCOORD, FACE, UNDEFINED };

class Mesh : public Geometry {
        
        std::vector<VertexData> vertices;
        data_type det_dtype(const char *);
        void read_wavefront(std::string);
        void set();
        

public:
        Mesh(std::string);
        void draw() const override;
};

#endif