#include "thumbnail.h"
#include "utils.h"

namespace thumbnail
{
    bool Thumbnail::init(HWND dest, HWND src)
    {
        m_dest = dest;

        if (FAILED(DwmRegisterThumbnail(dest, src, &m_thumb)))
        {
            return false;
        }

        RECT dest_rect = { 0, 0, THUMB_WIDTH, THUMB_HEIGHT };
        DWM_THUMBNAIL_PROPERTIES props = {};
        props.dwFlags = DWM_TNP_VISIBLE | DWM_TNP_RECTDESTINATION;
        props.fVisible = TRUE;
        props.rcDestination = dest_rect;

        return SUCCEEDED(DwmUpdateThumbnailProperties(m_thumb, &props));
    }

    void Thumbnail::cleanup()
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

    Thumbnail::~Thumbnail()
    {
        cleanup();
    }
}