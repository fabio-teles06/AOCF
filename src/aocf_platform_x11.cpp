#include <aocf/aocf.h>
#include <aocf/aocf_platform.h>
#include <aocf/aocf_gl.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <GL/glx.h>
#include <iostream>

namespace AOCF
{
    struct Window
    {
        Display *display;
        Window handle;
        bool shouldClose;
        GLXContext glContext;
    };

    static struct RenderAPIInfo
    {
        enum RenderAPIName
        {
            NONE = 0,
            OPENGL = 1
        };

        struct OpenGL
        {
            GLXContext sharedContext;
            unsigned int versionMajor;
            unsigned int versionMinor;
        };

        RenderAPIName name;
        OpenGL gl;
    } globalRenderApiInfo;

    bool Platform::initOpenGL(int32 major, int32 minor, int32 colorBits, int32 depthBits)
    {
        Window *dummyWindow = createWindow(1, 1, "");

        if (!dummyWindow)
        {
            return false;
        }

        globalRenderApiInfo.name = globalRenderApiInfo.OPENGL;
        globalRenderApiInfo.gl.versionMajor = major;
        globalRenderApiInfo.gl.versionMinor = minor;
        globalRenderApiInfo.gl.sharedContext = dummyWindow->glContext;

        destroyWindow(dummyWindow);
        return true;
    }

    Window *Platform::createWindow(int32 width, int32 height, const char *title)
    {
        Display *display = XOpenDisplay(NULL);
        if (!display)
        {
            return nullptr;
        }

        int screen = DefaultScreen(display);
        Window rootWindow = RootWindow(display, screen);

        GLint attribs[] = {
            GLX_RGBA,
            GLX_DEPTH_SIZE,
            24,
            GLX_DOUBLEBUFFER,
            None};
        XVisualInfo *vi = glXChooseVisual(display, screen, attribs);
        if (!vi)
        {
            XCloseDisplay(display);
            return nullptr;
        }

        Colormap colormap = XCreateColormap(display, rootWindow, vi->visual, AllocNone);
        XSetWindowAttributes swa;
        swa.colormap = colormap;
        swa.event_mask = ExposureMask | KeyPressMask | StructureNotifyMask;

        Window win = XCreateWindow(display, rootWindow, 0, 0, width, height, 0, vi->depth, InputOutput, vi->visual, CWColormap | CWEventMask, &swa);
        XStoreName(display, win, title);
        XMapWindow(display, win);

        GLXContext glContext = glXCreateContext(display, vi, globalRenderApiInfo.gl.sharedContext, GL_TRUE);
        if (!glContext)
        {
            XDestroyWindow(display, win);
            XCloseDisplay(display);
            return nullptr;
        }

        Window *window = new Window();
        window->display = display;
        window->handle = win;
        window->shouldClose = false;
        window->glContext = glContext;

        return window;
    }

    void Platform::destroyWindow(Window *window)
    {
        glxDestroyContext(window->display, window->glContext);
        XDestroyWindow(window->display, window->handle);
        XCloseDisplay(window->display);
        delete window;
    }

    void Platform::pollEvents(Window *window){
        XEvent event;
        while (XPending(window->display)){
            XNextEvent(window->display, &event);
            if (event.type == DestroyNotify){
                window->shouldClose = true;
            }
        }
    }

    void Platform::swapBuffers(Window *window)
    {
        glXSwapBuffers(window->display, window->handle);
    }

    bool Platform::getShouldClose(Window *window){
        return window->shouldClose;
    }

    void Platform::setShouldClose(Window *window, bool shouldClose){
        window->shouldClose = shouldClose;
    }

    int Platform::getTime(){
        return (int)(clock() / (CLOCKS_PER_SEC / 1000));
    }
}