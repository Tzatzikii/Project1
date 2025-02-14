#include "mesh.hpp"

void Mesh::set() {
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        glEnableVertexAttribArray(2);
        glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*)offsetof(VertexData, position));
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*)offsetof(VertexData, normal));
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*)offsetof(VertexData, texcoord));
}

data_type Mesh::det_dtype(const char * _linebuf){
        if(_linebuf[0] == 'f') return FACE;
        if(_linebuf[0] == 'v'){
                switch(_linebuf[1]){
                        case ' ': return POSITION;
                        case 'n': return NORMAL;
                        case 't': return TEXCOORD;
                }       
        }
        return UNDEFINED;
}

Mesh::Mesh(std::string _path) : Geometry() {
        read_wavefront(_path);
        set();
}

void Mesh::read_wavefront(std::string _path){
        std::ifstream file(_path);
        if(!file.is_open()) {
                std::cout << "Unable to read model mesh @ " << _path << std::endl;
                exit(1);
        }
        std::stringstream data;
        data << file.rdbuf();
        char linebuf[250];
        std::vector<vec4> positions;
        std::vector<vec4> normals;
        std::vector<vec2> texcoords;
        while(!data.eof()){
                data.getline(linebuf, 250, '\n');
                std::stringstream line(linebuf);
                float x, y, z;
                u_int vid, nid, tid;
                switch(det_dtype(linebuf)){
                        case POSITION:{
                                line.seekg(1);
                                ((line >> x).ignore(1) >> y).ignore(1) >> z;
                                positions.push_back({x, y, z, 1});
                                break;
                        }
                        case NORMAL:{
                                line.seekg(2);
                                ((line >> x).ignore(1) >> y).ignore(1) >> z;
                                normals.push_back({x, y, z, 0});
                                break;
                        }
                        case TEXCOORD:{
                                line.seekg(2);
                                (line >> x).ignore(1) >> y;
                                texcoords.push_back({x, y});
                                break;
                        }
                        case FACE:{
                                line.seekg(1);
                                for(int i = 0; i < 3; i++){
                                        (((line >> vid).ignore(1) >> tid).ignore(1) >> nid).ignore(1);
                                        vertices.push_back({positions[vid-1], normals[nid-1], texcoords[tid-1]});
                                }
                        }
                        default: continue;
                }   
        }
}

void Mesh::draw() const {
        glBindVertexArray(vao);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(VertexData), &vertices[0], GL_DYNAMIC_DRAW);
        glDrawArrays(GL_TRIANGLES, 0, vertices.size());
}