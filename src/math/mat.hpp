
#ifndef MATH_MAT_HPP_
#define MATH_MAT_HPP

#include <cmath>
#include "vec.hpp"

class mat4 {

//      private attribs
        vec4 row[4];

public:

//      public ctors
        mat4() :row{    {1.0f, 0.0f, 0.0f, 0.0f},
                        {0.0f, 1.0f, 0.0f, 0.0f},
                        {0.0f, 0.0f, 1.0f, 0.0f},
                        {0.0f, 0.0f, 0.0f, 1.0f} } {} 

        mat4(   float _x0, float _y0, float _z0, float _w0, 
                float _x1, float _y1, float _z1, float _w1,
                float _x2, float _y2, float _z2, float _w2,
                float _x3, float _y3, float _z3, float _w3 ) : 
                row{   {_x0, _y0, _z0, _w0},
                        {_x1, _y1, _z1, _w1},
                        {_x2, _y2, _z2, _w2},
                        {_x3, _y3, _z3, _w3} } {}

        mat4(   const vec4& _row0,
                const vec4& _row1,
                const vec4& _row2,
                const vec4& _row3) :  
                row{    _row0,
                        _row1,
                        _row2,
                        _row3 } {}

//      public methods
        mat4 transpose() const {
                mat4 ret;
                ret.row[0] = { this->row[0].x, this->row[1].x, this->row[2].x, this->row[3].x };
                ret.row[1] = { this->row[0].y, this->row[1].y, this->row[2].y, this->row[3].y };
                ret.row[2] = { this->row[0].z, this->row[1].z, this->row[2].z, this->row[3].z };
                ret.row[3] = { this->row[0].w, this->row[1].w, this->row[2].w, this->row[3].w };
                return ret;
        }

        static mat4 rotation(float _angle, vec3 _axis) { 
                
        }
//      public operators

        vec4 operator[](u_int i) const { return row[i]; }

};

inline vec4 operator*(const vec4& _vl, const mat4& _mr){
        mat4 ret = _mr.transpose();
        return { dot(_vl, _mr[0]), dot(_vl, _mr[1]), dot(_vl, _mr[2]), dot(_vl, _mr[3]) };
}
inline mat4 operator*(const mat4& _ml, const mat4& _mr){
        mat4 ret = _mr.transpose();
        for(int i = 0; i < 4; i++) ret[i] = _ml[i] * _mr;
        return ret; 
}

#endif
