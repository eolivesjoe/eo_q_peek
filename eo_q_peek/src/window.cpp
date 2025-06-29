#include "utils.h"
#include "window.h"

namespace window
{
    HWND createWindow(HINSTANCE hInstance)
    {
        const char CLASS_NAME[] = "OverlayWindow";

        WNDCLASS wc = {};
        wc.lpfnWndProc = DefWindowProc;
        wc.hInstance = hInstance;
        wc.lpszClassName = CLASS_NAME;

        RegisterClass(&wc);

        int x, y;
        util::getScreenBottomRight(x, y);

        HWND hwnd = CreateWindowEx(
            WS_EX_TOPMOST | WS_EX_TOOLWINDOW | WS_EX_NOACTIVATE,
            CLASS_NAME, "",
            WS_POPUP,
            x, y, THUMB_WIDTH, THUMB_HEIGHT,
            nullptr, nullptr, hInstance, nullptr);

        ShowWindow(hwnd, SW_SHOWNOACTIVATE);
        return hwnd;
    }
}