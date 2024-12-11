
#ifndef MATH_VEC_HPP_
#define MATH_VEC_HPP_

#include <cmath>

struct vec2;
struct vec3;
struct vec4;
float dot(const vec2&, const vec2&);
float dot(const vec3&, const vec3&);
float dot(const vec4&, const vec4&);

struct vec2 {

//      attribs
        float x, y;

//      ctors
        vec2(float _x, float _y) : x(_x), y(_y) {}
        vec2(const vec2& _v) : x(_v.x), y(_v.y) {}
        vec2(vec2&&) = delete;

//      methods
        float length() { return std::sqrt(dot(*this, *this)); }

//      operators
        vec2 operator*(const vec2& _vr) const { return { this->x * _vr.x, this->y * _vr.y }; }
        vec2 operator+(const vec2& _vr) const { return { this->x + _vr.x, this->y + _vr.y }; }
        vec2 operator=(const vec2& _vr) const { return { this->x, this->y }; }
        
};

struct vec3 {

//      attribs
        float x, y, z;

//      ctors
        vec3(float _x = 0, float _y = 0, float _z = 0) : x(_x), y(_y), z(_z) {}
        vec3(const vec2& _v) : x(_v.x), y(_v.y), z(1) {}
        vec3(const vec3& _v) : x(_v.x), y(_v.y), z(_v.z) {}
        vec3(vec3&&) = delete;

//      methods   
        float length() { return std::sqrt(dot(*this, *this)); }
        vec3 cross(const vec3& _v0, const vec3& _v1) const { return { _v0.y * _v1.z - _v0.z * _v1.y,
                                                                        _v0.z * _v1.x - _v0.x * _v1.z, 
                                                                        _v0.x * _v1.y - _v0.y * _v1.x }; }

//      operators
        vec3 operator*(const vec3& _vr) const { return { this->x * _vr.x, this->y * _vr.y, this->z * _vr.z }; }
        vec3 operator+(const vec3& _vr) const { return { this->x + _vr.x, this->y + _vr.y, this->z + _vr.z }; }
        vec3 operator=(const vec3& _vr) const { return { this->x, this->y, this->z }; }
};

struct vec4 {

//      attribs
        float x, y, z, w;

//      ctors
        vec4(float _x, float _y, float _z, float _w) : x(_x), y(_y), z(_z), w(_w) {}
        vec4(const vec4& _v) : x(_v.x), y(_v.y), z(_v.z), w(_v.w) {}
        vec4(vec4&&) = delete;

//      methods   
        float length() { return std::sqrt(dot(*this, *this)); }

//      operators
        vec4 operator*(const vec4& _vr) const { return { this->x * _vr.x, this->y * _vr.y, this->z * _vr.z, this->w * _vr.w }; }
        vec4 operator+(const vec4& _vr) const { return { this->x + _vr.x, this->y + _vr.y, this->z + _vr.z, this->w + _vr.w }; }
        vec4 operator=(const vec4& _vr) const { return { this->x, this->y, this->z, this->w }; }
        
};

inline float dot(const vec2& _v0, const vec2& _v1) { return _v0.x * _v1.x + _v0.y * _v1.y; }
inline float dot(const vec3& _v0, const vec3& _v1) { return _v0.x * _v1.x + _v0.y * _v1.y + _v0.z + _v1.z; }
inline float dot(const vec4& _v0, const vec4& _v1) { return _v0.x * _v1.x + _v0.y * _v1.y + _v0.z * _v1.z + _v0.z * _v1.z; }

#endif