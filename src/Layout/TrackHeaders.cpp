#include "TrackHeaders.h"

wxDECLARE_EVENT(TRACK_HEIGHT_CHANGED, wxCommandEvent);

TrackHeaders::TrackHeaders(wxWindow* parent)
    : wxPanel(parent, wxID_ANY)
{
    for(int i = 0; i < 10; i++)
    {
        trackHeaders.push_back(new TrackHeader(this, i));
    }

    Bind(wxEVT_SIZE, &TrackHeaders::OnSize, this);
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
        trackHeaderRect = wxRect(trackHeaderRect.GetBottomLeft() + wxPoint(0, 1), wxSize(clientRect.GetWidth(), 100));
        trackHeaders[i]->SetSize(trackHeaderRect);
    }

    e.Skip();
}

wxDEFINE_EVENT(TRACK_HEIGHT_CHANGED, wxCommandEvent);

int TrackHeaders::GetHeight() 
{
    int height = 0;

    for(int i = 0; i < trackHeaders.size(); i++)
    {
        height += trackHeaders[i]->GetSize().GetHeight();
    }    

    return height;
}

void TrackHeaders::HandleMouseWheelEvent(wxMouseEvent& m) 
{    
    m.ResumePropagation(wxEVENT_PROPAGATE_MAX);
    m.Skip();
}

BEGIN_EVENT_TABLE(TrackHeaders, wxWindow)
    EVT_MOUSEWHEEL(TrackHeaders::HandleMouseWheelEvent)
END_EVENT_TABLE()
