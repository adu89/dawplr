#include "TrackHeader.h"

#include <wx/dcbuffer.h>
#include <wx/dcgraph.h>

TrackHeader::TrackHeader(wxWindow* parent, int index) 
    : wxPanel(parent, index)
{    
    SetBackgroundStyle(wxBG_STYLE_PAINT);


    Bind(wxEVT_PAINT, &TrackHeader::OnPaint, this);
}

TrackHeader::~TrackHeader() 
{    
}

void TrackHeader::OnPaint(wxPaintEvent&)
{
    wxBufferedPaintDC dc(this);
    wxGCDC gc(dc);

    wxRect rect = GetClientRect();
    gc.SetPen(*wxLIGHT_GREY_PEN);
    gc.SetBrush(*wxLIGHT_GREY_BRUSH);

    gc.DrawRectangle(rect);  

    gc.SetPen(*wxMEDIUM_GREY_PEN);
    gc.SetBrush(*wxMEDIUM_GREY_BRUSH);

    gc.DrawRectangle(rect.GetBottomLeft() - wxSize(0, 1), wxSize(rect.GetWidth(), 2));
}

void TrackHeader::HandleMouseWheelEvent(wxMouseEvent& m) 
{    
    m.Skip();
}

BEGIN_EVENT_TABLE(TrackHeader, wxWindow)
    EVT_MOUSEWHEEL(TrackHeader::HandleMouseWheelEvent)
END_EVENT_TABLE()