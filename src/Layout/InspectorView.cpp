#include "InspectorView.h"

#include <wx/stattext.h>
#include <wx/sizer.h>

InspectorView::InspectorView(wxWindow* parent)
    : wxPanel(parent, wxID_ANY)
{
    SetBackgroundColour(*wxWHITE);

    wxStaticText* text = new wxStaticText(this, wxID_ANY, "Inspector View");

    wxBoxSizer* mainBoxSizer = new wxBoxSizer(wxHORIZONTAL);
    mainBoxSizer->Add(text, 1, wxALIGN_CENTER);

    SetSizer(mainBoxSizer);
    Layout();
}

InspectorView::~InspectorView()
{
}