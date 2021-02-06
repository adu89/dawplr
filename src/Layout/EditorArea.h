#pragma once

#include <wx/window.h>
#include <wx/splitter.h>

class EditorArea
	: public wxSplitterWindow
{
public:
	EditorArea(wxWindow* parent);
	~EditorArea();

	bool OnSashPositionChange(int) override;
};