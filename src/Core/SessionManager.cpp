#include "SessionManager.h"

SessionManager& SessionManager::Instance()
{
	static SessionManager sessionManager;
	return sessionManager;
}

SessionManager::SessionManager()
	: bpm(120), beat(1), pixelsPerBeat(100)
{
}

SessionManager::~SessionManager()
{
}