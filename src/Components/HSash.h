#pragma once

#include <wx/panel.h>
#include <wx/window.h>

wxDECLARE_EVENT(H_SASH_DRAGGING, wxCommandEvent);

class HSash
	: public wxPanel
{
public:
	HSash(wxWindow*);
	~HSash();
	void OnMouseEvent(wxMouseEvent&);
	// int GetY();
	// void SetY(int);
private:
	bool dragging;
	void onPaint(wxPaintEvent&);
	// int y;
	wxDECLARE_EVENT_TABLE();
};