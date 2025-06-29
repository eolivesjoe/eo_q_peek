#pragma once

#include <windows.h>

constexpr int THUMB_WIDTH = 400;
constexpr int THUMB_HEIGHT = 225;

namespace util
{
    HWND findWindowByTitle(const char* title);
    void getScreenBottomRight(int& x, int& y);
} // namespace util
