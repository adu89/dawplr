#pragma once

#include <vector>

#include "Track.h"
#include "Listeners.h"

class TrackManager {
public:
	TrackManager();
	~TrackManager();
	std::vector<Track>& GetTracks();
	void AddTrack(Track track);

	class Listener {
	public:
		virtual ~Listener() = default;
		virtual void OnAddTrack(Track& newTrack) = 0;
	};

	void AddListener(Listener* l);
	void RemoveListener(Listener* l);
private:
	std::vector<Track> tracks;
	Listeners<Listener> listeners;
}; 