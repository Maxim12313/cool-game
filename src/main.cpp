#define GLFW_INCLUDE_NONE
#include "../include/cool.hpp"
#include "../include/glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>

void error_callback(int error, const char *description) {
    fprintf(stderr, "Error: %s\n", description);
}

int main() {
    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) {
        printf("glfwinit error\n");
        exit(1);
    }

    GLFWwindow *window = glfwCreateWindow(800, 600, "GLFW Window", NULL, NULL);
    if (!window) {
        printf("window creation error\n");
        exit(1);
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
}
