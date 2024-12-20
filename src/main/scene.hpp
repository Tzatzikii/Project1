#ifndef MAIN_SCENE_HPP_
#define MAIN_SCENE_HPP_

#include <vector>
#include "camera.hpp"
#include "object.hpp"

extern const float g_camera_speed;

class Scene {
        Camera * camera;
        std::vector<Object*> objects;
        float shared_delta;
public:
        void build();
        void handle_key_callback(GLFWwindow * _window, int _key, int _scancode, int _action, int _mods);
        void handle_cursor_pos_callback(GLFWwindow * _window, double _xpos, double _ypos);
        void update(float _delta);
        void handle_polled_keys(float _delta);
        void rotate_camera(float _delta);
        void render() const;
        ~Scene();
};

#endif // MAIN_SCENE_HPP_