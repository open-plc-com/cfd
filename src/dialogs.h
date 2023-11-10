/*
    Name:        dialogs.h
    Purpose:     Open-PLC Tools
    Author:      www.open-plc.com
    Created:     2023/10
    Modified by:
    RCS-ID:
    Copyright:   (c) Open-PLC
    Licence:     The MIT License (MIT)
*/


#ifndef __DIALOGS__
#define __DIALOGS__

#include <wx/wx.h>
#include "myframe_fb.h"


class PrjAdd : public PrjAddFB
{
    private:
        DECLARE_EVENT_TABLE()

    protected:
        long l;
        std::vector<long> lval;
        std::vector<long> nval;

        void onOK( wxCommandEvent &event );     // Virtual
        void OnCANCEL( wxCommandEvent &event ); // Virtual
        void OnChar( wxKeyEvent &event );

    public:
        PrjAdd( wxWindow       *parent,
                wxWindowID     id = wxID_ANY,
                const wxString &title = wxEmptyString,
                const wxPoint  &pos = wxDefaultPosition,
                const wxSize   &size = wxDefaultSize,
                long           style = wxDEFAULT_DIALOG_STYLE );
        ~PrjAdd();

        bool ON_OK = false;
        bool PRJ_FILE_SELECT = false;
        int ReturnNn = 0;
        wxGrid *grid = 0;
        std::vector<POU_Struct> *m_pou;
        //wxString BlockType = wxEmptyString;
};

#endif // __DIALOGS__
