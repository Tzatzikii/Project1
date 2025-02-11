#include "scene.hpp"

void Scene::build() {
        camera = new Camera(vec3(0, 1, 4), vec3(0, 0, -1));
        Mesh * cube_mesh = new Mesh("res/models/cube.obj");
        Shader * default_shader = new Shader("res/shaders/basic");
        Texture * wood_texture = new Texture("res/textures/wood.tga");
        Object * cube = new Object(cube_mesh, wood_texture, default_shader);
        objects.push_back(cube);
}

bool key_poll[128] = {false};
void Scene::render() const {
        RenderState state;
        state.v = camera->v();
        state.p = camera->p();
        for(Object * object : objects) {
                object->draw(state);
        }
}

void Scene::update(float _delta) {
        shared_delta = _delta;
        handle_polled_keys(_delta);   
        
}


void Scene::handle_key_callback(GLFWwindow * _window, int _key, int _scancode, int _action, int _mods) {
        if(_action == GLFW_PRESS) key_poll[_key] = true;
        else if(_action == GLFW_RELEASE) key_poll[_key] = false;
}

void Scene::handle_cursor_pos_callback(GLFWwindow * _window, double _xpos, double _ypos) {
        std::cout << _xpos << " : " << _ypos << std::endl;
        camera->rotate_horizontal(_xpos * 0.01f);
        camera->rotate_vertical(_ypos * 0.01f);
        glfwSetCursorPos(_window, 0, 0);
}

void Scene::rotate_camera(float _delta) {
        
}

void Scene::handle_polled_keys(float _delta) {
        if(key_poll[GLFW_KEY_W]) camera->move_parallel(g_camera_speed * _delta);
        if(key_poll[GLFW_KEY_S]) camera->move_parallel(-g_camera_speed * _delta);
        if(key_poll[GLFW_KEY_A]) camera->move_perpendicular(g_camera_speed * _delta);
        if(key_poll[GLFW_KEY_D]) camera->move_perpendicular(-g_camera_speed * _delta);
}

Scene::~Scene() {
        for(Object * object : objects) delete object;
        delete camera;
}