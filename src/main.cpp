#define GLFW_INCLUDE_NONE
#include "../include/cool.hpp"
#include "../include/glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>

void errorCallback(int error, const char *description) {
    fprintf(stderr, "Error: %s\n", description);
}

void keyCallback(GLFWwindow *window, int key, int scancode, int action,
                 int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
        printf("inside\n");
    }
    printf("happened\n");
}

int main() {
    glfwSetErrorCallback(errorCallback);
    if (!glfwInit()) {
        printf("glfwinit error\n");
        exit(1);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    GLFWwindow *window = glfwCreateWindow(800, 600, "GLFW Window", NULL, NULL);
    if (!window) {
        printf("window creation error\n");
        exit(1);
    }

    glfwMakeContextCurrent(window);
    gladLoadGL();
    glfwSetKeyCallback(window, keyCallback);
    while (!glfwWindowShouldClose(window)) {
        // glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();
}
