#pragma once

#include <wx/window.h>
#include <wx/panel.h>

#include "Components/TrackLane.h"

class TrackLanes 
    : public wxPanel 
{
public:
    TrackLanes(wxWindow*);
    ~TrackLanes();
    void OnSize(wxSizeEvent&);
    void HandleMouseWheelEvent(wxMouseEvent&); 
private:
    std::vector<TrackLane*> trackLanes;    
    wxDECLARE_EVENT_TABLE();
};