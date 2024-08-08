#ifndef PLATFORM_H
#define PLATFORM_H

#include <aocf/aocf.h>

#ifdef PLATFORM_WINDOWS
#include <windows.h>
#include <windowsx.h>
#endif

#ifdef PLATFORM_WINDOWS
#ifdef AOCF_EXPORTS
#define PLATFORM_API __declspec(dllexport)
#else
#define PLATFORM_API __declspec(dllimport)
#endif // AOCF_EXPORTS
#else
#define PLATFORM_API
#endif // PLATFORM_WINDOWS

namespace AOCF
{
    struct Window;

    struct PLATFORM_API Platform final
    {
        static Window *createWindow(int32 width, int32 height, const char *title);
        static void destroyWindow(Window *window);
        static bool initOpenGL(int32 major, int32 minor, int32 colorBits = 32, int32 depthBits = 24);
        static void pollEvents(Window *window);
        static void swapBuffers(Window *window);
        static bool getShouldClose(Window *window);
        static void setShouldClose(Window *window, bool shouldClose);
        static int getTime();
    };
}

#endif // AOCF_PLATFORM_H