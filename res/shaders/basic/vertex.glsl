#version 450

layout(location = 0) in vec4 vtx_pos;
//layout(location = 1) in vec4 vtx_norm;
layout(location = 2) in vec2 vtx_uv;

out vec2 texcoord;

uniform mat4 mvp;
uniform bool line;
void main(){

       texcoord = vtx_uv;
       gl_Position = mvp * vtx_pos;
}