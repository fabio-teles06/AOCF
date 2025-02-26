#include <aocf/aocf_platform.h>
#include <aocf/aocf_keyboard.h>
#include <aocf/aocf_gl.h>

int main()
{
    if (!AOCF::Platform::initOpenGL(3, 3))
    {
        return -1;
    }
    AOCF::Window *w = AOCF::Platform::createWindow(800, 600, "AOCF Window");

    AOCF::Keyboard keyboard;

    while (!AOCF::Platform::getShouldClose(w))
    {
        AOCF::Platform::pollEvents(w);

        if (keyboard.getKeyUp(AOCF::KEYCODE_A)){
            AOCF::Platform::setShouldClose(w, true);
        }

        AOCF::Platform::swapBuffers(w);
    }

    AOCF::Platform::destroyWindow(w);

    return 0;
}