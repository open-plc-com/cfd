/*
    Name:        myframe_static_events.cpp
    Purpose:     Open-PLC Tools
    Author:      www.open-plc.com
    Created:     2023/10
    Modified by:
    RCS-ID:
    Copyright:   (c) Open-PLC
    Licence:     The MIT License (MIT)
*/


#include "myframe.h"
#include "./pict/project.xpm"
#include "./pict/st.xpm"
#include "./pict/fbd.xpm"
#include "./pict/ld.xpm"
#include "./pict/var_inout.xpm"
#include "./pict/f.xpm"


// ============================================================================
void MyFrame::OnF3( wxCommandEvent &WXUNUSED( event ) )
// ============================================================================
{
    if( m_mgr1.GetPane( m_nb_prj ).IsShown() )
    {
        m_mgr1.GetPane( m_nb_prj ).Show( false );
        m_mgr1.Update();
    }
    else
    {
        m_mgr1.GetPane( m_nb_prj ).Show( true );
        m_mgr1.Update();
    }
    //event.Skip();
}
// ============================================================================


// ============================================================================
void MyFrame::OnF4( wxCommandEvent &WXUNUSED( event ) )
// ============================================================================
{
    int n;
    wxString s;

    n = m_prj_tree->GetNumberCols();
    s = m_prj_tree->GetCellValue( Select_Row, (n-2) );

    if( ( s != wxT( "PRJ" ) ) && ( s != wxT( "FUNC" ) ) )
    {
        if( m_mgr1.GetPane( m_nb_grid ).IsShown() )
        {
            m_mgr1.GetPane(m_nb_grid).Show(false);
            m_mgr1.Update();
            m_prj_tree->SetCellValue( Select_Row, (n-3), wxT( "F" ) );
        }
        else
        {
            m_mgr1.GetPane(m_nb_grid).Show(true);
            m_mgr1.Update();
            m_prj_tree->SetCellValue( Select_Row, (n-3), wxT( "T" ) );
        }
    }
    else
    {
        m_mgr1.GetPane(m_nb_grid).Show(false);
        m_mgr1.Update();
    }
    //event.Skip();
}
// ============================================================================


// ============================================================================
void MyFrame::OnF5( wxCommandEvent &WXUNUSED( event ) )
// ============================================================================
{
    if( m_mgr1.GetPane( m_pou_tree ).IsShown() )
    {
        m_mgr1.GetPane( m_pou_tree ).Show( false );
        m_mgr1.GetPane( m_pou_text ).Show( false );
        m_mgr1.Update();
    }
    else
    {
        m_mgr1.GetPane( m_pou_tree ).Show( true ).BestSize( wxSize( 240, -1 ) );
        m_mgr1.GetPane( m_pou_text ).Show( true );
        m_mgr1.Update();
        m_pou_tree->Expand( pou_item_root );
    }
    //event.Skip();
}
// ============================================================================


// ============================================================================
void MyFrame::OnF6( wxCommandEvent &WXUNUSED( event ) )
// ============================================================================
{
////int i;
////long l;
printf( "MyFrame::OnF6\n" );

//	ObjProps *dlg = new ObjProps( this );
//	dlg->SetTitle( wxT( "Block properties" ) );

////dlg->m_static_text1->Show( false );
////dlg->m_choice->Show( false );
////dlg->m_staticline6->Show( false );
//dlg->m_name->Disable();
////dlg->m_choice->Disable();

////dlg->Fit();







//dlg->m_pou = &m_POU;

//dlg->IN_OUT_Decode_Ptr = IN_OUT_Decode_Ptr;
//dlg->Shape_Ptr = Shape_Ptr;
//dlg->Link_Point_Ptr = Link_Point_Ptr;
//dlg->Block_ID = Block_ID;
//dlg->Block_Name = Block_Name;
//dlg->IN_OUT_Decode = IN_OUT_Decode;
//dlg->Make_Obj = Make_Obj;

//dlg->Fill_POU();

//dlg->ShowModal();

////dlg->

////dlg->m_pou = &m_POU;

////dlg->grid = m_prj_tree;
////dlg->m_name->SetLabel( wxT( "Project Name" ) );
////dlg->m_language->Show( false );
////dlg->m_choice_lang->Show( false );
////dlg->PRJ_FILE_SELECT = true;
////dlg->m_file_name->Show( true );
////dlg->m_file_set->Show( true );



//	delete dlg;

//	event.Skip();
}
// ============================================================================


