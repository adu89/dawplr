#include "VScroll.h"

#include "Core/Constants.h"
#include "Layout/EditorContainer.h"

wxDECLARE_EVENT(SCROLL_OFFSET_Y_CHANGED, wxCommandEvent);

VScroll::VScroll(wxWindow* parent) 
    : wxPanel(parent, wxID_ANY)
    , dragging(false)
{
    SetBackgroundColour(*wxRED);

    scroller = new VScroller(this);

    Bind(wxEVT_SIZE, &VScroll::OnSize, this);
    Bind(SCROLL_OFFSET_Y_CHANGED, &VScroll::OnScrollYOffsetChanged, this);

    scroller->SetBackgroundColour(*wxBLACK);
}

VScroll::~VScroll() 
{
    
}

void VScroll::OnSize(wxSizeEvent& e) 
{
    wxRect clientRect = GetClientRect();
    scroller->SetSize(wxRect(0, scroller->GetY(), Constants::SCROLL_BAR_INNER_WIDTH, clientRect.GetHeight() * scrollRatio));
    scroller->CenterOnParent(wxHORIZONTAL);
}

void VScroll::SetScrollRatio(float s) 
{
    scrollRatio = s;
}

void VScroll::SetScrollOffset(float y) 
{
    scroller->SetY(y);  
}

float VScroll::GetScrollOffset() 
{
    return scroller->GetY();
}

void VScroll::OnScrollYOffsetChanged()
{
    static_cast<EditorContainer*>(GetParent())->OnScrollYOffsetChanged();
}

void VScroll::OnMouseEvent(wxMouseEvent& m) 
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

    // m.ResumePropagation(wxEVENT_PROPAGATE_MAX);
    // m.Skip();
}

BEGIN_EVENT_TABLE(VScroll, wxWindow)
    EVT_MOUSE_EVENTS(VScroll::OnMouseEvent)
END_EVENT_TABLE()
