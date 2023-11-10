/*
	Name:			myframe.h
	Purpose:		Open-PLC Tools
	Author:			www.open-plc.com
	Created:		20YY/MM
	Modified by:
	RCS-ID:
	Copyright:		(c) Open-PLC
	Licence:		The MIT License (MIT)
*/


#ifndef __MYFRAME__
#define __MYFRAME__

//#pragma warning(disable : 4018)
//#pragma warning(disable : 4663)


#include "myframe_fb.h"
#include "gbl.h"
#include "msg.h"
#include "dialogs.h"
#include "obj_props.h"


// ============================================================================
class MyFrame : public MyFrameFB
// ============================================================================
{
    private:
        DECLARE_EVENT_TABLE()
        wxAuiManager m_mgr1;

    protected:
        //enum MenuIDs
        //{
            //MENU_ID_CONTEXT_1 = 11001,
            //MENU_ID_CONTEXT_2,
            //MENU_ID_CONTEXT_3,
        //};

        int  Menu_Select;
        int  Select_Row = 0;
        int  Block_ID   = -1;
        bool Start      = true;

        bool SHIFT_KEY, ALT_KEY, CTRL_KEY = false;
        //bool m_POU_Select = false;
        //bool m_PRJ_Select = false;

        void Init( void );
        void LangInit();
        void Init_POU_Tree();
        int  PathInit( void );
        void WriteCfg();
        void ReadCfg();
        void WritePrj();
        int  ReadPrj();

        void OnF3( wxCommandEvent &event );
        void OnF4( wxCommandEvent &event );
        void OnF5( wxCommandEvent &event );
        void OnF6( wxCommandEvent &event );
        //void OnF12( wxCommandEvent &event );

        void OnPrjAdd( wxCommandEvent &event );
        void OnPrjOpen( wxCommandEvent &event );
        void OnPrjSave( wxCommandEvent &event );
        void OnPrjDel( wxCommandEvent &event );
        void OnPrjUp( wxCommandEvent &event );
        void OnPrjDown( wxCommandEvent &event );
        //void OnPrjEdit( wxCommandEvent &event );

        void OnPrjSelectCell( wxGridEvent &event );
        void OnPrjMenuSelect( wxCommandEvent &event );
        void OnPrjSize( wxSizeEvent &event );

        void OnMaxSize( wxMaximizeEvent &event ); // virtual
        void OnSize( wxSizeEvent &event );        // virtual
        void OnMove( wxMoveEvent &event );        // virtual

        void OnPOUEnter( wxMouseEvent& event ); // virtual
        void OnPOULeave( wxMouseEvent& event ); // virtual
        void onPOUBeginDrag( wxTreeEvent& event ); // virtual
        void OnPOUTreeSelChanged( wxTreeEvent &event ); // virtual

        void OnChar( wxKeyEvent &event );

        void OnExit( wxCommandEvent &event );

    public:
        MyFrame( wxWindow       *parent,
                 wxWindowID     id     = wxID_ANY,
                 const wxString &title = wxEmptyString,
                 const wxPoint  &pos   = wxDefaultPosition,
                 const wxSize   &size  = wxSize( 800, 600 ),
                 long           style  = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL );

        ~MyFrame();

        wxString PRJ_NAME  = wxEmptyString;
        wxString PRJ_FILE  = wxEmptyString;
        wxString EXEC_PATH = wxEmptyString;
        wxString DATA_DIR  = wxEmptyString;
        wxString WORK_PATH = wxEmptyString;
        wxString S_NAME    = wxEmptyString;
        wxString S_EXT     = wxEmptyString;
        wxChar   PATH_SEP  = 0;

        bool Win_MaxSize = false;
        int  Win_PosX    = 0;
        int  Win_PosY    = 0;
        int  Win_SizeX   = 0;
        int  Win_SizeY   = 0;
		int  Display_Resolution;

        unsigned int LANG;
		bool PRJ_CHANGED = false;
		//int PRJ_SEL_ITEM = -1;
        //unsigned int SCALE;
        //unsigned int PAPE_TYPE; // 0=A0; 1=A1; 2=A2; 3=A3; 4=A4
        //unsigned int DPI = 2400;

        // POU tree
        struct POU_Struct POU_Tree;

		wxTreeItemId pou_item_root, pou_item_prev;
		std::vector <POU_Struct> m_POU;

		std::vector <Shape_Struct> shape_obj;
		std::vector <Shape_Struct> make_shape_obj;					// work vector; make new object
		std::vector <Shape_Struct> *Shape_Ptr = &make_shape_obj;	// for pointer function (callback)

		std::vector <Link_Point_Struct> link_point;
		std::vector <Link_Point_Struct> make_link_point;					// work vector; make new link points
		std::vector <Link_Point_Struct> *Link_Point_Ptr = &make_link_point;	// for pointer function (callback)

		std::vector <IN_OUT_Decode_Struct> IN_OUT_Decode_Vect;
		std::vector <IN_OUT_Decode_Struct> *IN_OUT_Decode_Ptr = &IN_OUT_Decode_Vect; // for pointer function (callback)

		// Functions as pointer
		static void IN_OUT_Decode( std::string, // POU_InOut
								   std::vector <IN_OUT_Decode_Struct>& );

		static void Make_Obj( int,  wxString, // Block_ID, obj_name
							   std::vector <IN_OUT_Decode_Struct>&,
							   std::vector <Shape_Struct>&,
							   std::vector <Link_Point_Struct>& );
};
// ============================================================================


// ============================================================================
class GridBitmap : public wxGridCellStringRenderer
// ============================================================================
{
    public:
        wxBitmap bitmap;
        GridBitmap( wxBitmap bm ) { bitmap = bm; }

        void Draw( wxGrid         &grid,
                   wxGridCellAttr &attr,
                   wxDC           &dc,
                   const wxRect   &rect,
                   int            row,
                   int            col,
                   bool           isSelected )
                 {
                     wxGridCellStringRenderer::Draw( grid, attr, dc, rect, row, col, isSelected );
                     dc.DrawBitmap( bitmap, rect.x, rect.y );
                 }
};
// ============================================================================


#endif // __MYFRAME__

//#pragma warning(default : 4018)
//#pragma warning(default : 4663)
