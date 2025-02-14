#include "shader.hpp"

std::string Shader::read_shader(const GLchar * _path, const GLchar * _stype) const {
        std::ifstream is(_path, std::ifstream::in);
        if(!is.is_open()) {
                std::cout << "Invalid " << _stype << " shader path" << std::endl;
        }
        std::stringstream ss;
        ss << is.rdbuf() << "\0";
        is.close();
        std::string ret = ss.str();

        return ret;
}

std::string Shader::get_shader_err(GLuint _shader) const {
        GLint msg_len = 0;
        glGetShaderiv(_shader, GL_INFO_LOG_LENGTH, &msg_len);
        std::string err_msg(msg_len, '\0');
        glGetShaderInfoLog(_shader, msg_len, &msg_len, &err_msg[0]); 
        return err_msg;
}

std::string Shader::get_program_err(GLuint _program) const {
        GLint msg_len = 0;
        glGetProgramiv(_program, GL_INFO_LOG_LENGTH, &msg_len);
        std::string err_msg(msg_len, '\0');
        glGetShaderInfoLog(_program, msg_len, &msg_len, &err_msg[0]); 
        
        return err_msg;
}


GLboolean Shader::check_compiled(GLuint _shader) const {
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
GLboolean Shader::check_linked(GLuint _program) const {
        int linked;
        glGetProgramiv(_program, GL_LINK_STATUS, &linked);
        if(!linked) {
                std:: cout << "Shader linking error" << std::endl  << get_program_err(_program) << std::endl;
                return GL_FALSE;
        }
        return GL_TRUE;
}
GLuint Shader::create_shader(const GLchar * _path, GLenum _type, GLchar * _stype) const {
        GLuint shader = glCreateShader(_type);
        if(!shader) {
                std::cout << "Failed to create " << _stype << " shader." << std::endl;
                exit(1);
        }
        std::string shader_str = read_shader(_path, _stype);
        const GLchar * cstr = shader_str.c_str();
        glShaderSource(shader, 1, &cstr, NULL);
        glCompileShader(shader);
        if(!check_compiled(shader)){
                glDeleteShader(shader);
                exit(1);
        }
        return shader;
        
}
GLuint Shader::create_program() const {
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

void Shader::create(const GLchar * _vpath, const GLchar * _fpath) {
        vertex_shader  = create_shader(_vpath, GL_VERTEX_SHADER, "Vertex");
        fragment_shader = create_shader(_fpath, GL_FRAGMENT_SHADER, "Fragment");
        program = create_program();
        glDetachShader(program, vertex_shader);
        glDetachShader(program, fragment_shader);
        std::cout << "Program created successfully" << std::endl;
}


Shader::Shader(const GLchar * _folder) {
        std::string folder(_folder);
        std::string vpath(_folder), fpath(_folder);
        vpath = _folder + std::string("/vertex.glsl");
        fpath = _folder + std::string("/fragment.glsl");
        create(vpath.c_str(), fpath.c_str());
        
}
void Shader::use() const {
        glUseProgram(program);
}

bool Shader::check_location(GLint _location, std::string _name) const {
        if(_location < 0) {
                std::cout << "Error while setting uniform variable \"" << _name << "\"" << std::endl;
                return false;
        }
        return true;
}
void Shader::set_uniform(int _i, std::string _name) const{
        GLint location = glGetUniformLocation(program, _name.c_str());
        if(!check_location(location, _name)) return;
        glUniform1i(location, _i);
}
void Shader::set_uniform(float _f, std::string _name) const{
        GLint location = glGetUniformLocation(program, _name.c_str());
        if(!check_location(location, _name)) return;
        glUniform1f(location, _f);
}
void Shader::set_uniform(const glm::vec2& _v, std::string _name) const {
        GLint location = glGetUniformLocation(program, _name.c_str());
        if(!check_location(location, _name)) return;
        glUniform2f(location, _v.x, _v.y);
}
void Shader::set_uniform(const glm::vec3& _v, std::string _name) const {
        GLint location = glGetUniformLocation(program, _name.c_str());
        if(!check_location(location, _name)) return;
        glUniform3f(location, _v.x, _v.y, _v.z);
}
void Shader::set_uniform(const glm::vec4& _v, std::string _name) const {
        GLint location = glGetUniformLocation(program, _name.c_str());
        if(!check_location(location, _name)) return;
        glUniform4f(location, _v.x, _v.y, _v.z, _v.w);
}
void Shader::set_uniform(glm::mat4 _m, std::string _name) const {
        GLint location = glGetUniformLocation(program, _name.c_str());
        if(!check_location(location, _name)) return;
        glUniformMatrix4fv(location, 1, GL_FALSE, &_m[0][0]);
}
void Shader::set_uniform(bool _b, std::string _name) const {
        GLint location = glGetUniformLocation(program, _name.c_str());
        if(!check_location(location, _name)) return;
        glUniform1i(location, (int)_b);
}
void Shader::set_uniform(const Texture& _texture, std::string _sampler_name) const {
        GLint location = glGetUniformLocation(program, _sampler_name.c_str());
        if(!check_location(location, _sampler_name)) return;
        glActiveTexture(GL_TEXTURE0+_texture.cpu_id);
        glBindTexture(GL_TEXTURE_2D, _texture.gpu_id);
        glUniform1i(location, _texture.cpu_id);
}
void Shader::set_uniform(const std::vector<Light>& _arr, std::string _name) const {
        for(int i = 0; i < _arr.size(); i++) {
                set_uniform(_arr[i].dir, std::string(_name + "[") + std::to_string(i) + std::string("].dir"));
                set_uniform(_arr[i].ia, std::string(_name + "[") + std::to_string(i) + std::string("].ia"));
                set_uniform(_arr[i].is, std::string(_name + "[") + std::to_string(i) + std::string("].is"));
                set_uniform(_arr[i].id, std::string(_name + "[") + std::to_string(i) + std::string("].id"));
        }
}
void Shader::set_uniform(const Material& _material, std::string _name) const {
        set_uniform(_material.d, _name + ".d");
        set_uniform(_material.ka, _name + ".ka");
        set_uniform(_material.kd, _name + ".kd");
        set_uniform(_material.ke, _name + ".ke");
        set_uniform(_material.ks, _name + ".ks");
        set_uniform(_material.ni, _name + ".ni");
        set_uniform(_material.ns, _name + ".ns");
}

void Shader::bind(RenderState _state) const {
        mat4 mvp = _state.p * _state.v * _state.m;
        set_uniform(mvp, "mvp");
        set_uniform(_state.m, "m");
        set_uniform(_state.m_inv, "m_inv");
        set_uniform(_state.cam_pos, "cam_pos");
        set_uniform(*_state.lights, "lights");
        set_uniform((int)_state.lights->size(), "n_lights");
        set_uniform(*_state.texture, "sampler");

        set_uniform(*_state.material, "material");
}