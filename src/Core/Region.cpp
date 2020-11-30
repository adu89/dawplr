#include "Region.h"

Region::Region(std::string name, int startTime, int endTime, float** samples)
	: name(name), startTime(startTime), endTime(endTime), samples(samples)
{
}

Region::~Region()
{
}
