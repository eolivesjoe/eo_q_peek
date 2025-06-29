#include <thread>
#include <chrono>
#include <string>

#include "window.h"
#include "thumbnail.h"
#include "utils.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR lpCmdLine, int)
{
    HWND overlay_hwnd = nullptr;
    HWND target_hwnd = nullptr;
    HTHUMBNAIL thumbnail = nullptr;
    const char* app_name = lpCmdLine;

    target_hwnd = util::findWindowByTitle(app_name);
    if (!target_hwnd)
    {
        return 1;
    }

    while (true)
    {
        HWND foreground_window = GetForegroundWindow();

        if (foreground_window != target_hwnd && !overlay_hwnd)
        {
            overlay_hwnd = window::createWindow(hInstance);
            thumbnail::setupThumbnail(overlay_hwnd, target_hwnd, thumbnail);
        }
        else if (foreground_window == target_hwnd && overlay_hwnd)
        {
            thumbnail::cleanupThumbnail(overlay_hwnd, thumbnail);
            overlay_hwnd = nullptr;
            thumbnail = nullptr;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    return 0;
}