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
    vsash = new VSash(this);
    trackLanesContainer = new TrackLanesContainer(this);

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

    trackLanesContainer->SetSize(wxRect(vsash->GetRect().GetTopRight() - wxPoint(-1, tracksYOffSet), wxPoint(clientRect.GetRight(), wxMax(trackHeaders->GetHeight(), clientRect.GetHeight()))));
    //trackLanes->SetSize(wxRect(vsash->GetRect().GetTopRight() - wxPoint(trackLanesXOffset, tracksYOffSet), vsash->GetRect().GetBottomRight() + wxPoint(2000, 0)));
}

void EditorView::HandleMouseWheelEvent(wxMouseEvent& m) 
{
    m.Skip();
}

void EditorView::ScrollUp(wxScrollWinEvent& evt) 
{
    auto orientation = evt.GetOrientation();

    if(tracksYOffSet && orientation == wxMouseWheelAxis::wxMOUSE_WHEEL_VERTICAL) 
    {
        tracksYOffSet -= wxMin(tracksYOffSet, Constants::SCROLL_SPEED);

        wxCommandEvent event(TRACKS_OFFSET_Y_CHANGED);
        wxPostEvent(GetParent(), event);
    }

    if (orientation == wxMouseWheelAxis::wxMOUSE_WHEEL_HORIZONTAL)
        trackLanesContainer->ScrollRight();
}

void EditorView::ScrollDown(wxScrollWinEvent& evt) 
{
    int maxOffset = GetVirtualHeight() - GetClientRect().GetHeight();
    
    auto orientation = evt.GetOrientation();

    if(tracksYOffSet < maxOffset && orientation == wxMouseWheelAxis::wxMOUSE_WHEEL_VERTICAL) {
        tracksYOffSet += wxMin(maxOffset - tracksYOffSet, Constants::SCROLL_SPEED);

        wxCommandEvent event(TRACKS_OFFSET_Y_CHANGED);
        wxPostEvent(GetParent(), event);
    }

    if (orientation == wxMouseWheelAxis::wxMOUSE_WHEEL_HORIZONTAL)
        trackLanesContainer->ScrollLeft();
}

int EditorView::GetVirtualHeight() 
{
    return trackHeaders->GetHeight() + GetClientRect().GetHeight() / 3;    
}

int EditorView::GetTracksYOffset() 
{
    return tracksYOffSet;    
}

int EditorView::GetTrackLanesXOffset()
{
    return trackLanesContainer->GetTrackLanesXOffset();
}

void EditorView::SetTrackLanesXOffset(int xOffset)
{
    trackLanesContainer->SetTrackLanesXOffset(xOffset);
    trackLanesContainer->PostSizeEvent();
}

int EditorView::GetTrackLanesContainerWidth()
{
    return trackLanesContainer->GetRect().GetWidth();
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
    trackLanesContainer->OnTrackHeaderHeightChanged(e.GetId(), e.GetInt());

    trackHeaders->PostSizeEvent();

    wxCommandEvent event(TRACKS_HEIGHT_CHANGED);
    wxPostEvent(GetParent(), event);
}

void EditorView::OnTrackLaneHeightChanged(wxCommandEvent& e)
{
    trackHeaders->SetTrackHeight(e.GetId(), e.GetInt());

    trackLanesContainer->OnTrackLaneHeightChanged();
    trackHeaders->PostSizeEvent();

    wxCommandEvent event(TRACKS_HEIGHT_CHANGED);
    wxPostEvent(GetParent(), event);
}

void EditorView::OnTrackListChanged(wxCommandEvent& e)
{
    e.Skip();
}

void EditorView::OnTrackXOffsetChanged(wxCommandEvent&)
{
    trackLanesContainer->PostSizeEvent();
}

int EditorView::GetTrackLanesVirtualWidth()
{
    return trackLanesContainer->GetTrackLanesVirtualWidth();
}

BEGIN_EVENT_TABLE(EditorView, wxWindow)
    EVT_MOUSEWHEEL(EditorView::HandleMouseWheelEvent)
END_EVENT_TABLE()
