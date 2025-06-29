#include "utils.h"
#include "thumbnail.h"

namespace thumbnail
{
    bool setupThumbnail(HWND dest, HWND src, HTHUMBNAIL& thumb)
    {
        if (FAILED(DwmRegisterThumbnail(dest, src, &thumb)))
        {
            return false;
        }

        RECT destRect = { 0, 0, THUMB_WIDTH, THUMB_HEIGHT };
        DWM_THUMBNAIL_PROPERTIES props = {};
        props.dwFlags = DWM_TNP_VISIBLE | DWM_TNP_RECTDESTINATION;
        props.fVisible = TRUE;
        props.rcDestination = destRect;

        return SUCCEEDED(DwmUpdateThumbnailProperties(thumb, &props));
    }

    void cleanupThumbnail(HWND dest, HTHUMBNAIL thumb)
    {
        if (thumb)
        {
            DwmUnregisterThumbnail(thumb);
        }
        if (dest)
        {
            DestroyWindow(dest);
        }
    }
}
