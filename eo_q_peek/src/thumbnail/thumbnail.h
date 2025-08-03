#pragma once

#include <windows.h>
#include <dwmapi.h>

namespace thumbnail
{
    class Thumbnail
    {
    public:
        ~Thumbnail();

        bool Init(HWND dest, HWND src);
        void Cleanup();

    private:
        HWND m_dest = nullptr;
        HTHUMBNAIL m_thumb = nullptr;
    };
} // namespace thumbnail