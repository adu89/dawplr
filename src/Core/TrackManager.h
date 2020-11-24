#pragma once

#include <vector>

#include "Track.h"

class TrackManager {
public:
	static TrackManager& Instance();
	const std::vector<Track>& GetTracks();
	void AddTrack(Track&&);
private:
	TrackManager();
	~TrackManager();
	std::vector<Track> tracks;
};