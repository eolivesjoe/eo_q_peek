#include <windows.h>

#include "app.h"
#include "../logger/logger.h"
#include "../utils/utils.h"

namespace app
{
    bool App::Init(const char* appName)
    {
        if (!appName || appName[0] == '\0')
        {
            logger::Error("No app name provided.");
            return false;
        }

        m_target = util::FindWindowByTitle(appName);
        if (!m_target)
        {
            logger::Error("Could not find target window.");
            return false;
        }

        HINSTANCE hInstance = GetModuleHandle(nullptr);
        if (!m_window.Create(hInstance))
        {
            logger::Error("Failed to create window.");
            return false;
        }

        m_window.Show();

        if (!m_thumbnail.Init(m_window.Hwnd(), m_target))
        {
            logger::Error("Failed to initialise thumbnail.");
            return false;
        }

        logger::Info("App initialised.");
        return true;
    }

    void App::Run()
    {
        MSG msg = {};
        while (true) 
        {
            while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) 
            {
                if (msg.message == WM_QUIT) 
                {
                    logger::Info("Received WM_QUIT message.");
                    return;
                }

                TranslateMessage(&msg);
                DispatchMessage(&msg);
			}

            if (!IsWindow(m_target))
            {
                logger::Warning("Target window no longer exists. Exiting app.");
                PostQuitMessage(0);
                return;
            }

            UpdateFocusState();

			// prevents high CPU usage
			Sleep(100);
        }
    }

    void App::UpdateFocusState()
    {
        HWND fg = GetForegroundWindow();

        if (fg == m_target)
        {
            if (!m_isTargetFocused)
            {
                m_thumbnail.Hide();
                m_isTargetFocused = true;
                logger::Info("Target focused.");
            }
        }
        else
        {
            if (m_isTargetFocused)
            {
                m_thumbnail.Show();
                m_isTargetFocused = false;
                logger::Info("Target unfocused.");
            }
        }
	}
}