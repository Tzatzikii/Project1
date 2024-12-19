#ifndef MAIN_SCENE_HPP_
#define MAIN_SCENE_HPP_

#include <vector>
#include "camera.hpp"
#include "object.hpp"

extern const float g_camera_speed;

class Scene {
        Camera * camera;
        std::vector<Object*> objects;
public:
        void build();
        void handle_key_callback(GLFWwindow * _window, int _key, int _scancode, int _action, int _mods);
        void update(float _delta);
        void handle_polled_keys(float _delta);
        void render() const;
        ~Scene();
};

#endif // MAIN_SCENE_HPP_