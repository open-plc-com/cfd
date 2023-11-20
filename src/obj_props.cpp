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
    int      x, y, x1, y1, x2, y2;;
    wxPen    p_pen;
    wxPoint  p;
    wxString s;

    m_text->Clear();

    Shape_Ptr->clear();
    Link_Point_Ptr->clear();
    Shape_Ptr->resize( 1 );

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
        Make_Obj( Block_ID, obj_name, *IN_OUT_Decode_Ptr, *Shape_Ptr, *Link_Point_Ptr );
    }

    m_panel8->GetSize( &x, &y );
    bm = wxBitmap( x, y );
    mem_dc.SelectObject( bm );

    wxFont font = wxFont( FONT_SIZE, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString );
    p_pen.SetColour( 0, 0, 0 );
    p_pen.SetWidth( 1 );

    mem_dc.SetPen( p_pen );
    mem_dc.SetFont( font );
    mem_dc.SetBackground( *wxWHITE_BRUSH );
    mem_dc.SetBackgroundMode( wxTRANSPARENT );
    mem_dc.Clear();

    p = Shape_Ptr->at(0).Size;
    x1 = x/2 - p.x/2;
    y1 = y/2 - p.y/2;
    Shape_Ptr->at(0).Anchor = wxPoint( x1, y1 );
    x2 = p.x;
    y2 = p.y;
    mem_dc.DrawRectangle( x1, y1, x2, y2 );

    x1 = Shape_Ptr->at(0).Name_POU_Pos.x + Shape_Ptr->at(0).Anchor.x;
    y1 = Shape_Ptr->at(0).Name_POU_Pos.y + Shape_Ptr->at(0).Anchor.y;
    mem_dc.DrawText( Shape_Ptr->at(0).Name_POU, x1, y1 );

    if( Link_Point_Ptr->size() > 0 )
    {
        wxSize sz = wxSize( ( Shape_Ptr->at(0).Size.x - (Shape_Ptr->at(0).Size_W) ), Shape_Ptr->at(0).Size_H );
        wxRect rect;
        rect.SetSize(sz);

        y2 = ( (Shape_Ptr->at(0).Size_H*3/2) + Shape_Ptr->at(0).Anchor.y );
        for( i = 0; i < Link_Point_Ptr->size(); i++ )
        {
            if( Link_Point_Ptr->at(i).In_Out == 1 )
            {
                s = Link_Point_Ptr->at(i).Name_IO.c_str();

                x1 = Link_Point_Ptr->at(i).Name_IO_Pos.x;
                y1 = Link_Point_Ptr->at(i).Name_IO_Pos.y;
                rect.SetX(x1 + Shape_Ptr->at(0).Anchor.x );
                rect.SetY(y1 + Shape_Ptr->at(0).Anchor.y );
                mem_dc.DrawLabel( s, rect, wxALIGN_LEFT | wxALIGN_TOP );

                x1 = Link_Point_Ptr->at(i).Pos.x + Shape_Ptr->at(0).Anchor.x;
                y1 = Link_Point_Ptr->at(i).Pos.y + Shape_Ptr->at(0).Anchor.y;
                x2 = Shape_Ptr->at(0).Anchor.x;
                mem_dc.DrawLine( x1, y1, x2, y1 );
            }

            if( Link_Point_Ptr->at(i).In_Out == 2 )
            {
                s = Link_Point_Ptr->at(i).Name_IO.c_str();

                x1 = Link_Point_Ptr->at(i).Name_IO_Pos.x - Shape_Ptr->at(0).Size_W;
                y1 = Link_Point_Ptr->at(i).Name_IO_Pos.y;
                rect.SetX(x1 + Shape_Ptr->at(0).Anchor.x );
                rect.SetY(y1 + Shape_Ptr->at(0).Anchor.y);
                mem_dc.DrawLabel( s, rect, wxALIGN_RIGHT | wxALIGN_TOP );

                x1 = Shape_Ptr->at(0).Size.x + Shape_Ptr->at(0).Anchor.x;
                x2 = x1 + Shape_Ptr->at(0).Size_W;
                y1 = Link_Point_Ptr->at(i).Pos.y + Shape_Ptr->at(0).Anchor.y;
                mem_dc.DrawLine( x1, y1, x2, y1 );
            }
        }
    }

    wxImage img = bm.ConvertToImage();
    m_bitmap->SetBitmap( img );

    event.Skip();
}
// ============================================================================


// ============================================================================
void ObjProps::OnChoise( wxCommandEvent &event )
// ============================================================================
{
printf( "ObjProps::OnChoise\n" );
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
//printf( "\nObjProps::onOK\n" );
//printf( "obj_name=%s Block_Name=%s\n", (const char*) obj_name.c_str(), (const char*) Block_Name.c_str() );
// Check for obj_name & Block_Name

	ON_OK = true;
	//Close(); // ???
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
