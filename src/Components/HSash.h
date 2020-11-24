#pragma once

#include <wx/panel.h>
#include <wx/window.h>

wxDECLARE_EVENT(H_SASH_DRAGGING, wxCommandEvent);
wxDECLARE_EVENT(H_SASH_START_DRAGGING, wxCommandEvent);

class HSash
	: public wxPanel
{
public:
	HSash(wxWindow*);
	~HSash();
	void OnMouseEvent(wxMouseEvent&);
	void OnPaint(wxPaintEvent&);
	int GetY();
	void SetY(int);
private:
	bool dragging;
	int y;
	wxDECLARE_EVENT_TABLE();
};