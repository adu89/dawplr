#pragma once

#include <wx/string.h>

namespace Constants {
    constexpr int MAIN_WINDOW_WIDTH = 1200;
    constexpr int MAING_WINDOW_HEIGHT = 800;
    const wxString MAIN_WINDOW_TITLE = "Dawplr";
    constexpr int TRANSPORT_BAR_HEIGHT = 80;
    constexpr int SPLITTER_MIN_WIDTH = 100;
    constexpr int INSPECTOR_VIEW_WIDTH = 200;
    constexpr int BOTTOM_PANEL_WIDTH = 200;
    constexpr int TRACK_HEADER_MIN_WIDTH = 100;    
    constexpr int TRACK_HEADER_WIDTH = 200;
    constexpr int TRACK_HEADER_MAX_WIDTH = 400;
    constexpr int TRACK_LANE_WIDTH = 2000;
    constexpr int TRACK_LANE_HEIGHT = 100;
    constexpr int SASH_WIDTH = 12;
    constexpr int TRACK_HEADER_MIN_HEIGHT = 50;
    constexpr int TRACK_HEADER_HEIGHT = 100;
    constexpr int TRACK_HEADER_MAX_HEIGHT = 1000;
    constexpr int SCROLL_BAR_WIDTH = 12;
    constexpr int SCROLL_BAR_INNER_WIDTH = 8;
    constexpr int SCROLL_SPEED = 10;
}

enum Events {
    FileNew = 1,
    FileOpen,
    FileSave,
    FileSaveAs,
    FileExit,
    InsertAudioFile,
    InsertTrack,
    SettingsAudioPreferences,
    HelpDocumentation,
    HelpAbout
};