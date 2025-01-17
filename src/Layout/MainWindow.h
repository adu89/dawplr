#pragma once

#include "wx/frame.h"

#include "Core/TrackManager.h"

class MainWindow 
    : public wxFrame 
{
public:
    MainWindow(TrackManager&);
    ~MainWindow();
private:
    void onFileOpen(wxCommandEvent& event);
    void onFileNew(wxCommandEvent& event);
    void onFileSave(wxCommandEvent& event);
    void onFileSaveAs(wxCommandEvent& event);
    void onFileExit(wxCommandEvent& event);
    void onInsertFile(wxCommandEvent& event);
    void onInserTrack(wxCommandEvent& event);
    void onSettingsAudioSettings(wxCommandEvent& event);
    void onHelpDocumentation(wxCommandEvent& event);
    void onHelpAbout(wxCommandEvent& event);

    TrackManager& trackManager;
};