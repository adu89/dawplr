#pragma once

#include <wx/panel.h>
#include <wx/window.h>

#include "Events/TrackBodyHeightChangedEvent.h"

class HSash;
class RegionArea;

class TrackBody
	: public wxPanel 
{
public:
	TrackBody(wxWindow*, int);
	~TrackBody();
private:
	void onSashDragging(wxCommandEvent&);
	void onSize(wxSizeEvent&);
	HSash* hSash;
	RegionArea* regionArea;
};