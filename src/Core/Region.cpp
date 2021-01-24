#include "Region.h"

Region::Region(std::string name, long startSample, long endSample, AudioFile<float> audioFile)
	: name(name), startSample(startSample), endSample(endSample), audioFile(audioFile)
{
}

Region::~Region()
{
}

AudioFile<float>& Region::GetAudioData()
{
	return audioFile;
}
