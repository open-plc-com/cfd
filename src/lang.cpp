/*
    Name:        lang.cpp
    Purpose:     Open-PLC Tools
    Author:      www.open-plc.com
    Created:     2023/11
    Modified by:
    RCS-ID:
    Copyright:   (c) Open-PLC
    Licence:     The MIT License (MIT)
*/


#include <vector>
#include "myframe.h"
#include "myframe_fb.h"


// ============================================================================
void MyFrame::LangInit()
// ============================================================================
{

	LANG = wxLocale::GetSystemLanguage();
	//LANG = -1;
//printf("lang=%d\n", LANG );

	if( LANG == wxLANGUAGE_RUSSIAN_RUSSIA )
	{
		int menu_item;

		menu_item = m_menubar->FindMenuItem( wxT( "&File" ), wxT( "Exit\tAlt+F4" ) );
//printf( "Lang: menu_item=%d\n", menu_item );

		//m_menubar->SetLabel( menu_item, MSG_004 );

		//menu_item = m_menubar->FindMenu( wxT( "&File" ) );
		//m_menubar->SetMenuLabel( menu_item, MSG_003 );

		//menu_item = m_menubar->FindMenu( wxT( "&View" ) );
		//m_menubar->SetMenuLabel( menu_item, MSG_005 );

		//m_shape_name->SetLabel( MSG_002 ); // Shape

	}
}
