#pragma once

#include <wx/window.h>
#include <wx/splitter.h>
#include "Core/TrackManager.h"

class EditorArea
	: public wxSplitterWindow
{
public:
	EditorArea(wxWindow*, TrackManager&);
	~EditorArea();

	bool OnSashPositionChange(int) override;
};
