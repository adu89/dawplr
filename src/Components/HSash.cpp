#include "HSash.h"

#include "Core/Constants.h"

wxDEFINE_EVENT(H_SASH_DRAGGING, wxCommandEvent);
wxDEFINE_EVENT(H_SASH_START_DRAGGING, wxCommandEvent);

HSash::HSash(wxWindow* parent)
	: wxPanel(parent, wxID_ANY)
	, dragging(false)
    , y(0)
{
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));
}

HSash::~HSash()
{
}

int HSash::GetY()
{
    return y;
}

void HSash::SetY(int newY)
{
    y = newY;
}

void HSash::OnMouseEvent(wxMouseEvent& m)
{
    if (m.Leaving() && !dragging)
        SetCursor(wxCURSOR_DEFAULT);

    if (m.Entering())
        SetCursor(wxCURSOR_SIZENS);

    if (m.LeftDown())
    {
        SetCursor(wxCURSOR_SIZENS);
        CaptureMouse();
        dragging = true;

        wxCommandEvent event(H_SASH_START_DRAGGING);
        wxPostEvent(GetParent(), event);
    }

    if (m.LeftUp())
    {
        SetCursor(wxCURSOR_DEFAULT);
        ReleaseMouse();
        dragging = false;
    }

    if (dragging)
    {
        wxPoint mouseOnScreen = wxGetMousePosition();

        auto destination = GetParent()->ScreenToClient(mouseOnScreen);

        if (destination.y <= Constants::TRACK_HEADER_MAX_HEIGHT && destination.y >= Constants::TRACK_HEADER_MIN_HEIGHT) {
            y = destination.y;
        
            wxCommandEvent event(H_SASH_DRAGGING);
            wxPostEvent(GetParent(), event);
        }
    }

    m.Skip();
}

BEGIN_EVENT_TABLE(HSash, wxWindow)
    EVT_MOUSE_EVENTS(HSash::OnMouseEvent)
END_EVENT_TABLE()