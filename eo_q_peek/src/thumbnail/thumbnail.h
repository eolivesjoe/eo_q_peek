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
        void Show();
        void Hide();

    private:
        HWND m_dest = nullptr;
        HTHUMBNAIL m_thumb = nullptr;
    };
} // namespace thumbnail