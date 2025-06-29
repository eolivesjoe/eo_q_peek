#include "utils.h"

namespace util
{
	HWND findWindowByTitle(const char* title)
	{
		return FindWindowA(nullptr, title);
	}

	void getScreenBottomRight(int& x, int& y)
	{
		//RECT m_desktop_rect;
		//const HWND m_desktop = GetDesktopWindow();
		//GetWindowRect(m_desktop, &m_desktop_rect);

		RECT work_area;
		SystemParametersInfo(SPI_GETWORKAREA, 0, &work_area, 0);

		x = work_area.right - THUMB_WIDTH;
		y = work_area.bottom - THUMB_HEIGHT - 24;
	}
}