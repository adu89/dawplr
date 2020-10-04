#pragma once

#include <wx/panel.h>
#include <wx/window.h>

wxDECLARE_EVENT(SCROLL_OFFSET_Y_CHANGED, wxCommandEvent);

class VScroller 
    : public wxPanel {
public:
    VScroller(wxWindow*);
    ~VScroller();
    void OnMouseEvent(wxMouseEvent&);
    int GetY();
    void SetY(int);
private:
    int y;
    int mouseDownY;
    bool dragging;
    wxDECLARE_EVENT_TABLE();
};
