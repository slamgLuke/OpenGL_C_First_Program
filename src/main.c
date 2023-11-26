#include "initWindow.h"
#include "shaderLoader.h"

#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <cglm/cglm.h>


#define SHADER_PATH "shaders/"
#define VERT_SHADER SHADER_PATH "vert.glsl"
#define FRAG_SHADER SHADER_PATH "checkers_frag.glsl"

#define WIDTH 1920
#define HEIGHT 1080


int main()
{
    glewExperimental = 1;
    GLFWwindow* window = initWindow(WIDTH, HEIGHT, "Hello World! :)");
    if (window == NULL) return 1;
    printf("OpenGL: version supported by this platform (%s): \n", glGetString(GL_VERSION));

    static const GLfloat bgVertexData[] = {
        0.f, 0.f, 0.f,
        1.f, 0.f, 0.f,
        1.f, 1.f, 0.f,
        0.f, 1.f, 0.f
    };

    static const GLfloat cubeVertexdata[] = {
        // Front face
        0.25f, 0.25f, -0.25f,
        0.75f, 0.25f, -0.25f,
        0.75f, 0.75f, -0.25f,
        0.25f, 0.75f, -0.25f,

        // Back face
        0.25f, 0.75f, -0.75f,
        0.75f, 0.75f, -0.75f,
        0.75f, 0.25f, -0.75f,
        0.25f, 0.25f, -0.75f
    };

    GLuint bgVAO, bgVBO, cubeVAO, cubeVBO;
    glGenVertexArrays(1, &bgVAO);
    glGenBuffers(1, &bgVBO);

    glGenVertexArrays(1, &cubeVAO);
    glGenBuffers(1, &cubeVBO);

    // BG
    glBindVertexArray(bgVAO);

    glBindBuffer(GL_ARRAY_BUFFER, bgVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(bgVertexData), bgVertexData, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    glBindVertexArray(0);

    // Cube
    glBindVertexArray(cubeVAO);

    glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertexdata), cubeVertexdata, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    glBindVertexArray(0);



    GLuint programID = LoadShaders(VERT_SHADER, FRAG_SHADER);

    // Clock for checker bg shader
    GLint timeUniform = glGetUniformLocation(programID, "time");
    double startTime = glfwGetTime();

    // Object type uniform
    GLint objectTypeUniform = glGetUniformLocation(programID, "objectType");
    


    // Main loop
    do {
        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT);

        // Use our shader
        glUseProgram(programID);

        // Set time uniform variable
        double currentTime = glfwGetTime();
        glUniform1f(timeUniform, (float)(currentTime - startTime));

        // Draw BG
        glUniform1i(objectTypeUniform, 0);
        glBindVertexArray(bgVAO);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
        glBindVertexArray(0);

        // Draw cube
        glUniform1i(objectTypeUniform, 1);
        glBindVertexArray(cubeVAO);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 8);
        glBindVertexArray(0);


        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && // Exit if the ESC key was pressed
           glfwWindowShouldClose(window) == 0);                 // or window was closed

    return 0;
}
