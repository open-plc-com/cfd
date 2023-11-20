///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/statline.h>
#include "shape.h"
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/aui/auibook.h>
#include <wx/stc/stc.h>
#include <wx/toolbar.h>
#include <wx/grid.h>
#include <wx/treectrl.h>
#include <wx/textctrl.h>
#include <wx/aui/aui.h>
#include <wx/aui/auibar.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/valtext.h>
#include <wx/choice.h>
#include <wx/filepicker.h>
#include <wx/statbox.h>
#include <wx/splitter.h>
#include <wx/statbmp.h>

///////////////////////////////////////////////////////////////////////////

#define ID_GRID_ADD 1000
#define ID_GRID_DEL 1001
#define ID_GRID_UP 1002
#define ID_GRID_DOWN 1003
#define ID_PRJ_ADD 1004
#define ID_PRJ_DEL 1005
#define ID_PRJ_UP 1006
#define ID_PRJ_DOWN 1007
#define ID_PRJ_EDIT 1008
#define ID_ADD_SHOW 1009
#define ID_ADD_COMPILER 1010
#define ID_FBD_CURSOR 1011
#define ID_FBD_MOVE 1012
#define ID_FBD_CMT 1013
#define ID_FBD_VAR 1014
#define ID_FBD_FB 1015
#define ID_FBD_CONNECT 1016
#define ID_LD_CURSOR 1017
#define ID_LD_MOVE 1018
#define ID_LD_CMT 1019
#define ID_LD_POWER 1020
#define ID_LD_COIL 1021
#define ID_LD_CONTACT 1022
#define ID_LD_VAR 1023
#define ID_LD_FB 1024
#define ID_LD_CONNECT 1025
#define ID_PRJ_OPEN 1026
#define ID_PRJ_SAVE 1027
#define ID_EXIT 1028
#define ID_SHOW_F3 1029
#define ID_SHOW_F4 1030
#define ID_SHOW_F5 1031
#define ID_SHOW_F6 1032
#define ID_B1 1033

///////////////////////////////////////////////////////////////////////////////
/// Class MyFrameFB
///////////////////////////////////////////////////////////////////////////////
class MyFrameFB : public wxFrame
{
	private:

	protected:
		wxAuiNotebook* m_nb_shape;
		wxPanel* m_panel2;
		wxStaticText* m_shape_name;
		wxStaticLine* m_staticline1;
		wxAuiNotebook* m_nb_edit;
		wxPanel* m_panel3;
		wxStaticText* m_edit_name;
		wxStaticLine* m_staticline3;
		wxStyledTextCtrl* m_edit;
		wxAuiNotebook* m_nb_grid;
		wxPanel* m_panel4;
		wxToolBar* m_grid_tool;
		wxToolBarToolBase* m_grid_add;
		wxToolBarToolBase* m_grid_del;
		wxToolBarToolBase* m_grid_up;
		wxToolBarToolBase* m_grid_down;
		wxStaticLine* m_staticline5;
		wxGrid* m_grid;
		wxAuiNotebook* m_nb_prj;
		wxPanel* m_panel5;
		wxToolBar* m_prj_tool;
		wxToolBarToolBase* m_prj_add;
		wxToolBarToolBase* m_prj_del;
		wxToolBarToolBase* m_prj_up;
		wxToolBarToolBase* m_prj_down;
		wxToolBarToolBase* m_prj_edit;
		wxStaticLine* m_staticline51;
		wxGrid* m_prj_tree;
		wxTreeCtrl* m_pou_tree;
		wxTextCtrl* m_pou_text;
		wxAuiToolBar* m_st_tool;
		wxAuiToolBarItem* m_st_tool_cursor;
		wxAuiToolBarItem* m_add_tool_show;
		wxAuiToolBarItem* m_add_tool_compiler;
		wxAuiToolBarItem* m_fbd_tool_cursor;
		wxAuiToolBarItem* m_fbd_tool_move;
		wxAuiToolBarItem* m_fbd_tool_cmt;
		wxAuiToolBarItem* m_fbd_tool_var;
		wxAuiToolBarItem* m_fbd_tool_fb;
		wxAuiToolBarItem* m_fbd_tool_connect;
		wxAuiToolBarItem* m_ld_tool_cursor;
		wxAuiToolBarItem* m_ld_tool_move;
		wxAuiToolBarItem* m_ld_tool_cmt;
		wxAuiToolBarItem* m_ld_tool_power;
		wxAuiToolBarItem* m_ld_tool_coil;
		wxAuiToolBarItem* m_ld_tool_contact;
		wxAuiToolBarItem* m_ld_tool_var;
		wxAuiToolBarItem* m_ld_tool_fb;
		wxAuiToolBarItem* m_ld_tool_connect;
		wxMenuBar* m_menubar;
		wxMenu* m_menu_file;
		wxMenu* m_menu_view;
		wxMenu* m_menu_tool;
		wxStatusBar* m_statusbar;

