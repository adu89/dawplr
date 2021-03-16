#include "MainWindow.h"

#include <wx/log.h>
#include <wx/msgdlg.h>
#include <wx/filedlg.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/textdlg.h>
#include <AudioFile.h>

#include "Core/Constants.h"
#include "Core/Track.h"
#include "Core/Region.h"
#include "MainMenu.h"
#include "TransportBar.h"
#include "MainVerticalSplitter.h"

MainWindow::MainWindow(TrackManager& trackManager)
    : wxFrame(NULL, wxID_ANY, Constants::MAIN_WINDOW_TITLE)
    , trackManager(trackManager)
{ 
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));
    
    SetMenuBar(new MainMenu());

    wxBoxSizer* mainBoxSizer = new wxBoxSizer(wxVERTICAL);

    TransportBar* transportBar = new TransportBar(this);
    mainBoxSizer->Add(transportBar, 1, wxEXPAND);

    mainBoxSizer->AddSpacer(4);

    MainVerticalSplitter* mainVerticalSplitter = new MainVerticalSplitter(this, trackManager);
    mainBoxSizer->Add(mainVerticalSplitter, 1, wxEXPAND);

    Bind(wxEVT_MENU, &MainWindow::onFileOpen, this, Events::FileOpen);
    Bind(wxEVT_MENU, &MainWindow::onFileNew, this, Events::FileNew);
    Bind(wxEVT_MENU, &MainWindow::onFileSave, this, Events::FileSave);
    Bind(wxEVT_MENU, &MainWindow::onFileSaveAs, this, Events::FileSaveAs);
    Bind(wxEVT_MENU, &MainWindow::onFileExit, this, Events::FileExit);
    Bind(wxEVT_MENU, &MainWindow::onInsertFile, this, Events::InsertAudioFile);
    Bind(wxEVT_MENU, &MainWindow::onInserTrack, this, Events::InsertTrack);
    Bind(wxEVT_MENU, &MainWindow::onSettingsAudioSettings, this, Events::SettingsAudioPreferences);
    Bind(wxEVT_MENU, &MainWindow::onHelpDocumentation, this, Events::HelpDocumentation);
    Bind(wxEVT_MENU, &MainWindow::onHelpAbout, this, Events::HelpAbout);    

    SetSizer(mainBoxSizer);
    Layout();
    CenterOnScreen(wxBOTH);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onFileOpen(wxCommandEvent& event) 
{
    wxFileDialog openFileDialog(this, "Open a session", "", "", "Dawplr session files (*.dwp)|*.dwp", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
	openFileDialog.Center(wxBOTH);

	if (openFileDialog.ShowModal() == wxID_OK)
    {
        wxLogInfo("onFileOpen");
    }
}

void MainWindow::onFileNew(wxCommandEvent& event) 
{
    wxFileDialog newFileDialog(this, "Create a new session", "", "", "Dawplr session files (*.dwp)|*.dwp", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
	newFileDialog.Centre(wxBOTH);

	if (newFileDialog.ShowModal() == wxID_OK)
    {
        wxLogInfo("onFileOpen");
    }
}

void MainWindow::onFileSave(wxCommandEvent& event) 
{
    wxLogInfo("onFileSave");
}

void MainWindow::onFileSaveAs(wxCommandEvent& event) 
{
    wxFileDialog fileSaveAsDialog(this, "Save session as", "", "", "Dawplr session files (*.dwp)|*.dwp", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
	fileSaveAsDialog.Centre(wxBOTH);

	if (fileSaveAsDialog.ShowModal() == wxID_OK)
    {
        wxLogInfo("onFileSaveAs");
    }}

void MainWindow::onFileExit(wxCommandEvent& event) 
{
    auto result = wxMessageBox("Are you sure you want to exit?", "Please confirm", wxICON_QUESTION | wxYES_NO, this);

    if(result == wxYES)
        Close();
}

void MainWindow::onInsertFile(wxCommandEvent& event) 
{
    wxFileDialog insertFileDialog(this, "Insert a file", "", "", "Audio file (*.wav)|*.wav", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
	insertFileDialog.Centre(wxBOTH);

	if (insertFileDialog.ShowModal() == wxID_OK)
    {
        AudioFile<float> file;
        file.load(insertFileDialog.GetPath());

        Track track = Track(insertFileDialog.GetFilename(), file.getNumChannels(), false, false);
        long size = file.samples[0].size();
        track.AddRegion(Region(insertFileDialog.GetFilename(), 0, size, std::move(file)));
        trackManager.AddTrack(std::move(track));
    }
}

void MainWindow::onInserTrack(wxCommandEvent& event) 
{
    wxTextEntryDialog textEntryDialog(this, "Track name", "Insert track");

    if (textEntryDialog.ShowModal() == wxID_OK)
    {
        trackManager.AddTrack(Track(textEntryDialog.GetValue(), 2, true, true));
    }
}

void MainWindow::onSettingsAudioSettings(wxCommandEvent& event) 
{
    wxLogInfo("onSettingsAudioSettings");
}

void MainWindow::onHelpDocumentation(wxCommandEvent& event) 
{
    wxLogInfo("onHelpDocumentation");
}

void MainWindow::onHelpAbout(wxCommandEvent& event) 
{
    wxLogInfo("onHelpAbout");
}