#include "TrackHeaderHeightChangedEvent.h"


TrackHeaderHeightChangedEvent::TrackHeaderHeightChangedEvent(int index, int height)
    : wxEvent(0, TRACK_HEADER_HEIGHT_CHANGED)
    , index(index)
    , height(height)
{
}

wxEvent* TrackHeaderHeightChangedEvent::Clone() const
{ 
    return new TrackHeaderHeightChangedEvent(*this); 
}

int TrackHeaderHeightChangedEvent::GetIndex()
{
    return index;
}

int TrackHeaderHeightChangedEvent::GetHeight()
{
    return height;
}


wxDEFINE_EVENT(TRACK_HEADER_HEIGHT_CHANGED, TrackHeaderHeightChangedEvent);

#define TrackHeaderHeightChangedEventHandler(func) (&func)

