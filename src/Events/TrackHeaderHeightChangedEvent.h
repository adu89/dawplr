#pragma once

#include <wx/event.h>

class TrackHeaderHeightChangedEvent;
wxDECLARE_EVENT(TRACK_HEADER_HEIGHT_CHANGED, TrackHeaderHeightChangedEvent);

class TrackHeaderHeightChangedEvent
    : public wxEvent
{
public:
    TrackHeaderHeightChangedEvent(int index, int height);
    virtual wxEvent *Clone() const;

    int GetIndex();
    int GetHeight();
private:
    int index;
    int height;
};