#pragma once

#include <wx/filedlg.h>
#include <wx/window.h>

class CustomFileDialog
	: public wxFileDialog
{
public:
	CustomFileDialog(wxWindow*);
	~CustomFileDialog();
	void MSWOnInitDone(WXHWND hDlg) override;
};
