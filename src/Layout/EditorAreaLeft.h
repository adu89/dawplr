#pragma once

#include <wx/window.h>
#include <wx/panel.h>

#include "TrackHeaderArea.h"

class EditorAreaLeft
	: public wxPanel
{
public:
	EditorAreaLeft(wxWindow*);
	~EditorAreaLeft();
	TrackHeaderArea* GetTrackHeaderArea();
private:
	TrackHeaderArea* trackHeaderArea;
};