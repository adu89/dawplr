#include "TrackHeaderArea.h"

#include <wx/gbsizer.h>

#include "Components/TrackBody.h"

TrackHeaderArea::TrackHeaderArea(wxWindow* parent)
    : SyncedScrolledWindow(parent)
{
	wxGridBagSizer* gbSizer = new wxGridBagSizer(0, 0);

	for (int i = 0; i < 25; i++)
	{
		TrackBody* trackBody = new TrackBody(this, i);
		trackBody->SetMinSize(wxSize(2000, trackBody->GetVirtualHeight()));
		gbSizer->Add(trackBody, wxGBPosition(i, 0));
	}

	SetSizer(gbSizer);
	FitInside();
	SetScrollRate(10, 10);

    DoShowScrollbars(wxSHOW_SB_NEVER, wxSHOW_SB_NEVER);
}

TrackHeaderArea::~TrackHeaderArea()
{
}
