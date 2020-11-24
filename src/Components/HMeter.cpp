#include "HMeter.h"

#include <wx/dcbuffer.h>
#include <wx/dcgraph.h>

HMeter::HMeter(wxWindow* parent)
	: wxPanel(parent, wxID_ANY)
	, value(0)
	, max(1)
{
	Bind(wxEVT_PAINT, &HMeter::OnPaint, this);
}

HMeter::~HMeter()
{
}

void HMeter::OnPaint(wxPaintEvent&)
{
	wxBufferedPaintDC dc(this);
	wxGCDC gc(dc);

	wxRect rect = GetClientRect();

	gc.SetPen(*wxGREY_PEN);
	gc.SetBrush(*wxGREY_BRUSH);

	gc.DrawRectangle(rect);

	auto width = (value * rect.GetWidth()) / max;

	gc.SetPen(*wxGREEN_PEN);
	gc.SetBrush(*wxGREEN_BRUSH);

	rect.SetWidth(width);

	gc.DrawRectangle(rect);
}

void HMeter::SetValue(int v)
{
	value = v;
}

void HMeter::SetMax(int m)
{
	max = m;
}
