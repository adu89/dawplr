#pragma once

#include <wx/panel.h>
#include <wx/window.h>

class TrackLane 
    : public wxPanel 
{
public:
    TrackLane(wxWindow* parent, int);
    ~TrackLane();
    void OnPaint(wxPaintEvent&);
    void HandleMouseWheelEvent(wxMouseEvent&);
private:
    wxDECLARE_EVENT_TABLE();
};