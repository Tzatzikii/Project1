#ifndef MAIN_SHADER_HPP_
#define MAIN_SHADER_HPP_

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>                                                                                                            

class Shader {          

//      attribs
        GLuint program;
        GLuint vertex_shader, fragment_shader;

//      private methods
        std::string read_shader(const GLchar * _path) const {
                std::ifstream is(_path, std::ifstream::in);
                if(!is.is_open()) {
                        std::cout << "Invalid shader path" << std::endl;
                }
                std::stringstream ss;
                ss << is.rdbuf() << "\0";
                is.close();
                std::string ret = ss.str();

                return ret;
        }

        std::string get_shader_err(GLuint _shader) const {
                GLint msg_len = 0;
                glGetShaderiv(_shader, GL_INFO_LOG_LENGTH, &msg_len);
                std::string err_msg(msg_len, '\0');
                glGetShaderInfoLog(_shader, msg_len, &msg_len, &err_msg[0]); 
                return err_msg;
        }

        std::string get_program_err(GLuint _program) const {
                GLint msg_len = 0;
                glGetProgramiv(_program, GL_INFO_LOG_LENGTH, &msg_len);
                std::string err_msg(msg_len, '\0');
                glGetShaderInfoLog(_program, msg_len, &msg_len, &err_msg[0]); 
                
                return err_msg;
        }


        GLboolean check_compiled(GLuint _shader) const {
                int compiled;
                glGetShaderiv(_shader, GL_COMPILE_STATUS, &compiled);
                if(!compiled) {

                        std::string err = get_shader_err(_shader);
                        std::cout << "Shader compilation error" << std::endl 
                        << get_shader_err(_shader) << std::endl;
                
                        return GL_FALSE;
                }
                return GL_TRUE;
        }
        GLboolean check_linked(GLuint _program) const {
                int linked;
                glGetProgramiv(_program, GL_LINK_STATUS, &linked);
                if(!linked) {
                      std:: cout << "Shader linking error" << std::endl  << get_program_err(_program) << std::endl;
                      return GL_FALSE;
                }
                return GL_TRUE;
        }
        GLuint create_shader(const GLchar * _path, GLenum _type, GLchar * _err) const {
                GLuint shader = glCreateShader(_type);
                if(!shader) {
                        std::cout << _err << std::endl;
                        exit(1);
                }
                std::string shader_str = read_shader(_path);
                const GLchar * cstr = shader_str.c_str();
                glShaderSource(shader, 1, &cstr, NULL);
                glCompileShader(shader);
                if(!check_compiled(shader)){
                        glDeleteShader(shader);
                        exit(1);
                }
                return shader;
                
        }
        GLuint create_program() const {
                GLuint prog = glCreateProgram();
                glAttachShader(prog, vertex_shader);
                glAttachShader(prog, fragment_shader);

                glLinkProgram(prog);
                if(!check_linked(prog)) {
                        glDeleteProgram(prog);
                        glDeleteShader(vertex_shader);
                        glDeleteShader(fragment_shader);
                        exit(1);
                }
                return prog;
        }

        void create(const GLchar * _vpath, const GLchar * _fpath) {
                vertex_shader  = create_shader(_vpath, GL_VERTEX_SHADER, "Vertex shader creation failed.");
                fragment_shader = create_shader(_fpath, GL_FRAGMENT_SHADER, "Fragment shader creation failed.");
                program = create_program();
                glDetachShader(program, vertex_shader);
                glDetachShader(program, fragment_shader);
                std::cout << "Program created successfully" << std::endl;
       }


public:
        Shader(const GLchar * _folder) {
                std::string folder(_folder);
                std::string vpath(_folder), fpath(_folder);
                vpath = _folder + std::string("/vertex.glsl");
                fpath = _folder + std::string("/fragment.glsl");
                create(vpath.c_str(), fpath.c_str());
                
        }
        void use() {
                glUseProgram(program);
        }
};

#endif