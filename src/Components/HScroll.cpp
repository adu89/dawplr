#include "HScroll.h"

#include "Core/Constants.h"
#include "Layout/EditorContainer.h"

HScroll::HScroll(wxWindow* parent)
    : wxPanel(parent, wxID_ANY)
    , dragging(false)
{
    SetBackgroundColour(*wxRED);

    scroller = new HScroller(this);

    Bind(wxEVT_SIZE, &HScroll::OnSize, this);
    Bind(SCROLL_OFFSET_X_CHANGED, &HScroll::OnScrollXOffsetChanged, this);

    scroller->SetBackgroundColour(*wxBLACK);
}

HScroll::~HScroll()
{

}

void HScroll::OnSize(wxSizeEvent& e)
{
    wxRect clientRect = GetClientRect();
    scroller->SetSize(wxRect(scroller->GetX(), 0, clientRect.GetWidth() * scrollRatio, Constants::SCROLL_BAR_INNER_WIDTH));
    scroller->CenterOnParent(wxVERTICAL);
}

void HScroll::SetScrollRatio(float s)
{
    scrollRatio = s;
}

void HScroll::SetScrollOffset(float x)
{
    scroller->SetX(x);
}

float HScroll::GetScrollOffset()
{
    return scroller->GetX();
}

void HScroll::OnScrollXOffsetChanged(wxCommandEvent& e)
{
    e.Skip();
}

void HScroll::OnMouseEvent(wxMouseEvent& m)
{
    // if(m.LeftDown()) 
    // {
    //     std::cout << "left-down" << std::endl;
    //     CaptureMouse();
    //     dragging = true;
    // }

    // if(m.LeftUp())
    // {
    //     std::cout << "left-up" << std::endl;
    //     ReleaseMouse();
    //     dragging = false;
    // }

    // if(dragging) 
    // {
    //     std::cout << "dragging" << std::endl;

    //     wxPoint mouseOnScreen = wxGetMousePosition();

    //     auto destination = GetParent()->ScreenToClient(mouseOnScreen);

    //     std::cout << destination.y << std::endl;

    //     if(/*destination.x <= Constants::TRACK_HEADER_MAX_WIDTH && destination.x >= Constants::TRACK_HEADER_MIN_WIDTH*/ true) {
    //         SetYOffset(destination.y);
    //         SendSizeEvent();
    //     }
    // }

    m.Skip();
}

BEGIN_EVENT_TABLE(HScroll, wxWindow)
EVT_MOUSE_EVENTS(HScroll::OnMouseEvent)
END_EVENT_TABLE()
