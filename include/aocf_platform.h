#ifndef PLATFORM_H
#define PLATFORM_H

#include <aocf.h>

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
        static Window* createWindow(int32 width, int32 height, const char* title);
        static void pollEvents();
        static bool getShouldClose(Window* window);
        static void setShouldClose(Window* window, bool shouldClose);
        static int getTime();
        // static Window* CreateWindow(const char* title, int width, int height);
        // static void DestroyWindow(Window* window);
        // static void SwapBuffers(Window* window);
    };
}

#endif