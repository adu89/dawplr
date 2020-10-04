#include "MainVerticalSplitter.h"
#include "Core/Constants.h"
#include "InspectorView.h"
#include "MainHorizontalSplitter.h"

MainVerticalSplitter::MainVerticalSplitter(wxWindow* parent)
    : wxSplitterWindow(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D | wxSP_LIVE_UPDATE)
{
    SetBackgroundColour(*wxWHITE);

    SetDoubleBuffered(true);

    SetMinimumPaneSize(Constants::SPLITTER_MIN_WIDTH);

    SplitVertically(new InspectorView(this), new MainHorizontalSplitter(this), Constants::INSPECTOR_VIEW_WIDTH);
}

MainVerticalSplitter::~MainVerticalSplitter()
{
}