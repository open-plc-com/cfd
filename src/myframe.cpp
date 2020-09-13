/*
	Name:
	Purpose:
	Author:			www.open-plc.com
	Created:		202x/xx
	Modified by:
	RCS-ID:
	Copyright:		(c) Open-PLC
	Licence:		The MIT License (MIT)
*/


#include "myframe.h"
#include "dev.xpm"

#include "gw.xpm"
#include "dev_20.xpm"
#include "c_20_0.xpm"
#include "c_20_1.xpm"
#include "c_20_2.xpm"
#include "c_20_3.xpm"
#include "c_20_4.xpm"
#include "c_20_5.xpm"
#include "l_green_18.xpm"
#include "l_red_18.xpm"

//#include "connect.xpm"
//#include "disconnect.xpm"
//#include "pw_g.xpm"
//#include "pw_r.xpm"
#include "empty.xpm"
//#include "exclamation.xpm"

//#include "set_com.cpp"
#include "grid_dev.cpp"


//#include "set_uart1.cpp"
//#include "myframe_config.cpp"
//#include "files.cpp"
//#include "new_prj.cpp"
//#include "myframe_tools_events.cpp"
#include "myframe_virtual_events.cpp"
//#include "fw_gen.cpp"

//#include "read_com.cpp"
//#include "write_com.cpp"


