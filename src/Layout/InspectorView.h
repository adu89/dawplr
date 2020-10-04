#pragma once

#include <wx/panel.h>
#include <wx/window.h>

class InspectorView 
    : public wxPanel
{
public:
    InspectorView(wxWindow*);
    ~InspectorView() override;
};