#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "shader.hpp"

const uint16_t WINDOW_HEIGHT = 600;
const uint16_t WINDOW_WIDTH = 800;

void framebuffer_size_callback(GLFWwindow *window, uint16_t width, uint16_t height);
void processInput(GLFWwindow *window);

int main(int argc, char *argv[])
{
    /////////////////////////
    // Setting GL Context
    /////////////////////////
    std::cout << "Hellow World!" << std::endl;

    if (!glfwInit())
    {
        fprintf(stderr, "Failed to initialize GLFW\n");
        exit(EXIT_FAILURE);
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); // Setting the version of GL
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window;
    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Hello World", NULL, NULL);
    if (!window)
    {
        fprintf(stderr, "Failed to open GLFW window\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window); // make the context of our window the main context on the current thread

    // Initialize Glad (load OpenGL function pointers) before using any GL function
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        fprintf(stderr, "Failed to initialize Glad\n");
        exit(EXIT_FAILURE);
    }

    const char *version = (const char *)glGetString(GL_VERSION);
    fprintf(stderr, "OpenGL version: %s\n", version);

    /////////////////////////
    // Configuring GL Objects
    /////////////////////////
    Shader triangleShader("C:/Dev/Graphics/resources/shaders/triangle.vs", "C:/Dev/Graphics/resources/shaders/triangle.fs");

    float vertices[] = {
        // positions         // colors
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom left
        0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f    // top
    };

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    glfwSetFramebufferSizeCallback(window, (GLFWframebuffersizefun)framebuffer_size_callback);

    while (!glfwWindowShouldClose(window))
    {
        // check I/O events
        processInput(window);

        // clear screen's color buffer
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // state-using
        glClear(GL_COLOR_BUFFER_BIT);         // state-setting

        // rendering command here
        triangleShader.use();
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // swap buffers
        glfwSwapBuffers(window);
        // check events in que
        glfwPollEvents();
    }

    glfwTerminate();

    return true;
}

void framebuffer_size_callback(GLFWwindow *window, uint16_t width, uint16_t height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
