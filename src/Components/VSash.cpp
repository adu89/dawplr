#include "VSash.h"

#include "Core/Constants.h"

VSash::VSash(wxWindow* parent) 
    : wxPanel(parent, wxID_ANY)
    , x(Constants::TRACK_HEADER_WIDTH)
    , width(Constants::SASH_WIDTH)
    , dragging(false)
{    
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));
}

VSash::~VSash()
{    
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
            SendSizeEventToParent();
        }
    }

    m.ResumePropagation(wxEVENT_PROPAGATE_MAX);
    m.Skip();
}

BEGIN_EVENT_TABLE(VSash, wxWindow)
    EVT_MOUSE_EVENTS(VSash::OnMouseEvent)
END_EVENT_TABLE()

