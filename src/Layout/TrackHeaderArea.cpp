#include "TrackHeaderArea.h"

#include <wx/gbsizer.h>
#include <wx/log.h>

#include "Components/TrackBody.h"

TrackHeaderArea::TrackHeaderArea(wxWindow* parent)
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

    DoShowScrollbars(wxSHOW_SB_NEVER, wxSHOW_SB_NEVER);

	Bind(TRACK_BODY_HEIGHT_CHANGED, &TrackHeaderArea::onTrackBodyHeightChanged, this);
}

TrackHeaderArea::~TrackHeaderArea()
{
}

void TrackHeaderArea::onTrackBodyHeightChanged(TrackBodyHeightChangedEvent& e)
{
	auto trackBody = static_cast<TrackBody*>(GetWindowChild(e.GetIndex()));
	trackBody->SetMinSize(wxSize(2000, e.GetHeight()));

	FitInside();
}
