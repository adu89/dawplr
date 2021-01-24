#pragma once

#pragma once

#include <wx/panel.h>
#include <wx/window.h>

wxDECLARE_EVENT(SCROLL_OFFSET_X_CHANGED, wxCommandEvent);

class HScroller
    : public wxPanel {
public:
    HScroller(wxWindow*);
    ~HScroller();
    void OnMouseEvent(wxMouseEvent&);
    int GetX();
    void SetX(int);
private:
    int x;
    int mouseDownX;
    bool dragging;
    wxDECLARE_EVENT_TABLE();
};
