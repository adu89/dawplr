#pragma once

#include <wx/splitter.h>
#include <wx/window.h>

#include "Core/TrackManager.h"
class MainVerticalSplitter 
    : public wxSplitterWindow 
{
public:
    MainVerticalSplitter(wxWindow*, TrackManager&);
    ~MainVerticalSplitter() override;

    bool OnSashPositionChange(int) override;
};