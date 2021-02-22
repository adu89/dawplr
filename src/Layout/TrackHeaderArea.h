#pragma once

#include <wx/window.h>

#include "Components/SyncedScrollWindow.h"

class TrackHeaderArea
    : public SyncedScrolledWindow
{
public:
    TrackHeaderArea(wxWindow*);
    ~TrackHeaderArea();
};