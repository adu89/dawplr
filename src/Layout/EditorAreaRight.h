#pragma once


#include <wx/window.h>
#include <wx/dc.h>
#include <wx/gbsizer.h>

#include "Components/TrackBody.h"
#include "Components/SyncedScrollWindow.h"
#include "Events/TrackBodyHeightChangedEvent.h"
#include "Events/TrackHeaderHeightChangedEvent.h"
#include "Core/TrackManager.h"

class EditorAreaRight
	: public SyncedScrolledWindow
	, public TrackManager::Listener
{
public:
	EditorAreaRight(wxWindow*, TrackManager&);
	~EditorAreaRight();

	void OnAddTrack(Track& newTrack);
private:
	void onTrackBodyHeightChanged(TrackBodyHeightChangedEvent&);
	void onTrackHeaderHeightChanged(TrackHeaderHeightChangedEvent&);
	TrackManager& trackManager;
	wxGridBagSizer* sizer;
};