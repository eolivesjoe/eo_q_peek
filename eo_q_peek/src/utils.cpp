#include "utils.h"

namespace util
{
    HWND findWindowByTitle(const char* title)
    {
        return FindWindowA(nullptr, title);
    }

    void getScreenBottomRight(int& x, int& y)
    {
        RECT m_desktop_rect;
        const HWND m_desktop = GetDesktopWindow();
        GetWindowRect(m_desktop, &m_desktop_rect);
        x = m_desktop_rect.right - THUMB_WIDTH;
        y = m_desktop_rect.bottom - THUMB_HEIGHT;
    }
}