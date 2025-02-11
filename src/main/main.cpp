#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include "shader.hpp"
#include "glm_math_includes.hpp"
#include "scene.hpp"
#include <GL/gl.h>

const float g_fov = 90.0f;
const float g_fp = 0.1f; 
const float g_bp = 100.0f; // render dist
const float g_camera_speed = 5.0f;
const u_int g_window_w = 600;
const u_int g_window_h = 600;

Scene scene;
void key_callback_wrapper(GLFWwindow * _window, int _key, int _scancode, int _action, int _mods) {
        scene.handle_key_callback(_window, _key, _scancode, _action, _mods);
        
}

void cursor_pos_callback_wrapper(GLFWwindow * _window, double _xpos, double _ypos) {
        scene.handle_cursor_pos_callback(_window, _xpos, _ypos);
}

void init(GLFWwindow * _window) {
        glewInit();
        glViewport(0, 0, g_window_w, g_window_h);
        glEnable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);
        glfwSwapInterval(0);
        glLineWidth(10);
        glfwSetKeyCallback(_window, key_callback_wrapper);
        glfwSetCursorPosCallback(_window, cursor_pos_callback_wrapper);
        glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        if (glfwRawMouseMotionSupported()) glfwSetInputMode(_window, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);
        scene.build();
}




void loop(GLFWwindow * _window) {
    

        while(!glfwWindowShouldClose(_window)){
                glClearColor(0.4f, 0.4f, 0.4f, 1.0f);
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                static float t_end = 0.0f;
                const float dt = 1.0f;
                float t_start = t_end;
                t_end = glfwGetTime();
                for(float t = t_start; t < t_end; t+=dt){
                        float delta = std::min(dt, t_end - t);
                        scene.update(delta);
                }
                scene.render();
                glfwSwapBuffers(_window);
                glfwPollEvents();
        }
}

int main() {

        GLFWwindow * window;

        if(!glfwInit()) {
                printf("GLFW initialization error\n");
                return -1;
        }


        window = glfwCreateWindow(g_window_h, g_window_w, "Client", NULL, NULL);

        if(!window) {
                glfwTerminate();
                return -1;
        }

        std::cout << glfwGetVersionString() << std::endl; 
        glfwMakeContextCurrent(window);
        init(window);
        loop(window);

        

        glfwTerminate();

        return 0;
}