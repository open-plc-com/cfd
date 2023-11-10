/*
	Name:			myframe_init.cpp
	Purpose:		Open-PLC Tools
	Author:			www.open-plc.com
	Created:		20YY/MM
	Modified by:
	RCS-ID:
	Copyright:		(c) Open-PLC
	Licence:		The MIT License (MIT)
*/


#include "myframe.h"
#include "dev.xpm"
#include "./pict/project.xpm"
#include "./pict/f.xpm"
#include "./pict/st.xpm"
#include "./pict/fbd.xpm"
#include "./pict/ld.xpm"
#include "./pict/var_inout.xpm"
//#include "cur_add.xpm"
//#include "cur_move.xpm"
//#include "load.xpm"

#include <wx/display.h>

// ============================================================================
void MyFrame::Init()
// ============================================================================
{
    int       m, n;
    wxPoint   pos;
    wxDisplay displ;
    wxSize    ws;

	SetIcon( wxIcon( dev_xpm ) );	// Set Icon

	SetMinSize( wxSize( 800, 600 ) );
	Fit();
	pos = GetPosition();
	if( ( pos.x >= 0 ) && ( pos.y >= 0 ) )
	{
		Win_PosX = pos.x;
		Win_PosY = pos.y;
	}

	ws = displ.GetPPI();
	Display_Resolution = ws.GetWidth();

	m_shape->m_fbd_tool = m_fbd_tool;
	m_shape->m_ld_tool  = m_ld_tool;
	m_shape->shape_obj  = &shape_obj;

	m_fbd_tool->ToggleTool( ID_FBD_CURSOR, true );
	m_ld_tool->ToggleTool( ID_LD_CURSOR, true );


//printf( "Width=%d Height=%d\n", ws.GetWidth(), ws.GetHeight() );

	//m_menu_view->FindItem( ID_SHOW_F4 )->Enable( false );

	//m_menu_view->Delete( ID_SHOW_F3 );
	//m_menu_view->Delete(ID_SHOW_F4);
	//m_menu_view->Delete(ID_SHOW_F5);
	//m_menu_view->Delete(ID_SHOW_F6);

	//m_menu_view->Append( ID_SHOW_F3, wxT( "F3_ADD\tF3" ) );

//printf( "OPT_VER=%s", OPT_VER );

	m_grid_tool->EnableTool( ID_GRID_ADD, false );
	m_grid_tool->EnableTool( ID_GRID_DEL, false );
	m_grid_tool->EnableTool( ID_GRID_UP, false );
	m_grid_tool->EnableTool( ID_GRID_DOWN, false );

// --- Prj tree init ----------------------------------------------------------

	//m_prj_tool->EnableTool( ID_PRJ_ADD, false );
	m_prj_tool->EnableTool( ID_PRJ_DEL, false );
	m_prj_tool->EnableTool( ID_PRJ_UP, false );
	m_prj_tool->EnableTool( ID_PRJ_DOWN, false );
	m_prj_tool->EnableTool( ID_PRJ_EDIT, false );

	//m_prj_tree->DisableCellEditControl();
	m_prj_tree->SetCellHighlightPenWidth(0);
	m_prj_tree->SetSelectionBackground( wxColour( 192, 192, 192 ) );
	m_prj_tree->SetSelectionForeground( wxColour( 0, 0, 0 ) );

	n = m_prj_tree->GetNumberCols();
	m = m_prj_tree->GetRowSize(0);

	m_prj_tree->SetColSize( 0, m );
	m_prj_tree->SetColSize( 1, m );
	m_prj_tree->SetColSize( 2, m );
	m_prj_tree->SetColSize( 3, (m*2) );

#ifdef SHOW_T1
	m_prj_tree->SetColSize( (n-1), (m) );
	m_prj_tree->SetColSize( (n-2), (m*2) );
	m_prj_tree->SetColSize( (n-3), (m) );
	m_prj_tree->SetColSize( (n-4), (m) );
#else
	m_prj_tree->SetColSize( (n-1), 0 ); // size = 0
	m_prj_tree->SetColSize( (n-2), 0 ); // size = 0
	m_prj_tree->SetColSize( (n-3), 0 ); // size = 0
	m_prj_tree->SetColSize( (n-4), 0 ); // size = 0
#endif

	m_prj_tree->EnableDragGridSize( false );
	m_prj_tree->EnableDragColSize( false );

// --- AUI Init ---------------------------------------------------------------

	m_mgr1.SetManagedWindow( m_panel1 );
	// m_mgr1.SetFlags(0);
	m_mgr1.SetFlags( wxAUI_MGR_LIVE_RESIZE );


//	wxToolBar *m_toolBar1 = new wxToolBar( m_panel1,
//										wxID_ANY,
//										wxDefaultPosition,
//										wxDefaultSize,
//										wxTB_HORIZONTAL | wxTB_NODIVIDER | wxTB_FLAT );
//	m_toolBar1->AddTool( wxID_ANY,
//						wxT("tool"),
//						wxBitmap( dev_xpm ),
//						wxNullBitmap,
//						wxITEM_NORMAL,
//						wxT("tool1"),
//						wxT("tool2") );
//
//					//wxEmptyString,
//					//wxEmptyString);
//	m_toolBar1->Realize();


	m_nb_shape->SetTabCtrlHeight(0);
	m_nb_edit->SetTabCtrlHeight(0);
	m_nb_prj->SetTabCtrlHeight(0);
	m_nb_grid->SetTabCtrlHeight(0);

	m_mgr1.AddPane( m_nb_grid, wxCENTER );
	//m_mgr1.AddPane( m_nb_shape, wxAuiPaneInfo().
					//ToolbarPane().
					//Center().
					//Name(wxT("shape")) );

	m_nb_shape->SetWindowStyleFlag( wxBORDER_SUNKEN );
	m_mgr1.AddPane( m_nb_shape, wxCENTER );
	//m_mgr1.AddPane( m_nb_shape, wxAuiPaneInfo().
					//ToolbarPane().
					//Center().
					//Name(wxT("shape")) );


	m_mgr1.AddPane( m_nb_edit, wxCENTER );
	m_mgr1.AddPane( m_nb_prj, wxLEFT );
	m_mgr1.GetPane( m_nb_edit ).Show( false );

	m_mgr1.AddPane( m_st_tool,
					wxAuiPaneInfo().
					ToolbarPane().
					Name(wxT("m_st_tool")).
					Top().
					Row(1).
					Floatable( true ).
					LeftDockable( true ).
					RightDockable( true ).
					BottomDockable( false ) );
//	m_tool1->SetState( wxAUI_BUTTON_STATE_CHECKED );

	m_mgr1.AddPane( m_fbd_tool,
					wxAuiPaneInfo().
					ToolbarPane().
					Name(wxT("m_fbd_tool")).
					Top().
					Row(1).
					Floatable( true ).
					LeftDockable( true ).
					RightDockable( true ).
					BottomDockable( false ) );
//	m_tool1->SetState( wxAUI_BUTTON_STATE_CHECKED );

	m_mgr1.AddPane( m_ld_tool,
					wxAuiPaneInfo().
					ToolbarPane().
					Name(wxT("m_ld_tool")).
					Top().
					Row(1).
					Floatable( true ).
					LeftDockable( true ).
					RightDockable( true ).
					BottomDockable( false ) );
//	m_tool1->SetState( wxAUI_BUTTON_STATE_CHECKED );

	m_mgr1.AddPane( m_add_tool,
					wxAuiPaneInfo().
					ToolbarPane().
					Name(wxT("m_ld_tool")).
					Top().
					Row(1).
					Floatable( true ).
					LeftDockable( true ).
					RightDockable( true ).
					BottomDockable( false ) );
//	m_tool1->SetState( wxAUI_BUTTON_STATE_CHECKED );

	m_mgr1.AddPane( m_pou_tree,
					wxAuiPaneInfo().
					//ToolbarPane().
					Name( wxT( "pou" ) ).
					Right().
					CloseButton( false ).
					BestSize( wxSize( 300, -1 ) ).
					//Resizable().
					CaptionVisible( false ) );
					//Floatable(true).
					//LeftDockable(true).
					//RightDockable(true).
					//BottomDockable(true));

	m_mgr1.AddPane( m_pou_text,
					wxAuiPaneInfo().
					//ToolbarPane().
					Name( wxT( "pou text" ) ).
					Right().
					//Top().
					CloseButton( false ).
					//BestSize( wxSize( 300, -1 ) ).
					CaptionVisible( false ).
					Floatable( true )
					//LeftDockable(true).
					//RightDockable(true).
					//BottomDockable(true));
					//Floatable(false).
					//LeftDockable( true ).
					//RightDockable( true ).
					//BottomDockable( true ) );
					);

//	m_mgr1.AddPane( m_prj_tree,
//					wxAuiPaneInfo().
//					//ToolbarPane().
//					Name(wxT("S1")).
//					Left().
//					BestSize(wxSize(300,-1)).
//					Resizable().
//					//CloseButton(false).
//					CaptionVisible(false).
//					Floatable(true).
//					LeftDockable(true).
//					RightDockable(true).
//					BottomDockable(true));

	//m_mgr1.Update();

//m_mgr1.GetPane(m_toolBar1).Show(false);
//m_mgr1.GetPane(m_nb_shape).Show(false);
//m_mgr1.GetPane(m_nb_edit).Show(false);
//m_mgr1.Update();

	m_mgr1.GetPane( m_nb_prj ).
				    CaptionVisible( false ).
				    BestSize( wxSize( 300, -1 ) ).
				    Resizable();

//m_mgr1.Update();


//printf( "m_nb_edit.Show()=%d\n", m_mgr1.GetPane( m_nb_edit ).IsShown() );
//printf( "m_nb_shape.Show()=%d\n", m_mgr1.GetPane( m_nb_shape ).IsShown() );

	//m_mgr1.GetPane( m_pou_tree ).Show( false );
	//m_mgr1.GetPane( m_pou_text ).Show( false );
	//m_mgr1.GetPane( m_pou_tree ).Show( true );
	//m_mgr1.GetPane( m_pou_text ).Show( true );
	//m_mgr1.Update();

	m_mgr1.GetPane( m_nb_shape ).Show( false );
	m_mgr1.GetPane( m_nb_edit ).Show( false );
	m_mgr1.GetPane( m_nb_grid ).Show( false );

//m_mgr1.GetPane( m_pou_tree ).Show( false );
//m_mgr1.GetPane( m_pou_text).Show( false );
////m_mgr1.GetPane( m_st_tool).Show( false );

	m_mgr1.GetPane( m_st_tool).Show( false );
	m_mgr1.GetPane( m_fbd_tool).Show( false );
	m_mgr1.GetPane( m_ld_tool).Show( false );
	m_mgr1.GetPane( m_add_tool).Show( false );

	m_mgr1.Update();

	Start = false;
	//m_prj_tree->SetGridCursor( 0, 0 );
}
// ============================================================================
