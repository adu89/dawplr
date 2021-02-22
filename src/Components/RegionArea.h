#pragma once

#include <wx/panel.h>
#include <wx/window.h>

class RegionArea
	: public wxPanel 
{
public:
	RegionArea(wxWindow* parent);
	~RegionArea();
	void OnPaint(wxPaintEvent&);
};
