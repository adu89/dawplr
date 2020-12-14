#include "TrackLanes.h"

#include "Core/TrackManager.h"

TrackLanes::TrackLanes(wxWindow* parent)
    : wxPanel(parent, wxID_ANY)
{
    TrackManager& trackManager = TrackManager::Instance();

    for (int i = 0; i < trackManager.GetTracks().size(); i++)
    {
        trackLanes.push_back(new TrackLane(this, i));
    }

    trackManager.AddListener(this);

    Bind(wxEVT_SIZE, &TrackLanes::OnSize, this);
    Bind(TRACK_LANE_HEIGHT_CHANGED, &TrackLanes::OnTrackHeightChanged, this);
}

TrackLanes::~TrackLanes()
{
    TrackManager& trackManager = TrackManager::Instance();
    trackManager.RemoveListener(this);
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

void TrackLanes::OnAddTrack(const Track& t)
{
    trackLanes.push_back(new TrackLane(this, trackLanes.size()));
    this->PostSizeEvent();
}

BEGIN_EVENT_TABLE(TrackLanes, wxWindow)
    EVT_MOUSEWHEEL(TrackLanes::HandleMouseWheelEvent)
END_EVENT_TABLE()
