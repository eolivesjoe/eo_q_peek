#pragma once

#include <windows.h>
#include <dwmapi.h>

namespace thumbnail
{
    class Thumbnail
    {
    public:
        Thumbnail(HWND destWindow, HWND srcWindow);

        ~Thumbnail();
        bool reg();

    private:
        HTHUMBNAIL m_thumbnail;
    };
} // namespace thumbnail