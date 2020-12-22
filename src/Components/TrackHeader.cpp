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

wxDEFINE_EVENT(TRACK_HEADER_HEIGHT_CHANGED, wxCommandEvent);

TrackHeader::TrackHeader(wxWindow* parent, int index) 
    : wxPanel(parent, index)
    , height(Constants::TRACK_HEADER_HEIGHT)
    , index(index)
{    
    using namespace Constants;
    
    auto& trackManager = TrackManager::Instance();
    auto track = trackManager.GetTracks().at(index);

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
    solo->SetValue(track.IsSoloed());

    wxToggleButton* mute = new wxToggleButton(this, wxID_ANY, wxString("M"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT);
    mute->SetMinSize(wxSize(MUTE_BUTTON_WIDTH, -1));
    horizontalBoxSizer->Add(mute, 0, wxTOP | wxRIGHT, 10);
    mute->SetValue(track.IsMuted());

    wxBoxSizer* hashSizer = new wxBoxSizer(wxHORIZONTAL);
    hSash = new HSash(this);
    hSash->SetMinSize(wxSize(-1, SASH_HEIGHT));
    hashSizer->Add(hSash, 1, wxEXPAND);
    mainBoxSizer->Add(hashSizer, 0, wxEXPAND);

    this->SetSizer(mainBoxSizer);
    this->Layout();

    Bind(H_SASH_DRAGGING, &TrackHeader::OnHSashDragging, this);
}

TrackHeader::~TrackHeader() 
{    
}

int TrackHeader::GetHeight()
{
    return height;
}

void TrackHeader::SetHeight(int h)
{
    height = h;
}

void TrackHeader::OnHSashDragging(wxCommandEvent& e)
{
    height = hSash->GetY() + 1;
    
    wxCommandEvent event(TRACK_HEADER_HEIGHT_CHANGED);

    event.SetId(index);
    event.SetInt(height);

    wxPostEvent(GetParent(), event);
}

void TrackHeader::HandleMouseWheelEvent(wxMouseEvent& m) 
{    
    m.Skip();
}

BEGIN_EVENT_TABLE(TrackHeader, wxWindow)
    EVT_MOUSEWHEEL(TrackHeader::HandleMouseWheelEvent)
END_EVENT_TABLE()