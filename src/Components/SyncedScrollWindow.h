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
protected:
    SyncedScrolledWindow* otherWindow;
    
private:
    void DoSync()
    {
        if(otherWindow && !otherWindow->IsSyncing())
        {
            isSyncing = true;

            //Ignore scrolling in the x direction.
            otherWindow->Scroll(wxPoint(otherWindow->GetViewStart().x, GetViewStart().y));

            isSyncing = false;
        }
    };

    bool isSyncing;
};