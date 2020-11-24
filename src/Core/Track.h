#pragma once

#include <string>

class Track {
public:
	Track();
	Track(std::string, bool, bool); 
	~Track();
	std::string GetName();
	void SetName(std::string);
	bool IsSoloed();
	bool IsMuted();
private:
	std::string name;
	bool soloed;
	bool muted;
};