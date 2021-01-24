#include "TrackLanesContainer.h"

#include <wx/dcgraph.h>
#include <wx/dcbuffer.h>

#include "Core/Constants.h"

wxDEFINE_EVENT(TRACKS_OFFSET_X_CHANGED, wxCommandEvent);

TrackLanesContainer::TrackLanesContainer(wxWindow* parent)
	: wxPanel(parent, wxID_ANY)
    , trackLanesXOffset(0)
{
    trackLanes = new TrackLanes(this);

    Bind(wxEVT_PAINT, &TrackLanesContainer::OnPaint, this);
    Bind(wxEVT_SIZE, &TrackLanesContainer::OnSize, this);
}

TrackLanesContainer::~TrackLanesContainer()
{
}

void TrackLanesContainer::OnSize(wxSizeEvent&)
{
    wxRect clientRect = GetClientRect();
    trackLanes->SetSize(wxRect(clientRect.GetX() - trackLanesXOffset, clientRect.GetY(), 2000, wxMax(trackLanes->GetHeight(), clientRect.GetHeight())));
}

int TrackLanesContainer::GetTrackLanesVirtualWidth()
{
    return trackLanes->GetRect().GetWidth();
}

void TrackLanesContainer::OnTrackHeaderHeightChanged(int id, int height)
{
    trackLanes->SetTrackHeight(id, height);
    trackLanes->PostSizeEvent();
}

void TrackLanesContainer::SetTrackLanesXOffset(int xOffset)
{
    trackLanesXOffset = xOffset;
}

int TrackLanesContainer::GetTrackLanesXOffset()
{
    return trackLanesXOffset;
}

void TrackLanesContainer::OnTrackLaneHeightChanged()
{
    trackLanes->PostSizeEvent();
}

void TrackLanesContainer::ScrollRight()
{
    int trackLanesWidth = trackLanes->GetRect().GetWidth();
    int clientWidth = GetClientRect().GetWidth();

    int maxOffset = trackLanes->GetRect().GetWidth() - GetClientRect().GetWidth();

    if (trackLanesXOffset < maxOffset) {
        trackLanesXOffset += wxMin(maxOffset - trackLanesXOffset, Constants::SCROLL_SPEED);

        wxCommandEvent event(TRACKS_OFFSET_X_CHANGED);
        wxPostEvent(GetParent(), event);
    }
}

void TrackLanesContainer::ScrollLeft()
{
    if (trackLanesXOffset >= 0)
    {
        trackLanesXOffset -= wxMin(trackLanesXOffset, Constants::SCROLL_SPEED);

        wxCommandEvent event(TRACKS_OFFSET_X_CHANGED);
        wxPostEvent(GetParent(), event);
    }
}

void TrackLanesContainer::OnPaint(wxPaintEvent&)
{
    wxBufferedPaintDC dc(this);
    wxGCDC gc(dc);

    wxRect rect = GetClientRect();

    gc.SetPen(*wxRED_PEN);
    gc.SetBrush(*wxRED_BRUSH);

    gc.DrawRectangle(rect);
}
