#include "EditorView.h"

#include "core/Constants.h"
#include "EditorContainer.h"

EditorView::EditorView(wxWindow* parent)
    : wxPanel(parent, wxID_ANY) 
    , tracksYOffSet(0)
{    
    SetBackgroundColour(*wxYELLOW);

    trackHeaders = new TrackHeaders(this);
    trackLanes = new TrackLanes(this);
    vsash = new VSash(this);

    Bind(wxEVT_SIZE, &EditorView::OnSize, this);
    Bind(wxEVT_SCROLLWIN_LINEUP, &EditorView::ScrollUp, this);   
    Bind(wxEVT_SCROLLWIN_LINEDOWN, &EditorView::ScrollDown, this);   
}

EditorView::~EditorView() 
{    
}

void EditorView::OnSize(wxSizeEvent& e) 
{    
    auto clientRect = GetClientRect();

    vsash->SetSize(wxRect(vsash->GetX(), clientRect.GetTop(), vsash->GetWidth(), trackHeaders->GetHeight()));
    trackHeaders->SetSize(wxRect(clientRect.GetTopLeft() - wxPoint(0, tracksYOffSet), vsash->GetRect().GetBottomLeft()));
    trackLanes->SetSize(wxRect(vsash->GetRect().GetTopRight() + wxPoint(0, tracksYOffSet*-1), wxSize(2000, vsash->GetRect().GetHeight())));

    e.Skip();
}

void EditorView::HandleMouseWheelEvent(wxMouseEvent& m) 
{
    m.ResumePropagation(wxEVENT_PROPAGATE_MAX);
    m.Skip();
}

void EditorView::ScrollUp(wxScrollWinEvent&) 
{
    if(tracksYOffSet) 
    {
        tracksYOffSet -= wxMin(tracksYOffSet, Constants::SCROLL_SPEED);
        static_cast<EditorContainer*>(GetParent())->OnTrackYOffsetChanged();
    }
}

void EditorView::ScrollDown(wxScrollWinEvent&) 
{
    int maxOffset = GetVirtualHeight() - GetClientRect().GetHeight();
    
    if(tracksYOffSet < maxOffset) {
        tracksYOffSet += wxMin(maxOffset - tracksYOffSet, Constants::SCROLL_SPEED);
        static_cast<EditorContainer*>(GetParent())->OnTrackYOffsetChanged();
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

BEGIN_EVENT_TABLE(EditorView, wxWindow)
    EVT_MOUSEWHEEL(EditorView::HandleMouseWheelEvent)
END_EVENT_TABLE()
