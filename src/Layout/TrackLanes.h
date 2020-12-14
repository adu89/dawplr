#pragma once

#include <wx/window.h>
#include <wx/panel.h>

#include <vector>

#include "Components/TrackLane.h"
#include "Core/TrackManager.h"

class TrackLanes 
    : public wxPanel 
    , public TrackManager::Listener
{
public:
    TrackLanes(wxWindow*);
    ~TrackLanes();
    void OnSize(wxSizeEvent&);
    int GetHeight();
    void SetTrackHeight(int index, int height);
    void HandleMouseWheelEvent(wxMouseEvent&); 
    void OnTrackHeightChanged(wxCommandEvent&);
    void OnAddTrack(const Track& t) override;
private:
    std::vector<TrackLane*> trackLanes;    
    wxDECLARE_EVENT_TABLE();
};