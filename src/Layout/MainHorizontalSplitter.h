#pragma once

#include <wx/splitter.h>
#include <wx/window.h>

class MainHorizontalSplitter 
    : public wxSplitterWindow 
{
public:
    MainHorizontalSplitter(wxWindow*);
    ~MainHorizontalSplitter() override;
};