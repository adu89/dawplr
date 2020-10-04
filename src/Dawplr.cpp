#include "Dawplr.h"

bool Dawplr::OnInit() 
{    
    wxApp::OnInit();

    MainWindow* mainWindow = new MainWindow();

    mainWindow->Show(true);
    mainWindow->Maximize();

    SetTopWindow(mainWindow);

    return true;
}

wxIMPLEMENT_APP(Dawplr);
