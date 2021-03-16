#include "TrackManager.h"

std::vector<Track>& TrackManager::GetTracks()
{
	return tracks;
}

void TrackManager::AddTrack(Track track)
{
	tracks.push_back(std::move(track));
	listeners.Call([&](Listener* l) { l->OnAddTrack(tracks[tracks.size() - 1]);  });
}

void TrackManager::AddListener(Listener* l)
{
	listeners.AddListener(l);
}

void TrackManager::RemoveListener(Listener* l)
{
	listeners.RemoveListener(l);
}

TrackManager::TrackManager()
{
}

TrackManager::~TrackManager()
{
}
