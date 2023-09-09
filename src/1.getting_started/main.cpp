#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main(int argc, char *argv[])
{

    std::cout << "Hellow World!" << std::endl;

    GLFWwindow *window;

    if (!glfwInit())
    {
        fprintf(stderr, "Failed to initialize GLFW\n");
        exit(EXIT_FAILURE);
    }

    window = glfwCreateWindow(300, 300, "Hello World", NULL, NULL);
    if (!window)
    {
        fprintf(stderr, "Failed to open GLFW window\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);

    // Initialize Glad (load OpenGL function pointers)
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        fprintf(stderr, "Failed to initialize Glad\n");
        exit(EXIT_FAILURE);
    }

    const char *version = (const char *)glGetString(GL_VERSION);
    fprintf(stderr, "OpenGL version: %s\n", version);

    while (!glfwWindowShouldClose(window))
    {
        // swap buffers
        glfwSwapBuffers(window);

        // check events in que
        glfwPollEvents();
    }

    glfwTerminate();

    return true;
}