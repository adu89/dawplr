#include "HSash.h"

#include <wx/dcbuffer.h>
#include <wx/dcgraph.h>

#include "Core/Constants.h"

wxDEFINE_EVENT(H_SASH_DRAGGING, wxCommandEvent);

HSash::HSash(wxWindow* parent)
	: wxPanel(parent, wxID_ANY)
	, dragging(false)
    // , y(0)
{
    SetMinSize(wxSize(-1, Constants::SASH_HEIGHT));

    Bind(wxEVT_PAINT, &HSash::onPaint, this);
}

HSash::~HSash()
{
}


void HSash::onPaint(wxPaintEvent&)
{
    wxBufferedPaintDC dc(this);

    dc.SetPen(*wxBLACK_PEN);
    dc.SetBrush(*wxBLACK_BRUSH);

    // if (index % 2 == 0) {
    //     dc.SetPen(*wxGREEN_PEN);
    //     dc.SetBrush(*wxGREEN_BRUSH);
    // }

    dc.DrawRectangle(GetUpdateRegion().GetBox());

    //auto x = this->GetUpdateRegion().GetBox();
    //dc.DrawText(wxString("Track: " + wxString(std::to_string(index))), x.GetTopLeft());
}

// int HSash::GetY()
// {
//     return y;
// }

// void HSash::SetY(int newY)
// {
//     y = newY;
// }

void HSash::OnMouseEvent(wxMouseEvent& m)
{
    if (m.Leaving() && !dragging)
        SetCursor(wxCURSOR_DEFAULT);

    if (m.Entering())
        SetCursor(wxCURSOR_SIZENS);

    if (m.LeftDown())
    {
        SetCursor(wxCURSOR_SIZENS);
        CaptureMouse();
        dragging = true;
    }

    if (m.LeftUp())
    {
        SetCursor(wxCURSOR_DEFAULT);
        ReleaseMouse();
        dragging = false;
    }

    if (dragging)
    {
        wxPoint mouseOnScreen = wxGetMousePosition();

        auto destination = GetParent()->ScreenToClient(mouseOnScreen);
    
        wxCommandEvent event(H_SASH_DRAGGING);
        event.SetInt(destination.y);
        wxPostEvent(GetParent(), event);
    }

    m.Skip();
}

BEGIN_EVENT_TABLE(HSash, wxWindow)
    EVT_MOUSE_EVENTS(HSash::OnMouseEvent)
END_EVENT_TABLE()
