#include "TrackHeader.h"

#include <wx/dcbuffer.h>
#include <wx/dcgraph.h>
#include "Core/Constants.h"

wxDEFINE_EVENT(TRACK_HEADER_HEIGHT_CHANGED, wxCommandEvent);

TrackHeader::TrackHeader(wxWindow* parent, int index) 
    : wxPanel(parent, index)
    , height(Constants::TRACK_HEADER_HEIGHT)
    , index(index)
{    
    SetBackgroundStyle(wxBG_STYLE_PAINT);

    hSash = new HSash(this);

    Bind(wxEVT_PAINT, &TrackHeader::OnPaint, this);
    Bind(wxEVT_SIZE, &TrackHeader::OnSize, this);
    Bind(H_SASH_DRAGGING, &TrackHeader::OnHSashDragging, this);
}

TrackHeader::~TrackHeader() 
{    
}

int TrackHeader::GetHeight()
{
    return height;
}

void TrackHeader::SetHeight(int h)
{
    height = h;
}

void TrackHeader::OnHSashDragging(wxCommandEvent& e)
{
    height = hSash->GetY() + 1;
    
    wxCommandEvent event(TRACK_HEADER_HEIGHT_CHANGED);

    event.SetId(index);
    event.SetInt(height);

    wxPostEvent(GetParent(), event);
}

void TrackHeader::OnSize(wxSizeEvent& e)
{
    auto clientRect = GetClientRect();

    hSash->SetSize(wxRect(clientRect.GetBottomLeft() - wxPoint(0, 3), clientRect.GetBottomRight()));
}

void TrackHeader::OnPaint(wxPaintEvent&)
{
    wxBufferedPaintDC dc(this);
    wxGCDC gc(dc);

    wxRect rect = GetClientRect();
    gc.SetPen(*wxLIGHT_GREY_PEN);
    gc.SetBrush(*wxLIGHT_GREY_BRUSH);

    gc.DrawRectangle(rect);  

    //gc.SetPen(*wxMEDIUM_GREY_PEN);
    //gc.SetBrush(*wxMEDIUM_GREY_BRUSH);

    //gc.DrawRectangle(rect.GetBottomLeft() - wxSize(0, 1), wxSize(rect.GetWidth(), 2));
}

void TrackHeader::HandleMouseWheelEvent(wxMouseEvent& m) 
{    
    m.Skip();
}

BEGIN_EVENT_TABLE(TrackHeader, wxWindow)
    EVT_MOUSEWHEEL(TrackHeader::HandleMouseWheelEvent)
END_EVENT_TABLE()