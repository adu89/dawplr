#include "Dawplr.h"

#include "Core/TrackManager.h"
#include <iostream>

bool Dawplr::OnInit() 
{    
    wxApp::OnInit();

    TrackManager& trackManager = TrackManager::Instance();
    trackManager.AddTrack(Track("Accoustic Guitar", 2, false, false));
    trackManager.AddTrack(Track("Vocal", 2, true, false));

    MainWindow* mainWindow = new MainWindow();

    mainWindow->Show(true);
    mainWindow->Maximize();

    SetTopWindow(mainWindow);

    return true;
}

wxIMPLEMENT_APP(Dawplr);
