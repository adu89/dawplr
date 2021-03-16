#include "TrackHeaderArea.h"

#include <wx/log.h>

#include "Components/TrackBody.h"
#include "Components/TrackHeader.h"
#include "Core/Constants.h"

TrackHeaderArea::TrackHeaderArea(wxWindow* parent, TrackManager& trackManager)
    : SyncedScrolledWindow(parent)
	, trackManager(trackManager)
{
	sizer = new wxGridBagSizer();
	sizer->AddGrowableCol(0);

	auto& tracks = trackManager.GetTracks();

	for(int i = 0; i < tracks.size(); ++i)
	{
		TrackHeader* trackHeader = new TrackHeader(this, i, tracks[i]);
		sizer->Add(trackHeader, wxGBPosition(i, 0), wxDefaultSpan, wxEXPAND);
	}

	SetSizer(sizer);
	FitInside();
	SetScrollRate(20, 20);

	DoShowScrollbars(wxSHOW_SB_NEVER, wxSHOW_SB_NEVER);

	Bind(TRACK_BODY_HEIGHT_CHANGED, &TrackHeaderArea::onTrackBodyHeightChanged, this);
	Bind(TRACK_HEADER_HEIGHT_CHANGED, &TrackHeaderArea::onTrackHeaderHeightChanged, this);

	trackManager.AddListener(this);
}

TrackHeaderArea::~TrackHeaderArea()
{
	trackManager.RemoveListener(this);
}

void TrackHeaderArea::onTrackBodyHeightChanged(TrackBodyHeightChangedEvent& e)
{
	auto trackHeader = static_cast<TrackHeader*>(GetWindowChild(e.GetIndex()));
	trackHeader->SetMinSize(wxSize(-1, e.GetHeight()));
	FitInside();
}

void TrackHeaderArea::OnAddTrack(Track& track)
{
	auto trackIndex = trackManager.GetTracks().size() - 1;
	TrackHeader* trackHeader = new TrackHeader(this, trackIndex, track);
	sizer->Add(trackHeader, wxGBPosition(trackIndex, 0), wxDefaultSpan, wxEXPAND);
	FitInside();
}

void TrackHeaderArea::onTrackHeaderHeightChanged(TrackHeaderHeightChangedEvent& e)
{
	wxPostEvent(otherWindow, e);
	FitInside();
}