// ===========================================================================
// ===                            MyFrame                                  ===
// ===========================================================================
MyFrame::MyFrame( wxWindow *parent,
// ===========================================================================
				  wxWindowID		 id,
				  const wxString	&title,
				  const wxPoint		&pos,
				  const wxSize		&size,
				  long style )
		: MyFrameFB( parent, id, title, pos, size, style )
{
	int			x, y, m;
	wxString	s;

	SetIcon( wxIcon( dev_xpm ) );	// Set Icon
	_log = m_log;

srand( ( unsigned ) time( NULL ) );

//FW_SN	 = rand() << 16;
//FW_SN	|= rand();;

//s.Printf( wxT( "FW_SN=%u\n" ), FW_SN );
//_log->AppendText( s );

//	if( OnPathInit() )
//	{
//		Close();
//	}

	GetSize( &x, &y );
	SetMinSize( wxSize( x, y ) );
	SetMaxSize( wxSize( ( x + 20 ), ( y + 20 ) ) );
	Fit();
	SetSize( wxSize( x, y ) );
	SetMaxSize( wxSize( -1, -1 ) );

Init_Grid_Dev();

//	Disable_Config();
//	Clear_Project();

//_log->AppendText( s );

//c_grid = new wxGrid( this, wxID_ANY ); //, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );


m_auinotebook->RemovePage( m_auinotebook->GetPageIndex( m_v ) );
m_auinotebook->SetSelection( m_auinotebook->GetPageIndex( m_device_panel ) );



m_COM_Text->Show( false );
m_COM_choice->Show( false );
m_com_bitmap->Show( false );
//m_tool_run->Show( false );
//ID_TOOL_RUN
m_tool_data->SetToolNormalBitmap( ID_TOOL_RUN, empty_xpm );
m_tool_data->EnableTool( ID_TOOL_RUN, false );





	// Set grid

m_grid->SetColMinimalAcceptableWidth( 0 );
m_grid->SetRowMinimalAcceptableHeight( 0 );
//m_grid->SetRowLabelSize( 0 );
//m_grid->SetColLabelSize( 0 );
m_grid->SetDefaultCellBackgroundColour( m_config_panel->GetBackgroundColour() );

//*

//	m_grid->SetRowLabelSize( 1 );
	m_grid->SetRowLabelSize( 30 );
	m_grid->SetColLabelSize( 20 );
	m_grid->DisableDragRowSize();
	m_grid->SetDefaultCellBackgroundColour( m_config_panel->GetBackgroundColour() );
	m_grid->EnableDragGridSize( false );
	m_grid->EnableDragColSize( false );

	m_grid->AppendCols( 6 );
	m_grid->AppendRows( 7 );

	m_grid->SetColLabelValue( 0, wxEmptyString );
	//m_grid->SetColLabelValue( 0, wxT( "Name" ) );
	m_grid->SetColLabelValue( 1, wxT( "Value" ) );
	//m_grid->SetColLabelValue( 1, wxT( "" ) );
	m_grid->SetColLabelValue( 2, wxT( "Type" ) );
	m_grid->SetColLabelValue( 3, wxT( "Port" ) );
	m_grid->SetColLabelValue( 4, wxT( "Comment" ) );
	m_grid->SetColLabelValue( 5, wxT( "Sync" ) );
	//m_grid->SetColLabelValue( 5, wxT( "" ) );

	m_grid->SetColSize( 0, 20 );
	//m_grid->SetColSize( 1, 0 );
	m_grid->SetColSize( 1, 100 );
	//m_grid->SetColSize( 1, 20 );
	m_grid->SetColSize( 2, 180 );
	m_grid->SetColSize( 3, 60 );
	m_grid->SetColSize( 4, 400 );
	//m_grid->SetColSize( 5, 20 );
	m_grid->SetColSize( 5, 100 );

	//m_grid->SetRowSize( 1, 0 );
	//m_grid->SetRowSize( 2, 0 );
	//m_grid->SetRowSize( 3, 0 );
	//m_grid->SetRowSize( 4, 0 );
	//m_grid->SetRowSize( 5, 0 );
	//m_grid->SetRowSize( 6, 0 );

	wxGridCellAttr *pAttr = new wxGridCellAttr;
	pAttr->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	m_grid->SetColAttr( 0, pAttr );
	m_grid->SetColAttr( 1, pAttr );
	m_grid->SetColAttr( 2, pAttr );
	m_grid->SetColAttr( 3, pAttr );
	m_grid->SetColAttr( 4, pAttr );
	m_grid->SetColAttr( 5, pAttr );


m_grid->SetCellRenderer(0, 0, new myImageGridCellRenderer(c_20_0_xpm));
m_grid->SetCellRenderer(1, 0, new myImageGridCellRenderer(c_20_4_xpm));
m_grid->SetCellRenderer(2, 0, new myImageGridCellRenderer(c_20_1_xpm));
m_grid->SetCellRenderer(3, 0, new myImageGridCellRenderer(c_20_2_xpm));
m_grid->SetCellRenderer(4, 0, new myImageGridCellRenderer(c_20_3_xpm));



m_grid->SelectRow( 3 );
//m_auinotebook->SetSelection( 0 );



//*/


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// test ???
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


	// Show/Hide tools
	// ---------------------------------------------------------------------------

//m_main_tool->Hide();
//m_tool_data->Hide();
//m_staticline1->Show( false );

	// Show/Hide sizers
	// ---------------------------------------------------------------------------

	// Interfaces
	// ----------

//	sbSizerInterfaces->Show( false );
	sbSizerSerial->Show( false );
	m_tool_UART->Show( false );
	m_check_UART->Show( false );
	m_check_USB_VCP->Show( true );
	m_check_USB_console->Show( false );
	sbSizerCAN->Show( false );
	sbSizerEth->Show( false );

//sbSizerSerial->RecalcSizes();
//sbSizerInterfaces->RecalcSizes();


	// Indicators
	// ----------

	sbSizerIndicators->Show( false );
//	sbSizerLED->Show( true );
//	m_check_PC13->Show( true );

//	sbSizerDisplayI2C->Show( false );
//	m_check_LCD1602->Show( true );
//	m_check_8574->Show( true );
//	m_check_8574A->Show( true );
//	m_check_SSD1306->Show( false );

//	m_staticline2->Show( true );
//	m_staticline12->Show( true );
//	m_staticline13->Show( true );
//	m_staticline14->Show( true );
//	m_staticline9->Show( true );
//	m_staticline10->Show( true );
//	m_staticline11->Show( true );
//	m_staticline14->Show( true );

	// Disable lines DS1306
//	m_staticline5->Show( false );
//	m_staticline9->Show( false );
//	m_staticline10->Show( false );
//	m_staticline14->Show( false );

//sbSizerIndicators->RecalcSizes();

	// Sensors
	// -------

//	sbSizerSensors->Show( false );
//	m_check_BME280->Show( false );
	m_check_BH1750->Show( false );
	m_check_CCS811->Show( false );
	m_check_EC11->Show( false );

//sbSizerSensors->RecalcSizes();

	// System

//	sbSizerSystem->Show( false );
//	m_toolBarSystem->Show( true );
//	m_check_WatchDog->Show( false );
	m_check_MCO->Show( false );
	m_text_ibt_fix_time->Show( false );
	m_ibt_fix_time->Show( false );
	m_check_Timer->Show( false );

sbSizerSerial->RecalcSizes();
sbSizerInterfaces->RecalcSizes();
sbSizerSystem->RecalcSizes();
sbSizerSensors->RecalcSizes();
sbSizerIndicators->RecalcSizes();


	// Screen lines

//	m_staticline_interfaces->Show( false );
	m_staticline_indicators->Show( false );
	m_staticline_sensors->Show( false );
	m_staticline_system->Show( false );


	// --- Tools -----------------------------------------------------------------

//	m_main_tool->EnableTool( ID_TOOL_SAVE, true );
//	m_main_tool->EnableTool( ID_TOOL_GENERATE, true );

//	m_main_tool->SetToolNormalBitmap( ID_TOOL_CONNECT, disconnect_xpm );
//	m_main_tool->SetToolShortHelp( ID_TOOL_CONNECT, wxT( "Disconnect COM-Port" ) );
//	m_bitmap_com_indicator->SetBitmap( pw_r_xpm );

//	m_main_tool->SetToolNormalBitmap( ID_TOOL_CONNECT, connect_xpm );
//	m_main_tool->SetToolShortHelp( ID_TOOL_CONNECT, wxT( "Connect COM-Port" ) );
//	m_bitmap_com_indicator->SetBitmap( pw_r_xpm );
//	m_main_tool->EnableTool( ID_TOOL_CONNECT, true );
//	m_main_tool->EnableTool( ID_TOOL_CONNECT, false );
//	m_main_tool->EnableTool( ID_TOOL_CONNECT, false );

//	m_tool_data->SetToolNormalBitmap( ID_TOOL_INS_ROW, empty_xpm );
//	m_tool_data->EnableTool( ID_TOOL_INS_ROW, true );
//	m_tool_data->SetToolNormalBitmap( ID_TOOL_DEL_ROW, empty_xpm );
//	m_tool_data->EnableTool( ID_TOOL_DEL_ROW, true );
//	m_tool_data->SetToolNormalBitmap( ID_TOOL_ROW_UP, empty_xpm );
//	m_tool_data->EnableTool( ID_TOOL_ROW_UP, true );
//	m_tool_data->SetToolNormalBitmap( ID_TOOL_ROW_DOWN, empty_xpm );
//	m_tool_data->EnableTool( ID_TOOL_ROW_DOWN, true );
//	m_tool_data->SetToolNormalBitmap( ID_TOOL_RUN, empty_xpm );
//	m_tool_data->EnableTool( ID_TOOL_RUN, false );

//	m_tool_UART->SetToolNormalBitmap( ID_TOOL_UART_CONFIG, empty_xpm );
//	m_tool_UART->EnableTool( ID_TOOL_UART_CONFIG, false );
//	m_tool_UART->SetToolNormalBitmap( ID_TOOL_SERIAL_HELP, empty_xpm );
//	m_tool_UART->EnableTool( ID_TOOL_SERIAL_HELP, false );

//	m_tool_CAN->SetToolNormalBitmap( ID_TOOL_CAN_CFG, empty_xpm );
//	m_tool_CAN->EnableTool( ID_TOOL_CAN_CFG, false );
//	m_tool_CAN->SetToolNormalBitmap( ID_TOOL_CAN_HELP, empty_xpm );
//	m_tool_CAN->EnableTool( ID_TOOL_CAN_HELP, false );

//	m_tool_Ethernet->SetToolNormalBitmap( ID_TOOL_ETH_CFG, empty_xpm );
//	m_tool_Ethernet->EnableTool( ID_TOOL_ETH_CFG, false );
//	m_tool_Ethernet->SetToolNormalBitmap( ID_TOOL_ETH_HELP, empty_xpm );
//	m_tool_Ethernet->EnableTool( ID_TOOL_ETH_HELP, false );

//	m_tool_Display_I2C->SetToolNormalBitmap( ID_TOOL_I2C_HELP, empty_xpm );
//	m_tool_Display_I2C->EnableTool( ID_TOOL_I2C_HELP, false );

	m_toolBarSensor->SetToolNormalBitmap( ID_TOOL_EC11_CONFIG, empty_xpm );
	m_toolBarSensor->EnableTool( ID_TOOL_EC11_CONFIG, false );
//	m_toolBarSensor->SetToolNormalBitmap( ID_TOOL_EC11_HELP, empty_xpm );
//	m_toolBarSensor->EnableTool( ID_TOOL_EC11_HELP, false );

	m_toolBarSystem->EnableTool( ID_TOOL_TIMER_CONFIG, false );
	m_toolBarSystem->SetToolNormalBitmap( ID_TOOL_TIMER_CONFIG, empty_xpm );


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
m_interfaces_window->Fit();
//wxYield();
//Fit();
//m_interfaces_window->Refresh();
//Update();
//Refresh();

//int n1, n2;
//n1 = m_auinotebook->GetPageIndex( m_interfaces_window );
//n2 = m_auinotebook->GetPageIndex( m_config_panel );
//m_auinotebook->SetSelection( n2 );
//m_auinotebook->SetSelection( n1 );


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

////IO_COM->Close();
////IO_COM->Close();
////IO_COM->Close();
//
//	if( !Read_Cfg() )
//	{
//		if( !Read_Prj() )
//		{
//			Enable_Config();
//			m = sizeof( VAR_1XX_TYPES ) / sizeof( int );
//			ce2 = new wxGridCellChoiceEditor( m, VAR_1XX_TYPES );
//			ce3 = new wxGridCellChoiceEditor( PORT_NN, SEL_PORT );
//			ce5 = new wxGridCellChoiceEditor( 3, cs5 );
//		}
//	}
//
//	if( Win_SizeX && Win_SizeY  )
//	{
//		// Restore size & position
//		if( ( Win_PosX >= 0 ) && ( Win_PosY >= 0 ) )
//		{
//			Move( Win_PosX, Win_PosY );
//		}
//		if( Win_SizeX && Win_SizeY )
//		{
//			SetSize( wxSize( Win_SizeX, Win_SizeY ) );
//		}
//		if( Read_Win_MaxSize )
//		{
//		Win_MaxSize = true;
//		Maximize();
//		}
//		else
//		{
//			Win_MaxSize = false;
//		}
//	}
//
////	m_auinotebook->SetSelection( m_auinotebook->GetPageIndex( m_data_panel ) );
//	m_auinotebook->SetSelection( m_auinotebook->GetPageIndex( m_panel_log ) );
//	m_config_window->Fit();
//	srand( ( unsigned ) time( NULL ) );
//
//	if( COM_NN > 0 )
//	{
//		s.Printf( wxT( "COM%d" ), COM_NN );
//		m_tool_com_port->SetValue( s );
//	}
//
//
//// ---------------------------------------------------------------------------
//// Start threads
//// ---------------------------------------------------------------------------
//
////	read_com_thread_ptr = Create_Read_COM_Thread();
////	if( read_com_thread_ptr->Run() != wxTHREAD_NO_ERROR )
////	{
////		wxMessageBox( wxT( "Can't start COM read thread" ) );
////		Close();
////	}
////
////	write_com_thread_ptr = Create_Write_COM_Thread();
////	if( write_com_thread_ptr->Run() != wxTHREAD_NO_ERROR )
////	{
////		wxMessageBox( wxT( "Can't start COM write thread" ) );
////		Close();
////	}
}
// === end of MyFrame ========================================================


