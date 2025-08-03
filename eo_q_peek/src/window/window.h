#pragma once

#include <windows.h>
namespace window
{
    class Window
    {
    public:
        bool Create(HINSTANCE hInstance);
        void Show();
        HWND Hwnd() const;

    private:
        HWND m_hwnd = nullptr;
        static LRESULT CALLBACK OverlayProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
    };
} // namespace window