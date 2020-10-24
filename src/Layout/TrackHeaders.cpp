#include "TrackHeaders.h"

TrackHeaders::TrackHeaders(wxWindow* parent)
    : wxPanel(parent, wxID_ANY)
{
    for(int i = 0; i < 10; i++)
    {
        trackHeaders.push_back(new TrackHeader(this, i));
    }

    Bind(wxEVT_SIZE, &TrackHeaders::OnSize, this);
    Bind(TRACK_HEADER_HEIGHT_CHANGED, &TrackHeaders::OnTrackHeightChanged, this);
}

TrackHeaders::~TrackHeaders()
{
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
