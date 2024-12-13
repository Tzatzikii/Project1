#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include "shader.hpp"
#include "../math/mathdef.hpp"
#include "geometry.hpp"
#include "camera.hpp"

const float g_fov = M_PI_2f;
const u_int g_window_w = 600;
const u_int g_window_h = 600;

void init() {
        glewInit();
}

void loop(GLFWwindow * window) {
        Shader shader("../../res/shaders/basic");
        shader.use();
        Geometry geo;
        Camera cam();
        geo.push({{0, 1, 1, 1}, {0, 1, 1, 1}, {0, 0}});
        geo.push({{1, 0, 1, 1}, {0, 1, 1, 1}, {0, 0}});
        geo.push({{-1, 0, 1, 1}, {0, 1, 1, 1}, {0, 0}});

        geo.draw();
        
        while(!glfwWindowShouldClose(window)){
                glClearColor(0.4f, 0.4f, 0.4f, 1.0f);
                glClear(GL_COLOR_BUFFER_BIT);
                glDrawArrays(GL_TRIANGLES, 0, 3);
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