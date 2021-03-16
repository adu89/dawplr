#pragma once

#include <wx/splitter.h>
#include <wx/window.h>

#include "Core/TrackManager.h"

class MainHorizontalSplitter 
    : public wxSplitterWindow 
{
public:
    MainHorizontalSplitter(wxWindow*, TrackManager&);
    ~MainHorizontalSplitter() override;
};