#include "EditorArea.h"

#include "Core/Constants.h"
#include "EditorAreaLeft.h"
#include "EditorAreaRight.h"
#include "TrackHeaderArea.h"

EditorArea::EditorArea(wxWindow* parent)
	: wxSplitterWindow(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D | wxSP_LIVE_UPDATE)
{
	SetMinimumPaneSize(Constants::TRACK_HEADER_MIN_WIDTH);

	EditorAreaLeft* editorAreaLeft = new EditorAreaLeft(this);
	EditorAreaRight* editorAreaRight = new EditorAreaRight(this);	

	auto trackHeaderArea = editorAreaLeft->GetTrackHeaderArea();
	trackHeaderArea->SetOtherWindow(editorAreaRight);
	editorAreaRight->SetOtherWindow(trackHeaderArea);

	SplitVertically(editorAreaLeft, editorAreaRight, Constants::TRACK_HEADER_WIDTH);
}

EditorArea::~EditorArea()
{
}

bool EditorArea::OnSashPositionChange(int position)
{
	return position > Constants::TRACK_HEADER_MAX_WIDTH ? false : true;
}
