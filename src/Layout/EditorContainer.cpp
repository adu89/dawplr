#include "EditorContainer.h"

#include "Core/Constants.h"

EditorContainer::EditorContainer(wxWindow* parent)
    : wxPanel(parent, wxID_ANY)
    , mouseWheelRotation(0)
{
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));
    SetDoubleBuffered(true);

    editorView = new EditorView(this);
    verticalScrollBar = new VScroll(this);

    Bind(wxEVT_SIZE, &EditorContainer::OnSize, this);
    Bind(SCROLL_OFFSET_Y_CHANGED, &EditorContainer::OnScrollYOffsetChanged, this);
    Bind(TRACKS_OFFSET_Y_CHANGED, &EditorContainer::OnTrackYOffsetChanged, this);
    Bind(TRACKS_HEIGHT_CHANGED, &EditorContainer::OnTracksHeightChanged, this);

}

EditorContainer::~EditorContainer() 
{
}

void EditorContainer::OnSize(wxSizeEvent& e) 
{
    using namespace Constants;
    
    wxRect clientRect = GetClientRect();
    
    verticalScrollBar->SetScrollRatio(GetScrollRatio());
    verticalScrollBar->SetScrollOffset(editorView->GetTracksYOffset()*GetScrollRatio());
    verticalScrollBar->SetSize(wxRect(wxPoint(clientRect.GetRight() - (SCROLL_BAR_WIDTH-1), 0), wxSize(SCROLL_BAR_WIDTH, clientRect.GetHeight())));

    editorView->SetSize(wxRect(clientRect.GetTopLeft(), verticalScrollBar->GetRect().GetBottomLeft() - wxSize(1, 0)));
}

void EditorContainer::OnTrackYOffsetChanged(wxCommandEvent& event)
{    
    verticalScrollBar->SetScrollRatio(GetScrollRatio());
    verticalScrollBar->SetScrollOffset(editorView->GetTracksYOffset()*GetScrollRatio());
    verticalScrollBar->PostSizeEvent();

    editorView->PostSizeEvent();
}

void EditorContainer::OnScrollYOffsetChanged(wxCommandEvent& event)
{
    verticalScrollBar->PostSizeEvent();

    editorView->SetTracksYOffset(verticalScrollBar->GetScrollOffset() / GetScrollRatio());
    editorView->PostSizeEvent();
}

float EditorContainer::GetScrollRatio()
{
    return static_cast<float>(GetClientRect().GetHeight()) / static_cast<float>(editorView->GetVirtualHeight());
}

void EditorContainer::OnTracksHeightChanged(wxCommandEvent& e)
{
    verticalScrollBar->SetScrollRatio(GetScrollRatio());
    verticalScrollBar->SetScrollOffset(editorView->GetTracksYOffset() * GetScrollRatio());

    verticalScrollBar->PostSizeEvent();
}

void EditorContainer::HandleMouseWheelEvent(wxMouseEvent& m) 
{
    mouseWheelRotation += m.GetWheelRotation();
    int lines = mouseWheelRotation / m.GetWheelDelta();
    mouseWheelRotation -= lines * m.GetWheelDelta();

    if(lines != 0) {
        wxScrollWinEvent newEvent;
        newEvent.SetPosition(0);
        newEvent.SetOrientation(wxVERTICAL);
        newEvent.SetEventObject(editorView);

        if (m.IsPageScroll())
        {
            if (lines > 0)
                newEvent.SetEventType(wxEVT_SCROLLWIN_PAGEUP);
            else
                newEvent.SetEventType(wxEVT_SCROLLWIN_PAGEDOWN);

            editorView->GetEventHandler()->ProcessEvent(newEvent);
        }
        else
        {
            lines *= m.GetLinesPerAction();

            if (lines > 0)
                newEvent.SetEventType(wxEVT_SCROLLWIN_LINEUP);
            else
                newEvent.SetEventType(wxEVT_SCROLLWIN_LINEDOWN);

            int times = abs(lines);
            
            for (; times > 0; times--)
                editorView->GetEventHandler()->ProcessEvent(newEvent);
        }
    }
}

BEGIN_EVENT_TABLE(EditorContainer, wxWindow)
    EVT_MOUSEWHEEL(EditorContainer::HandleMouseWheelEvent)
END_EVENT_TABLE()


