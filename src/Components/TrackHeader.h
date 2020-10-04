#pragma once

#include <wx/panel.h>
#include <wx/window.h>

class TrackHeader 
    : public wxPanel 
{
public:
    TrackHeader(wxWindow*, int);
    ~TrackHeader();    
    void OnPaint(wxPaintEvent&);
    void HandleMouseWheelEvent(wxMouseEvent&);
private:
    wxDECLARE_EVENT_TABLE();
};