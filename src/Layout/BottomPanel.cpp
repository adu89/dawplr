#include "BottomPanel.h"

#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/notebook.h>

BottomPanel::BottomPanel(wxWindow* parent)
    : wxPanel(parent, wxID_ANY)
{
    wxBoxSizer* mainBoxSizer = new wxBoxSizer(wxVERTICAL);

    wxNotebook* noteBook = new wxNotebook(this, wxID_ANY);
    mainBoxSizer->Add(noteBook, 1, wxEXPAND);

    noteBook->AddPage(new wxPanel(noteBook), "Mixer");
    noteBook->AddPage(new wxPanel(noteBook), "Piano Roll");

    SetSizer(mainBoxSizer);
    Layout();
}

BottomPanel::~BottomPanel()
{
}