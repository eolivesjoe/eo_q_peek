#include <windows.h>

#include "app.h"
#include "logger.h"
#include "utils.h"

namespace app
{
    bool App::init(const char* appName)
    {
        if (!appName || appName[0] == '\0')
        {
            logger::error("No app name provided.");
            return false;
        }

        m_target = util::findWindowByTitle(appName);
        if (!m_target)
        {
            logger::error("Could not find target window.");
            return false;
        }

        HINSTANCE hInstance = GetModuleHandle(nullptr);
        if (!m_window.create(hInstance))
        {
            logger::error("Failed to create window.");
            return false;
        }

        m_window.show();

        if (!m_thumbnail.init(m_window.hwnd(), m_target))
        {
            logger::error("Failed to initialise thumbnail.");
            return false;
        }

        logger::info("App initialised.");
        return true;
    }

    void App::run()
    {
        MSG msg = {};
        while (GetMessage(&msg, nullptr, 0, 0)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        logger::info("Exiting message loop.");
    }
}