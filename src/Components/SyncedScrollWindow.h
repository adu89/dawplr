#pragma once

#include <wx/window.h>
#include <wx/scrolwin.h>

#include <memory>

class SyncedScrolledWindow 
    : public wxScrolledWindow
{
public:
    SyncedScrolledWindow(wxWindow* parent)
        : wxScrolledWindow(parent, wxID_ANY), otherWindow(nullptr), isSyncing(false)
    {
    }

    ~SyncedScrolledWindow() {}; 

    void SetOtherWindow(SyncedScrolledWindow* window)
    {
        otherWindow = window;

        DoSync();
    }

    bool IsSyncing() 
    {
        return isSyncing;
    };   

    void ScrollWindow(int x, int y, const wxRect* rect) override
    {
        DoSync();

        wxWindow::ScrollWindow(x, y, rect);
    }
private:
    void DoSync()
    {
        if(otherWindow && !otherWindow->IsSyncing())
        {
            isSyncing = true;

            otherWindow->Scroll(GetViewStart());

            isSyncing = false;
        }
    };

    SyncedScrolledWindow* otherWindow;
    bool isSyncing;
};