#include "TrackBodyHeightChangedEvent.h"


TrackBodyHeightChangedEvent::TrackBodyHeightChangedEvent(int index, int height)
    : wxEvent(0, TRACK_BODY_HEIGHT_CHANGED)
    , index(index)
    , height(height)
{
}

wxEvent* TrackBodyHeightChangedEvent::Clone() const
{ 
    return new TrackBodyHeightChangedEvent(*this); 
}

int TrackBodyHeightChangedEvent::GetIndex()
{
    return index;
}

int TrackBodyHeightChangedEvent::GetHeight()
{
    return height;
}


wxDEFINE_EVENT(TRACK_BODY_HEIGHT_CHANGED, TrackBodyHeightChangedEvent);

#define TrackBodyHeightChangedEventHandler(func) (&func)

