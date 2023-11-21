/*
    Name:        myframe.cpp
    Purpose:     Open-PLC Tools
    Author:      www.open-plc.com
    Created:     2023/11
    Modified by:
    RCS-ID:
    Copyright:   (c) Open-PLC
    Licence:     The MIT License (MIT)
*/


#include <vector>
#include "myframe.h"
#include "myframe_fb.h"

#include "dev.xpm"

class PaintCtrl;


// ============================================================================
// ===                            MyFrame                                   ===
// ============================================================================
MyFrame::MyFrame( wxWindow       *parent,
                  wxWindowID     id,
                  const wxString &title,
                  const wxPoint  &pos,
                  const wxSize   &size,
                  long           style )
        :MyFrameFB(parent, id, title, pos, size, style )
// ============================================================================
{
    int n;
    wxString s;

    SHIFT_KEY = false;
    ALT_KEY   = false;
    CTRL_KEY  = false;

    if ( PathInit() )
    {
        Close();
    }
    Init();
    LangInit();
    ReadCfg();
    if( PRJ_FILE != wxEmptyString )
    {
        n = ReadPrj();
    }
    Init_POU_Tree();

    Bind( wxEVT_COMMAND_MENU_SELECTED,
          &MyFrame::OnPrjMenuSelect,
          this,
          MENU_ID_CONTEXT_1,
          MENU_ID_CONTEXT_3 );
}
// === end of MyFrame::MyFrame ================================================


// ============================================================================
MyFrame::~MyFrame()
// ============================================================================
{
	//wxString s;

	WriteCfg();
	WritePrj();
	m_mgr1.UnInit();
}
// ============================================================================


// ============================================================================
void MyFrame::OnExit( wxCommandEvent &WXUNUSED( event ) )
// ============================================================================
{
	Close();
}
// ============================================================================


// ============================================================================
void MyFrame::IN_OUT_Decode( std::string in_out_str,
                             std::vector <IN_OUT_Decode_Struct> &IN_OUT_Decode_Ptr)
// ============================================================================
{
    int i, j, n, n1;
    wxString s, s1, s2;
    wxString ss1, ss2;

    IN_OUT_Decode_Struct IN_OUT_Decode_Var;
    IN_OUT_Decode_Ptr.clear();

    s = in_out_str;
    s.Replace( " ", "" );
    s.Replace( "(", "" );
    s.Replace( ")", "," );

    n = s.Find( "=>" );
    if( n != wxNOT_FOUND )
    {
        s1 = s.Mid( 0, n );
        s2 = s.Mid( (n+2), (s.Len()-n-2) );

        j = 1;
        i = 0;
        while( s1.Len() )
        {
            n = s1.Find( "," );
            s = s1.Mid( 0, n );
            n1 = s.Find( ":" );
            if( n1 != wxNOT_FOUND )
            {
                ss1 = s.Mid( 0, n1 );
                ss2 = s.Mid( n1+1 );
                IN_OUT_Decode_Var.Nn = j++;
                IN_OUT_Decode_Var.InOut = 1;
                IN_OUT_Decode_Var.Type = (const char*) ss1.c_str();
                IN_OUT_Decode_Var.Name = (const char*) ss2.c_str();
                IN_OUT_Decode_Ptr.push_back( IN_OUT_Decode_Var );
            }
            s1 = s1.Mid( n+1 );
            if( i++ > 20 )
            {
                break;
            }
        }

        i = 0;
        while( s2.Len() )
        {
            n = s2.Find( "," );
            s = s2.Mid( 0, n );
            n1 = s.Find( ":" );
            if( n1 != wxNOT_FOUND )
            {
                ss1 = s.Mid( 0, n1 );
                ss2 = s.Mid( n1+1 );
                IN_OUT_Decode_Var.Nn = j++;
                IN_OUT_Decode_Var.InOut = 2;
                IN_OUT_Decode_Var.Type = (const char*) ss1.c_str();
                IN_OUT_Decode_Var.Name = (const char*) ss2.c_str();
                IN_OUT_Decode_Ptr.push_back( IN_OUT_Decode_Var );
            }
            s2 = s2.Mid( n+1 );
            if( i++ > 20 )
            {
                break;
            }
        }
    }
}
// ============================================================================


// ============================================================================
void MyFrame::Make_Obj( int block_id, wxString obj_name,
                        std::vector <IN_OUT_Decode_Struct> &IN_OUT_Decode_Ptr,
                        std::vector <Shape_Struct> &Shape_Ptr,
                        std::vector <Link_Point_Struct> &Link_Point_Ptr )
