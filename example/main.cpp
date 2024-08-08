#include <aocf/aocf_platform.h>
#include <aocf/aocf_gl.h>

#include <stdio.h>

int main()
{
    AOCF::Platform::initOpenGL(3, 2);
    AOCF::Window *w = AOCF::Platform::createWindow(800, 600, "AOCF Window");

    // create a triangle
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f};

    unsigned int VBO;
    //glGenBuffers(1, &VBO);
    //glBindBuffer(GL_ARRAY_BUFFER, VBO);
    //glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    // 1. then set the vertex attributes pointers
    //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    //glEnableVertexAttribArray(0);

    // // create a shader
    // const char *vertexShaderSource = "#version 150 core\n"
    //                                  "in vec3 aPos;\n"
    //                                  "void main()\n"
    //                                  "{\n"
    //                                  "    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    //                                  "}\0";
    // const char *fragmentShaderSource = "#version 150 core\n"
    //                                    "out vec4 FragColor;\n"
    //                                    "void main()\n"
    //                                    "{\n"
    //                                    "    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    //                                    "}\0";

    // int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    // glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    // glCompileShader(vertexShader);

    // int success;
    // char infoLog[512];
    // glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    // if (!success)
    // {
    //     glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    //     printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n%s\n", infoLog);
    // }

    // int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    // glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    // glCompileShader(fragmentShader);

    // glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    // if (!success)
    // {
    //     glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
    //     printf("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n%s\n", infoLog);
    // }

    // int shaderProgram = glCreateProgram();
    // glAttachShader(shaderProgram, vertexShader);
    // glAttachShader(shaderProgram, fragmentShader);

    // glLinkProgram(shaderProgram);

    // glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    // if (!success)
    // {
    //     glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
    //     printf("ERROR::SHADER::PROGRAM::LINKING_FAILED\n%s\n", infoLog);
    // }

    // glUseProgram(shaderProgram);
    // glDeleteShader(vertexShader);
    // glDeleteShader(fragmentShader);

    while (!AOCF::Platform::getShouldClose(w))
    {
        AOCF::Platform::pollEvents(w);

        AOCF::Platform::swapBuffers(w);
    }

    // cleanup
    //glDeleteProgram(shaderProgram);
    // glDeleteBuffers(1, &VBO);
    AOCF::Platform::destroyWindow(w);

    return 0;
}