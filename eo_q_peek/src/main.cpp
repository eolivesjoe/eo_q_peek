#include <thread>
#include <chrono>

#include "window.h"
#include "thumbnail.h"
#include "utils.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int)
{
    HWND overlayHwnd = nullptr;
    HWND targetHwnd = nullptr;
    HTHUMBNAIL thumbnail = nullptr;

    targetHwnd = util::findWindowByTitle(TARGET_WINDOW_TITLE);
    if (!targetHwnd)
    {
        MessageBox(nullptr, "Window not found.", "Error", MB_OK);
        return 1;
    }

    while (true)
    {
        HWND foregroundWindow = GetForegroundWindow();

        if (foregroundWindow != targetHwnd && !overlayHwnd)
        {
            overlayHwnd = window::createWindow(hInstance);
            thumbnail::setupThumbnail(overlayHwnd, targetHwnd, thumbnail);
        }
        else if (foregroundWindow == targetHwnd && overlayHwnd)
        {
            thumbnail::cleanupThumbnail(overlayHwnd, thumbnail);
            overlayHwnd = nullptr;
            thumbnail = nullptr;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    return 0;
}