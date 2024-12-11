#version 450

layout(location = 0) in vec3 vtx_pos;


void main(){
       gl_Position = vec4(vtx_pos, 1);
}