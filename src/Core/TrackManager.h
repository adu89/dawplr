#pragma once

#include <vector>

#include "Track.h"
#include "Listeners.h"

class TrackManager {
public:
	static TrackManager& Instance();
	const std::vector<Track>& GetTracks();
	void AddTrack(Track track);

	class Listener {
	public:
		virtual ~Listener() = default;
		virtual void OnAddTrack(const Track& newTrack) = 0;
	};

	void AddListener(Listener* l);
	void RemoveListener(Listener* l);
private:
	TrackManager();
	~TrackManager();
	std::vector<Track> tracks;
	Listeners<Listener> listeners;
}; 