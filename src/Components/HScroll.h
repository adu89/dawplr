#pragma once

#pragma once

#include <wx/window.h>
#include <wx/panel.h>

#include "HScroller.h"

class HScroll
    : public wxPanel
{
public:
    HScroll(wxWindow*);
    ~HScroll();
    void OnSize(wxSizeEvent& e);
    void SetScrollRatio(float);
    void SetScrollOffset(float);
    float GetScrollOffset();
    void OnMouseEvent(wxMouseEvent&);
    void OnScrollXOffsetChanged(wxCommandEvent&);
private:
    HScroller* scroller;
    float scrollRatio;
    bool dragging;
    wxDECLARE_EVENT_TABLE();
};
