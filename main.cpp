#include </opt/homebrew/opt/glew/include/GL/glew.h>
#include </opt/homebrew/opt/glfw/include/GLFW/glfw3.h>
#include <cstdio>

// install glfw (graphics library framework) - brew install glfw
// include the path in c_cpp_properties.json

void error_callback(int error, const char *description)
{
    fprintf(stderr, "Error: %s\n", description);
}

int main()
{
    // typedef void(*GLFWerrorfun)(int, const char *)
    glfwSetErrorCallback(error_callback);

    glewExperimental = GL_TRUE;

    if (!glfwInit())
    {
        return -1;
    }

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow *window = glfwCreateWindow(640, 480, "Space Invaders", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    GLenum err = glewInit();
    if (err != GLEW_OK)
    {
        fprintf(stderr, "Error initializing GLEW.\n");
        glfwTerminate();
        return -1;
    }

    int glVersion[2] = {-1, 1};
    glGetIntegerv(GL_MAJOR_VERSION, &glVersion[0]);
    glGetIntegerv(GL_MINOR_VERSION, &glVersion[1]);

    printf("Using OpenGL: %d.%d\n", glVersion[0], glVersion[1]);

    glClearColor(1.0, 0.0, 0.0, 1.0);
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

/**
 * g++ -std=c++11 -o main -lglfw -lglew -framework OpenGL main.cpp
 * have to include the paths for the flags
 * create a makefile so you dont have to do

    g++ main.cpp -o app \
    -I/opt/homebrew/opt/glew/include \
    -I/opt/homebrew/opt/glfw/include \
    -L/opt/homebrew/opt/glew/lib \
    -L/opt/homebrew/opt/glfw/lib \
    -framework OpenGL \
    -lglfw -lGLEW

 * everytime want to build
 */