#pragma once

#include "../window/window.h"
#include "../thumbnail/thumbnail.h"

namespace app
{
	class App
	{
	public:
		bool Init(const char* appName);
		void Run();
		void UpdateFocusState();

	private:
		class window::Window m_window;
		class thumbnail::Thumbnail m_thumbnail;
		HWND m_target = nullptr;
		bool m_isTargetFocused = false;
	};
} // namespace app