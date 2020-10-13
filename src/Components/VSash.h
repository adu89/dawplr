#pragma once

#include <wx/panel.h>
#include <wx/window.h>

wxDECLARE_EVENT(V_SASH_DRAGGING, wxCommandEvent);

class VSash 
    : public wxPanel 
{
public:
    VSash(wxWindow*);
    ~VSash();
    int GetWidth();
    void SetWidth(int);
    int GetX();
    void SetX(int);
    bool Dragging();
    void OnMouseEvent(wxMouseEvent&);

private:
    int x;
    int width;
    bool dragging;
    wxDECLARE_EVENT_TABLE();
};

