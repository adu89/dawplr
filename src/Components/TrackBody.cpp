#include "TrackBody.h"

#include "Core/Constants.h"
#include "Components/RegionArea.h"
#include "Components/HSash.h"

#include <wx/scrolwin.h>
#include <wx/sizer.h>
#include <wx/log.h>

TrackBody::TrackBody(wxWindow* parent, int index)
    : wxPanel(parent, index)
{    
    wxBoxSizer* mainBoxSizer = new wxBoxSizer(wxVERTICAL);

    RegionArea* regionArea = new RegionArea(this);
    hSash = new HSash(this);

    mainBoxSizer->Add(regionArea, 1, wxEXPAND);
    mainBoxSizer->Add(hSash, 0, wxEXPAND);

    SetSizer(mainBoxSizer);
	FitInside();

    //For some reason, the following line only works properly after SetSizer(...) is called
    SetMinSize(wxSize(2000, Constants::TRACK_HEADER_HEIGHT + Constants::SASH_HEIGHT));

    Bind(H_SASH_DRAGGING, &TrackBody::onSashDragging, this);
}

TrackBody::~TrackBody()
{
}

void TrackBody::onSashDragging(wxCommandEvent& e)
{
    using namespace Constants;

    int sashHeight = hSash->GetSize().GetHeight();
    int sashY = e.GetInt();

    int nextTrackBodyHeight = wxMax(TRACK_HEADER_MIN_HEIGHT + sashHeight, sashY + sashHeight);
    nextTrackBodyHeight = wxMin(TRACK_HEADER_MAX_HEIGHT + sashHeight, nextTrackBodyHeight);

    SetMinSize(wxSize(2000, nextTrackBodyHeight));

    TrackBodyHeightChangedEvent event(GetId(), nextTrackBodyHeight);
    wxPostEvent(GetParent(), event);
    

    //GetParent()->FitInside();
}