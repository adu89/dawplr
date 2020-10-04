#pragma once

#include <wx/window.h>
#include <wx/panel.h>

#include "EditorView.h"
#include "Components/VScroll.h"

wxDECLARE_EVENT(SCROLL_OFFSET_Y_CHANGED, wxCommandEvent);
wxDECLARE_EVENT(TRACKS_OFFSET_Y_CHANGED, wxCommandEvent);

class EditorContainer 
    : public wxPanel 
{
public:
    EditorContainer(wxWindow*);
    ~EditorContainer();    
    void OnSize(wxSizeEvent&);
    void HandleMouseWheelEvent(wxMouseEvent&);
    void OnTrackYOffsetChanged(wxCommandEvent& event);
    void OnScrollYOffsetChanged(wxCommandEvent& event);
    float GetScrollRatio();
private:
    EditorView* editorView;
    VScroll* verticalScrollBar;
    int mouseWheelRotation;
    wxDECLARE_EVENT_TABLE();
};
