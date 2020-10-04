#pragma once

#include <wx/window.h>
#include <wx/panel.h>
#include "VScroller.h"

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
    void OnScrollYOffsetChanged();
private:
    VScroller* scroller;
    float scrollRatio;
    bool dragging;
    wxDECLARE_EVENT_TABLE();
};
