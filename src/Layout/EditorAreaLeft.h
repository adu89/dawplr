#pragma once

#include <wx/panel.h>
#include <wx/window.h>
#include <wx/dc.h>

class EditorAreaLeft
	: public wxPanel
{
public:
	EditorAreaLeft(wxWindow* parent);
	~EditorAreaLeft();
	void OnPaint(wxPaintEvent&);
	void SetSrcY(int);
private:
	int srcY;
};