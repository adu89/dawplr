#include "MainMenu.h"

#include <wx/menuitem.h>

#include "core/Constants.h"

MainMenu::MainMenu()
{
    wxMenu* fileMenu = new wxMenu();
    fileMenu->Append(new wxMenuItem(fileMenu, Events::FileNew, "New"));
    fileMenu->Append(new wxMenuItem(fileMenu, Events::FileOpen, "Open"));
    fileMenu->AppendSeparator();
    fileMenu->Append(new wxMenuItem(fileMenu, Events::FileSave, "Save"));
    fileMenu->Append(new wxMenuItem(fileMenu, Events::FileSaveAs, "Save As"));
    fileMenu->AppendSeparator();
    fileMenu->Append(new wxMenuItem(fileMenu, Events::FileExit, "Exit"));    
    Append(fileMenu, "File");

    wxMenu* insertMenu = new wxMenu();
    insertMenu->Append(new wxMenuItem(insertMenu, Events::InsertAudioFile, "Insert Audio File"));
    insertMenu->Append(new wxMenuItem(insertMenu, Events::InsertTrack, "Insert Track"));
    Append(insertMenu, "Insert");

    wxMenu* settingsMenu = new wxMenu();
    settingsMenu->Append(new wxMenuItem(settingsMenu, Events::SettingsAudioPreferences, "Audio Preferences"));
    Append(settingsMenu, "Settings");

    wxMenu* helpMenu = new wxMenu();
    helpMenu->Append(new wxMenuItem(helpMenu, Events::HelpDocumentation, "Documentation"));
    helpMenu->Append(new wxMenuItem(helpMenu, Events::HelpAbout, "About"));
    Append(helpMenu, "Help");
}

MainMenu::~MainMenu()
{
}