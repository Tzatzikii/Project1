#version 450

layout(location = 0) in vec3 vtx_pos;
layout(location = 1) in vec3 vtx_norm;
layout(location = 2) in vec2 vtx_uv;

uniform vec4 cam_pos;
uniform mat4 mvp;
uniform mat4 m, m_inv;

out vec4 w_vtx_pos;
out vec4 w_vtx_norm;
out vec4 w_cam_pos;
out vec2 texcoord;

void main(){
        texcoord = vtx_uv;
        gl_Position = mvp * vec4(vtx_pos, 1);
        w_vtx_pos = m * vec4(vtx_pos, 1);
        w_vtx_norm = vec4(vtx_norm, 0) * m_inv;
        w_cam_pos = cam_pos;
}