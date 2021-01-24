#pragma once

#include <wx/window.h>
#include <wx/panel.h>

#include "EditorView.h"
#include "Components/VScroll.h"
#include "Components//HScroll.h"

class EditorContainer 
    : public wxPanel 
{
public:
    EditorContainer(wxWindow*);
    ~EditorContainer();    
    void OnSize(wxSizeEvent&);
    void HandleMouseWheelEvent(wxMouseEvent&);
    void OnTrackYOffsetChanged(wxCommandEvent&);
    void OnScrollYOffsetChanged(wxCommandEvent&);
    float GetYScrollRatio();
    void OnTracksHeightChanged(wxCommandEvent&);
    void OnTrackListChanged(wxCommandEvent&);
    void OnTrackXOffsetChanged(wxCommandEvent&);
    float GetXScrollRatio();
    void OnScrollXOffsetChanged(wxCommandEvent&);
private:
    EditorView* editorView;
    VScroll* verticalScrollBar;
    HScroll* horizontalScrollBar;
    int mouseWheelRotation;
    wxDECLARE_EVENT_TABLE();
};
