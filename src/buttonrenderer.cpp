/*
    Name:
    Purpose:        plc_cfg
    Author:         www.open-plc.com
    Created:        2020/07
    Modified by:
    RCS-ID:
    Copyright:
    Licence:        The MIT License (MIT)
*/

#include "buttonrenderer.h"
#include <wx/renderer.h>
#include <wx/settings.h>
#include <wx/colour.h>


void ButtonRenderer::Draw( wxGrid           &grid,
                           wxGridCellAttr   &attr,
                           wxDC             &dc,
                           const wxRect     &rect,
                           int               row,
                           int               col,
                           bool              isSelected )
{
    dc.SetBrush( wxBrush( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) ) );
    dc.DrawRectangle( rect.GetX(), rect.GetY(), rect.GetWidth(), rect.GetHeight() );

    int strength = 1;

    wxPen pen1( *wxWHITE, strength );
    dc.SetPen( pen1 );
    dc.DrawLine( rect.GetLeft()   + strength - 1,
                 rect.GetTop()    + strength - 1,
                 rect.GetLeft()   + strength - 1,
                 rect.GetBottom() - strength + 1);
    dc.DrawLine( rect.GetLeft()   + strength - 1,
                 rect.GetTop()    + strength - 1,
                 rect.GetRight()  - strength,
                 rect.GetTop()    + strength - 1 );

    wxPen pen2( *wxBLACK, strength );
    dc.SetPen( pen2 );
    dc.DrawLine( rect.GetRight() - strength,
                 rect.GetTop(),
                 rect.GetRight() - strength,
                 rect.GetBottom() );
    dc.DrawLine( rect.GetLeft(),
                 rect.GetBottom(),
                 rect.GetRight() - strength,
                 rect.GetBottom());

    // draw the label
    dc.SetBackgroundMode( wxTRANSPARENT );
    dc.SetTextForeground( attr.GetTextColour() );
    dc.SetFont( attr.GetFont() );
    dc.DrawLabel( label, rect, wxALIGN_CENTER_VERTICAL | wxALIGN_CENTER_HORIZONTAL );
}
