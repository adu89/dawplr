#pragma once 

#include <wx/panel.h>
#include <wx/window.h>

#include <vector>

#include "Components/TrackHeader.h"
#include "Core/TrackManager.h"

wxDECLARE_EVENT(TRACK_LIST_CHANGED, wxCommandEvent);

class TrackHeaders 
    : public wxPanel 
    , public TrackManager::Listener
{
public:
    TrackHeaders(wxWindow*);
    ~TrackHeaders() override;
    void OnSize(wxSizeEvent&);
    int GetHeight();
    void HandleMouseWheelEvent(wxMouseEvent&);
    void OnTrackHeightChanged(wxCommandEvent&);
    void SetTrackHeight(int index, int height);

    void OnAddTrack(Track& t) override;
private:
    std::vector<TrackHeader*> trackHeaders;
    wxDECLARE_EVENT_TABLE();
};

