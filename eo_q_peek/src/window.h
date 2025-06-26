#pragma once
#include <windows.h>

namespace window
{
	class Window {
	public:
		Window(HINSTANCE hInst, int width, int height);
		~Window();
		bool create();
		HWND getHWND() const;
		void runMessageLoop();

	private:
		static LRESULT CALLBACK wndProc(HWND, UINT, WPARAM, LPARAM);
	};
} // namespace window