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
        while (GetMessage(&msg, nullptr, 0, 0)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        logger::Info("Exiting message loop.");
    }
}