#pragma once

#include <wx/panel.h>
#include <wx/window.h>
#include "Components/HSash.h"

wxDECLARE_EVENT(TRACK_HEADER_HEIGHT_CHANGED, wxCommandEvent);

class TrackHeader 
    : public wxPanel 
{
public:
    TrackHeader(wxWindow*, int);
    ~TrackHeader();    
    void OnPaint(wxPaintEvent&);
    void HandleMouseWheelEvent(wxMouseEvent&);
    void OnSize(wxSizeEvent&);
    void OnHSashDragging(wxCommandEvent&);
    int GetHeight();
    void SetHeight(int);
private:
    HSash* hSash;
    int height;
    int index;
    wxDECLARE_EVENT_TABLE();
};