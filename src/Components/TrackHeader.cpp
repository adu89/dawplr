#include "TrackHeader.h"

#include <wx/dcbuffer.h>
#include <wx/dcgraph.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/gauge.h>
#include <string>  
#include "Core/Constants.h"
#include "Components/HMeter.h"

wxDEFINE_EVENT(TRACK_HEADER_HEIGHT_CHANGED, wxCommandEvent);

TrackHeader::TrackHeader(wxWindow* parent, int index) 
    : wxPanel(parent, index)
    , height(Constants::TRACK_HEADER_HEIGHT)
    , index(index)
{    
    //SetBackgroundStyle(wxBG_STYLE_PAINT);

    using namespace Constants;

    wxBoxSizer* mainBoxSizer = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer* horizontalBoxSizer = new wxBoxSizer(wxHORIZONTAL);
    mainBoxSizer->Add(horizontalBoxSizer, 1, wxEXPAND);

    wxStaticText* trackNumber = new wxStaticText(this, wxID_ANY, wxString(std::to_string(index)), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
    trackNumber->SetMinSize(wxSize(TRACK_NUMBER_WIDTH, -1));
    horizontalBoxSizer->Add(trackNumber, 0, wxALIGN_CENTER_VERTICAL);

    //wxPanel* spacer = new wxPanel(this, wxID_ANY);
    //spacer->SetBackgroundColour(*wxGREEN);
    //spacer->SetMinSize(wxSize(1, -1));
    //horizontalBoxSizer->Add(spacer, 0, wxEXPAND);

    wxBoxSizer* verticalBoxSizer = new wxBoxSizer(wxVERTICAL);
    horizontalBoxSizer->Add(verticalBoxSizer, 1);

    wxTextCtrl* trackName = new wxTextCtrl(this, wxID_ANY, "Track");
    verticalBoxSizer->Add(trackName, 0, wxEXPAND | wxTOP | wxBOTTOM, 10);

    HMeter* hMeter = new HMeter(this);
    hMeter->SetMinSize(wxSize(-1, 10));
    hMeter->SetValue(20*index);
    hMeter->SetMax(100);
    verticalBoxSizer->Add(hMeter, 0, wxEXPAND);
    
    wxButton* solo = new wxButton(this, wxID_ANY, wxString("S"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT);
    solo->SetMinSize(wxSize(SOLO_BUTTON_WIDTH, -1));
    horizontalBoxSizer->Add(solo, 0, wxTOP | wxLEFT, 10);

    wxButton* mute = new wxButton(this, wxID_ANY, wxString("M"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT);
    mute->SetMinSize(wxSize(MUTE_BUTTON_WIDTH, -1));
    horizontalBoxSizer->Add(mute, 0, wxTOP | wxRIGHT, 10);

    wxBoxSizer* hashSizer = new wxBoxSizer(wxHORIZONTAL);
    hSash = new HSash(this);
    hSash->SetMinSize(wxSize(-1, SASH_HEIGHT));
    hashSizer->Add(hSash, 1, wxEXPAND);
    mainBoxSizer->Add(hashSizer, 0, wxEXPAND);

    this->SetSizer(mainBoxSizer);
    this->Layout();

    //Bind(wxEVT_PAINT, &TrackHeader::OnPaint, this);
    //Bind(wxEVT_SIZE, &TrackHeader::OnSize, this);
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

void TrackHeader::OnSize(wxSizeEvent& e)
{
    auto clientRect = GetClientRect();

    //hSash->SetSize(wxRect(clientRect.GetBottomLeft() - wxPoint(0, 4), clientRect.GetBottomRight()));
}

void TrackHeader::OnPaint(wxPaintEvent&)
{
    wxBufferedPaintDC dc(this);
    wxGCDC gc(dc);

    wxRect rect = GetClientRect();
    gc.SetPen(*wxLIGHT_GREY_PEN);
    gc.SetBrush(*wxLIGHT_GREY_BRUSH);

    gc.DrawRectangle(rect);  

    //gc.SetPen(*wxMEDIUM_GREY_PEN);
    //gc.SetBrush(*wxMEDIUM_GREY_BRUSH);

    //gc.DrawRectangle(rect.GetBottomLeft() - wxSize(0, 1), wxSize(rect.GetWidth(), 2));
}

void TrackHeader::HandleMouseWheelEvent(wxMouseEvent& m) 
{    
    m.Skip();
}

BEGIN_EVENT_TABLE(TrackHeader, wxWindow)
    EVT_MOUSEWHEEL(TrackHeader::HandleMouseWheelEvent)
END_EVENT_TABLE()