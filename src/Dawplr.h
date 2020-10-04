#pragma once

// #define wxUSE_DEBUG_CONTEXT 1
// #define wxUSE_MEMORY_TRACING 1
// #define wxUSE_GLOBAL_MEMORY_OPERATORS 1
// #define wxUSE_DEBUG_NEW_ALWAYS 1

#include <wx/wx.h>
#include "Layout/MainWindow.h"

class Dawplr 
    : public wxApp 
{
public:
    virtual bool OnInit();   
};