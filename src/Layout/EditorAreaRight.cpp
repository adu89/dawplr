#include "EditorAreaRight.h"

#include <wx/log.h>
#include <wx/gbsizer.h>

EditorAreaRight::EditorAreaRight(wxWindow* parent)
	: SyncedScrolledWindow(parent)
{
	wxGridBagSizer* gbSizer = new wxGridBagSizer(0, 0);

	for (int i = 0; i < 25; i++)
	{
		TrackBody* trackBody = new TrackBody(this, i);
		gbSizer->Add(trackBody, wxGBPosition(i, 0));
	}

	SetSizer(gbSizer);
	FitInside();
	SetScrollRate(10, 10);

	Bind(TRACK_BODY_HEIGHT_CHANGED, &EditorAreaRight::onTrackBodyHeightChanged, this);
}

EditorAreaRight::~EditorAreaRight()
{
}

void EditorAreaRight::onTrackBodyHeightChanged(TrackBodyHeightChangedEvent& e)
{
	wxPostEvent(otherWindow, e);
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
