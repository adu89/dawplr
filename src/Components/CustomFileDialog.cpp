#include "CustomFileDialog.h"

#include <wx/log.h>

CustomFileDialog::CustomFileDialog(wxWindow* parent)
	: wxFileDialog(parent)
{
}

CustomFileDialog::~CustomFileDialog()
{
}

void CustomFileDialog::MSWOnInitDone(WXHWND hDlg)
{
	this->CenterOnParent();
}
