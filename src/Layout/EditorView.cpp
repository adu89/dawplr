#include "EditorView.h"

#include "core/Constants.h"

wxDEFINE_EVENT(TRACKS_OFFSET_Y_CHANGED, wxCommandEvent);
wxDEFINE_EVENT(TRACKS_HEIGHT_CHANGED, wxCommandEvent);

EditorView::EditorView(wxWindow* parent)
    : wxPanel(parent, wxID_ANY) 
    , tracksYOffSet(0)
{    
    SetBackgroundColour(*wxLIGHT_GREY);

    trackHeaders = new TrackHeaders(this);
    trackLanes = new TrackLanes(this);
    vsash = new VSash(this);

    Bind(wxEVT_SIZE, &EditorView::OnSize, this);
    Bind(wxEVT_SCROLLWIN_LINEUP, &EditorView::ScrollUp, this);   
    Bind(wxEVT_SCROLLWIN_LINEDOWN, &EditorView::ScrollDown, this);  
    Bind(V_SASH_DRAGGING, &EditorView::OnVSashDragging, this);
    Bind(TRACK_HEADER_HEIGHT_CHANGED, &EditorView::OnTrackHeaderHeightChanged, this);
    Bind(TRACK_LANE_HEIGHT_CHANGED, &EditorView::OnTrackLaneHeightChanged, this);
    Bind(TRACK_LIST_CHANGED, &EditorView::OnTrackListChanged, this);
}

EditorView::~EditorView() 
{    
}

void EditorView::OnSize(wxSizeEvent& e) 
{    
    auto clientRect = GetClientRect();

    vsash->SetSize(wxRect(vsash->GetX(), clientRect.GetTop(), vsash->GetWidth(), wxMax(trackHeaders->GetHeight(), clientRect.GetHeight())));
    trackHeaders->SetSize(wxRect(clientRect.GetTopLeft() - wxPoint(0, tracksYOffSet), vsash->GetRect().GetBottomLeft() - wxPoint(1, 0)));
    trackLanes->SetSize(wxRect(vsash->GetRect().GetTopRight() - wxPoint(-1, tracksYOffSet), vsash->GetRect().GetBottomRight() + wxPoint(2000, 0)));
}

void EditorView::HandleMouseWheelEvent(wxMouseEvent& m) 
{
    m.Skip();
}

void EditorView::ScrollUp(wxScrollWinEvent&) 
{
    if(tracksYOffSet) 
    {
        tracksYOffSet -= wxMin(tracksYOffSet, Constants::SCROLL_SPEED);

        wxCommandEvent event(TRACKS_OFFSET_Y_CHANGED);
        wxPostEvent(GetParent(), event);
    }
}

void EditorView::ScrollDown(wxScrollWinEvent&) 
{
    int maxOffset = GetVirtualHeight() - GetClientRect().GetHeight();
    
    if(tracksYOffSet < maxOffset) {
        tracksYOffSet += wxMin(maxOffset - tracksYOffSet, Constants::SCROLL_SPEED);

        wxCommandEvent event(TRACKS_OFFSET_Y_CHANGED);
        wxPostEvent(GetParent(), event);
    }
}

int EditorView::GetVirtualHeight() 
{
    return trackHeaders->GetHeight() + GetClientRect().GetHeight() / 3;    
}

int EditorView::GetTracksYOffset() 
{
    return tracksYOffSet;    
}

void EditorView::SetTracksYOffset(int yOffset) 
{
    tracksYOffSet = yOffset;    
}

void EditorView::OnVSashDragging(wxCommandEvent&)
{
    QueueEvent(new wxSizeEvent);
}

void EditorView::OnTrackHeaderHeightChanged(wxCommandEvent& e)
{
    trackLanes->SetTrackHeight(e.GetId(), e.GetInt());

    trackHeaders->PostSizeEvent();
    trackLanes->PostSizeEvent();

    wxCommandEvent event(TRACKS_HEIGHT_CHANGED);
    wxPostEvent(GetParent(), event);
}

void EditorView::OnTrackLaneHeightChanged(wxCommandEvent& e)
{
    trackHeaders->SetTrackHeight(e.GetId(), e.GetInt());

    trackLanes->PostSizeEvent();
    trackHeaders->PostSizeEvent();

    wxCommandEvent event(TRACKS_HEIGHT_CHANGED);
    wxPostEvent(GetParent(), event);
}

void EditorView::OnTrackListChanged(wxCommandEvent& e)
{
    e.Skip();
}

BEGIN_EVENT_TABLE(EditorView, wxWindow)
    EVT_MOUSEWHEEL(EditorView::HandleMouseWheelEvent)
END_EVENT_TABLE()
