#pragma once

#include <windows.h>

constexpr int THUMB_WIDTH = 320;
constexpr int THUMB_HEIGHT = 180;
constexpr const char* TARGET_WINDOW_TITLE = "Quake Live";

namespace util
{
    HWND findWindowByTitle(const char* title);
    void getScreenBottomRight(int& x, int& y);
} // namespace util
