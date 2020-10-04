#include "MainHorizontalSplitter.h"

#include "Core/Constants.h"
#include "BottomPanel.h"
#include "EditorContainer.h"

MainHorizontalSplitter::MainHorizontalSplitter(wxWindow* parent)
    : wxSplitterWindow(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D | wxSP_LIVE_UPDATE)
{
    SetMinimumPaneSize(Constants::SPLITTER_MIN_WIDTH);

    SplitHorizontally(new EditorContainer(this), new BottomPanel(this), -1 * Constants::BOTTOM_PANEL_WIDTH);
}

MainHorizontalSplitter::~MainHorizontalSplitter()
{
}