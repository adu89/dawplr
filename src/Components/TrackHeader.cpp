#include "TrackHeader.h"

#include <wx/dcbuffer.h>
#include <wx/dcgraph.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/tglbtn.h>
#include <wx/gauge.h>

#include <string>  

#include "Core/Constants.h"
#include "Core/TrackManager.h"
#include "Components/HMeter.h"
#include "Events/TrackHeaderHeightChangedEvent.h"

TrackHeader::TrackHeader(wxWindow* parent, int index, Track& track) 
    : wxPanel(parent, index)
    , track(track)
{    
    using namespace Constants;

    wxBoxSizer* mainBoxSizer = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer* horizontalBoxSizer = new wxBoxSizer(wxHORIZONTAL);
    mainBoxSizer->Add(horizontalBoxSizer, 1, wxEXPAND);

    wxStaticText* trackNumber = new wxStaticText(this, wxID_ANY, wxString(std::to_string(index+1)), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
    trackNumber->SetMinSize(wxSize(TRACK_NUMBER_WIDTH, -1));
    horizontalBoxSizer->Add(trackNumber, 0, wxALIGN_CENTER_VERTICAL);

    wxBoxSizer* verticalBoxSizer = new wxBoxSizer(wxVERTICAL);
    horizontalBoxSizer->Add(verticalBoxSizer, 1);

    wxTextCtrl* trackName = new wxTextCtrl(this, wxID_ANY, track.GetName());
    verticalBoxSizer->Add(trackName, 0, wxEXPAND | wxTOP | wxBOTTOM, 10);

    HMeter* hMeter = new HMeter(this);
    hMeter->SetMinSize(wxSize(-1, 10));
    hMeter->SetValue(20*index);
    hMeter->SetMax(100);
    verticalBoxSizer->Add(hMeter, 0, wxEXPAND);
    
    wxToggleButton* solo = new wxToggleButton(this, wxID_ANY, wxString("S"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT);
    solo->SetMinSize(wxSize(SOLO_BUTTON_WIDTH, -1));
    horizontalBoxSizer->Add(solo, 0, wxTOP | wxLEFT, 10);
    solo->SetValue(true);

    wxToggleButton* mute = new wxToggleButton(this, wxID_ANY, wxString("M"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT);
    mute->SetMinSize(wxSize(MUTE_BUTTON_WIDTH, -1));
    horizontalBoxSizer->Add(mute, 0, wxTOP | wxRIGHT, 10);
    mute->SetValue(false);

    wxBoxSizer* hashSizer = new wxBoxSizer(wxHORIZONTAL);
    hSash = new HSash(this);
    hSash->SetMinSize(wxSize(-1, SASH_HEIGHT));
    hashSizer->Add(hSash, 1, wxEXPAND);
    mainBoxSizer->Add(hashSizer, 0, wxEXPAND);

    this->SetSizer(mainBoxSizer);
    this->Layout();

	SetMinSize(wxSize(-1, Constants::TRACK_HEADER_HEIGHT + Constants::SASH_HEIGHT)); 

    Bind(H_SASH_DRAGGING, &TrackHeader::onSashDragging, this);
}

TrackHeader::~TrackHeader() 
{    
}

void TrackHeader::onSashDragging(wxCommandEvent& e)
{
    using namespace Constants;

    int sashHeight = hSash->GetSize().GetHeight();
    int sashY = e.GetInt();

    int nextTrackHeaderHeight = wxMax(TRACK_HEADER_MIN_HEIGHT + sashHeight, sashY + sashHeight);
    nextTrackHeaderHeight = wxMin(TRACK_HEADER_MAX_HEIGHT + sashHeight, nextTrackHeaderHeight);

    SetMinSize(wxSize(-1, nextTrackHeaderHeight));

    TrackHeaderHeightChangedEvent event(GetId(), nextTrackHeaderHeight);
    wxPostEvent(GetParent(), event);
}