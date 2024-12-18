#include "camera.hpp"

Camera::Camera(vec3 _pos, vec3 _dir) : pos(_pos, 1), dir(normalize(_dir), 0), vup(0, 1, 0){
        set();
}

void Camera::set() {
        asp = (float)g_window_w / (float)g_window_h;
        fov = to_rad(g_fov);
        fp = g_fp, bp = g_bp;
}

mat4 Camera::v() {
        vec3 w = normalize(-vec3( dir.x, dir.y, dir.z ));
        vec3 u = normalize(cross(w, vup));
        vec3 v = cross(u, w);
        mat4 rodrig({u, 0}, {v, 0}, {w, 0}, {0.0f, 0.0f, 0.0f, 1.0f});
        return glm::translate(rodrig, vec3(-pos));
        
}

mat4 Camera::p() {
        return glm::perspective(fov, asp, fp, bp);
}