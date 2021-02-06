#pragma once

#include <wx/scrolwin.h>
#include <wx/window.h>
#include <wx/dc.h>

#include <vector>

#include "EditorAreaLeft.h";

class EditorAreaRight
	: public wxScrolledWindow
{
public:
	EditorAreaRight(wxWindow*, EditorAreaLeft*);
	~EditorAreaRight();

	//void OnDraw(wxDC&) override;
	void OnScrollUp(wxScrollWinEvent&);
	void OnScrollDown(wxScrollWinEvent&);
	void OnSize(wxSizeEvent&);
private:
	EditorAreaLeft* editorAreaLeft;
	int lastYScrollPos;
};