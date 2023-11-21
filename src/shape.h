/*
	Name:			shape.h
	Purpose:		Open-PLC Tools
	Author:			www.open-plc.com
	Created:		2023/10
	Modified by:
	RCS-ID:
	Copyright:		(c) Open-PLC
	Licence:		The MIT License (MIT)
*/


#ifndef __SHAPE__
#define __SHAPE__

#include <wx/wx.h>
#include "wx/graphics.h"
#include "wx/dcbuffer.h"
#include <wx/aui/aui.h>
#include <wx/aui/auibar.h>

//#include <vector>
//#include <iterator>

#include "gbl.h"


class Shape : public wxScrolledWindow
{
	private:
		DECLARE_EVENT_TABLE()

	protected:
        bool SHIFT_KEY, ALT_KEY, CTRL_KEY = false;
        //int  Win_PosX = 0;
        //int  Win_PosY = 0;

		wxPen p_pen;
		wxPoint start_pos, end_pos;
		//wxBufferedPaintDC dc_bg(void);

		void OnPaint( wxPaintEvent &event );
		void OnEraseBackground( wxEraseEvent &event );

		void OnLeftMouseDown( wxMouseEvent &event );
		void OnLeftMouseUp( wxMouseEvent &event );
		void OnLeftMouseDClick( wxMouseEvent &event );
		void OnRightMouseDown(wxMouseEvent &event);
		//void OnMouseMove( wxMouseEvent &event );
		void OnMiddleDown( wxMouseEvent &event );
		void OnMotion( wxMouseEvent &event );
		void OnMouseWheel( wxMouseEvent &event );

//void ew( wxMouseEvent& event );
//void lw( wxMouseEvent& event );

		void OnShapeEnter( wxMouseEvent &event );
		void OnShapeLeave( wxMouseEvent &event );


        //void OnKeyDown( wxKeyEvent &event );
        void OnKeyUp( wxKeyEvent &event );
        void OnChar( wxKeyEvent &event );

		//void OnSize( wxSizeEvent &event );

//void PaintObj( wxDC *dc );



    public:
        Shape( wxWindow      *parent,
               wxWindowID    id    = wxID_ANY,
               const wxPoint &pos  = wxDefaultPosition,
               const wxSize  &size = wxDefaultSize,
               long          style = wxNO_BORDER);

		wxAuiToolBar *m_fbd_tool;
		wxAuiToolBar *m_ld_tool;

		Tools_Type   m_tool;

        //Shape( wxWindow *parent, wxWindowID, const wxPoint &pos, const wxSize &size );
        //~Shape();

//wxTreeItemId pou_item_root, pou_item_prev;
std::vector <POU_Struct> *m_POU;


		std::vector<Shape_Struct> *shape_obj;
		int block_id;
		wxString block_name;


        //std::vector <Shape_Struct> shape_obj;
        std::vector <Shape_Struct> make_shape_obj;                  // work vector; make new object
        std::vector <Shape_Struct> *Shape_Ptr = &make_shape_obj;    // for pointer function (callback)

        std::vector <Link_Point_Struct> link_point;
        std::vector <Link_Point_Struct> make_link_point;                    // work vector; make new link points
        std::vector <Link_Point_Struct> *Link_Point_Ptr = &make_link_point; // for pointer function (callback)

        std::vector <IN_OUT_Decode_Struct> IN_OUT_Decode_Vect;
        std::vector <IN_OUT_Decode_Struct> *IN_OUT_Decode_Ptr = &IN_OUT_Decode_Vect; // for pointer function (callback)

//        // Functions as pointer
//        static void IN_OUT_Decode( std::string, // POU_InOut
//                                   std::vector <IN_OUT_Decode_Struct>& );
//
//        static void Make_Obj( int,  wxString, // Block_ID, obj_name
//                               std::vector <IN_OUT_Decode_Struct>&,
//                               std::vector <Shape_Struct>&,
//                               std::vector <Link_Point_Struct>& );



};

#endif // __SHAPE__
