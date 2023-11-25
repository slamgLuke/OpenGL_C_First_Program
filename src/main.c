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


int main()
{
    glewExperimental = 1;
    GLFWwindow* window = initWindow(600, 400, "Hello World! :)");
    if (window == NULL) return 1;
    printf("OpenGL: version supported by this platform (%s): \n", glGetString(GL_VERSION));


    // VAO
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // An array of 3 vectors which represents 3 vertices
    static const GLfloat g_vertex_buffer_data[] = {
        0.f, 0.f, 0.f,
        1.f, 0.f, 0.f,
        1.f, 1.f, 0.f,
        0.f, 1.f, 0.f
    };


    // This will identify our vertex buffer
    GLuint vertexbuffer;
    // Generate 1 buffer, put the resulting identifier in vertexbuffer
    glGenBuffers(1, &vertexbuffer);
    // The following commands will talk about our 'vertexbuffer' buffer
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    // Give our vertices to OpenGL.
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);


    // Create and compile our GLSL program from the shaders
    GLuint programID = LoadShaders(VERT_SHADER, FRAG_SHADER);

    // Clock for shaders
    GLint timeUniform = glGetUniformLocation(programID, "time");
    double startTime = glfwGetTime();
    

    // Main loop
    do {
        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT);

        // Bind vao
        glBindVertexArray(vao);

        // Use our shader
        glUseProgram(programID);


        // Set time uniform variable
        double currentTime = glfwGetTime();
        glUniform1f(timeUniform, (float)(currentTime - startTime));

        
        // 1rst attribute buffer : vertices
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glVertexAttribPointer(
            0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
            3,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0,                  // stride
            NULL            // array buffer offset
        );

        // Draw shape
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
        glDisableVertexAttribArray(0);


        // Unbind vao
        glBindVertexArray(0);


        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && // Exit if the ESC key was pressed
           glfwWindowShouldClose(window) == 0);                 // or window was closed

    return 0;
}
