#include "TrackLane.h"

#include <wx/dcbuffer.h>
#include <wx/dcgraph.h>

#include "Core/Constants.h"
#include "Core//TrackManager.h"

wxDEFINE_EVENT(TRACK_LANE_HEIGHT_CHANGED, wxCommandEvent);

TrackLane::TrackLane(wxWindow* parent, int index)
    : wxPanel(parent, index)
    , height(Constants::TRACK_LANE_HEIGHT)
    , index(index)
{
    SetBackgroundStyle(wxBG_STYLE_PAINT);

    hSash = new HSash(this);

    Bind(wxEVT_PAINT, &TrackLane::OnPaint, this);
    Bind(wxEVT_SIZE, &TrackLane::OnSize, this);
    Bind(H_SASH_DRAGGING, &TrackLane::OnHSashDragging, this);
}

TrackLane::~TrackLane()
{
} 

int TrackLane::GetHeight()
{
    return height;
}

void TrackLane::SetHeight(int h)
{
    height = h;
}

void TrackLane::OnHSashDragging(wxCommandEvent& e)
{
    // height = hSash->GetY() + 1;

    // wxCommandEvent event(TRACK_LANE_HEIGHT_CHANGED);

    // event.SetId(index);
    // event.SetInt(height);

    // wxPostEvent(GetParent(), event);
}

void TrackLane::OnSize(wxSizeEvent& e)
{
    auto clientRect = GetClientRect();

    hSash->SetSize(wxRect(clientRect.GetBottomLeft() - wxPoint(0, 3), clientRect.GetBottomRight()));
}


void TrackLane::OnPaint(wxPaintEvent&)
{
    TrackManager& trackManager = TrackManager::Instance();
    Track& track = trackManager.GetTracks().at(index);

    wxRect rect = GetClientRect();

    wxBufferedPaintDC dc(this);
    wxGCDC gc(dc);

    gc.SetPen(*wxLIGHT_GREY_PEN);
    gc.SetBrush(*wxLIGHT_GREY_BRUSH);

    gc.DrawRectangle(rect);

    gc.SetPen(*wxRED_PEN);

    int currentBpm = 120;
    double pixelsPerBeat = 50.0;

    for (Region& r : track.GetRegions())
    {
        double beats = r.GetAudioData().getLengthInSeconds() * (currentBpm / 60);
        int pixels = wxRound(beats * pixelsPerBeat);
        int samplesPerPixel = wxRound(r.GetAudioData().getNumSamplesPerChannel() / pixels);

        gc.DrawRectangle(wxRect(0, 0, pixels, rect.GetHeight() - hSash->GetSize().GetHeight()));

        double half = rect.GetHeight() / 2;

        gc.SetPen(*wxBLUE_PEN);

        gc.SetAxisOrientation(true, true);
        gc.SetDeviceOrigin(0, half);

        int totalSamples = r.GetAudioData().getNumSamplesPerChannel();
        auto& samples = r.GetAudioData().samples;

        for (int pixel = 0; pixel < pixels; pixel++)
        {
            int startIndex = pixel * samplesPerPixel;
            int endIndex = wxMin(startIndex + samplesPerPixel, totalSamples);

            float positiveMax = -1;
            float negativeMax = 1;

            for (int sampleIndex = startIndex; sampleIndex < endIndex; sampleIndex++)
            {
                float currentSample = samples[0][sampleIndex];

                if (currentSample > 0)
                {
                    positiveMax = currentSample > positiveMax ? currentSample : positiveMax;
                }
                else
                {
                    negativeMax = currentSample < negativeMax ? currentSample : negativeMax;
                }
            }

            gc.DrawLine(wxRealPoint(pixel, wxMax(positiveMax * half, .5)), wxRealPoint(pixel, wxMin(negativeMax * half, -.5)));

            positiveMax = -1;
            negativeMax = 1;
        }
    }
}

void TrackLane::HandleMouseWheelEvent(wxMouseEvent& m) 
{    
    m.Skip();
}

BEGIN_EVENT_TABLE(TrackLane, wxWindow)
    EVT_MOUSEWHEEL(TrackLane::HandleMouseWheelEvent)
END_EVENT_TABLE()