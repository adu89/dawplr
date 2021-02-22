#include "EditorAreaLeftBottomControls.h"

EditorAreaLeftBottomControls::EditorAreaLeftBottomControls(wxWindow* parent)
    : wxPanel(parent, wxID_ANY)
{
    SetMinSize(wxSize(-1, wxSystemSettings::GetMetric(wxSYS_HSCROLL_Y)));
}

EditorAreaLeftBottomControls::~EditorAreaLeftBottomControls()
{
}
