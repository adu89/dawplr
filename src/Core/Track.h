#pragma once

#include "Core/Region.h"

#include <vector>
#include <string>
#include <optional>

class Track 
{
public:
	Track();
	Track(std::string, int, bool, bool); 
	~Track();
	std::string GetName();
	std::vector<Region>& GetRegions();
	void AddRegion(Region region);
	void SetName(std::string);
	bool IsSoloed();
	bool IsMuted();
private:
	std::string name;
	bool soloed;
	bool muted;
	int channels;
	std::optional<int> color;
	std::vector<Region> regions;
};