// ============================================================================
void MyFrame::OnPrjSave( wxCommandEvent &event )
// ============================================================================
{
//printf( "MyFrame::OnPrjSave\n" );
    event.Skip();
}
// ============================================================================


// ============================================================================
void MyFrame::OnPrjOpen( wxCommandEvent &event )
// ============================================================================
{
//printf( "MyFrame::OnPrjOpen\n" );
    event.Skip();
}
// ============================================================================


// ============================================================================
void MyFrame::OnChar( wxKeyEvent &event )
// ============================================================================
{
    wxUint32 key;

    key = event.GetKeyCode();

//printf( "myframe key=%04X %c  ", key, key );
//printf( "alt=%d control=%d shift=%d\n", event.m_altDown, event.m_controlDown, event.m_shiftDown );

//  if( key == 'A' )
//  {
////printf( "key == 'A'\n" );
////printf( "alt=%d control=%d shift=%d\n", event.m_altDown, event.m_controlDown, event.m_shiftDown );
//
//  }
    event.Skip();
}
// ============================================================================


// ============================================================================
void MyFrame::OnMaxSize( wxMaximizeEvent &event )
// ============================================================================
{
    Win_MaxSize = true;
    event.Skip();
}
// ============================================================================


// ============================================================================
void MyFrame::OnSize( wxSizeEvent &event )
// ============================================================================
{
    wxString s;
    wxPoint  pos  = GetPosition();
    wxSize   size = event.GetSize();

    if( ( pos.x >= 0 ) && ( pos.y >= 0 ) )
    {
        Win_MaxSize = false;
        Win_PosX    = pos.x;
        Win_PosY    = pos.y;
        Win_SizeX   = size.x;
        Win_SizeY   = size.y;
    }
    Refresh();
    event.Skip();
}
// ============================================================================


// ============================================================================
void MyFrame::OnMove( wxMoveEvent &event ) // Form move
// ============================================================================
{
    wxPoint pos = GetPosition();

    if( ( pos.x >= 0 ) && ( pos.y >= 0 ) )
    {
        Win_PosX = pos.x;
        Win_PosY = pos.y;
    }
    event.Skip();
}
// ============================================================================


