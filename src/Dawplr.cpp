#include "Dawplr.h"

#include "Core/TrackManager.h"

bool Dawplr::OnInit() 
{    
    wxApp::OnInit();

    Track t = Track("Accoustic Guitar", 2, false, false);

    trackManager.AddTrack(std::move(t));

    MainWindow* mainWindow = new MainWindow(trackManager);

    mainWindow->Show(true);
    mainWindow->Maximize();

    SetTopWindow(mainWindow);

    return true;
}

wxIMPLEMENT_APP(Dawplr);
