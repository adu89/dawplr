#include "RegionArea.h"

#include <wx/dcbuffer.h>

RegionArea::RegionArea(wxWindow* parent)
    : wxPanel(parent, wxID_ANY)
{
    Bind(wxEVT_PAINT, &RegionArea::OnPaint, this);
}

RegionArea::~RegionArea()
{
}

void RegionArea::OnPaint(wxPaintEvent& evt)
{
    wxBufferedPaintDC dc(this);

    dc.SetPen(*wxRED_PEN);
    dc.SetBrush(*wxRED_BRUSH);

    // if (index % 2 == 0) {
    //     dc.SetPen(*wxGREEN_PEN);
    //     dc.SetBrush(*wxGREEN_BRUSH);
    // }

    dc.DrawRectangle(GetUpdateRegion().GetBox());

    //auto x = this->GetUpdateRegion().GetBox();
    //dc.DrawText(wxString("Track: " + wxString(std::to_string(index))), x.GetTopLeft());
}