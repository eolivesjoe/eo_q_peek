#include "utils.h"

namespace util
{
	HWND FindWindowByTitle(const char* title)
	{
		return FindWindowA(nullptr, title);
	}

	void GetScreenBottomRight(int& x, int& y)
	{
		RECT workArea;
		SystemParametersInfo(SPI_GETWORKAREA, 0, &workArea, 0);

		x = workArea.right - THUMB_WIDTH;
		y = workArea.bottom - THUMB_HEIGHT - 24;
	}
}