#pragma once

#include <string>		
#include <AudioFile.h>

class Region
{
public:
	Region(std::string name, long startSample, long endSample, AudioFile<float> audioFile);
	~Region();
	AudioFile<float>& GetAudioData();
private:
	std::string name;
	long startSample;
	long endSample;
	AudioFile<float> audioFile;
};