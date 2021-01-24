#include "Dawplr.h"

#include "Core/TrackManager.h"

bool Dawplr::OnInit() 
{    
    wxApp::OnInit();

    TrackManager& trackManager = TrackManager::Instance();

    Track t = Track("Accoustic Guitar", 2, false, false);

    trackManager.AddTrack(std::move(t));

    MainWindow* mainWindow = new MainWindow();

    mainWindow->Show(true);
    mainWindow->Maximize();

    SetTopWindow(mainWindow);

    return true;
}

wxIMPLEMENT_APP(Dawplr);
