#ifndef MAIN_SHADER_HPP_
#define MAIN_SHADER_HPP_

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>      
#include "glm_math_includes.hpp"    
#include "texture.hpp"                                                                                                  

class Shader {          

        GLuint program;
        GLuint vertex_shader, fragment_shader;

        std::string read_shader(const GLchar * _path, const GLchar * _stype) const;
        std::string get_shader_err(GLuint _shader) const;
        std::string get_program_err(GLuint _program) const;
        GLboolean check_compiled(GLuint _shader) const;
        GLboolean check_linked(GLuint _program) const;
        GLuint create_shader(const GLchar * _path, GLenum _type, GLchar * _stype) const;
        GLuint create_program() const;

        void create(const GLchar * _vpath, const GLchar * _fpath);


public:
        Shader(const GLchar * _folder);
        void use();

        bool check_location(GLint _location, std::string _name);

        void set_uniform(const glm::vec2& _v, std::string _name);
        void set_uniform(const glm::vec3& _v, std::string _name);
        void set_uniform(const glm::vec4& _v, std::string _name);
        void set_uniform(glm::mat4 _m, std::string _name);
        void set_uniform(Texture& _texture, std::string _sampler_name);  
        void set_uniform(bool _b, std::string _name);
};

#endif