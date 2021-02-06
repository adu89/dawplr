#include "EditorAreaLeft.h"

#include <wx/log.h>
#include <wx/dcbuffer.h>

EditorAreaLeft::EditorAreaLeft(wxWindow* parent)
	: wxPanel(parent, wxID_ANY), srcY(0)
{
	Bind(wxEVT_PAINT, &EditorAreaLeft::OnPaint, this);
}

EditorAreaLeft::~EditorAreaLeft()
{
}

void EditorAreaLeft::OnPaint(wxPaintEvent&)
{
	wxBufferedPaintDC dc(this);

	dc.SetPen(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
	dc.SetBrush(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));

	dc.DrawRectangle(GetClientRect());

	int height = 100;
	int accY = 0;

	int clientY = GetClientSize().y - 17;
	int clientX = GetClientSize().x;

	for (int i = 0; i < 5000; i++)
	{
		if (i % 2 == 0) {
			dc.SetPen(*wxRED_PEN);
			dc.SetBrush(*wxRED_BRUSH);
		}
		else {
			dc.SetPen(*wxGREEN_PEN);
			dc.SetBrush(*wxGREEN_BRUSH);
		}

		if (accY >= srcY && (accY + height <= srcY + clientY))
		{
			dc.DrawRectangle(wxRect(0, accY - srcY, clientX, 100));
			dc.DrawText(wxString(std::to_string(i)), 1, accY - srcY);
			dc.DrawText(wxString(std::to_string(i)), 1001, accY - srcY);
		}

		accY += height;

	}

	dc.SetPen(*wxWHITE_PEN);
	dc.SetBrush(*wxWHITE_BRUSH);

	dc.DrawRectangle(0, clientY, clientX, 1);

	dc.SetPen(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));
	dc.SetBrush(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

	dc.DrawRectangle(0, clientY + 1, clientX, 16);
}

void EditorAreaLeft::SetSrcY(int y)
{
	srcY = y;
	Refresh();
}
