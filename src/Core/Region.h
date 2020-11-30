#pragma once

#include <string>			

class Region
{
public:
	Region(std::string name, int startTime, int endTime);
	~Region();
private:
	std::string name;
	int startTime;
	int endTime;
	float** samples;
};