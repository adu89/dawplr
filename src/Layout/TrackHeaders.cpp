#include "TrackHeaders.h"

wxDEFINE_EVENT(TRACK_LIST_CHANGED, wxCommandEvent);

TrackHeaders::TrackHeaders(wxWindow* parent)
    : wxPanel(parent, wxID_ANY)
{
    TrackManager& trackManager = TrackManager::Instance();

    for(int i = 0; i < trackManager.GetTracks().size(); i++)
    {
        trackHeaders.push_back(new TrackHeader(this, i));
    }

    trackManager.AddListener(this);

    Bind(wxEVT_SIZE, &TrackHeaders::OnSize, this);
    Bind(TRACK_HEADER_HEIGHT_CHANGED, &TrackHeaders::OnTrackHeightChanged, this);
}

TrackHeaders::~TrackHeaders()
{
    TrackManager& trackManager = TrackManager::Instance();
    trackManager.RemoveListener(this);
}

void TrackHeaders::OnSize(wxSizeEvent& e) 
{    
    auto clientRect = GetClientRect();

    auto trackHeaderRect = wxRect(clientRect.GetTopLeft(), wxSize(0, 0));

    for(int i = 0; i < trackHeaders.size(); i++)
    {
        trackHeaderRect = wxRect(trackHeaderRect.GetBottomLeft() + wxPoint(0, 1), wxSize(clientRect.GetWidth(), trackHeaders[i]->GetHeight()));
        trackHeaders[i]->SetSize(trackHeaderRect);
    }
}

int TrackHeaders::GetHeight() 
{
    int height = 0;

    for(int i = 0; i < trackHeaders.size(); i++)
    {
        height += trackHeaders[i]->GetSize().GetHeight();
    }    

    return height;
}

void TrackHeaders::SetTrackHeight(int index, int height)
{
    trackHeaders[index]->SetHeight(height);
}

void TrackHeaders::OnAddTrack(const Track& t)
{
    trackHeaders.push_back(new TrackHeader(this, trackHeaders.size()));
    this->PostSizeEvent();

    wxCommandEvent event(TRACK_LIST_CHANGED);
    wxPostEvent(GetParent(), event);
}

void TrackHeaders::HandleMouseWheelEvent(wxMouseEvent& m) 
{    
    m.Skip();
}

void TrackHeaders::OnTrackHeightChanged(wxCommandEvent& m) 
{    
    m.Skip();
}

BEGIN_EVENT_TABLE(TrackHeaders, wxWindow)
    EVT_MOUSEWHEEL(TrackHeaders::HandleMouseWheelEvent)
END_EVENT_TABLE()
