#pragma once

#include <wx/menu.h>

class MainMenu 
    : public wxMenuBar 
{
public:
    MainMenu();
    ~MainMenu() override;
};