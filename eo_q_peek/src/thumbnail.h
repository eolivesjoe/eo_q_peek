#pragma once

#include <windows.h>
#include <dwmapi.h>

#pragma comment(lib, "dwmapi.lib")

namespace thumbnail
{
    bool setupThumbnail(HWND dest, HWND src, HTHUMBNAIL& thumb);
    void cleanupThumbnail(HWND dest, HTHUMBNAIL thumb);
} // namespace thumbnail