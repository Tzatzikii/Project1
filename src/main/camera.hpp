#ifndef MAIN_CAMERA_HPP_
#define MAIN_CAMERA_HPP_

#include "../math/mathdef.hpp"

extern const float g_fov;
extern const float g_fp;
extern const float g_bp;
extern const u_int g_window_w;
extern const u_int g_window_h;

class Camera {
        vec4 pos, dir;
        vec3 vup;
        float fov, asp, fp,  bp;
public:
        Camera(vec3, vec3);
        void set();
        mat4 v();
        mat4 p();
};

#endif