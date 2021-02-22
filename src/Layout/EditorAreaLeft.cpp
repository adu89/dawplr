#include "EditorAreaLeft.h"

#include "Components/EditorAreaLeftBottomControls.h"

#include <wx/sizer.h>

EditorAreaLeft::EditorAreaLeft(wxWindow* parent)
	: wxPanel(parent, wxID_ANY)
{
	wxBoxSizer* boxSizer = new wxBoxSizer(wxVERTICAL);

	trackHeaderArea = new TrackHeaderArea(this);
	EditorAreaLeftBottomControls* editorAreaLeftBottomControls = new EditorAreaLeftBottomControls(this);

	boxSizer->Add(trackHeaderArea, 1, wxEXPAND);
	boxSizer->Add(editorAreaLeftBottomControls, 0, wxEXPAND);

	SetSizer(boxSizer);
	FitInside();
}

EditorAreaLeft::~EditorAreaLeft()
{
}

TrackHeaderArea* EditorAreaLeft::GetTrackHeaderArea()
{
	return trackHeaderArea;
}