// ===========================================================================
MyFrame::~MyFrame()
// ===========================================================================
{
//	Asc_to_Save();
//	Write_Cfg();

//write_com_thread_ptr->m_cancel = true;
//while( write_com_thread_ptr->IsAlive() ){}
//delete write_com_thread_ptr;

//read_com_thread_ptr->m_cancel = true;
//while( read_com_thread_ptr->IsAlive() ){}
//delete read_com_thread_ptr;

	//m_grid->BeginBatch();
	//m_grid->ClearGrid();
	//m_grid->EndBatch();
//	delete IO_COM;
}
// ===========================================================================


//// ===========================================================================
//void MyFrame::OnExit( wxCommandEvent &WXUNUSED( event ) )
//// ===========================================================================
//{
////wxString s;
////write_com_thread_ptr->m_cancel = true;
////write_com_thread_ptr->Kill();
//
////while( write_com_thread_ptr->IsAlive() ){}
//
////if( write_com_thread_ptr->IsAlive() )
////_log->AppendText( wxT( "IsAlive\n" ) );
////else
////_log->AppendText( wxT( "Stop\n" ) );
////delete write_com_thread_ptr;
////s.Printf( wxT( "w ptr=%d\n" ), write_com_thread_ptr );
////_log->AppendText( s );
//	Close();
//}
//// ===========================================================================


