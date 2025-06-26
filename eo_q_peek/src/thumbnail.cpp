#include "thumbnail.h"

namespace thumbnail 
{
	Thumbnail::Thumbnail(HWND destWindow, HWND srcWindow)
	{
		m_thumbnail = nullptr;
	}

	Thumbnail::~Thumbnail() {}

	bool Thumbnail::reg()
	{
		return true;
	}
}