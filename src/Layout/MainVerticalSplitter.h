#pragma once

#include <wx/splitter.h>
#include <wx/window.h>

class MainVerticalSplitter 
    : public wxSplitterWindow 
{
public:
    MainVerticalSplitter(wxWindow* parent);
    ~MainVerticalSplitter() override;
};