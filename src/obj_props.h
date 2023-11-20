/*
    Name:        obj_props.h
    Purpose:     Open-PLC Tools
    Author:      www.open-plc.com
    Created:     2023/11
    Modified by:
    RCS-ID:
    Copyright:   (c) Open-PLC
    Licence:     The MIT License (MIT)
*/


#ifndef __OBJ_PROPS__
#define __OBJ_PROPS__

#include <wx/wx.h>
#include "myframe_fb.h"
#include "gbl.h"


// ============================================================================
class ObjProps : public ObjPropsFB
// ============================================================================
{
    private:
        DECLARE_EVENT_TABLE()

    protected:
        int SEL_POU;
        wxMemoryDC mem_dc;
        wxBitmap bm;

//		void onOK( wxCommandEvent &event );
//		void OnCANCEL( wxCommandEvent &event );
		void OnChar( wxKeyEvent &event );

    public:
        ObjProps( wxWindow       *parent,
                  wxWindowID     id = wxID_ANY,
                  const wxString &title = wxEmptyString,
                  const wxPoint  &pos = wxDefaultPosition,
//                const wxSize   &size = wxDefaultSize,
                  const wxSize   &size  = wxSize( 800, 600 ),
//                long           style = wxDEFAULT_DIALOG_STYLE );
                  long           style = wxCAPTION |
                                         wxCLOSE_BOX |
                                         //wxMAXIMIZE_BOX |
                                         //wxRESIZE_BORDER |
                                         //wxSTAY_ON_TOP |
                                         wxSYSTEM_MENU );
        ~ObjProps();

		void Fill_POU();
		void OnPOUTreeSelChanged( wxTreeEvent &event ); // virtual
        void onOK( wxCommandEvent &event );             // Virtual
        void OnCANCEL( wxCommandEvent &event );         // Virtual
		void OnChoise( wxCommandEvent& event );         // Virtual

        wxTreeItemId			pou_item_root, pou_item_prev;
		std::vector<POU_Struct>	*m_pou;

		// point to vectors (myframe.h)
		std::vector <IN_OUT_Decode_Struct>	*IN_OUT_Decode_Ptr;	// = &IN_OUT_Decode_Vect
		std::vector <Shape_Struct>			*Shape_Ptr;			// = &Shape_Ptr
		std::vector <Link_Point_Struct>		*Link_Point_Ptr;	// = &Link_Point_Ptr

		// pointer functions (myframe.cpp)
		void (*IN_OUT_Decode)( std::string, std::vector <IN_OUT_Decode_Struct>& );
		void (*Make_Obj)( int, wxString,
						std::vector <IN_OUT_Decode_Struct>&,
						std::vector <Shape_Struct>&,
						std::vector <Link_Point_Struct>& );

		bool			ON_OK = false;
		unsigned int	Block_ID;
		wxString		Block_Name;
		wxString		obj_name;
};
// ============================================================================

#endif // __OBJ_PROPS__
