#include "EditorAreaRight.h"

#include <wx/log.h>
#include <wx/gbsizer.h>

#include "TrackBody.h"

EditorAreaRight::EditorAreaRight(wxWindow* parent, EditorAreaLeft* editorAreaLeft)
	: wxScrolledWindow(parent, wxID_ANY), editorAreaLeft(editorAreaLeft)
{
	SetBackgroundColour(*wxLIGHT_GREY);

	//SetScrollbars(1, 1, 3000, 500000, 0, 0);
	//SetScrollRate(10, 10);

	Bind(wxEVT_SIZE, &EditorAreaRight::OnSize, this);
	Bind(wxEVT_SCROLLWIN_LINEUP, &EditorAreaRight::OnScrollUp, this);
	Bind(wxEVT_SCROLLWIN_LINEDOWN, &EditorAreaRight::OnScrollDown, this);

	wxGridBagSizer* gbSizer = new wxGridBagSizer(0, 0);

	for (int i = 0; i < 100; i++)
	{
		TrackBody* tb = new TrackBody(this, i);
		gbSizer->Add(tb, wxGBPosition(i, 0));
	}

	SetSizer(gbSizer);
	FitInside();
	SetScrollRate(1, 1);
}

EditorAreaRight::~EditorAreaRight()
{
}

//void EditorAreaRight::OnDraw(wxDC& dc)
//{
//	int height = 100;
//	int accY = 0;
//	int srcX, srcY;
//
//	CalcUnscrolledPosition(0, 0, &srcX, &srcY);
//
//	editorAreaLeft->SetSrcY(srcY);
//
//	for (int i = 0; i < 5000; i++)
//	{
//		if (i % 2 == 0) {
//			dc.SetPen(*wxRED_PEN);
//			dc.SetBrush(*wxRED_BRUSH);
//		} else{
//			dc.SetPen(*wxGREEN_PEN);
//			dc.SetBrush(*wxGREEN_BRUSH);
//		}
//
//		int clientY = GetClientSize().y;
//		int clientX = GetClientSize().x;
//
//		if (accY >= srcY && (accY + height <= srcY + clientY))
//		{
//			dc.DrawRectangle(wxRect(srcX, accY, clientX, 100));
//			dc.DrawText(wxString(std::to_string(i)), 1, accY);
//			dc.DrawText(wxString(std::to_string(i)), 1001, accY);
//		}
//
//		accY += height;
//	}
//}

void EditorAreaRight::OnScrollUp(wxScrollWinEvent& e)
{
	int x = 0, y = 10;

	if (e.GetOrientation() == wxOrientation::wxHORIZONTAL)
		x = 10, y = 0;

	wxLogDebug("OnScrollUp");
	auto st = GetViewStart();
	Scroll(st.x - x, st.y - y);
}

void EditorAreaRight::OnScrollDown(wxScrollWinEvent& e)
{
	int x = 0, y = 10;

	if (e.GetOrientation() == wxOrientation::wxHORIZONTAL)
		x = 10, y = 0;

	wxLogDebug("OnScrollDown");
	auto st = GetViewStart();
	Scroll(st.x + x, st.y + y);
}

void EditorAreaRight::OnSize(wxSizeEvent&)
{
	wxLogDebug("OnSize");

	for (auto child : GetChildren())
	{
		TrackBody* trackBody = static_cast<TrackBody*>(child);
		trackBody->SetMinSize(wxSize(wxMax(trackBody->GetVirtualWidth(), GetClientSize().GetWidth()) * 2, trackBody->GetVirtualHeight()));
	}
}
