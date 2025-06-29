#include "window.h"
#include "utils.h"

namespace window
{
	bool Window::create(HINSTANCE hInstance)
	{
		const char CLASS_NAME[] = "Window";

		WNDCLASS wc = {};
		wc.lpfnWndProc = overlayProc;
		wc.lpfnWndProc = DefWindowProc;
		wc.hInstance = hInstance;
		wc.lpszClassName = CLASS_NAME;

		RegisterClass(&wc);

		int x, y;
		util::getScreenBottomRight(x, y);

		m_hwnd = CreateWindowEx(
			WS_EX_TOPMOST | WS_EX_TOOLWINDOW | WS_EX_NOACTIVATE,
			CLASS_NAME, "",
			WS_POPUP,
			x, y, THUMB_WIDTH, THUMB_HEIGHT,
			nullptr, nullptr, hInstance, nullptr);

		LONG ex_style = GetWindowLong(m_hwnd, GWL_EXSTYLE);
		SetWindowLong(m_hwnd, GWL_EXSTYLE, ex_style | WS_EX_LAYERED | WS_EX_TRANSPARENT);
		SetLayeredWindowAttributes(m_hwnd, 0, 255, LWA_ALPHA);

		return m_hwnd != nullptr;
	}

	void Window::show()
	{
		if (m_hwnd)
		{
			ShowWindow(m_hwnd, SW_SHOWNOACTIVATE);
		}
	}

	HWND Window::hwnd() const
	{
		return m_hwnd;
	}

	LRESULT CALLBACK Window::overlayProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
		switch (msg)
		{
		case WM_PAINT:
		{
			PAINTSTRUCT ps;
			BeginPaint(hwnd, &ps);
			EndPaint(hwnd, &ps);
			return 0;
		}
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		}
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
}