// ============================================================================
void MyFrame::OnPrjAdd( wxCommandEvent &WXUNUSED( event ) )
// ============================================================================
{
    int      i, m, n;
    bool     prg_found;
    bool     func_found;
    wxMenu   menu;
    wxString s;

    m = m_prj_tree->GetNumberRows(); // Number of Rows
    n = m_prj_tree->GetNumberCols(); // Number of Cols

    if( ( m == 1 ) && ( m_prj_tree->GetCellValue( 0, (n-2) ) == wxEmptyString ) )
    {
        PrjAdd *dlg = new PrjAdd( this );
        dlg->grid = m_prj_tree;
        dlg->m_pou = &m_POU;
        dlg->SetTitle( wxT( "Create Project" ) );
        dlg->m_name->SetLabel( wxT( "Project Name" ) );
        dlg->m_language->Show( false );
        dlg->m_choice_lang->Show( false );
        dlg->PRJ_FILE_SELECT = true;
        dlg->m_file_name->Show( true );
        dlg->m_file_set->Show( true );
        dlg->Fit();
        dlg->ShowModal();

        if( dlg->ON_OK )
        {
            PRJ_NAME = dlg->m_text_name->GetValue();
            PRJ_FILE = dlg->m_file_set->GetPath();
            m_prj_tree->SetCellRenderer( 0, 0, new GridBitmap( wxBitmap( project_xpm ) ) );
            m_prj_tree->SetCellSize( 0, 1, 1, (n-3) );
            m_prj_tree->SetCellValue( 0, 1, PRJ_NAME );
            m_prj_tree->SetCellValue( 0, (n-2), wxT( "PRJ" ) );
            m_prj_tree->SetCellValue( 0, (n-1), wxT( "-1" ) );
        }
        delete dlg;
    }
    else
    {
        prg_found = false;
        func_found = false;
        for( i = 0; i < m; i++ )
        {
            s = m_prj_tree->GetCellValue( i, (n-2) );
            if( s == wxT( "PRG" ) )
            {
                prg_found = true;
            }
            else
            if( s == wxT( "FUNC" ) )
            {
                func_found = true;
            }
        }

        if( prg_found )
        {
            PrjAdd *dlg = new PrjAdd( this );
            dlg->m_pou = &m_POU;
            dlg->SetTitle( wxT( "Append Function Block" ) );
            dlg->m_name->SetLabel( wxT( "Function Block Name" ) );
            dlg->grid = m_prj_tree;
            dlg->Fit();
            dlg->ShowModal();

            if( dlg->ON_OK )
            {
                if( dlg->ReturnNn < 0 )
                {
                    dlg->ReturnNn = 1;
                }

                if( !func_found )
                {
                    m_prj_tree->InsertRows( 1 );
                    m_prj_tree->SetCellSize( 1, 2, 1, 3 );
                    m_prj_tree->SetCellRenderer( 1, 1, new GridBitmap( wxBitmap( f_xpm ) ) );
                    m_prj_tree->SetCellValue( 1, 2, wxT("Function blocks") );
                    m_prj_tree->SetCellValue( 1, (n-2), wxT( "FUNC" ) );
                    m_prj_tree->SetCellValue( 1, (n-1), wxT( "-1" ) );
                    m = m_prj_tree->GetNumberRows();
                }

                m--;
                m_prj_tree->InsertRows( m );
                m_prj_tree->SetCellRenderer( m, 2, new GridBitmap( wxBitmap( fbd_xpm ) ) );
                s = dlg->m_choice_lang->GetStringSelection();
                s = wxT( "(" ) + s;
                s = s + wxT( ")" );
                m_prj_tree->SetCellValue( m, 3, s );
                m_prj_tree->SetCellValue( m, 4, dlg->m_text_name->GetValue() );
                m_prj_tree->SetCellValue( m, (n-3), wxT("F") );
                m_prj_tree->SetCellValue( m, (n-2), dlg->m_choice_lang->GetStringSelection() );
                s.Printf( "%d", dlg->ReturnNn );
                m_prj_tree->SetCellValue( m, (n-1), s );
            }
        }
        else
        {
            Menu_Select = -1;
            menu.Append( MENU_ID_CONTEXT_1, "Append Functional block" );
            menu.Append( MENU_ID_CONTEXT_2, "Append Program Block" );
            //menu.Append( MENU_ID_CONTEXT_3, "Context Menu command..." );
            PopupMenu( &menu );

            switch( Menu_Select )
            {
                case MENU_ID_CONTEXT_1:
                    {
                        PrjAdd *dlg = new PrjAdd( this );
                        dlg->m_pou = &m_POU;
                        dlg->SetTitle( wxT( "Append Function Block" ) );
                        dlg->m_name->SetLabel( wxT( "Function Block Name" ) );
                        dlg->grid = m_prj_tree;
                        dlg->Fit();
                        dlg->ShowModal();

                        if( dlg->ON_OK )
                        {
                            if( dlg->ReturnNn < 0 )
                            {
                                dlg->ReturnNn = 1;
                            }

                            if( !func_found )
                            {
                                m_prj_tree->InsertRows( 1 );
                                m_prj_tree->SetCellSize( 1, 2, 1, 3 );
                                m_prj_tree->SetCellRenderer( 1, 1, new GridBitmap( wxBitmap( f_xpm ) ) );
                                m_prj_tree->SetCellValue( 1, 2, wxT("Function blocks") );
                                m_prj_tree->SetCellValue( 1, (n-2), wxT( "FUNC" ) );
                                m_prj_tree->SetCellValue( 1, (n-1), wxT( "-1" ) );
                                m = m_prj_tree->GetNumberRows();
                            }

                            m_prj_tree->AppendRows();
                            m_prj_tree->SetCellRenderer( m, 2, new GridBitmap( wxBitmap( fbd_xpm ) ) );
                            s = dlg->m_choice_lang->GetStringSelection();
                            s = wxT( "(" ) + s;
                            s = s + wxT( ")" );
                            m_prj_tree->SetCellValue( m, 3, s );
                            m_prj_tree->SetCellValue( m, 4, dlg->m_text_name->GetValue() );
                            m_prj_tree->SetCellValue( m, (n-3), wxT("F") );
                            m_prj_tree->SetCellValue( m, (n-2), dlg->m_choice_lang->GetStringSelection() );
                            s.Printf( "%d", dlg->ReturnNn );
                            m_prj_tree->SetCellValue( m, (n-1), s );
                        }
                        delete dlg;
                    }
                    break;
                case MENU_ID_CONTEXT_2:
                    {
                        PrjAdd *dlg = new PrjAdd( this );
                        dlg->m_pou = &m_POU;
                        dlg->SetTitle( wxT( "Append Program Block" ) );
                        dlg->m_name->SetLabel( wxT( "Program Block Name" ) );
                        dlg->m_language->Show( false );
                        dlg->m_choice_lang->Show( false );
                        dlg->grid = m_prj_tree;
                        dlg->Fit();
                        dlg->ShowModal();

                        if( dlg->ON_OK )
                        {
                            s = dlg->m_text_name->GetValue();
                            m_prj_tree->AppendRows();
                            m_prj_tree->SetCellSize( m, 3, 1, 2 );
                            m_prj_tree->SetCellRenderer( m, 1, new GridBitmap( wxBitmap( var_inout_xpm ) ) );
                            m_prj_tree->SetCellRenderer( m, 2, new GridBitmap( wxBitmap( fbd_xpm ) ) );
                            m_prj_tree->SetCellValue( m, 3, dlg->m_text_name->GetValue() );
                            m_prj_tree->SetCellValue( m, (n-3), wxT("F") );
                            m_prj_tree->SetCellValue( m, (n-2), wxT("PRG") );
                            m_prj_tree->SetCellValue( m, (n-1), wxT("0") );
                        }
                        delete dlg;
                    }
                    break;
                //default:
                    //break;
            }
        }
    }
//printf( "Add\n" );
	Init_POU_Tree();
}
// ============================================================================


