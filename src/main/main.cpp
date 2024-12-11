#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include "shader.hpp"
#include "../math/mathdef.hpp"
void init() {
        glewInit();
}

void loop(GLFWwindow * window) {
        Shader shader("src/shaders/basic");
        shader.use();
        unsigned int vao, vbo;
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
        vec3 vtx[] = {{0, 1, 1}, {1, 0, 1}, {-1, 0, 1}};
        glBufferData(GL_ARRAY_BUFFER, 3*sizeof(vtx), vtx, GL_STATIC_DRAW);
        
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