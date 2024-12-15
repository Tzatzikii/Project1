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
}

void loop(GLFWwindow * window) {
        Camera cam({0, 0, 4}, {0, 1, -4});
        Shader shader("../res/shaders/basic");
        //Texture txtr("../../res/textures/wood.tga");
        mat4 v = cam.v();
        mat4 p = cam.p();
        mat4 mvp =  p * v;
        Mesh cube("../res/models/cube.obj");
        shader.use();
        shader.set_uniform(mvp, "mvp");
        
        while(!glfwWindowShouldClose(window)){
                glClearColor(0.4f, 0.4f, 0.4f, 1.0f);
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                cube.draw();

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