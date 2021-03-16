#include "EditorAreaRight.h"

#include <wx/log.h>

EditorAreaRight::EditorAreaRight(wxWindow* parent, TrackManager& trackManager)
	: SyncedScrolledWindow(parent)
	, trackManager(trackManager)
{
	 sizer = new wxGridBagSizer(0, 0);

	auto& tracks = trackManager.GetTracks();

	for(int i = 0; i < tracks.size(); ++i)
	{
		TrackBody* trackBody = new TrackBody(this, i);
		sizer->Add(trackBody, wxGBPosition(i, 0));
	}

	SetSizer(sizer);
	FitInside();
	SetScrollRate(20, 20);

	Bind(TRACK_BODY_HEIGHT_CHANGED, &EditorAreaRight::onTrackBodyHeightChanged, this);
	Bind(TRACK_HEADER_HEIGHT_CHANGED, &EditorAreaRight::onTrackHeaderHeightChanged, this);

	trackManager.AddListener(this);
}

EditorAreaRight::~EditorAreaRight()
{
	trackManager.RemoveListener(this);
}

void EditorAreaRight::onTrackBodyHeightChanged(TrackBodyHeightChangedEvent& e)
{
	wxPostEvent(otherWindow, e);
	FitInside();
}

void EditorAreaRight::onTrackHeaderHeightChanged(TrackHeaderHeightChangedEvent& e)
{
	auto trackBody = static_cast<TrackBody*>(GetWindowChild(e.GetIndex()));
	trackBody->SetMinSize(wxSize(trackBody->GetSize().GetWidth(), e.GetHeight()));
	FitInside();
}

void EditorAreaRight::OnAddTrack(Track& track)
{
	auto trackIndex = trackManager.GetTracks().size() - 1;
	TrackBody* trackBody = new TrackBody(this, trackIndex);
	sizer->Add(trackBody, wxGBPosition(trackIndex, 0));
	FitInside();
}


// void EditorAreaRight::OnSize(wxSizeEvent&)
// {
// 	for (auto child : GetChildren())
// 	{
// 		TrackBody* trackBody = static_cast<TrackBody*>(child);
// 	}

// 	Layout();
// 	AdjustScrollbars();
// }
