#include "TransportBar.h"

#include <wx/sizer.h>
#include <wx/stattext.h>

#include "Core/Constants.h"

TransportBar::TransportBar(wxWindow* parent)
    : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(-1, Constants::TRANSPORT_BAR_HEIGHT))
{
    SetBackgroundColour(*wxWHITE);

    SetMaxSize(wxSize(-1, Constants::TRANSPORT_BAR_HEIGHT));

    wxStaticText* text = new wxStaticText(this, wxID_ANY, "Transport Bar");

    wxBoxSizer* mainBoxSizer = new wxBoxSizer(wxHORIZONTAL);
    mainBoxSizer->Add(text, 1, wxALIGN_CENTER);

    SetSizer(mainBoxSizer);
    Layout();
}

TransportBar::~TransportBar()
{
}