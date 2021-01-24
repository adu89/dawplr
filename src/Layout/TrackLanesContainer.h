#pragma once

#include <wx/panel.h>
#include <wx/window.h>

#include "TrackLanes.h"

wxDECLARE_EVENT(TRACKS_OFFSET_X_CHANGED, wxCommandEvent);

class TrackLanesContainer 
	: public wxPanel 
{
public:
	TrackLanesContainer(wxWindow*);
	~TrackLanesContainer();
	void OnPaint(wxPaintEvent&);
	void OnSize(wxSizeEvent&);
	int GetTrackLanesVirtualWidth();
	void OnTrackHeaderHeightChanged(int, int);
	void SetTrackLanesXOffset(int);
	int GetTrackLanesXOffset();
	void OnTrackLaneHeightChanged();
	void ScrollRight();
	void ScrollLeft();
private:
	TrackLanes* trackLanes;
	int trackLanesXOffset;
};