#pragma once

#include <wx/panel.h>
#include <wx/window.h>

class BottomPanel 
    : public wxPanel 
{
public:
    BottomPanel(wxWindow*);
    ~BottomPanel() override;
};