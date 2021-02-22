#pragma once

class SessionManager 
{
public:
	static SessionManager& Instance();

private:
	SessionManager();
	~SessionManager();
	int bpm;
	float beat;
	int pixelsPerBeat;
}; 