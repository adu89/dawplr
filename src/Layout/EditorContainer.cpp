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
    horizontalScrollBar = new HScroll(this);

    Bind(wxEVT_SIZE, &EditorContainer::OnSize, this);
    Bind(SCROLL_OFFSET_Y_CHANGED, &EditorContainer::OnScrollYOffsetChanged, this);
    Bind(TRACKS_OFFSET_Y_CHANGED, &EditorContainer::OnTrackYOffsetChanged, this);
    Bind(TRACKS_HEIGHT_CHANGED, &EditorContainer::OnTracksHeightChanged, this);
    Bind(TRACK_LIST_CHANGED, &EditorContainer::OnTrackListChanged, this);
    Bind(SCROLL_OFFSET_X_CHANGED, &EditorContainer::OnScrollXOffsetChanged, this);
    Bind(TRACKS_OFFSET_X_CHANGED, &EditorContainer::OnTrackXOffsetChanged, this);
}

EditorContainer::~EditorContainer() 
{
}

void EditorContainer::OnSize(wxSizeEvent& e) 
{
    using namespace Constants;
    
    wxRect clientRect = GetClientRect();
    
    verticalScrollBar->SetScrollRatio(GetYScrollRatio());
    verticalScrollBar->SetScrollOffset(editorView->GetTracksYOffset() * GetYScrollRatio());
    verticalScrollBar->SetSize(wxRect(wxPoint(clientRect.GetRight() - (SCROLL_BAR_WIDTH-1), 0), wxSize(SCROLL_BAR_WIDTH, clientRect.GetHeight())));

    horizontalScrollBar->SetScrollRatio(GetXScrollRatio());
    horizontalScrollBar->SetScrollOffset(editorView->GetTrackLanesXOffset() * GetXScrollRatio());
    horizontalScrollBar->SetSize(wxRect(wxPoint(0, clientRect.GetBottom() - (SCROLL_BAR_WIDTH - 1)), wxSize(clientRect.GetWidth() - SCROLL_BAR_WIDTH, SCROLL_BAR_WIDTH)));

    editorView->SetSize(wxRect(clientRect.GetTopLeft(), horizontalScrollBar->GetRect().GetTopRight()));
}

void EditorContainer::OnTrackYOffsetChanged(wxCommandEvent& event)
{    
    verticalScrollBar->SetScrollRatio(GetYScrollRatio());
    verticalScrollBar->SetScrollOffset(editorView->GetTracksYOffset()* GetYScrollRatio());
    verticalScrollBar->PostSizeEvent();

    editorView->PostSizeEvent();
}

void EditorContainer::OnScrollYOffsetChanged(wxCommandEvent& event)
{
    verticalScrollBar->PostSizeEvent();

    editorView->SetTracksYOffset(verticalScrollBar->GetScrollOffset() / GetYScrollRatio());
    editorView->PostSizeEvent();
}

float EditorContainer::GetYScrollRatio()
{
    return static_cast<float>(GetClientRect().GetHeight()) / static_cast<float>(editorView->GetVirtualHeight());
}

float EditorContainer::GetXScrollRatio()
{
    return static_cast<float>(editorView->GetTrackLanesContainerWidth()) / static_cast<float>(editorView->GetTrackLanesVirtualWidth());
}

void EditorContainer::OnScrollXOffsetChanged(wxCommandEvent&)
{
    horizontalScrollBar->PostSizeEvent();

    editorView->SetTrackLanesXOffset(horizontalScrollBar->GetScrollOffset() / GetXScrollRatio());
}

void EditorContainer::OnTracksHeightChanged(wxCommandEvent& e)
{
    verticalScrollBar->SetScrollRatio(GetYScrollRatio());
    verticalScrollBar->SetScrollOffset(editorView->GetTracksYOffset() * GetYScrollRatio());

    verticalScrollBar->PostSizeEvent();
}

void EditorContainer::OnTrackListChanged(wxCommandEvent&)
{
    verticalScrollBar->SetScrollRatio(GetYScrollRatio());
    verticalScrollBar->SetScrollOffset(editorView->GetTracksYOffset() * GetYScrollRatio());

    verticalScrollBar->PostSizeEvent();
}

void EditorContainer::OnTrackXOffsetChanged(wxCommandEvent& evt)
{
    horizontalScrollBar->SetScrollRatio(GetXScrollRatio());
    horizontalScrollBar->SetScrollOffset(editorView->GetTrackLanesXOffset() * GetXScrollRatio());
    horizontalScrollBar->PostSizeEvent();

    editorView->OnTrackXOffsetChanged(evt);
}

void EditorContainer::HandleMouseWheelEvent(wxMouseEvent& m) 
{
    mouseWheelRotation += m.GetWheelRotation();
    int lines = mouseWheelRotation / m.GetWheelDelta();
    mouseWheelRotation -= lines * m.GetWheelDelta();

    auto axis = m.GetWheelAxis();

    if(lines != 0) {
        wxScrollWinEvent newEvent;
        newEvent.SetPosition(0);
        newEvent.SetOrientation(m.GetWheelAxis());
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


