/*
    Name:        var_props.h
    Purpose:     Open-PLC Tools
    Author:      www.open-plc.com
    Created:     2023/11
    Modified by:
    RCS-ID:
    Copyright:   (c) Open-PLC
    Licence:     The MIT License (MIT)
*/


#ifndef __VAR_PROPS__
#define __VAR_PROPS__

#include <wx/wx.h>
#include "gbl.h"
#include "msg.h"
#include "myframe_fb.h"
#include "var_props.h"


// ============================================================================
class VarProps : public VarPropsFB
// ============================================================================
{
    private:
        DECLARE_EVENT_TABLE()

    protected:
        //int SEL_POU;
        wxMemoryDC dc;
        wxBitmap bm;

		//void onOK( wxCommandEvent &event );
		//void OnCANCEL( wxCommandEvent &event );
		void OnChar( wxKeyEvent &event );

    public:
        VarProps( wxWindow       *parent,
                  wxWindowID     id = wxID_ANY,
                  const wxString &title = wxEmptyString,
                  const wxPoint  &pos = wxDefaultPosition,
//                const wxSize   &size = wxDefaultSize,
                  const wxSize   &size  = wxSize( 340, 340 ),
//                long           style = wxDEFAULT_DIALOG_STYLE );
                  long           style = wxCAPTION |
                                         wxCLOSE_BOX |
                                         //wxMAXIMIZE_BOX |
                                         //wxRESIZE_BORDER |
                                         //wxSTAY_ON_TOP |
                                         wxSYSTEM_MENU );
        ~VarProps();

		//void Fill_POU();
		//void OnPOUTreeSelChanged( wxTreeEvent &event ); // virtual
		void Preview();
		void OnListBox( wxCommandEvent &event );
        void onOK( wxCommandEvent &event );             // Virtual
        void OnCANCEL( wxCommandEvent &event );         // Virtual
		void OnChoice( wxCommandEvent &event );         // Virtual

        //wxTreeItemId			pou_item_root, pou_item_prev;
		//std::vector<POU_Struct>	*m_pou;

		// point to vectors (myframe.h)
		//std::vector <IN_OUT_Decode_Struct>	*IN_OUT_Decode_Ptr;	// = &IN_OUT_Decode_Vect
		//std::vector <Shape_Struct>			*Shape_Ptr;			// = &Shape_Ptr
		//std::vector <Link_Point_Struct>		*Link_Point_Ptr;	// = &Link_Point_Ptr

		// pointer functions (myframe.cpp)
//		void (*IN_OUT_Decode)( std::string, std::vector <IN_OUT_Decode_Struct>& );
//		void (*Make_Obj)( int, wxString,
//						std::vector <IN_OUT_Decode_Struct>&,
//						std::vector <Shape_Struct>&,
//						std::vector <Link_Point_Struct>& );

		bool			ON_OK = false;
		unsigned int	Block_ID;
		wxString		Block_Name;

wxArrayString arr_s;

		//wxString		obj_name;
};
// ============================================================================


#endif // __VAR_PROPS__
