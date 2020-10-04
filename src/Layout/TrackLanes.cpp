#include "TrackLanes.h"

TrackLanes::TrackLanes(wxWindow* parent)
    : wxPanel(parent, wxID_ANY)
{
    SetBackgroundColour(*wxLIGHT_GREY);

    for(int i = 0; i < 10; i++)
    {
        trackLanes.push_back(new TrackLane(this, i));
    }

    Bind(wxEVT_SIZE, &TrackLanes::OnSize, this);
}

TrackLanes::~TrackLanes()
{
}

void TrackLanes::OnSize(wxSizeEvent& e) 
{    
    auto clientRect = GetClientRect();

    auto trackLaneRect = wxRect(clientRect.GetTopLeft(), wxSize(0, 0));

    for(int i = 0; i < trackLanes.size(); i++)
    {
        trackLaneRect = wxRect(trackLaneRect.GetBottomLeft() + wxPoint(0, 1), wxSize(clientRect.GetWidth(), 100));
        trackLanes[i]->SetSize(trackLaneRect);
    }
}

void TrackLanes::HandleMouseWheelEvent(wxMouseEvent& m) 
{    
    m.Skip();
}

BEGIN_EVENT_TABLE(TrackLanes, wxWindow)
    EVT_MOUSEWHEEL(TrackLanes::HandleMouseWheelEvent)
END_EVENT_TABLE()
