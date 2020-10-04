#pragma once 

#include <wx/panel.h>
#include <wx/window.h>
#include <vector>
#include "Components/TrackHeader.h"

class TrackHeaders 
    : public wxPanel 
{
public:
    TrackHeaders(wxWindow*);
    ~TrackHeaders() override;
    void OnSize(wxSizeEvent&);
    int GetHeight();
    void HandleMouseWheelEvent(wxMouseEvent&);
private:
    std::vector<TrackHeader*> trackHeaders;
    wxDECLARE_EVENT_TABLE();
};

