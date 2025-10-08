#include "thumbnail.h"
#include "../utils/utils.h"

namespace thumbnail
{
    Thumbnail::~Thumbnail()
    {
        Cleanup();
    }

    bool Thumbnail::Init(HWND dest, HWND src)
    {
        m_dest = dest;

        if (FAILED(DwmRegisterThumbnail(dest, src, &m_thumb)))
        {
            return false;
        }

        RECT destRect = { 0, 0, THUMB_WIDTH, THUMB_HEIGHT };
        DWM_THUMBNAIL_PROPERTIES props = {};
        props.dwFlags = DWM_TNP_VISIBLE | DWM_TNP_RECTDESTINATION;
        props.fVisible = TRUE;
        props.rcDestination = destRect;

        return SUCCEEDED(DwmUpdateThumbnailProperties(m_thumb, &props));
    }

    void Thumbnail::Cleanup()
    {
        if (m_thumb)
        {
            DwmUnregisterThumbnail(m_thumb);
            m_thumb = nullptr;
        }
        if (m_dest)
        {
            DestroyWindow(m_dest);
            m_dest = nullptr;
        }
    }

    void Thumbnail::Show()
    {
        if (!m_thumb) return;

        DWM_THUMBNAIL_PROPERTIES props = {};
        props.dwFlags = DWM_TNP_VISIBLE;
        props.fVisible = TRUE;

		GetClientRect(m_dest, &props.rcDestination);
        DwmUpdateThumbnailProperties(m_thumb, &props);
	}

    void Thumbnail::Hide()
    {
        if (!m_thumb) return;

        DWM_THUMBNAIL_PROPERTIES props = {};
        props.dwFlags = DWM_TNP_VISIBLE;
        props.fVisible = FALSE;

        GetClientRect(m_dest, &props.rcDestination);
        DwmUpdateThumbnailProperties(m_thumb, &props);
	}
}