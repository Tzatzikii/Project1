#include "scene.hpp"

void Scene::build() {
        camera = new Camera(vec3(0, 1, 4), vec3(0, 0, -1));
        Light light = {{1, 2, 1, 0}, {5, 3, 5}, {1, 0, 1}, {1, 1, 1}};
        //Light probe1 = {{}};

        Model * cube_model = new Model("cube");
        Model * sky_cube  = new Model("skybox");
        Model * sphere_model = new Model("shinysphere");
        Model * shiny_torus = new Model("halfshinytorus");

        Shader * default_shader = new Shader("res/shaders/phong");

        Texture * pure_white = new Texture("res/textures/white.png");
        Texture * skybox_texture = new Texture("res/textures/grassyskybox.png");
        Texture * wood_texture = new Texture("res/textures/wood.tga");
        Texture * metallic_texture = new Texture("res/textures/thing.png");

        Object * skybox = new Object(sky_cube, skybox_texture, default_shader);
        Object * cube = new Object(cube_model, wood_texture, default_shader);
        Object * cube2 = new Object(cube_model, metallic_texture, default_shader);
        Object * sphere = new Object(sphere_model, pure_white, default_shader);
        Object * light_indicator = new Object(sphere_model, metallic_texture, default_shader);
        Object * torus = new Object(shiny_torus, pure_white, default_shader);

        light_indicator->translate({0, 1, 0});
        light_indicator->scale({0.1f, 0.1f, 0.1f});

        sphere->translate({0, -1, 4});
        skybox->scale({50, 50, 50});
        cube->translate({0, -2, 0});
        cube2->translate({5, 0, 0});
        torus->translate({-1, 2, -1});
        objects.push_back(skybox);
        objects.push_back(cube);
        objects.push_back(cube2);
        objects.push_back(sphere);
        objects.push_back(torus);
        objects.push_back(light_indicator);
        lights.push_back(light);
}

bool key_poll[128] = {false};
void Scene::render() const {
        RenderState state;
        state.v = camera->v();
        state.p = camera->p();
        state.cam_pos = camera->pos;
        //std::cout << state.cam_pos.x << " : " << state.cam_pos.y << " : " << state.cam_pos.z << std::endl;
        state.lights = &lights;
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