/*
    Name:        var_props.cpp
    Purpose:     Open-PLC Tools
    Author:      www.open-plc.com
    Created:     2023/11
    Modified by:
    RCS-ID:
    Copyright:   (c) Open-PLC
    Licence:     The MIT License (MIT)
*/


//#include "gbl.h"
//#include "msg.h"
//#include "myframe_fb.h"
#include "var_props.h"


// ============================================================================
VarProps::VarProps( wxWindow       *parent,
                            wxWindowID     id,
                            const wxString &title,
                            const wxPoint  &pos,
                            const wxSize   &size,
                            long           style )
         :VarPropsFB( parent, id, title, pos, size, style )
// ============================================================================
{
//printf( "VarProps::VarProps\n" );
Centre();
}
// ============================================================================


// ============================================================================
VarProps::~VarProps() {}
// ============================================================================


// ============================================================================
void VarProps::Preview()
// ============================================================================
{
	int    x, y, x1, y1, x2, y2, w, h;
	int    x3, y3, x4, y4, x5;
	wxSize sz;
	wxPen  p_pen;
	wxRect rect;
	wxString s;

//printf( "m_list->GetSelection()=%d\n", m_list->GetSelection() );

	s = m_list->GetString( m_list->GetSelection() );
    s.Trim(false).Trim(true);
	if( s != wxEmptyString )
	{
		sz = m_panel->GetSize();
		x = sz.x;
		y = sz.y;

		bm = wxBitmap( x, y );
		dc.SelectObject( bm );

		wxFont font = wxFont( FONT_SIZE, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString );
		p_pen.SetColour( 0, 0, 0 );
		p_pen.SetWidth( 1 );

		dc.SetPen( p_pen );
		dc.SetFont( font );
		dc.SetBackground( *wxWHITE_BRUSH );
		dc.SetBackgroundMode( wxTRANSPARENT );
		dc.Clear();

		sz = dc.GetTextExtent( m_text->GetValue() );
		x2 = sz.x;
		y2 = sz.y;
		rect.SetSize(sz);

//      x1,y1          x5,y1
//        o              o
//
//        y3             y3
//        o              o
//
//      x1,y4          x5,y4
//        o              o

		sz = dc.GetTextExtent( "W" );
		w = sz.x;
		h = sz.y;

		x1 = (x/2) - (x2/2);
		y1 = (y/2) - (y2/2);
		rect.SetX( x1 );
		rect.SetY( y1 );

		//x1 = x1 - w/2 - h;
		x1 = x1 - w/2;
		y1 = y1 - h/2;
		x2 += w; // + h*2;
		y2 += h;

		y3 = ( y1 + y2 ) - ( y2 / 2 );
		x3 = x1 + y3 - y1;
		x4 = x1 + x2 - y3 + y1;
		x5 = x1 + x2;
		y4 = y1 + y2;

		dc.DrawRectangle( x1, y1, x2, y2 );
		dc.DrawLabel( m_text->GetValue(), rect, wxALIGN_CENTER | wxALIGN_TOP );

		if( ( m_choice->GetCurrentSelection() == 0 ) || ( m_choice->GetCurrentSelection() == 2 ) )
		{
			dc.DrawLine( x5, y3, (x5+w), y3 );
		}

		if( ( m_choice->GetCurrentSelection() == 1 ) || ( m_choice->GetCurrentSelection() == 2 ) )
		{
			dc.DrawLine( x1, y3, (x1-w), y3 );
		}

		wxImage img = bm.ConvertToImage();
		m_bitmap->SetBitmap( img );
	}
}
// ============================================================================


// ============================================================================
void VarProps::OnChar( wxKeyEvent &event )
// ============================================================================
{
    wxUint32 key;
    key = event.GetKeyCode();
    if( key == WXK_ESCAPE )
    {
        Close();
    }
    event.Skip();
}
// ============================================================================


// ============================================================================
void VarProps::OnListBox( wxCommandEvent &event )
// ============================================================================
{
	wxString s;

	s = m_list->GetString( m_list->GetSelection() );
    s.Trim(false).Trim(true);
	if( s != wxEmptyString )
	{
		m_text->SetValue( s );
		Preview();
	}

	event.Skip();
}
// ============================================================================


// ============================================================================
void VarProps::OnChoice( wxCommandEvent &event )
// ============================================================================
{
	Preview();
	event.Skip();
}
// ============================================================================


// ============================================================================
void VarProps::onOK( wxCommandEvent &event )
// ============================================================================
{
printf( "\nVarProps::onOK\n" );
//printf( "obj_name=%s Block_Name=%s\n", (const char*) obj_name.c_str(), (const char*) Block_Name.c_str() );
// Check for obj_name & Block_Name

printf( "Block_ID=%d\n", Block_ID );

//if( obj_name != wxEmptyString )
//{
//printf( "Shape_Ptr->size()=%d\n", Shape_Ptr->size() );

	//ON_OK = true;
	//Close();
//}

	event.Skip();
}
// ============================================================================


// ============================================================================
void VarProps::OnCANCEL( wxCommandEvent &event )
// ============================================================================
{
    Close();
    event.Skip();
}
// ============================================================================


BEGIN_EVENT_TABLE( VarProps, VarPropsFB )
    EVT_CHAR_HOOK( VarProps::OnChar )
END_EVENT_TABLE()
