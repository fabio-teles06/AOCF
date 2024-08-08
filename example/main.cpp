#include <aocf/aocf_platform.h>
#include <aocf/aocf_gl.h>

int main()
{
    AOCF::Platform::initOpenGL(3, 2);
    AOCF::Window *w = AOCF::Platform::createWindow(800, 600, "AOCF Window");

    // timer
    int lastTime = AOCF::Platform::getTime();
    while (!AOCF::Platform::getShouldClose(w))
    {
        AOCF::Platform::pollEvents(w);

        

        AOCF::Platform::swapBuffers(w);
    }

    return 0;
}