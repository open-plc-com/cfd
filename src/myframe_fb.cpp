///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "myframe_fb.h"

#include "pict/add.xpm"
#include "pict/add_block.xpm"
#include "pict/add_coil.xpm"
#include "pict/add_comment.xpm"
#include "pict/add_connection.xpm"
#include "pict/add_contact.xpm"
#include "pict/add_powerrail.xpm"
#include "pict/add_variable.xpm"
#include "pict/compiler.xpm"
#include "pict/cursor.xpm"
#include "pict/del.xpm"
#include "pict/down.xpm"
#include "pict/edit_button.xpm"
#include "pict/move.xpm"
#include "pict/show_code.xpm"
#include "pict/up.xpm"

///////////////////////////////////////////////////////////////////////////

MyFrameFB::MyFrameFB( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetFont( wxFont( 11, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	m_panel1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel1->SetFont( wxFont( 10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	m_nb_shape = new wxAuiNotebook( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_nb_shape->SetFont( wxFont( 10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	m_nb_shape->Hide();

	m_panel2 = new wxPanel( m_nb_shape, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel2->SetFont( wxFont( 10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	m_panel2->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	m_shape_name = new wxStaticText( m_panel2, wxID_ANY, wxT("Shape"), wxDefaultPosition, wxDefaultSize, 0 );
	m_shape_name->Wrap( -1 );
	bSizer3->Add( m_shape_name, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxBOTTOM, 5 );

	m_staticline1 = new wxStaticLine( m_panel2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer3->Add( m_staticline1, 0, wxEXPAND, 5 );

	m_shape = new Shape( m_panel2, wxID_ANY );
	m_shape->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	bSizer3->Add( m_shape, 1, wxEXPAND, 5 );


	m_panel2->SetSizer( bSizer3 );
	m_panel2->Layout();
	bSizer3->Fit( m_panel2 );
	m_nb_shape->AddPage( m_panel2, wxEmptyString, false, wxNullBitmap );

	bSizer2->Add( m_nb_shape, 0, 0, 5 );

	m_nb_edit = new wxAuiNotebook( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_nb_edit->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	m_nb_edit->Hide();

	m_panel3 = new wxPanel( m_nb_edit, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel3->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	m_edit_name = new wxStaticText( m_panel3, wxID_ANY, wxT("ST"), wxDefaultPosition, wxDefaultSize, 0 );
	m_edit_name->Wrap( -1 );
	bSizer4->Add( m_edit_name, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxBOTTOM, 5 );

	m_staticline3 = new wxStaticLine( m_panel3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer4->Add( m_staticline3, 0, wxEXPAND, 5 );

	m_edit = new wxStyledTextCtrl( m_panel3, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, wxEmptyString );
	m_edit->SetUseTabs( false );
	m_edit->SetTabWidth( 4 );
	m_edit->SetIndent( 4 );
	m_edit->SetTabIndents( false );
	m_edit->SetBackSpaceUnIndents( true );
	m_edit->SetViewEOL( false );
	m_edit->SetViewWhiteSpace( false );
	m_edit->SetMarginWidth( 2, 0 );
	m_edit->SetIndentationGuides( false );
	m_edit->SetReadOnly( false );
	m_edit->SetMarginWidth( 1, 0 );
	m_edit->SetMarginType( 0, wxSTC_MARGIN_NUMBER );
	m_edit->SetMarginWidth( 0, m_edit->TextWidth( wxSTC_STYLE_LINENUMBER, wxT("_99999") ) );
	{
		wxFont font = wxFont( 12, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString );
		m_edit->StyleSetFont( wxSTC_STYLE_DEFAULT, font );
	}
	m_edit->MarkerDefine( wxSTC_MARKNUM_FOLDER, wxSTC_MARK_BOXPLUS );
	m_edit->MarkerSetBackground( wxSTC_MARKNUM_FOLDER, wxColour( wxT("BLACK") ) );
	m_edit->MarkerSetForeground( wxSTC_MARKNUM_FOLDER, wxColour( wxT("WHITE") ) );
	m_edit->MarkerDefine( wxSTC_MARKNUM_FOLDEROPEN, wxSTC_MARK_BOXMINUS );
	m_edit->MarkerSetBackground( wxSTC_MARKNUM_FOLDEROPEN, wxColour( wxT("BLACK") ) );
	m_edit->MarkerSetForeground( wxSTC_MARKNUM_FOLDEROPEN, wxColour( wxT("WHITE") ) );
	m_edit->MarkerDefine( wxSTC_MARKNUM_FOLDERSUB, wxSTC_MARK_EMPTY );
	m_edit->MarkerDefine( wxSTC_MARKNUM_FOLDEREND, wxSTC_MARK_BOXPLUS );
	m_edit->MarkerSetBackground( wxSTC_MARKNUM_FOLDEREND, wxColour( wxT("BLACK") ) );
	m_edit->MarkerSetForeground( wxSTC_MARKNUM_FOLDEREND, wxColour( wxT("WHITE") ) );
	m_edit->MarkerDefine( wxSTC_MARKNUM_FOLDEROPENMID, wxSTC_MARK_BOXMINUS );
	m_edit->MarkerSetBackground( wxSTC_MARKNUM_FOLDEROPENMID, wxColour( wxT("BLACK") ) );
	m_edit->MarkerSetForeground( wxSTC_MARKNUM_FOLDEROPENMID, wxColour( wxT("WHITE") ) );
	m_edit->MarkerDefine( wxSTC_MARKNUM_FOLDERMIDTAIL, wxSTC_MARK_EMPTY );
	m_edit->MarkerDefine( wxSTC_MARKNUM_FOLDERTAIL, wxSTC_MARK_EMPTY );
	m_edit->SetSelBackground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );
	m_edit->SetSelForeground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );
	m_edit->SetFont( wxFont( 12, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer4->Add( m_edit, 1, wxEXPAND, 5 );


	m_panel3->SetSizer( bSizer4 );
	m_panel3->Layout();
	bSizer4->Fit( m_panel3 );
	m_nb_edit->AddPage( m_panel3, wxEmptyString, false, wxNullBitmap );

	bSizer2->Add( m_nb_edit, 0, 0, 5 );

	m_nb_grid = new wxAuiNotebook( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_nb_grid->SetFont( wxFont( 10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	m_nb_grid->Hide();

	m_panel4 = new wxPanel( m_nb_grid, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	m_grid_tool = new wxToolBar( m_panel4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_FLAT|wxTB_HORIZONTAL );
	m_grid_tool->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	m_grid_add = m_grid_tool->AddTool( ID_GRID_ADD, wxT("tool"), wxBitmap( add_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_grid_del = m_grid_tool->AddTool( ID_GRID_DEL, wxT("tool"), wxBitmap( del_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_grid_up = m_grid_tool->AddTool( ID_GRID_UP, wxT("tool"), wxBitmap( up_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_grid_down = m_grid_tool->AddTool( ID_GRID_DOWN, wxT("tool"), wxBitmap( down_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_grid_tool->Realize();

	bSizer6->Add( m_grid_tool, 0, wxEXPAND, 5 );

	m_staticline5 = new wxStaticLine( m_panel4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer6->Add( m_staticline5, 0, wxEXPAND|wxBOTTOM, 5 );

	m_grid = new wxGrid( m_panel4, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_grid->CreateGrid( 5, 5 );
	m_grid->EnableEditing( true );
	m_grid->EnableGridLines( true );
	m_grid->EnableDragGridSize( false );
	m_grid->SetMargins( 0, 0 );

	// Columns
	m_grid->EnableDragColMove( false );
	m_grid->EnableDragColSize( true );
	m_grid->SetColLabelSize( 20 );
	m_grid->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_grid->EnableDragRowSize( true );
	m_grid->SetRowLabelSize( 40 );
	m_grid->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_grid->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	m_grid->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	bSizer6->Add( m_grid, 1, wxEXPAND, 5 );


	m_panel4->SetSizer( bSizer6 );
	m_panel4->Layout();
	bSizer6->Fit( m_panel4 );
	m_nb_grid->AddPage( m_panel4, wxEmptyString, false, wxNullBitmap );

	bSizer2->Add( m_nb_grid, 0, 0, 5 );

	m_nb_prj = new wxAuiNotebook( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_nb_prj->SetFont( wxFont( 10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	m_nb_prj->Hide();

	m_panel5 = new wxPanel( m_nb_prj, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel5->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );

	m_prj_tool = new wxToolBar( m_panel5, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_FLAT|wxTB_HORIZONTAL );
	m_prj_add = m_prj_tool->AddTool( ID_PRJ_ADD, wxT("prj_add_tool"), wxBitmap( add_xpm ), wxNullBitmap, wxITEM_NORMAL, wxT("Add Item"), wxEmptyString, NULL );

	m_prj_del = m_prj_tool->AddTool( ID_PRJ_DEL, wxT("tool"), wxBitmap( del_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_prj_up = m_prj_tool->AddTool( ID_PRJ_UP, wxT("tool"), wxBitmap( up_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_prj_down = m_prj_tool->AddTool( ID_PRJ_DOWN, wxT("tool"), wxBitmap( down_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_prj_edit = m_prj_tool->AddTool( ID_PRJ_EDIT, wxT("tool"), wxBitmap( edit_button_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	m_prj_tool->Realize();

	bSizer7->Add( m_prj_tool, 0, wxEXPAND, 5 );

	m_staticline51 = new wxStaticLine( m_panel5, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer7->Add( m_staticline51, 0, wxEXPAND, 5 );

	m_prj_tree = new wxGrid( m_panel5, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN );

	// Grid
	m_prj_tree->CreateGrid( 1, 9 );
	m_prj_tree->EnableEditing( false );
	m_prj_tree->EnableGridLines( true );
	m_prj_tree->EnableDragGridSize( false );
	m_prj_tree->SetMargins( 0, 0 );

	// Columns
	m_prj_tree->EnableDragColMove( false );
	m_prj_tree->EnableDragColSize( true );
	m_prj_tree->SetColLabelSize( 0 );
	m_prj_tree->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_prj_tree->EnableDragRowSize( true );
	m_prj_tree->SetRowLabelSize( 0 );
	m_prj_tree->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_prj_tree->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_CENTER );
	m_prj_tree->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	m_prj_tree->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	bSizer7->Add( m_prj_tree, 1, wxEXPAND, 5 );


	m_panel5->SetSizer( bSizer7 );
	m_panel5->Layout();
	bSizer7->Fit( m_panel5 );
	m_nb_prj->AddPage( m_panel5, wxEmptyString, false, wxNullBitmap );

	bSizer2->Add( m_nb_prj, 0, 0, 5 );

	m_pou_tree = new wxTreeCtrl( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE );
	m_pou_tree->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	m_pou_tree->Hide();

	bSizer2->Add( m_pou_tree, 0, 0, 5 );

	m_pou_text = new wxTextCtrl( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY );
	m_pou_text->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	m_pou_text->Hide();

	bSizer2->Add( m_pou_text, 0, 0, 5 );

	m_st_tool = new wxAuiToolBar( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_TB_GRIPPER|wxAUI_TB_HORZ_LAYOUT );
	m_st_tool->SetFont( wxFont( 10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	m_st_tool->Hide();

	m_st_tool_cursor = m_st_tool->AddTool( wxID_ANY, wxT("tool"), wxBitmap( cursor_xpm ), wxNullBitmap, wxITEM_NORMAL, wxT("tool"), wxEmptyString, NULL );

	m_st_tool->Realize();

	bSizer2->Add( m_st_tool, 0, 0, 5 );

	m_add_tool = new wxAuiToolBar( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_TB_GRIPPER|wxAUI_TB_HORZ_LAYOUT );
	m_add_tool->SetFont( wxFont( 10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	m_add_tool->Hide();

	m_add_tool_show = m_add_tool->AddTool( ID_ADD_SHOW, wxT("tool"), wxBitmap( show_code_xpm ), wxNullBitmap, wxITEM_NORMAL, wxT("View Code"), wxEmptyString, NULL );

	m_add_tool_compiler = m_add_tool->AddTool( ID_ADD_COMPILER, wxT("tool"), wxBitmap( compiler_xpm ), wxNullBitmap, wxITEM_NORMAL, wxT("Build"), wxEmptyString, NULL );

	m_add_tool->Realize();

	bSizer2->Add( m_add_tool, 0, 0, 5 );

	m_fbd_tool = new wxAuiToolBar( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_TB_GRIPPER|wxAUI_TB_HORZ_LAYOUT );
	m_fbd_tool->SetFont( wxFont( 10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	m_fbd_tool_cursor = m_fbd_tool->AddTool( ID_FBD_CURSOR, wxT("tool"), wxBitmap( cursor_xpm ), wxNullBitmap, wxITEM_RADIO, wxEmptyString, wxEmptyString, NULL );

	m_fbd_tool_move = m_fbd_tool->AddTool( ID_FBD_MOVE, wxT("tool"), wxBitmap( move_xpm ), wxNullBitmap, wxITEM_RADIO, wxEmptyString, wxEmptyString, NULL );

	m_fbd_tool_cmt = m_fbd_tool->AddTool( ID_FBD_CMT, wxT("tool"), wxBitmap( add_comment_xpm ), wxNullBitmap, wxITEM_RADIO, wxEmptyString, wxEmptyString, NULL );

	m_fbd_tool_var = m_fbd_tool->AddTool( ID_FBD_VAR, wxT("tool"), wxBitmap( add_variable_xpm ), wxNullBitmap, wxITEM_RADIO, wxEmptyString, wxEmptyString, NULL );

	m_fbd_tool_fb = m_fbd_tool->AddTool( ID_FBD_FB, wxT("tool"), wxBitmap( add_block_xpm ), wxNullBitmap, wxITEM_RADIO, wxEmptyString, wxEmptyString, NULL );

	m_fbd_tool_connect = m_fbd_tool->AddTool( ID_FBD_CONNECT, wxT("tool"), wxBitmap( add_connection_xpm ), wxNullBitmap, wxITEM_RADIO, wxEmptyString, wxEmptyString, NULL );

	m_fbd_tool->Realize();

	bSizer2->Add( m_fbd_tool, 0, 0, 5 );

	m_ld_tool = new wxAuiToolBar( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_TB_GRIPPER|wxAUI_TB_HORZ_LAYOUT );
	m_ld_tool->SetFont( wxFont( 10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	m_ld_tool_cursor = m_ld_tool->AddTool( ID_LD_CURSOR, wxT("tool"), wxBitmap( cursor_xpm ), wxNullBitmap, wxITEM_RADIO, wxEmptyString, wxEmptyString, NULL );

	m_ld_tool_move = m_ld_tool->AddTool( ID_LD_MOVE, wxT("tool"), wxBitmap( move_xpm ), wxNullBitmap, wxITEM_RADIO, wxEmptyString, wxEmptyString, NULL );

	m_ld_tool_cmt = m_ld_tool->AddTool( ID_LD_CMT, wxT("tool"), wxBitmap( add_comment_xpm ), wxNullBitmap, wxITEM_RADIO, wxEmptyString, wxEmptyString, NULL );

	m_ld_tool_power = m_ld_tool->AddTool( ID_LD_POWER, wxT("tool"), wxBitmap( add_powerrail_xpm ), wxNullBitmap, wxITEM_RADIO, wxEmptyString, wxEmptyString, NULL );

	m_ld_tool_coil = m_ld_tool->AddTool( ID_LD_COIL, wxT("tool"), wxBitmap( add_coil_xpm ), wxNullBitmap, wxITEM_RADIO, wxEmptyString, wxEmptyString, NULL );

	m_ld_tool_contact = m_ld_tool->AddTool( ID_LD_CONTACT, wxT("tool"), wxBitmap( add_contact_xpm ), wxNullBitmap, wxITEM_RADIO, wxEmptyString, wxEmptyString, NULL );

	m_ld_tool_var = m_ld_tool->AddTool( ID_LD_VAR, wxT("tool"), wxBitmap( add_variable_xpm ), wxNullBitmap, wxITEM_RADIO, wxEmptyString, wxEmptyString, NULL );

	m_ld_tool_fb = m_ld_tool->AddTool( ID_LD_FB, wxT("tool"), wxBitmap( add_block_xpm ), wxNullBitmap, wxITEM_RADIO, wxEmptyString, wxEmptyString, NULL );

	m_ld_tool_connect = m_ld_tool->AddTool( ID_LD_CONNECT, wxT("tool"), wxBitmap( add_connection_xpm ), wxNullBitmap, wxITEM_RADIO, wxEmptyString, wxEmptyString, NULL );

	m_ld_tool->Realize();

	bSizer2->Add( m_ld_tool, 0, 0, 5 );


	m_panel1->SetSizer( bSizer2 );
	m_panel1->Layout();
	bSizer2->Fit( m_panel1 );
	bSizer1->Add( m_panel1, 1, wxEXPAND|wxRIGHT, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();
	m_menubar = new wxMenuBar( 0 );
	m_menubar->SetFont( wxFont( 10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	m_menu_file = new wxMenu();
	wxMenuItem* m_menu_open;
	m_menu_open = new wxMenuItem( m_menu_file, ID_PRJ_OPEN, wxString( wxT("Open Project\tCtrl+O") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu_file->Append( m_menu_open );
	m_menu_open->Enable( false );

	wxMenuItem* m_menu_save;
	m_menu_save = new wxMenuItem( m_menu_file, ID_PRJ_SAVE, wxString( wxT("Save Project\tCtrl+S") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu_file->Append( m_menu_save );
	m_menu_save->Enable( false );

	wxMenuItem* m_menu_prj_add;
	m_menu_prj_add = new wxMenuItem( m_menu_file, ID_PRJ_ADD, wxString( wxT("&Add Project/Block/Program\tCtrl+A") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu_file->Append( m_menu_prj_add );

	wxMenuItem* m_menu_prj_close;
	m_menu_prj_close = new wxMenuItem( m_menu_file, wxID_ANY, wxString( wxT("Close Project") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu_file->Append( m_menu_prj_close );
	m_menu_prj_close->Enable( false );

	m_menu_file->AppendSeparator();

	wxMenuItem* m_menu_exit;
	m_menu_exit = new wxMenuItem( m_menu_file, ID_EXIT, wxString( wxT("E&xit\tAlt+F4") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu_file->Append( m_menu_exit );

	m_menubar->Append( m_menu_file, wxT("&File") );

	m_menu_view = new wxMenu();
	wxMenuItem* m_view_F3;
	m_view_F3 = new wxMenuItem( m_menu_view, ID_SHOW_F3, wxString( wxT("View project tree(On/Off)\tF3") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu_view->Append( m_view_F3 );

	wxMenuItem* m_view_F4;
	m_view_F4 = new wxMenuItem( m_menu_view, ID_SHOW_F4, wxString( wxT("View variables (On/Off)\tF4") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu_view->Append( m_view_F4 );

	wxMenuItem* m_view_F5;
	m_view_F5 = new wxMenuItem( m_menu_view, ID_SHOW_F5, wxString( wxT("View POU (On/Off)\tF5") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu_view->Append( m_view_F5 );

	wxMenuItem* m_view_F6;
	m_view_F6 = new wxMenuItem( m_menu_view, ID_SHOW_F6, wxString( wxT("Test\tF6") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu_view->Append( m_view_F6 );

	m_menubar->Append( m_menu_view, wxT("&View") );

	m_menu_tool = new wxMenu();
	wxMenuItem* m_1;
	m_1 = new wxMenuItem( m_menu_tool, wxID_ANY, wxString( wxT("MyMenuItem_1") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu_tool->Append( m_1 );

	wxMenuItem* m_2;
	m_2 = new wxMenuItem( m_menu_tool, wxID_ANY, wxString( wxT("MyMenuItem_2") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu_tool->Append( m_2 );

	m_menubar->Append( m_menu_tool, wxT("&Tools") );

	this->SetMenuBar( m_menubar );

	m_statusbar = this->CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );

	this->Centre( wxBOTH );

	// Connect Events
	m_prj_tree->Connect( wxEVT_GRID_SELECT_CELL, wxGridEventHandler( MyFrameFB::OnPrjSelectCell ), NULL, this );
	m_prj_tree->Connect( wxEVT_SIZE, wxSizeEventHandler( MyFrameFB::OnPrjSize ), NULL, this );
	m_pou_tree->Connect( wxEVT_ENTER_WINDOW, wxMouseEventHandler( MyFrameFB::OnPOUEnter ), NULL, this );
	m_pou_tree->Connect( wxEVT_LEAVE_WINDOW, wxMouseEventHandler( MyFrameFB::OnPOULeave ), NULL, this );
	m_pou_tree->Connect( wxEVT_COMMAND_TREE_BEGIN_DRAG, wxTreeEventHandler( MyFrameFB::onPOUBeginDrag ), NULL, this );
	m_pou_tree->Connect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( MyFrameFB::OnPOUTreeSelChanged ), NULL, this );
	this->Connect( m_st_tool_cursor->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrameFB::OnToolCursor ));
	this->Connect( m_ld_tool_cursor->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MyFrameFB::OnToolCursor ) );
}

MyFrameFB::~MyFrameFB()
{
	// Disconnect Events
	m_prj_tree->Disconnect( wxEVT_GRID_SELECT_CELL, wxGridEventHandler( MyFrameFB::OnPrjSelectCell ), NULL, this );
	m_prj_tree->Disconnect( wxEVT_SIZE, wxSizeEventHandler( MyFrameFB::OnPrjSize ), NULL, this );
	m_pou_tree->Disconnect( wxEVT_ENTER_WINDOW, wxMouseEventHandler( MyFrameFB::OnPOUEnter ), NULL, this );
	m_pou_tree->Disconnect( wxEVT_LEAVE_WINDOW, wxMouseEventHandler( MyFrameFB::OnPOULeave ), NULL, this );
	m_pou_tree->Disconnect( wxEVT_COMMAND_TREE_BEGIN_DRAG, wxTreeEventHandler( MyFrameFB::onPOUBeginDrag ), NULL, this );
	m_pou_tree->Disconnect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( MyFrameFB::OnPOUTreeSelChanged ), NULL, this );
	this->Disconnect( m_st_tool_cursor->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrameFB::OnToolCursor ));
	this->Disconnect( m_ld_tool_cursor->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MyFrameFB::OnToolCursor ) );

}

ConfigVarFB::ConfigVarFB( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetFont( wxFont( 11, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	m_text = new wxStaticText( this, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_text->Wrap( -1 );
	bSizer5->Add( m_text, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_grid_var = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_grid_var->CreateGrid( 5, 5 );
	m_grid_var->EnableEditing( true );
	m_grid_var->EnableGridLines( true );
	m_grid_var->EnableDragGridSize( false );
	m_grid_var->SetMargins( 0, 0 );

	// Columns
	m_grid_var->EnableDragColMove( false );
	m_grid_var->EnableDragColSize( true );
	m_grid_var->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_grid_var->EnableDragRowSize( true );
	m_grid_var->SetRowLabelSize( 1 );
	m_grid_var->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_grid_var->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer5->Add( m_grid_var, 0, wxALL, 5 );

	m_button = new wxButton( this, wxID_ANY, wxT("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_button, 0, wxALL|wxALIGN_RIGHT, 5 );


	this->SetSizer( bSizer5 );
	this->Layout();
	bSizer5->Fit( this );

	this->Centre( wxBOTH );
}

ConfigVarFB::~ConfigVarFB()
{
}

PrjAddFB::PrjAddFB( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetFont( wxFont( 11, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );

	wxFlexGridSizer* fgSizer;
	fgSizer = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer->SetFlexibleDirection( wxBOTH );
	fgSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_name = new wxStaticText( this, wxID_ANY, wxT("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_name->Wrap( -1 );
	fgSizer->Add( m_name, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );

	m_text_name = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	fgSizer->Add( m_text_name, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_language = new wxStaticText( this, wxID_ANY, wxT("Language"), wxDefaultPosition, wxDefaultSize, 0 );
	m_language->Wrap( -1 );
	fgSizer->Add( m_language, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );

	wxString m_choice_langChoices[] = { wxT("FBD"), wxT("LD"), wxT("ST") };
	int m_choice_langNChoices = sizeof( m_choice_langChoices ) / sizeof( wxString );
	m_choice_lang = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_langNChoices, m_choice_langChoices, 0 );
	m_choice_lang->SetSelection( 0 );
	fgSizer->Add( m_choice_lang, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer8->Add( fgSizer, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );

	m_file_name = new wxStaticText( this, wxID_ANY, wxT("File Name :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_file_name->Wrap( -1 );
	bSizer10->Add( m_file_name, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );

	m_file_set = new wxFilePickerCtrl( this, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("*.prj"), wxDefaultPosition, wxDefaultSize, wxFLP_OVERWRITE_PROMPT|wxFLP_SAVE|wxFLP_USE_TEXTCTRL );
	bSizer10->Add( m_file_set, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );


	bSizer8->Add( bSizer10, 0, wxEXPAND, 5 );

	m_staticline6 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer8->Add( m_staticline6, 0, wxTOP|wxEXPAND, 5 );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );

	m_button_ok = new wxButton( this, ID_B1, wxT("Ok"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_button_ok, 0, wxALL, 5 );

	m_button_cancel = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_button_cancel, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );


	bSizer8->Add( bSizer9, 0, wxALIGN_RIGHT, 5 );


	this->SetSizer( bSizer8 );
	this->Layout();
	bSizer8->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_button_ok->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PrjAddFB::onOK ), NULL, this );
	m_button_cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PrjAddFB::OnCANCEL ), NULL, this );
}

PrjAddFB::~PrjAddFB()
{
	// Disconnect Events
	m_button_ok->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PrjAddFB::onOK ), NULL, this );
	m_button_cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PrjAddFB::OnCANCEL ), NULL, this );

}

ObjPropsFB::ObjPropsFB( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetFont( wxFont( 10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );

	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 0, 2, 0, 0 );

	m_splitter = new wxSplitterWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_LIVE_UPDATE|wxSP_NOBORDER );
	m_splitter->Connect( wxEVT_IDLE, wxIdleEventHandler( ObjPropsFB::m_splitterOnIdle ), NULL, this );

	m_panel6 = new wxPanel( m_splitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( m_panel6, wxID_ANY, wxT("Library") ), wxVERTICAL );

	m_tree = new wxTreeCtrl( sbSizer1->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE|wxTR_HIDE_ROOT );
	sbSizer1->Add( m_tree, 1, wxEXPAND|wxTOP, 5 );


	m_panel6->SetSizer( sbSizer1 );
	m_panel6->Layout();
	sbSizer1->Fit( m_panel6 );
	m_panel7 = new wxPanel( m_splitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer151;
	bSizer151 = new wxBoxSizer( wxVERTICAL );

	m_text = new wxTextCtrl( m_panel7, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY );
	bSizer151->Add( m_text, 1, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 5 );


	m_panel7->SetSizer( bSizer151 );
	m_panel7->Layout();
	bSizer151->Fit( m_panel7 );
	m_splitter->SplitHorizontally( m_panel6, m_panel7, 240 );
	gSizer1->Add( m_splitter, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxHORIZONTAL );

	m_static_text1 = new wxStaticText( this, wxID_ANY, wxT("Name:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_static_text1->Wrap( -1 );
	bSizer17->Add( m_static_text1, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxRIGHT|wxLEFT, 5 );

	m_name = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( m_name, 1, wxALIGN_CENTER_VERTICAL|wxEXPAND|wxTOP|wxRIGHT|wxLEFT, 5 );


	bSizer16->Add( bSizer17, 0, wxEXPAND|wxTOP, 5 );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );

	m_static_text2 = new wxStaticText( this, wxID_ANY, wxT("Inputs:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_static_text2->Wrap( -1 );
	bSizer14->Add( m_static_text2, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 5 );

	wxArrayString m_choiceChoices;
	m_choice = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 60,-1 ), m_choiceChoices, 0 );
	m_choice->SetSelection( 0 );
	bSizer14->Add( m_choice, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 5 );


	bSizer16->Add( bSizer14, 0, wxEXPAND|wxTOP, 5 );

	m_staticline6 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer16->Add( m_staticline6, 0, wxEXPAND|wxTOP|wxBOTTOM, 5 );

	m_static_text3 = new wxStaticText( this, wxID_ANY, wxT("Preview"), wxDefaultPosition, wxDefaultSize, 0 );
	m_static_text3->Wrap( -1 );
	bSizer16->Add( m_static_text3, 0, wxRIGHT|wxLEFT, 5 );

	m_panel8 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE|wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer161;
	bSizer161 = new wxBoxSizer( wxVERTICAL );

	m_bitmap = new wxStaticBitmap( m_panel8, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer161->Add( m_bitmap, 1, wxALL|wxEXPAND, 5 );


	m_panel8->SetSizer( bSizer161 );
	m_panel8->Layout();
	bSizer161->Fit( m_panel8 );
	bSizer16->Add( m_panel8, 1, wxEXPAND|wxBOTTOM|wxRIGHT, 5 );


	gSizer1->Add( bSizer16, 1, wxEXPAND, 5 );


	bSizer11->Add( gSizer1, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxHORIZONTAL );

	m_button_ok = new wxButton( this, ID_B1, wxT("Ok"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( m_button_ok, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );

	m_button_cancel = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( m_button_cancel, 0, wxBOTTOM|wxRIGHT, 5 );


	bSizer11->Add( bSizer15, 0, wxALIGN_RIGHT|wxTOP, 5 );


	this->SetSizer( bSizer11 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_tree->Connect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( ObjPropsFB::OnPOUTreeSelChanged ), NULL, this );
	m_button_ok->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ObjPropsFB::onOK ), NULL, this );
	m_button_cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ObjPropsFB::OnCANCEL ), NULL, this );
}

ObjPropsFB::~ObjPropsFB()
{
	// Disconnect Events
	m_tree->Disconnect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( ObjPropsFB::OnPOUTreeSelChanged ), NULL, this );
	m_button_ok->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ObjPropsFB::onOK ), NULL, this );
	m_button_cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ObjPropsFB::OnCANCEL ), NULL, this );

}
