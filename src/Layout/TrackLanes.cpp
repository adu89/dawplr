#include "TrackLanes.h"

TrackLanes::TrackLanes(wxWindow* parent)
    : wxPanel(parent, wxID_ANY)
{
    for (int i = 0; i < 10; i++)
    {
        trackLanes.push_back(new TrackLane(this, i));
    }

    Bind(wxEVT_SIZE, &TrackLanes::OnSize, this);
    Bind(TRACK_LANE_HEIGHT_CHANGED, &TrackLanes::OnTrackHeightChanged, this);
}

TrackLanes::~TrackLanes()
{
}

void TrackLanes::OnSize(wxSizeEvent& e) 
{    
    auto clientRect = GetClientRect();

    auto trackLaneRect = wxRect(clientRect.GetTopLeft(), wxSize(0, 0));

    for (int i = 0; i < trackLanes.size(); i++)
    {
        trackLaneRect = wxRect(trackLaneRect.GetBottomLeft() + wxPoint(0, 1), wxSize(clientRect.GetWidth(), trackLanes[i]->GetHeight()));
        trackLanes[i]->SetSize(trackLaneRect);
    }
}

int TrackLanes::GetHeight()
{
    int height = 0;

    for (int i = 0; i < trackLanes.size(); i++)
    {
        height += trackLanes[i]->GetSize().GetHeight();
    }

    return height;
}

void TrackLanes::SetTrackHeight(int index, int height)
{
    trackLanes[index]->SetHeight(height);
}

void TrackLanes::HandleMouseWheelEvent(wxMouseEvent& m) 
{    
    m.Skip();
}

void TrackLanes::OnTrackHeightChanged(wxCommandEvent& m)
{
    m.Skip();
}

BEGIN_EVENT_TABLE(TrackLanes, wxWindow)
    EVT_MOUSEWHEEL(TrackLanes::HandleMouseWheelEvent)
END_EVENT_TABLE()
