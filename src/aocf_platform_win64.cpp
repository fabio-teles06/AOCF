#include <aocf.h>
#include <aocf_platform.h>

namespace AOCF
{
    struct Window
    {
        HWND handle;
        bool shouldClose;
        //
    };

    LRESULT aocfWindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
    {
        switch (msg)
        {
        case WM_CLOSE:
        {
            DestroyWindow(hwnd);
            break;
        }
        case WM_DESTROY:
        {
            PostQuitMessage(0);
            break;
        }
        default:
        {
            return DefWindowProc(hwnd, msg, wParam, lParam);
        }
        }
        return 0;
    }

    Window *Platform::createWindow(int32 width, int32 height, const char *title)
    {
        const char *aocfWindowClass = "AOCF_WINDOW_CLASS";
        HINSTANCE hInstance = GetModuleHandle(NULL);
        WNDCLASSEXA wc = {};

        if (!GetClassInfoExA(hInstance, aocfWindowClass, &wc))
        {
            wc.cbSize = sizeof(WNDCLASSEXA);
            wc.style = CS_HREDRAW | CS_VREDRAW;
            wc.lpfnWndProc = aocfWindowProc;
            wc.hInstance = hInstance;
            wc.hCursor = LoadCursor(NULL, IDC_ARROW);
            wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
            wc.lpszClassName = aocfWindowClass;

            if (!RegisterClassExA(&wc))
            {
                return nullptr;
            }
        }

        HWND windowHandle = CreateWindowExA(
            0,
            aocfWindowClass,
            title,
            WS_OVERLAPPEDWINDOW | WS_VISIBLE,
            CW_USEDEFAULT, CW_USEDEFAULT,
            width, height,
            NULL, NULL, hInstance, NULL);

        if (!windowHandle)
        {
            return nullptr;
        }

        Window *window = new Window();
        window->handle = windowHandle;
        window->shouldClose = false;

        return window;
    }

    void Platform::pollEvents()
    {
        MSG msg = {};
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    bool Platform::getShouldClose(Window *window)
    {
        return window->shouldClose;
    }

    void Platform::setShouldClose(Window *window, bool shouldClose)
    {
        window->shouldClose = shouldClose;
    }

    int Platform::getTime()
    {
        return GetTickCount();
    }

}