// ============================================================================
void MyFrame::OnPrjDel( wxCommandEvent &WXUNUSED( event ) )
// ============================================================================
{
//printf( "MyFrame::OnPrjDel\n" );
}
// ============================================================================


// ============================================================================
void MyFrame::OnPrjMenuSelect( wxCommandEvent &event )
// ============================================================================
{
    switch( event.GetId() )
    {
        case MENU_ID_CONTEXT_1:
            Menu_Select = MENU_ID_CONTEXT_1;
            break;
        case MENU_ID_CONTEXT_2:
            Menu_Select = MENU_ID_CONTEXT_2;
            break;
        case MENU_ID_CONTEXT_3:
            Menu_Select = MENU_ID_CONTEXT_3;
            break;
        default:
            Menu_Select = -1;
            break;
    }
    event.Skip();
}
// ============================================================================


// ============================================================================
void MyFrame::OnPrjUp( wxCommandEvent &WXUNUSED( event ) )
// ============================================================================
{
    int i, n;
    wxString s;
    wxGridCellRenderer *r1, *r2;

    n = m_prj_tree->GetNumberCols();

    for( i = 0; i < n; i++ )
    {
        s = m_prj_tree->GetCellValue( (Select_Row-1), i );
        if( s != wxEmptyString )
        {
            m_prj_tree->SetCellValue( (Select_Row-1), i, m_prj_tree->GetCellValue( Select_Row, i ) );
            m_prj_tree->SetCellValue( Select_Row, i, s );
        }
    }

    r1 = m_prj_tree->GetCellRenderer( (Select_Row-1), 2 );
    r2 = m_prj_tree->GetCellRenderer( Select_Row, 2 );
    m_prj_tree->SetCellRenderer( (Select_Row-1), 2, r2 );
    m_prj_tree->SetCellRenderer( Select_Row, 2, r1 );
    m_prj_tree->SetGridCursor( (Select_Row-1), 0 );
}
// ============================================================================


// ============================================================================
void MyFrame::OnPrjDown( wxCommandEvent &WXUNUSED( event ) )
// ============================================================================
{
    int i, n;
    wxString s;
    wxGridCellRenderer *r1, *r2;

    n = m_prj_tree->GetNumberCols();

    for( i = 0; i < n; i++ )
    {
        s = m_prj_tree->GetCellValue( (Select_Row+1), i );
        if( s != wxEmptyString )
        {
            m_prj_tree->SetCellValue( (Select_Row+1), i, m_prj_tree->GetCellValue( Select_Row, i ) );
            m_prj_tree->SetCellValue( Select_Row, i, s );
        }
    }

    r1 = m_prj_tree->GetCellRenderer( (Select_Row+1), 2 );
    r2 = m_prj_tree->GetCellRenderer( Select_Row, 2 );
    m_prj_tree->SetCellRenderer( (Select_Row+1), 2, r2 );
    m_prj_tree->SetCellRenderer( Select_Row, 2, r1 );
    m_prj_tree->SetGridCursor( (Select_Row+1), 0 );
}
// ============================================================================
