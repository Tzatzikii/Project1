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
        vec3 w = normalize(-vec3(dir));
        vec3 u = normalize(cross(vup, w));
        vec3 v = cross(w, u);
        mat4 rodrig({u, 0}, {v, 0}, {w, 0}, {0.0f, 0.0f, 0.0f, 1.0f});
        return glm::translate(glm::transpose(rodrig), vec3(-pos));
        
}

mat4 Camera::p() {
        return glm::perspective(fov, asp, fp, bp);
}

void Camera::rotate_horizontal(float _angle) {
        dir = dir * glm::rotate(mat4(1.0f), _angle, vup);
}

void Camera::rotate_vertical(float _angle) {
        vec3 axis = glm::cross(vec3(dir), vec3(vup));
        vec4 newdir = dir * glm::rotate(mat4(1.0f), _angle, glm::normalize(axis));
        if(std::abs(glm::dot(vec3(newdir), vup)) > 0.9) return;
        dir = newdir;
}

void Camera::move_parallel(float _units) {
        pos.x += dir.x * _units;
        pos.z += dir.z * _units;
}

void Camera::move_perpendicular(float _units) {
        vec4 side(cross(vup, vec3(dir)), 1);
        pos.x += _units * side.x;
        pos.z += _units * side.z;
}