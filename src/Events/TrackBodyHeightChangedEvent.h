#pragma once

#include <wx/event.h>

class TrackBodyHeightChangedEvent;
wxDECLARE_EVENT(TRACK_BODY_HEIGHT_CHANGED, TrackBodyHeightChangedEvent);

class TrackBodyHeightChangedEvent
    : public wxEvent
{
public:
    TrackBodyHeightChangedEvent(int index, int height);
    virtual wxEvent *Clone() const;

    int GetIndex();
    int GetHeight();
private:
    int index;
    int height;
};