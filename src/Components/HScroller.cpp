#include "HScroller.h"

#include "HScroll.h"

wxDEFINE_EVENT(SCROLL_OFFSET_X_CHANGED, wxCommandEvent);

HScroller::HScroller(wxWindow* parent)
    : wxPanel(parent, wxID_ANY)
    , x(0)
    , dragging(false)
    , mouseDownX(0)
{
}

HScroller::~HScroller()
{
}

void HScroller::OnMouseEvent(wxMouseEvent& m)
{
    if (m.LeftDown())
    {
        CaptureMouse();
        dragging = true;
        mouseDownX = m.GetX();
    }

    if (m.LeftUp())
    {
        ReleaseMouse();
        dragging = false;
    }

    if (dragging)
    {
        wxPoint mouseOnScreen = wxGetMousePosition();

        auto destination = GetParent()->ScreenToClient(mouseOnScreen);

        auto nextX = wxMax(destination.x - mouseDownX, GetParent()->GetRect().GetX());
        nextX = wxMin(nextX, GetParent()->GetRect().GetRight() - GetRect().GetWidth());

        x = nextX;

        wxCommandEvent event(SCROLL_OFFSET_X_CHANGED);
        wxPostEvent(GetParent(), event);
    }

    m.Skip();
}

int HScroller::GetX()
{
    return x;
}

void HScroller::SetX(int xVal)
{
    x = xVal;
}

BEGIN_EVENT_TABLE(HScroller, wxWindow)
EVT_MOUSE_EVENTS(HScroller::OnMouseEvent)
END_EVENT_TABLE()


