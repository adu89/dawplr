#pragma once

#include <wx/window.h>

#include "Components/SyncedScrollWindow.h"
#include "Events/TrackBodyHeightChangedEvent.h"

class TrackHeaderArea
    : public SyncedScrolledWindow
{
public:
    TrackHeaderArea(wxWindow*);
    ~TrackHeaderArea();
private:
    void onTrackBodyHeightChanged(TrackBodyHeightChangedEvent&);
};