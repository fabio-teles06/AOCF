#include <aocf_platform.h>

int main()
{
    AOCF::Window *w = AOCF::Platform::createWindow(800, 600, "AOCF Window");

    //timer
    int lastTime = AOCF::Platform::getTime();
    while (!AOCF::Platform::getShouldClose(w))
    {
        AOCF::Platform::pollEvents();

        if (AOCF::Platform::getTime() - lastTime > 1000)
        {
            AOCF::Platform::setShouldClose(w, true);
        }
    }

    return 0;
}