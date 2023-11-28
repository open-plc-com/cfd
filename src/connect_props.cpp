/*
    Name:        connect_props.cpp
    Purpose:     Open-PLC Tools
    Author:      www.open-plc.com
    Created:     2023/11
    Modified by:
    RCS-ID:
    Copyright:   (c) Open-PLC
    Licence:     The MIT License (MIT)
*/


#include "connect_props.h"


// ============================================================================
ConnectProps::ConnectProps( wxWindow       *parent,
                            wxWindowID     id,
                            const wxString &title,
                            const wxPoint  &pos,
                            const wxSize   &size,
                            long           style )
             :ConnectPropsFB( parent, id, title, pos, size, style ) {
printf( "ConnectProps::ConnectProps\n" );
Centre();}
// ============================================================================


// ============================================================================
ConnectProps::~ConnectProps() {}
// ============================================================================


// ============================================================================
void ConnectProps::Preview()
// ============================================================================
{
	int    x, y, x1, y1, x2, y2, w, h;
	int    x3, y3, x4, y4, x5;
	wxSize sz;
	wxPen  p_pen;
	wxRect rect;

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

//if( m_name->Len() > 0 )

	sz = dc.GetTextExtent( m_name->GetValue() );
	x2 = sz.x;
	y2 = sz.y;
	rect.SetSize(sz);

//  x1,y1          x5,y1
//    o              o
//
//      x3,y3  x4,y3
//        o      o
//
//  x1,y4          x5,y4
//    o              o

	sz = dc.GetTextExtent( "W" );
	w = sz.x;
	h = sz.y;

	x1 = (x/2) - (x2/2);
	y1 = (y/2) - (y2/2);
	rect.SetX( x1 );
	rect.SetY( y1 );

	x1 = x1 - w/2 - h;
	y1 = y1 - h/2;
	x2 += w + h*2;
	y2 += h;

	y3 = ( y1 + y2 ) - ( y2 / 2 );
	x3 = x1 + y3 - y1;
	x4 = x1 + x2 - y3 + y1;
	x5 = x1 + x2;
	y4 = y1 + y2;

	dc.DrawRectangle( x1, y1, x2, y2 );
	dc.DrawLabel( m_name->GetValue(), rect, wxALIGN_CENTER | wxALIGN_TOP );

	if( m_radio_btn1->GetValue() )
	{
		dc.DrawLine( x1, y1, x3, y3 );
		dc.DrawLine( x3, y3, x1, y4 );
		dc.DrawLine( x4, y1, x5, y3 );
		dc.DrawLine( x5, y3, x4, y4 );
		dc.DrawLine( x1, y3, (x1-w), y3 );
	}
	else
	{
		dc.DrawLine( x3, y1, x1, y3 );
		dc.DrawLine( x1, y3, x3, y4 );
		dc.DrawLine( x5, y1, x4, y3 );
		dc.DrawLine( x5, y4, x4, y3 );
		dc.DrawLine( x5, y3, (x5+w), y3 );
	}

	wxImage img = bm.ConvertToImage();
	m_bitmap->SetBitmap( img );
}
// ============================================================================


// ============================================================================
void ConnectProps::OnChar( wxKeyEvent &event )
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
void ConnectProps::OnText( wxCommandEvent &event )
// ============================================================================
{
	Preview();
	event.Skip();
}
// ============================================================================


// ============================================================================
void ConnectProps::OnRadioButton1( wxCommandEvent &event )
// ============================================================================
{
	Preview();
	event.Skip();
}
// ============================================================================


// ============================================================================
void ConnectProps::OnRadioButton2( wxCommandEvent &event )
// ============================================================================
{
	Preview();
	event.Skip();
}
// ============================================================================


// ============================================================================
void ConnectProps::onOK( wxCommandEvent &event )
// ============================================================================
{
printf( "\nConnectProps::onOK\n" );
printf( "m_name->GetValue()=%s Block_Name=%s\n", (const char*) m_name->GetValue().c_str(), (const char*) Block_Name.c_str() );

printf( "Block_ID=%d\n", Block_ID );


//obj_name = "1";
//if( obj_name != wxEmptyString )
//{
//printf( "Shape_Ptr->size()=%d\n", Shape_Ptr->size() );

	//if( m_name->GetValue().Len() == 0 )
	//{


	//}
//else
//{

	//ON_OK = true;
	//Close();

//}
//}

	event.Skip();
}
// ============================================================================


// ============================================================================
void ConnectProps::OnCANCEL( wxCommandEvent &event )
// ============================================================================
{
    Close();
    event.Skip();
}
// ============================================================================


BEGIN_EVENT_TABLE( ConnectProps, ConnectPropsFB )
    EVT_CHAR_HOOK( ConnectProps::OnChar )
END_EVENT_TABLE()
