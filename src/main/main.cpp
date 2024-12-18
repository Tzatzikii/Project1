#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include "shader.hpp"
#include "glm_math_includes.hpp"
#include "camera.hpp"
#include "mesh.hpp"
#include "texture.hpp"

const float g_fov = 90.0f;
const float g_fp = 0.1f; 
const float g_bp = 100.0f; // render dist
const u_int g_window_w = 600;
const u_int g_window_h = 600;


void init() {
        glewInit();
        glViewport(0, 0, g_window_w, g_window_h);
        glEnable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);
        glLineWidth(10);

}

Camera cam({0, 0, 4}, {0, 0, -1});

bool key_pressed[128] = {false};

void on_keyboard(GLFWwindow * window, int key, int scancode, int action, int mods) {
        if(action == GLFW_PRESS) key_pressed[key] = true;
        else if(action == GLFW_RELEASE) key_pressed[key] = false;
}

void loop(GLFWwindow * window) {

        
        Shader shader("../res/shaders/basic");
        Texture txtr("../res/textures/wood.tga");
        Mesh cube("../res/models/cube.obj");
        shader.use();
        shader.set_uniform(txtr, "sampler");
        glfwSetKeyCallback(window, on_keyboard);
        
        VertexData line[2] = {{{0,-1,0,1}, {0,0,0,0}, {0,0}}, {{0,-1,0,1}, {0,0,0,0}, {0,0}}};

        while(!glfwWindowShouldClose(window)){
                glClearColor(0.4f, 0.4f, 0.4f, 1.0f);
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                if(key_pressed[GLFW_KEY_L]) {
                        cam.rotate_horizontal(-0.1f);
                }
                if(key_pressed[GLFW_KEY_J]) {
                        cam.rotate_horizontal(0.1f);
                }
                if(key_pressed[GLFW_KEY_W]) {
                        cam.move_parallel(0.1f);
                }
                if(key_pressed[GLFW_KEY_S]) {
                        cam.move_parallel(-0.1f);
                }
                if(key_pressed[GLFW_KEY_A]) {
                        cam.move_perpendicular(-0.1f);
                }
                if(key_pressed[GLFW_KEY_D]) {
                        cam.move_perpendicular(0.1f);
                }
                line[1].position = cam.dir * 10.0f;
                mat4 v = cam.v();
                mat4 p = cam.p();
                mat4 mvp =  p * v;

                cube.draw();
                glDrawArrays(GL_LINES, 0, 2);
                glfwSwapBuffers(window);
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
        init();
        loop(window);

        

        glfwTerminate();

        return 0;
}