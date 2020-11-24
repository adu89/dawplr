#include "Track.h"

Track::Track()
    : name("New Track"), soloed(false), muted(false)
{
}

Track::Track(std::string name, bool soloed, bool muted)
    : name(name), soloed(soloed), muted(muted)
{
}

Track::~Track()
{
}

std::string Track::GetName()
{
    return std::string();
}

void Track::SetName(std::string n)
{
    name = n;
}

bool Track::IsSoloed()
{
    return soloed;
}

bool Track::IsMuted()
{
    return muted;
}
