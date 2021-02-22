#pragma once

#include <wx/panel.h>
#include <wx/window.h>

class TrackBody
	: public wxPanel 
{
public:
	TrackBody(wxWindow*, int);
	~TrackBody();
	int GetVirtualHeight();
	int GetVirtualWidth();
private:
	void onSashDragging(wxCommandEvent&);
	int virtualHeight;
	int virtualWidth;
	int index;
};