#pragma once

#include <wx/window.h>
#include <wx/panel.h>
#include "EditorView.h"
#include "Components/VScroll.h"

class EditorContainer 
    : public wxPanel 
{
public:
    EditorContainer(wxWindow*);
    ~EditorContainer();    
    void OnSize(wxSizeEvent&);
    void HandleMouseWheelEvent(wxMouseEvent&);

    void OnTrackYOffsetChanged();
    void OnScrollYOffsetChanged();
    float GetScrollRatio();
private:
    EditorView* editorView;
    VScroll* verticalScrollBar;
    int mouseWheelRotation;
    wxDECLARE_EVENT_TABLE();
};
