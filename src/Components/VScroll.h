#pragma once

#include <wx/window.h>
#include <wx/panel.h>

#include "VScroller.h"

wxDECLARE_EVENT(SCROLL_OFFSET_Y_CHANGED, wxCommandEvent);

class VScroll 
    : public wxPanel 
{
public:
    VScroll(wxWindow*);
    ~VScroll();
    void OnSize(wxSizeEvent& e); 
    void SetScrollRatio(float);
    void SetScrollOffset(float);
    float GetScrollOffset();   
    void OnMouseEvent(wxMouseEvent&);
    void OnScrollYOffsetChanged(wxCommandEvent&);
private:
    VScroller* scroller;
    float scrollRatio;
    bool dragging;
    wxDECLARE_EVENT_TABLE();
};
