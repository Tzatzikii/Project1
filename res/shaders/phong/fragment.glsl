#version 450

#define MAX_LIGHTS 16

struct Light {
        vec4 dir;
        vec3 is, id, ia;
};

struct Material {
        vec3 ka, kd, ks, ke;
        float ns, ni, d;
};

uniform Material material;
uniform int n_lights;
uniform Light lights[MAX_LIGHTS];
in vec4 w_vtx_pos;
in vec4 w_vtx_norm;
in vec4 w_cam_pos;
in vec2 texcoord; 

out vec4 radiance;
uniform sampler2D sampler;


void main(){
        radiance = texture(sampler, texcoord);
        vec3 phong_rad = {0, 0, 0};
        vec3 V = normalize(w_vtx_pos.xyz - w_cam_pos.xyz);
        for(int i = 0; i < n_lights; i++) {
                Light l = lights[i];
                Material m = material; //im lazy okay
                vec3 L = normalize(w_vtx_pos.xyz - l.dir.xyz);
                vec3 N = normalize(w_vtx_norm.xyz);
                vec3 H = normalize(V + L);
                vec3 diffuse = m.kd*dot(L, N)*l.id;
                if(dot(L, N) > 0) {
                        phong_rad = phong_rad + diffuse;
                }
                vec3 specular = m.ks*pow(dot(N, H), m.ns)*l.is;
                if(dot(N, H) > 0) {
                        phong_rad = phong_rad + specular;
                }
                phong_rad = phong_rad * exp(-length(w_vtx_pos - l.dir) * 0.04f);

        }
        radiance *= vec4(phong_rad, 0);
        

}