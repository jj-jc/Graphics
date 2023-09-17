// #include <iostream>
#define GLFW_INCLUDE_NONE // to void compilation problems with extension loading library
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

#include "shader.hpp"

const uint16_t WINDOW_HEIGHT = 600;
const uint16_t WINDOW_WIDTH = 800;

void framebuffer_size_callback(GLFWwindow *window, uint16_t width, uint16_t height);
void processInput(GLFWwindow *window);
int getMaxVertexAttribs();// return GL_MAX_VERTEX_ATTRIB

int main(int argc, char *argv[]) {
    /////////////////////////
    // Setting GL Context
    /////////////////////////
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize glfw\n");
        exit(EXIT_FAILURE);
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = nullptr;
    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Hello Textures", NULL, NULL);
    if (!window) {
        fprintf(stderr, "Failer to create a glfwWindow\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    // must do this before load glad library!!!
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        fprintf(stderr, "Failed to initialize Glad\n");
        exit(EXIT_FAILURE);
    }

    const char *version = (const char *) glGetString(GL_VERSION);
    fprintf(stderr, "OpenGL version: %s\n", version);

    /////////////////////////
    // Configuring GL Objects
    /////////////////////////
    Shader textureShader("C:/Dev/Graphics/resources/shaders/twoTextures.vs", "C:/Dev/Graphics/resources/shaders/twoTextures.fs");

    float vertices[] =
        {
            // positions            // colors           // TexCoord
            0.75f, 0.75f, 0.0f, 1.0f, 0.0f, 0.0f, 2.0f, 2.0f, // top right
            -0.75f, 0.75f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 2.0f,// top left
            0.75f, -0.75f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 0.0f,// bottom right
            -0.75f, -0.75f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f// bottom left

        };
    unsigned int indices[] =// It must be unsigned int always
        {
            0,
            1,
            2,// top triangle
            1,
            2,
            3// bottom triangle
        };

    unsigned int VAO, VBO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices, GL_STATIC_DRAW);

    // position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);
    // color
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // TexCoord
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) (6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    /////////////
    // Textures
    /////////////
    stbi_set_flip_vertically_on_load(true);// set stb_image.h to flip loaded texture's on the y-axis
    // glEnable(GL_BLEND);
    // glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    // Load image data
    int imageWidth, imageHeight, nrImageChannels;
    unsigned char *data = stbi_load("C:/Dev/Graphics/resources/textures/Wood_Wall.jpg",
                                    &imageWidth, &imageHeight, &nrImageChannels, 0);
    // config GL texture unit
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);// all upcomming GL_TEXTURE_2D oprations have effect on this texture object
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageWidth, imageHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        fprintf(stderr, "Failed to load texture\n");
    }

    data = stbi_load("C:/Dev/Graphics/resources/textures/Linux_penguin.png",
                     &imageWidth, &imageHeight, &nrImageChannels, 0);
    unsigned int texture2;
    glGenTextures(1, &texture2);
    glBindTexture(GL_TEXTURE_2D, texture2);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    float borderColor[] = {1.0f, 0.0f, 0.0f, 0.0f};
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imageWidth, imageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        fprintf(stderr, "Failed to load Texture\n");
    }

    stbi_image_free(data);
    /////////////////////////
    // Configure GL model
    /////////////////////////
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    glfwSetFramebufferSizeCallback(window, (GLFWframebuffersizefun) framebuffer_size_callback);
    // GL_FILL -> normal
    // GL_LINE -> wireframe mode
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    // Choose the shaderProgram to use
    textureShader.use();
    textureShader.setInt("ourTexture", 0);
    textureShader.setInt("ourTexture2", 1);

    // setting the texture unit, it is possible to change in every loop, have to be before binding VAO
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texture2);

    while (!glfwWindowShouldClose(window)) {
        // input
        processInput(window);

        // clear backbuffer
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // render
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        // swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // de-alocate all GL resources
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteProgram(textureShader.getProgramID());

    // terminate program
    glfwTerminate();
    return GL_TRUE;
}

void framebuffer_size_callback(GLFWwindow *window, uint16_t width, uint16_t height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// return GL_MAX_VERTEX_ATTRIB
int getMaxVertexAttribs() {
    int nrAttribs = 0;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttribs);
    return nrAttribs;
}
