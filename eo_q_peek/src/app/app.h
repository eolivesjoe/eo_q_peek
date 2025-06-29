#pragma once

#include "../window/window.h"
#include "../thumbnail/thumbnail.h"

namespace app
{
	class App
	{
	public:
		bool init(const char* appName);
		void run();

	private:
		class window::Window m_window;
		class thumbnail::Thumbnail m_thumbnail;
		HWND m_target = nullptr;
	};
} // namespace app