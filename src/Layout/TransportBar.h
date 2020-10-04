#pragma once

#include <wx/panel.h>
#include <wx/window.h>

class TransportBar 
    : public wxPanel 
{
public: 
    TransportBar(wxWindow*);
    ~TransportBar() override;
};