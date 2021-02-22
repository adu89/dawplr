#pragma once


#include <wx/window.h>
#include <wx/dc.h>

#include "Components/SyncedScrollWindow.h"

class EditorAreaRight
	: public SyncedScrolledWindow
{
public:
	EditorAreaRight(wxWindow*);
	~EditorAreaRight();
};