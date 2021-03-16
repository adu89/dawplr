#pragma once

#include <wx/window.h>
#include <wx/gbsizer.h>

#include "Components/SyncedScrollWindow.h"
#include "Events/TrackBodyHeightChangedEvent.h"
#include "Events/TrackHeaderHeightChangedEvent.h"
#include "Core/TrackManager.h"

class TrackHeaderArea
    : public SyncedScrolledWindow
    , public TrackManager::Listener
{
public:
    TrackHeaderArea(wxWindow*, TrackManager&);
    ~TrackHeaderArea();

    void OnAddTrack(Track&) override;
private:
    void onTrackBodyHeightChanged(TrackBodyHeightChangedEvent&);
    void onTrackHeaderHeightChanged(TrackHeaderHeightChangedEvent&);
    TrackManager& trackManager;
    wxGridBagSizer* sizer;
};