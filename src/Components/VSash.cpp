#include "VSash.h"

#include <wx/dcbuffer.h>
#include <wx/dcgraph.h>

#include "Core/Constants.h"

wxDEFINE_EVENT(V_SASH_DRAGGING, wxCommandEvent);

VSash::VSash(wxWindow* parent) 
    : wxPanel(parent, wxID_ANY)
    , x(Constants::TRACK_HEADER_WIDTH)
    , width(Constants::SASH_WIDTH)
    , dragging(false)
{    
    SetBackgroundColour(*wxLIGHT_GREY);

    Bind(wxEVT_PAINT, &VSash::OnPaint, this);
}

VSash::~VSash()
{    
}

void VSash::OnPaint(wxPaintEvent&)
{
    wxBufferedPaintDC dc(this);
    wxGCDC gc(dc);

    wxRect rect = GetClientRect();

    //gc.SetPen(*wxLIGHT_GREY_PEN);
    //gc.SetBrush(*wxLIGHT_GREY_BRUSH);

    //gc.DrawRectangle(rect);

    //rect.SetX(rect.GetX() - 1);
    //rect.SetWidth(rect.GetWidth() - 2);

    gc.SetPen(*wxGREY_PEN);
    gc.SetBrush(*wxGREY_BRUSH);

    gc.DrawRectangle(rect);
}

int VSash::GetX() 
{
    return x;
}

void VSash::SetX(int val) 
{
    x = val;
}

int VSash::GetWidth()
{
    return width;
}

void VSash::SetWidth(int val)
{
    width = val;
}

bool VSash::Dragging() 
{
    return dragging;    
}

void VSash::OnMouseEvent(wxMouseEvent& m) 
{
    if(m.Leaving() && !dragging)
        SetCursor(wxCURSOR_DEFAULT);

    if(m.Entering())
        SetCursor(wxCURSOR_SIZEWE);

    if(m.LeftDown()) 
    {
        SetCursor(wxCURSOR_SIZEWE);
        CaptureMouse();
        dragging = true;
    }

    if(m.LeftUp())
    {
        SetCursor(wxCURSOR_DEFAULT);
        ReleaseMouse();
        dragging = false;
    }

    if(dragging) 
    {
        wxPoint mouseOnScreen = wxGetMousePosition();
        
        auto destination = GetParent()->ScreenToClient(mouseOnScreen);

        if(destination.x <= Constants::TRACK_HEADER_MAX_WIDTH && destination.x >= Constants::TRACK_HEADER_MIN_WIDTH) {
            x = destination.x;

            wxCommandEvent event(V_SASH_DRAGGING);
            wxPostEvent(GetParent(), event);
        }
    }

    m.Skip();
}

BEGIN_EVENT_TABLE(VSash, wxWindow)
    EVT_MOUSE_EVENTS(VSash::OnMouseEvent)
END_EVENT_TABLE()

