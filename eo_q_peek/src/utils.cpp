#include "utils.h"

namespace util
{
    HWND findWindowByTitle(const char* title)
    {
        return FindWindowA(nullptr, title);
    }

    void getScreenBottomRight(int& x, int& y)
    {
        RECT m_desktop;
        const HWND m_hDesktop = GetDesktopWindow();
        GetWindowRect(m_hDesktop, &m_desktop);
        x = m_desktop.right - THUMB_WIDTH;
        y = m_desktop.bottom - THUMB_HEIGHT;
    }
}