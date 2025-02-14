#ifndef MAIN_RENDER_STATE_HPP_
#define MAIN_RENDER_STATE_HPP_

#include "light.hpp"
#include "texture.hpp"
#include "glm_math_includes.hpp"
#include "material.hpp"

struct RenderState {
        const std::vector<Light> * lights;
        Texture * texture;
        Material * material;
        mat4 m, m_inv;
        mat4 p, v;
        vec4 cam_pos;
};

#endif