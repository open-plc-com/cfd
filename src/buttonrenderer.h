/*
    Name:           buttonrenderer.h
    Purpose:        fcm
    Author:         www.open-plc.com
    Created:        2020/07
    Modified by:
    RCS-ID:
    Copyright:      (c) Open-PLC
    Licence:        The MIT License (MIT)
*/

#ifndef BUTTON_RENDERER_H
#define BUTTON_RENDERER_H

#pragma warning(disable: 4100)

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#else
    #include <wx/wxprec.h>
#endif

#include <wx/grid.h>


class ButtonRenderer : public wxGridCellRenderer
{
    public:
        wxString label;
        ButtonRenderer( wxString ws ) { label = ws; }
        virtual         ~ButtonRenderer() {}
        virtual          wxGridCellRenderer *Clone() const { return new ButtonRenderer( label ); }
        virtual void     Draw( wxGrid           &grid,
                               wxGridCellAttr   &attr,
                               wxDC             &dc,
                               const wxRect     &rect, 
                               int               row,
                               int               col,
                               bool              isSelected );
        virtual wxSize  GetBestSize( wxGrid             &grid,
                                     wxGridCellAttr     &attr,
                                     wxDC               &dc,
                                     int                 row,
                                     int                 col )
                                   { return wxSize( -1, -1 ); }
};


#endif