// ============================================================================
{
    unsigned int        i, n, n1, n2;
    unsigned int        size_w, size_h; // size of blank
    int                 size_in, size_out;
    int                 x, y;
    unsigned int        size_obj_name, w, h;
    wxMemoryDC          mem_dc;
    wxSize              sz;
    wxString            s;
    std::string         ss;
    Link_Point_Struct   lp;

    wxFont font = wxFont( FONT_SIZE,
                          wxFONTFAMILY_DEFAULT,
                          wxFONTSTYLE_NORMAL,
                          wxFONTWEIGHT_NORMAL,
                          false,
                          wxEmptyString );
    mem_dc.SetFont( font );

    sz = mem_dc.GetTextExtent( wxString::Format( wxT("W") ) ); // get size of blank
    s = wxT( "W" );
    sz = mem_dc.GetTextExtent( s );
    size_w = sz.GetWidth();
    size_h = sz.GetHeight();

    sz = mem_dc.GetTextExtent( obj_name );
    size_obj_name = sz.GetWidth() + size_w*2;

    n1 = 0;
    n2 = 0;
    size_in = 0;
    size_out = 0;
    for( i = 0; i < IN_OUT_Decode_Ptr.size(); i++ )
    {
//printf( "Nn=%d InOut=%d Type=%s Name=%s\n", IN_OUT_Decode_Ptr[i].Nn,
//                                            IN_OUT_Decode_Ptr[i].InOut,
//                                            IN_OUT_Decode_Ptr[i].Type.c_str(),
//                                            IN_OUT_Decode_Ptr[i].Name.c_str() );
        s = IN_OUT_Decode_Ptr[i].Name.c_str();
        sz = mem_dc.GetTextExtent( s );

        if( IN_OUT_Decode_Ptr[i].InOut == 1 )
        {
            n1++;
            if( sz.x > size_in )
            {
                size_in = sz.x;
            }
        }
        else
        if( IN_OUT_Decode_Ptr[i].InOut == 2 )
        {
            n2++;
            if( sz.x > size_out )
            {
                size_out = sz.x;
            }
        }
    }

    if( n1 > n2 )
    {
        n = n1;
    }
    else
    {
        n = n2;
    }

    w = size_in + size_out;
    if( size_obj_name > w )
    {
        w = size_obj_name;
    }

    w += (size_w*3);
    h = ( size_h * (n+2) ) * 3 / 2;
    sz = mem_dc.GetTextExtent( obj_name );
    x = ( w - sz.GetWidth() ) / 2;
    y = size_h / 2;

//Shape_Ptr[0].ID = ???
    Shape_Ptr[0].Block_ID = block_id;
    Shape_Ptr[0].Name_POU = obj_name;
    Shape_Ptr[0].Name_POU_Pos = wxPoint( x, y );
    Shape_Ptr[0].Anchor = wxPoint( 0, 0 );
    Shape_Ptr[0].Size = wxPoint( w, h );
    Shape_Ptr[0].Min_Size = wxPoint( w, h );
    Shape_Ptr[0].Size_W = size_w;
    Shape_Ptr[0].Size_H = size_h;

    y = (size_h / 2) + (size_h * 2);

    for( i = 0; i < IN_OUT_Decode_Ptr.size(); i++ )
    {
        if( IN_OUT_Decode_Ptr[i].InOut == 1 ) // In
        {
            lp.Name_IO = IN_OUT_Decode_Ptr[i].Name.c_str();
            lp.Type = IN_OUT_Decode_Ptr[i].Type;
            lp.In_Out = IN_OUT_Decode_Ptr[i].InOut;
            lp.Pos = wxPoint( -(int)size_w, (y+(size_h/2)) ); // link point pos
            lp.Name_IO_Pos = wxPoint( size_w, y );       // rectangle pos of Name

            y += ( size_h + (size_h/2) );
            Link_Point_Ptr.push_back( lp );
        }
    }

    y = (size_h / 2) + (size_h * 2);
    for( i = 0; i < IN_OUT_Decode_Ptr.size(); i++ )
    {
        if( IN_OUT_Decode_Ptr[i].InOut == 2 ) // Out
        {
            lp.Name_IO = IN_OUT_Decode_Ptr[i].Name.c_str();
            lp.Type = IN_OUT_Decode_Ptr[i].Type;
            lp.In_Out = IN_OUT_Decode_Ptr[i].InOut;
            lp.Pos = wxPoint( 0, (y+(size_h/2)) ); // Calculate X as size_w on draw
            lp.Name_IO_Pos = wxPoint( size_w, y );

            y += ( size_h + (size_h/2) );
            Link_Point_Ptr.push_back( lp );
        }
    }
}
// ============================================================================


BEGIN_EVENT_TABLE( MyFrame, MyFrameFB )
	EVT_MENU( ID_EXIT,    MyFrame::OnExit )
	EVT_MENU( ID_SHOW_F3, MyFrame::OnF3 )
	EVT_MENU( ID_SHOW_F4, MyFrame::OnF4 )
	EVT_MENU( ID_SHOW_F5, MyFrame::OnF5 )
	EVT_MENU( ID_SHOW_F6, MyFrame::OnF6 )

	EVT_MENU( ID_PRJ_ADD,  MyFrame::OnPrjAdd )
	EVT_MENU( ID_PRJ_OPEN, MyFrame::OnPrjOpen )
	EVT_MENU( ID_PRJ_SAVE, MyFrame::OnPrjSave )
	EVT_MENU( ID_PRJ_DEL,  MyFrame::OnPrjDel )
	EVT_MENU( ID_PRJ_UP,   MyFrame::OnPrjUp )
	EVT_MENU( ID_PRJ_DOWN, MyFrame::OnPrjDown )
	//EVT_MENU( ID_PRJ_EDIT, MyFrame::OnPrjEdit )

	EVT_SIZE( MyFrame::OnSize )
	EVT_MAXIMIZE( MyFrame::OnMaxSize )
	EVT_MOVE( MyFrame::OnMove )

	//EVT_KEY_DOWN(  MyFrame::OnKeyDown )
	//EVT_KEY_UP(    MyFrame::OnKeyUp )
	EVT_CHAR_HOOK( MyFrame::OnChar )
	//EVT_CHAR( MyFrame::OnChar )
END_EVENT_TABLE()
