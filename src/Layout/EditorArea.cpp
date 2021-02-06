#include "EditorArea.h"

#include "Core//Constants.h"
#include "EditorAreaLeft.h"
#include "EditorAreaRight.h"

EditorArea::EditorArea(wxWindow* parent)
	: wxSplitterWindow(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D | wxSP_LIVE_UPDATE)
{
	SetMinimumPaneSize(Constants::TRACK_HEADER_MIN_WIDTH);

	auto editorAreaLeft = new EditorAreaLeft(this);

	SplitVertically(editorAreaLeft, new EditorAreaRight(this, editorAreaLeft), Constants::TRACK_HEADER_WIDTH);
}

EditorArea::~EditorArea()
{
}

bool EditorArea::OnSashPositionChange(int position)
{
	return position > Constants::TRACK_HEADER_MAX_WIDTH ? false : true;
}
