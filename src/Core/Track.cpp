#include "Track.h"

Track::Track(std::string name, int channels, bool soloed, bool muted)
    : name(name), channels(2), soloed(soloed), muted(muted)
{
}

Track::~Track()
{
}

std::string Track::GetName()
{
    return name;
}

std::vector<Region>& Track::GetRegions()
{
    return std::vector<Region>();
}

void Track::AddRegion(Region region)
{
    regions.push_back(std::move(region));
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
