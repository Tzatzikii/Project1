#ifndef MAIN_RENDER_STATE_HPP_
#define MAIN_RENDER_STATE_HPP_

#include "texture.hpp"
#include "glm_math_includes.hpp"

struct RenderState {
        Texture * texture;
        mat4 m, m_inv;
        mat4 p, v;
};

#endif