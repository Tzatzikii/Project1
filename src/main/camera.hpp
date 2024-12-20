#ifndef MAIN_CAMERA_HPP_
#define MAIN_CAMERA_HPP_

#include "glm_math_includes.hpp"

extern const float g_fov;
extern const float g_fp;
extern const float g_bp;
extern const u_int g_window_w;
extern const u_int g_window_h;

inline float to_rad(float _deg) { return _deg * M_PI / 180.0f; }

struct Camera {
        vec4 pos, dir;
        vec3 vup;
        float fov, asp, fp,  bp;
public:
        Camera(vec3 _pos, vec3 _dir);
        void set();
        mat4 v();
        mat4 p();

        void rotate_horizontal(float _angle); 
        void rotate_vertical(float _angle);
        void move_parallel(float _units);
        void move_perpendicular(float _units); 
};

#endif