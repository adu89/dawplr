#pragma once

#include <wx/panel.h>
#include <wx/window.h>

#include "TrackHeaders.h"
#include "TrackLanes.h"
#include "TrackLanesContainer.h"
#include "Components/VSash.h"

wxDECLARE_EVENT(TRACKS_OFFSET_Y_CHANGED, wxCommandEvent);
wxDECLARE_EVENT(TRACKS_HEIGHT_CHANGED, wxCommandEvent);

class EditorView 
    : public wxPanel 
{
public:
    EditorView(wxWindow*);
    ~EditorView();
    void OnSize(wxSizeEvent&);
    void HandleMouseWheelEvent(wxMouseEvent&);
    void ScrollUp(wxScrollWinEvent&);
    void ScrollDown(wxScrollWinEvent&);
    int GetVirtualHeight();
    int GetTracksYOffset();
    void SetTracksYOffset(int);
    void OnVSashDragging(wxCommandEvent&);
    void OnTrackHeaderHeightChanged(wxCommandEvent&);
    void OnTrackLaneHeightChanged(wxCommandEvent&);
    void OnTrackListChanged(wxCommandEvent&);
    void OnTrackXOffsetChanged(wxCommandEvent&);
    int GetTrackLanesVirtualWidth();
    int GetTrackLanesXOffset();
    void SetTrackLanesXOffset(int);
    int GetTrackLanesContainerWidth();
private:
    int tracksYOffSet;
    TrackHeaders* trackHeaders;
    TrackLanesContainer* trackLanesContainer;
    VSash* vsash;
    wxDECLARE_EVENT_TABLE();
};

