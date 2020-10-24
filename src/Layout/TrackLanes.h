#pragma once

#include <wx/window.h>
#include <wx/panel.h>

#include <vector>

#include "Components/TrackLane.h"

class TrackLanes 
    : public wxPanel 
{
public:
    TrackLanes(wxWindow*);
    ~TrackLanes();
    void OnSize(wxSizeEvent&);
    int GetHeight();
    void SetTrackHeight(int index, int height);
    void HandleMouseWheelEvent(wxMouseEvent&); 
    void OnTrackHeightChanged(wxCommandEvent&);
private:
    std::vector<TrackLane*> trackLanes;    
    wxDECLARE_EVENT_TABLE();
};