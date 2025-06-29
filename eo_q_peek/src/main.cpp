#include "window.h"
#include "thumbnail.h"
#include "utils.h"
#include <thread>
#include <chrono>

HWND g_overlayHwnd = nullptr;
HWND g_targetHwnd = nullptr;
HTHUMBNAIL g_thumbnail = nullptr;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int)
{
    g_targetHwnd = util::findWindowByTitle(TARGET_WINDOW_TITLE);
    if (!g_targetHwnd)
    {
        MessageBox(nullptr, "Quake window not found.", "Error", MB_OK);
        return 1;
    }

    while (true)
    {
        HWND fg = GetForegroundWindow();

        if (fg != g_targetHwnd && !g_overlayHwnd)
        {
            g_overlayHwnd = window::createWindow(hInstance);
            thumbnail::setupThumbnail(g_overlayHwnd, g_targetHwnd, g_thumbnail);
        }
        else if (fg == g_targetHwnd && g_overlayHwnd)
        {
            thumbnail::cleanupThumbnail(g_overlayHwnd, g_thumbnail);
            g_overlayHwnd = nullptr;
            g_thumbnail = nullptr;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    return 0;
}
