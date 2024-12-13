#ifndef MAIN_CAMERA_HPP_
#define MAIN_CAMERA_HPP_

#include "../math/mathdef.hpp"

extern const float g_fov;
extern const u_int g_window_w;
extern const u_int g_window_h;

class Camera {
        vec3 pos, dir, vup;
        float fov, asp, fp,  bp;
public:
        Camera(vec3, vec3);
};

#endif