#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include "shader.hpp"
#include "../math/mathdef.hpp"
//#include "geometry.hpp"

void init() {
        glewInit();
}

void loop(GLFWwindow * window) {
        // Shader shader("src/shaders/basic");
        // shader.use();
        // Geometry geo;
        // geo.push({{0, 1, 1, 1}, {0, 1, 1, 1}, {0, 0}});
        // geo.push({{1, 0, 1, 1}, {0, 1, 1, 1}, {0, 0}});
        // geo.push({{-1, 0, 1, 1}, {0, 1, 1, 1}, {0, 0}});

        // geo.draw();
        
        // while(!glfwWindowShouldClose(window)){
        //         glClearColor(0.4f, 0.4f, 0.4f, 1.0f);
        //         glClear(GL_COLOR_BUFFER_BIT);
        //         glDrawArrays(GL_TRIANGLES, 0, 3);
        //         glfwSwapBuffers(window);

        //         glfwPollEvents();
        // }
}

int main() {

        GLFWwindow * window;

        if(!glfwInit()) {
                printf("GLFW initialization error\n");
                return -1;
        }


        window = glfwCreateWindow(600, 600, "Client", NULL, NULL);

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