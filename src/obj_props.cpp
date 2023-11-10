/*
    Name:        obj_props.cpp
    Purpose:     Open-PLC Tools
    Author:      www.open-plc.com
    Created:     2023/11
    Modified by:
    RCS-ID:
    Copyright:   (c) Open-PLC
    Licence:     The MIT License (MIT)
*/


#include "obj_props.h"
#include "msg.h"


// ============================================================================
ObjProps::ObjProps( wxWindow       *parent,
                    wxWindowID     id,
                    const wxString &title,
                    const wxPoint  &pos,
                    const wxSize   &size,
                    long           style )
         : ObjPropsFB( parent, id, title, pos, size, style ) {}
// ============================================================================


// ============================================================================
ObjProps::~ObjProps() {}
// ============================================================================


// ============================================================================
void ObjProps::Fill_POU()
// ============================================================================
{
    int i;

    pou_item_root = m_tree->AddRoot( PDU_TREE_HEAD );
    pou_item_prev = 0;

    for( i = 0; i < (int) m_pou->size(); i++ )
    {
        if( m_pou->at(i).Level == 1 )
        {
            pou_item_prev = m_tree->AppendItem( pou_item_root, m_pou->at(i).Name );
        }
        else if( m_pou->at(i).Level == 2 )
        {
            if( pou_item_prev )
            {
                m_tree->AppendItem( pou_item_prev, m_pou->at(i).Name );
            }
        }
    }

//IN_OUT_Decode( "in_str", *IN_OUT_Decode_Ptr);

//for( i = 0; i < IN_OUT_Decode_Ptr->size(); i++ )
//{
//printf( "Ptr=%d\n", IN_OUT_Decode_Ptr->at(i).Nn );
//}

//int x, y;
//m_panel8->GetSize( &x, &y );
//printf( "Height=%d Width=%d\n", x, y );
//m_bitmap->GetBitmap();




}
// ============================================================================


// ============================================================================
void ObjProps::OnPOUTreeSelChanged( wxTreeEvent &event )
// ============================================================================
{
    uint32_t i;
    wxString s;

    m_text->Clear();

    SEL_POU = -1;
    if( event.GetItem() != m_tree->GetRootItem() )
    {
        wxTreeItemId m_draggedItem = event.GetItem();
        s = m_tree->GetItemText( m_draggedItem );

        for( i = 0; i < m_pou->size(); i++ )
        {
            if( m_pou->at(i).Level == 2 )
            {
                if( m_pou->at(i).Name == (const char*) s.c_str() )
                {
                    if( m_pou->at(i).Comment != "" )
                    {
                        m_text->AppendText( m_pou->at(i).Comment );
                        m_text->AppendText( wxT( "\n\n ") );
                    }
                    m_text->AppendText( m_pou->at(i).POU_InOut );
                    SEL_POU = i;
                    break;
                }
            }
        }
    }

	if( SEL_POU >= 0 )
	{
		IN_OUT_Decode( m_pou->at(SEL_POU).POU_InOut, *IN_OUT_Decode_Ptr );
obj_name = m_pou->at(SEL_POU).Name;
//printf( "IN_OUT_Decode_Ptr->size()=%d\n", IN_OUT_Decode_Ptr->size() );
//printf( "obj_name=%s\n", (const char*) obj_name.c_str());
Make_Obj( Block_ID, obj_name, *IN_OUT_Decode_Ptr, *Shape_Ptr, *Link_Point_Ptr );
//*Shape_Ptr *Link_Point_Ptr

	}


int x, y;
wxPen p_pen;


m_panel8->GetSize( &x, &y );
//printf( "Height=%d Width=%d\n", x, y );

bm = wxBitmap( x, y );
mem_dc.SelectObject( bm );




//mem_dc.SetBrush( BG_COLOUR );
//mem_dc.SetBackground( BG_COLOUR );

wxFont font = wxFont( FONT_SIZE, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString );
p_pen.SetColour( 0, 0, 0 );
p_pen.SetWidth( 1 );

mem_dc.SetPen( p_pen );
mem_dc.SetFont( font );
//mem_dc.SetBackground( wxBrush( GetBackgroundColour() ) );
mem_dc.SetBackground( *wxWHITE_BRUSH );
mem_dc.SetBackgroundMode( wxTRANSPARENT );
mem_dc.Clear();

mem_dc.DrawText( wxT( "Text" ), 10, 10 );
mem_dc.DrawLine( 40,40,200,200 );

wxImage img = bm.ConvertToImage();
m_bitmap->SetBitmap( img );

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//wxSize sz;
//sz = mem_dc.GetTextExtent( wxString::Format( wxT("W") ) );
//printf( "w1=%d h1=%d\n", sz.GetWidth(), sz.GetHeight() );

	event.Skip();
}
// ============================================================================


// ============================================================================
void ObjProps::OnChar( wxKeyEvent &event )
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
void ObjProps::onOK( wxCommandEvent &event )
// ============================================================================
{
printf( "ObjProps::onOK\n" );


	ON_OK = true;
	event.Skip();
}
// ============================================================================


// ============================================================================
void ObjProps::OnCANCEL( wxCommandEvent &event )
// ============================================================================
{
    Close();
    event.Skip();
}
// ============================================================================


BEGIN_EVENT_TABLE( ObjProps, ObjPropsFB )
    EVT_CHAR_HOOK( ObjProps::OnChar )
END_EVENT_TABLE()
