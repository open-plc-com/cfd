/*
    Name:           main.cpp
    Purpose:        Open-PLC Tools
    Author:         www.open-plc.com
    Created:        20YY/MM
    Modified by:
    RCS-ID:
    Copyright:      (c) Open-PLC
    Licence:        The MIT License (MIT)
*/


#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "wx/wxprec.h"
#include <wx/txtstrm.h>

#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/file.h>
#include <wx/xml/xml.h>
#include <wx/grid.h>
#include <wx/mstream.h>
#include <wx/config.h>
#include <wx/socket.h>
#include <wx/textfile.h>
#include <wx/stdpaths.h>
#include <wx/dir.h>
#include <wx/aui/auibook.h>
#include "wx/generic/gridctrl.h"

//#ifdef WIN32
//#include <windows.h>
//#endif

#include "msg.h"
#include "gbl.h"
#include "myframe.h"

class MyFrame;

class my : public wxApp
{
    public:
        bool    OnInit();
        MyFrame *frame;
};

IMPLEMENT_APP( my )

bool my::OnInit()
{

    #ifdef WIN32
        BOOL chk = AllocConsole();
        if (chk)
        {
            freopen( "CONOUT$", "w", stdout );
        }
    #endif

    wxImage::AddHandler( new wxXPMHandler );
    wxImage::AddHandler( new wxPNGHandler );
    frame = new MyFrame( ( wxFrame* )NULL, -1, MSG_001 );
    frame->Show( TRUE );
    return true;
}
