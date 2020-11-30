#include "Dawplr.h"

#include "Core/TrackManager.h"
#include <iostream>


bool Dawplr::OnInit() 
{    
    wxApp::OnInit();

    TrackManager& trackManager = TrackManager::Instance();
    trackManager.AddTrack(Track("Accoustic Guitar", 2, false, false));
    trackManager.AddTrack(Track("Vocal", 2, true, false));
    trackManager.AddTrack(Track("Drums", 2, true, true));
    trackManager.AddTrack(Track("Snare", 2, true, false));
    trackManager.AddTrack(Track("Kick", 2, false, false));
    trackManager.AddTrack(Track("Tom", 2, false, true));

    //Track track("Drums", 2, true, false);
    //track.AddRegion(Region("test", 0, 10));
    //trackManager.AddTrack(track);

    MainWindow* mainWindow = new MainWindow();

    mainWindow->Show(true);
    mainWindow->Maximize();

    SetTopWindow(mainWindow);

    return true;
}

wxIMPLEMENT_APP(Dawplr);
