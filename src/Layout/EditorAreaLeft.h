#pragma once

#include <wx/window.h>
#include <wx/panel.h>

#include "TrackHeaderArea.h"
#include "Core/TrackManager.h"

class EditorAreaLeft
	: public wxPanel
{
public:
	EditorAreaLeft(wxWindow*, TrackManager&);
	~EditorAreaLeft();
	TrackHeaderArea* GetTrackHeaderArea();
private:
	TrackHeaderArea* trackHeaderArea;
};