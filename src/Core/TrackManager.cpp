#include "TrackManager.h"

TrackManager& TrackManager::Instance()
{
	static TrackManager trackManager;
	return trackManager;
}

const std::vector<Track>& TrackManager::GetTracks()
{
	return tracks;
}

void TrackManager::AddTrack(Track track)
{
	tracks.push_back(std::move(track));
}

TrackManager::TrackManager()
{
}

TrackManager::~TrackManager()
{
}