//// ===========================================================================
//void MyFrame::OnSize( wxSizeEvent &event )
//// ===========================================================================
//{
//	wxString	s;
//	wxPoint		pos  = GetPosition();
//	wxSize		size = event.GetSize();
//
//	if( ( pos.x >= 0 ) && ( pos.y >= 0 ) )
//	{
//		Win_MaxSize		= false;
//		Win_PosX		= pos.x;
//		Win_PosY		= pos.y;
//		Win_SizeX		= size.x;
//		Win_SizeY		= size.y;
//	}
//	event.Skip();
//}
//// ===========================================================================


//// ===========================================================================
//void MyFrame::OnMove( wxMoveEvent &event )
//// ===========================================================================
//{
//	wxString	s;
//	wxPoint		pos = GetPosition();
//
//	if( ( pos.x >= 0 ) && ( pos.y >= 0 ) )
//	{
//		Win_PosX	= pos.x;
//		Win_PosY	= pos.y;
//	}
//	m_grid->Refresh();
//    event.Skip();
//}
//// ===========================================================================


//// ===========================================================================
//void MyFrame::OnMaximized( wxMaximizeEvent &event )
//// ===========================================================================
//{
//	Win_MaxSize = true;
//	event.Skip();
//}
//// ===========================================================================


BEGIN_EVENT_TABLE( MyFrame, MyFrameFB )
//	EVT_MENU( ID_TOOL_NEW_PRJ,			MyFrame::OnTool_New_Prj )
//	EVT_MENU( ID_TOOL_OPEN_PRJ,			MyFrame::OnTool_Open_Prj )
//	EVT_MENU( ID_TOOL_CLOSE_PRJ,		MyFrame::OnTool_Close_Prj )
//	EVT_MENU( ID_TOOL_SAVE,				MyFrame::OnTool_Save_Prj )
//	EVT_MENU( ID_TOOL_GENERATE,			MyFrame::OnTool_Generate_FW )
//	EVT_MENU( ID_TOOL_EXIT,				MyFrame::OnExit )
//	EVT_MENU( ID_TOOL_COM_CONFIG,		MyFrame::OnTool_COM_config )
//	EVT_MENU( ID_TOOL_CONNECT,			MyFrame::OnTool_connect )
//	EVT_MENU( ID_TOOL_COM_CONNECT,		MyFrame::OnTool_COM_connect )
//	EVT_MENU( ID_TOOL_COM_DISCONNECT,	MyFrame::OnTool_COM_disconnect )
//	EVT_MENU( ID_TOOL_RUN,				MyFrame::OnTool_Run )
//	EVT_MENU( ID_TOOL_UART_CONFIG,		MyFrame::OnTool_UART1_config )
//	EVT_MENU( ID_TOOL_SERIAL_HELP,		MyFrame::OnTool_UART_help )
//	EVT_MENU( ID_TOOL_INS_ROW,			MyFrame::OnInsRow )
//	EVT_MENU( ID_TOOL_DEL_ROW,			MyFrame::OnDelRow )
//	EVT_MENU( ID_TOOL_ROW_UP,			MyFrame::OnRowUp )
//	EVT_MENU( ID_TOOL_ROW_DOWN,			MyFrame::OnRowDown )
//	EVT_MENU( ID_TOOL_ABOUT,			MyFrame::OnMyAbout )
//	EVT_MENU( ID_TOOL_FUNCTIONS,		MyFrame::OnMyFunctions )
//	EVT_MENU( ID_TOOL_I2C_HELP,			MyFrame::OnTool_I2C_help )
//	EVT_MENU( ID_TOOL_BME280_HELP,		MyFrame::OnTool_BME280_Help )
//	EVT_MENU( ID_TOOL_BH1750_HELP,		MyFrame::OnTool_BH1750_Help )
//	EVT_MENU( ID_TOOL_CCS811_HELP,		MyFrame::OnTool_CCS811_Help )

//	EVT_MAXIMIZE( MyFrame::OnMaximized )
//	EVT_SIZE( MyFrame::OnSize )
//	EVT_MOVE( MyFrame::OnMove )

    //EVT_GRID_EDITOR_HIDDEN( MyFrame::OnEditorHidden )
//    EVT_GRID_CELL_CHANGE( MyFrame::OnCellValueChanged )

//	//    EVT_GRID_CELL_LEFT_CLICK( MyFrame::OnCellLeftClick )
END_EVENT_TABLE()
