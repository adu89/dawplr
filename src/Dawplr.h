#pragma once

#include <wx/wx.h>

#include "Layout/MainWindow.h"

#include "Core/TrackManager.h"

class Dawplr 
    : public wxApp 
{
public:
    virtual bool OnInit();   

private:
    TrackManager trackManager;
};