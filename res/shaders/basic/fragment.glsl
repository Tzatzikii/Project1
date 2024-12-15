#version 450

out vec4 radiance;

in vec2 texcoord;

uniform sampler2D sampler;


void main(){
       radiance = texture(sampler, texcoord);
}