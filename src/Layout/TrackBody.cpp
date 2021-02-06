#include "TrackBody.h"

#include "Core/Constants.h"

#include <wx/log.h>
#include <wx/dcbuffer.h>

TrackBody::TrackBody(wxWindow* parent, int index)
    : wxPanel(parent, wxID_ANY), virtualHeight(Constants::TRACK_LANE_HEIGHT), index(index)
{
    Bind(wxEVT_PAINT, &TrackBody::OnPaint, this);
}

TrackBody::~TrackBody()
{
}

int TrackBody::GetVirtualHeight()
{
    return virtualHeight;
}

int TrackBody::GetVirtualWidth()
{
    return virtualWidth;
}

void TrackBody::OnPaint(wxPaintEvent& evt)
{
    wxLogDebug("OnPaint: " + wxString(std::to_string(index)));

    wxBufferedPaintDC dc(this);

    dc.SetPen(*wxRED_PEN);
    dc.SetBrush(*wxRED_BRUSH);

    if (index % 2 == 0) {
        dc.SetPen(*wxGREEN_PEN);
        dc.SetBrush(*wxGREEN_BRUSH);
    }

    dc.DrawRectangle(GetClientRect());

    //auto x = this->GetUpdateRegion().GetBox();
    //dc.DrawText(wxString("Track: " + wxString(std::to_string(index))), x.GetTopLeft());
}
