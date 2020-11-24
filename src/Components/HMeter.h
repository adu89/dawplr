#pragma once

#include <wx/panel.h>
#include <wx/window.h>

class HMeter 
	: public wxPanel
{
public:
	HMeter(wxWindow*);
	~HMeter();
	void OnPaint(wxPaintEvent&);
	void SetValue(int);
	void SetMax(int);
private:
	int value;
	int max;
};
