#ifndef MAIN_CAMERA_HPP_
#define MAIN_CAMERA_HPP_

#include "glm_math_includes.hpp"

extern const float g_fov;
extern const float g_fp;
extern const float g_bp;
extern const u_int g_window_w;
extern const u_int g_window_h;

inline float to_rad(float _deg) { return _deg * M_PI / 180.0f; }

class Camera {
        glm::vec4 pos, dir;
        glm::vec3 vup;
        float fov, asp, fp,  bp;
public:
        Camera(glm::vec3, glm::vec3);
        void set();
        glm::mat4 v();
        glm::mat4 p();
};

#endif