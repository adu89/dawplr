#include "TrackLane.h"

#include <wx/dcbuffer.h>
#include <wx/dcgraph.h>

TrackLane::TrackLane(wxWindow* parent, int index)
    : wxPanel(parent, index)
{
    SetBackgroundStyle(wxBG_STYLE_PAINT);

    Bind(wxEVT_PAINT, &TrackLane::OnPaint, this);
}

TrackLane::~TrackLane()
{
} 

void TrackLane::OnPaint(wxPaintEvent&)
{
    wxBufferedPaintDC dc(this);
    wxGCDC gc(dc);

    wxRect rect = GetClientRect();

    auto currentBpm = 120;
    auto note = 2;
    auto pixelsPerBeat = 100;
    auto slice = pixelsPerBeat / note;

    gc.SetPen(*wxLIGHT_GREY_PEN);
    gc.SetBrush(*wxLIGHT_GREY_BRUSH);

    gc.DrawRectangle(rect);

    gc.SetPen(*wxMEDIUM_GREY_PEN);
    gc.SetBrush(*wxMEDIUM_GREY_BRUSH);

    wxRect beatRect = wxRect(rect.GetTopLeft(), wxSize(slice, rect.GetHeight()));

    do 
    {
        gc.DrawRectangle(beatRect.GetTopRight(), wxSize(2, rect.GetHeight()));
        beatRect.Offset(slice, 0);
    } while (beatRect.GetRight() < rect.GetRight());

    gc.DrawRectangle(rect.GetBottomLeft() - wxSize(0, 1), wxSize(rect.GetWidth(), 2));

    gc.SetPen(wxColour(50, 205, 50, 255));
    gc.SetBrush(wxColour(50, 205, 50, 100));

    gc.DrawRoundedRectangle(rect.GetTopLeft() + wxSize(4, 4), wxSize(rect.GetWidth() - 8, rect.GetHeight() - 10), 4);    
}

void TrackLane::HandleMouseWheelEvent(wxMouseEvent& m) 
{    
    m.Skip();
}

BEGIN_EVENT_TABLE(TrackLane, wxWindow)
    EVT_MOUSEWHEEL(TrackLane::HandleMouseWheelEvent)
END_EVENT_TABLE()