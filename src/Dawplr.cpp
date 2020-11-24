#include "Dawplr.h"

#include "Core/TrackManager.h"


bool Dawplr::OnInit() 
{    
    wxApp::OnInit();

    TrackManager& trackManager = TrackManager::Instance();
    trackManager.AddTrack(Track("Accoustic Guitar", false, false));
    trackManager.AddTrack(Track("Vocal", true, false));

    MainWindow* mainWindow = new MainWindow();

    mainWindow->Show(true);
    mainWindow->Maximize();

    SetTopWindow(mainWindow);

    return true;
}

wxIMPLEMENT_APP(Dawplr);
