#include "TrackBody.h"

#include "Core/Constants.h"
#include "Components/RegionArea.h"
#include <Components/HSash.h>
#include <wx/scrolwin.h>

#include <wx/sizer.h>
#include <wx/log.h>

TrackBody::TrackBody(wxWindow* parent, int index)
    : wxPanel(parent, wxID_ANY), virtualHeight(Constants::TRACK_LANE_HEIGHT), index(index)
{
    wxBoxSizer* mainBoxSizer = new wxBoxSizer(wxVERTICAL);

    RegionArea* regionArea = new RegionArea(this);
    HSash* hSash = new HSash(this);

    mainBoxSizer->Add(regionArea, 1, wxEXPAND);
    mainBoxSizer->Add(hSash, 0, wxEXPAND);

    SetSizer(mainBoxSizer);
	FitInside();

    Bind(H_SASH_DRAGGING, &TrackBody::onSashDragging, this);
}

TrackBody::~TrackBody()
{
}

int TrackBody::GetVirtualHeight()
{
    return virtualHeight;
}

int TrackBody::GetVirtualWidth()
{
    return virtualWidth;
}

void TrackBody::onSashDragging(wxCommandEvent& e)
{
    SetMinSize(wxSize(2000, e.GetInt()));
    GetParent()->FitInside();
}