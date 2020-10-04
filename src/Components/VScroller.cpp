#include "VScroller.h"
#include "VScroll.h"

wxDEFINE_EVENT(SCROLL_OFFSET_Y_CHANGED, wxCommandEvent);

VScroller::VScroller(wxWindow* parent)
    : wxPanel(parent, wxID_ANY) 
    , y(0)
    , dragging(false)
    , mouseDownY(0)
{    
}

VScroller::~VScroller() 
{    
}

void VScroller::OnMouseEvent(wxMouseEvent& m) 
{
    if(m.LeftDown()) 
    {
        CaptureMouse();
        dragging = true;
        mouseDownY = m.GetY();
    }

    if(m.LeftUp())
    {
        ReleaseMouse();
        dragging = false;
    }

    if(dragging) 
    {
        wxPoint mouseOnScreen = wxGetMousePosition();
        
        auto destination = GetParent()->ScreenToClient(mouseOnScreen);

        auto nextY = wxMax(destination.y - mouseDownY, GetParent()->GetRect().GetY());
        nextY = wxMin(nextY, GetParent()->GetRect().GetBottom() - GetRect().GetHeight());

        y = nextY;
        static_cast<VScroll*>(GetParent())->OnScrollYOffsetChanged();

        wxCommandEvent event(SCROLL_OFFSET_Y_CHANGED); 
        wxPostEvent(GetParent(), event);
    }

    m.ResumePropagation(wxEVENT_PROPAGATE_MAX);
    m.Skip();
}

int VScroller::GetY() 
{
    return y;    
}

void VScroller::SetY(int yVal) 
{
    y = yVal;
}

BEGIN_EVENT_TABLE(VScroller, wxWindow)
    EVT_MOUSE_EVENTS(VScroller::OnMouseEvent)
END_EVENT_TABLE()