		// Virtual event handlers, override them in your derived class
		virtual void OnPrjSelectCell( wxGridEvent& event ) { event.Skip(); }
		virtual void OnPrjSize( wxSizeEvent& event ) { event.Skip(); }
		virtual void OnPOUEnter( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnPOULeave( wxMouseEvent& event ) { event.Skip(); }
		virtual void onPOUBeginDrag( wxTreeEvent& event ) { event.Skip(); }
		virtual void OnPOUTreeSelChanged( wxTreeEvent& event ) { event.Skip(); }
		virtual void OnToolCursor( wxCommandEvent& event ) { event.Skip(); }


	public:
		wxPanel* m_panel1;
		Shape *m_shape;
		wxAuiToolBar* m_add_tool;
		wxAuiToolBar* m_fbd_tool;
		wxAuiToolBar* m_ld_tool;

		MyFrameFB( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,400 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MyFrameFB();

};

///////////////////////////////////////////////////////////////////////////////
/// Class ConfigVarFB
///////////////////////////////////////////////////////////////////////////////
class ConfigVarFB : public wxDialog
{
	private:

	protected:
		wxStaticText* m_text;
		wxGrid* m_grid_var;
		wxButton* m_button;

	public:

		ConfigVarFB( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxCAPTION|wxCLOSE_BOX|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxSTAY_ON_TOP|wxSYSTEM_MENU );

		~ConfigVarFB();

};

///////////////////////////////////////////////////////////////////////////////
/// Class PrjAddFB
///////////////////////////////////////////////////////////////////////////////
class PrjAddFB : public wxDialog
{
	private:

	protected:
		wxStaticLine* m_staticline6;
		wxButton* m_button_ok;
		wxButton* m_button_cancel;

		// Virtual event handlers, override them in your derived class
		virtual void onOK( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCANCEL( wxCommandEvent& event ) { event.Skip(); }


	public:
		wxStaticText* m_name;
		wxTextCtrl* m_text_name;
		wxStaticText* m_language;
		wxChoice* m_choice_lang;
		wxStaticText* m_file_name;
		wxFilePickerCtrl* m_file_set;

		PrjAddFB( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE|wxSTAY_ON_TOP );

		~PrjAddFB();

};

///////////////////////////////////////////////////////////////////////////////
/// Class ObjPropsFB
///////////////////////////////////////////////////////////////////////////////
class ObjPropsFB : public wxDialog
{
	private:

	protected:
		wxSplitterWindow* m_splitter;
		wxPanel* m_panel6;
		wxTreeCtrl* m_tree;
		wxPanel* m_panel7;
		wxTextCtrl* m_text;
		wxStaticText* m_static_text3;
		wxPanel* m_panel8;
		wxStaticBitmap* m_bitmap;
		wxButton* m_button_ok;
		wxButton* m_button_cancel;

		// Virtual event handlers, override them in your derived class
		virtual void OnPOUTreeSelChanged( wxTreeEvent& event ) { event.Skip(); }
		virtual void OnChoise( wxCommandEvent& event ) { event.Skip(); }
		virtual void onOK( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCANCEL( wxCommandEvent& event ) { event.Skip(); }


	public:
		wxStaticText* m_static_text1;
		wxTextCtrl* m_name;
		wxStaticText* m_static_text2;
		wxChoice* m_choice;
		wxStaticLine* m_staticline6;

		ObjPropsFB( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 320,240 ), long style = wxDEFAULT_DIALOG_STYLE );

		~ObjPropsFB();

		void m_splitterOnIdle( wxIdleEvent& )
		{
			m_splitter->SetSashPosition( 240 );
			m_splitter->Disconnect( wxEVT_IDLE, wxIdleEventHandler( ObjPropsFB::m_splitterOnIdle ), NULL, this );
		}

};

