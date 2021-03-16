#pragma once

#include <wx/panel.h>
#include <wx/window.h>

#include "Components/HSash.h"
#include "Core/Track.h"

class TrackHeader 
    : public wxPanel 
{
public:
    TrackHeader(wxWindow*, int, Track&);
    ~TrackHeader();        

private:
    HSash* hSash;
    void onSashDragging(wxCommandEvent&);
    Track& track;
};