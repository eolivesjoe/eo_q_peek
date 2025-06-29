#pragma once

#include <windows.h>
namespace window
{
    class Window
    {
    public:
        bool create(HINSTANCE hInstance);
        void show();
        HWND hwnd() const;

    private:
        HWND m_hwnd = nullptr;
        static LRESULT CALLBACK overlayProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
    };
} // namespace window