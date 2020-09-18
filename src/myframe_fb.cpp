#include "myframe_fb.h"

#include "disk.xpm"
#include "exit.xpm"
#include "l_green.xpm"
#include "make_fw.xpm"
#include "play.xpm"
#include "search.xpm"
#include "setting_tools.xpm"
#include "table_edit.xpm"
#include "table_replace.xpm"
#include "table_row_delete.xpm"
#include "table_row_down.xpm"
#include "table_row_insert.xpm"
#include "table_row_up.xpm"

MyFrameFB::MyFrameFB( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
    this->SetSizeHints( wxDefaultSize, wxDefaultSize );
    this->SetFont( wxFont( 10, 70, 90, 90, false, wxEmptyString ) );

    m_menubar = new wxMenuBar( 0 );
    m_menu_file = new wxMenu();
    wxMenuItem* m_menu_new_project;
    m_menu_new_project = new wxMenuItem( m_menu_file, ID_TOOL_NEW_PRJ, wxString( wxT("New Project\tCtrl+N") ) , wxEmptyString, wxITEM_NORMAL );
    m_menu_file->Append( m_menu_new_project );

    wxMenuItem* m_menu_open_project;
    m_menu_open_project = new wxMenuItem( m_menu_file, ID_TOOL_OPEN_PRJ, wxString( wxT("Open Project\tCtrl+O") ) , wxEmptyString, wxITEM_NORMAL );
    m_menu_file->Append( m_menu_open_project );

    wxMenuItem* m_menu_save_project;
    m_menu_save_project = new wxMenuItem( m_menu_file, ID_TOOL_SAVE, wxString( wxT("Save project\tCtrl+S") ) , wxEmptyString, wxITEM_NORMAL );
    m_menu_file->Append( m_menu_save_project );

    wxMenuItem* m_menu_close_project;
    m_menu_close_project = new wxMenuItem( m_menu_file, ID_TOOL_CLOSE_PRJ, wxString( wxT("Close Project\tCtrl+Q") ) , wxEmptyString, wxITEM_NORMAL );
    m_menu_file->Append( m_menu_close_project );

    wxMenuItem* m_separator1;
    m_separator1 = m_menu_file->AppendSeparator();

    wxMenuItem* m_menu_exit;
    m_menu_exit = new wxMenuItem( m_menu_file, ID_TOOL_EXIT, wxString( wxT("Exit\tAlt+X") ) , wxEmptyString, wxITEM_NORMAL );
    m_menu_file->Append( m_menu_exit );

    m_menubar->Append( m_menu_file, wxT("&File") );

    m_menu_tools = new wxMenu();
    wxMenuItem* m_menu_sh_val;
    m_menu_sh_val = new wxMenuItem( m_menu_tools, ID_TOOL_SHVAL, wxString( wxT("Show values\tF5") ) , wxEmptyString, wxITEM_NORMAL );
    m_menu_tools->Append( m_menu_sh_val );
    m_menu_sh_val->Enable( false );

    wxMenuItem* m_menu_fw_gen;
    m_menu_fw_gen = new wxMenuItem( m_menu_tools, ID_TOOL_GENERATE, wxString( wxT("Firmware code generate\tF8") ) , wxEmptyString, wxITEM_NORMAL );
    m_menu_tools->Append( m_menu_fw_gen );

    m_menubar->Append( m_menu_tools, wxT("&Tools") );

    this->SetMenuBar( m_menubar );

    m_statusBar1 = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
    wxBoxSizer* bSizer1;
    bSizer1 = new wxBoxSizer( wxVERTICAL );

    m_panel1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
    wxBoxSizer* bSizer2;
    bSizer2 = new wxBoxSizer( wxVERTICAL );

    m_main_tool = new wxToolBar( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_FLAT|wxTB_HORIZONTAL );
    m_main_tool->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

    m_main_tool->AddTool( ID_TOOL_EXIT, wxT("tool"), wxBitmap( exit_xpm ), wxNullBitmap, wxITEM_NORMAL, wxT("Exit"), wxEmptyString );
    m_main_tool->AddTool( ID_TOOL_SAVE, wxT("tool"), wxBitmap( disk_xpm ), wxNullBitmap, wxITEM_NORMAL, wxT("Save project"), wxEmptyString );
    m_main_tool->AddSeparator();
    m_staticText1 = new wxStaticText( m_main_tool, wxID_ANY, wxT("MCU: "), wxDefaultPosition, wxDefaultSize, 0 );
    m_staticText1->Wrap( -1 );
    m_main_tool->AddControl( m_staticText1 );
    m_text_mcu = new wxTextCtrl( m_main_tool, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 140,-1 ), wxTE_READONLY );
    m_main_tool->AddControl( m_text_mcu );
    m_staticText3 = new wxStaticText( m_main_tool, wxID_ANY, wxT("-"), wxDefaultPosition, wxDefaultSize, 0 );
    m_staticText3->Wrap( -1 );
    m_staticText3->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );
    m_staticText3->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

    m_main_tool->AddControl( m_staticText3 );
    m_main_tool->AddSeparator();
    m_staticText2 = new wxStaticText( m_main_tool, wxID_ANY, wxT("Comment: "), wxDefaultPosition, wxDefaultSize, 0 );
    m_staticText2->Wrap( -1 );
    m_main_tool->AddControl( m_staticText2 );
    m_text_comment = new wxTextCtrl( m_main_tool, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 300,-1 ), wxTE_READONLY );
    m_main_tool->AddControl( m_text_comment );
    m_main_tool->Realize();

    bSizer2->Add( m_main_tool, 0, wxEXPAND, 5 );

    m_auinotebook = new wxAuiNotebook( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_NB_WINDOWLIST_BUTTON );
    m_auinotebook->SetFont( wxFont( 10, 70, 90, 90, false, wxEmptyString ) );

    m_device_panel = new wxPanel( m_auinotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
    wxBoxSizer* bSizer41;
    bSizer41 = new wxBoxSizer( wxVERTICAL );

    m_tool_data = new wxToolBar( m_device_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_FLAT|wxTB_HORIZONTAL|wxTB_NODIVIDER );
    m_tool_data->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

    m_tool_data->AddTool( ID_DEV_ADD_ROW, wxT("tool"), wxBitmap( table_row_insert_xpm ), wxNullBitmap, wxITEM_NORMAL, wxT("Insert row"), wxEmptyString );
    m_tool_data->AddTool( ID_DEV_DEL_ROW, wxT("tool"), wxBitmap( table_row_delete_xpm ), wxNullBitmap, wxITEM_NORMAL, wxT("Delete row"), wxEmptyString );
    m_tool_data->AddTool( ID_DEV_ROW_UP, wxT("tool"), wxBitmap( table_row_up_xpm ), wxNullBitmap, wxITEM_NORMAL, wxT("Row Up"), wxEmptyString );
    m_tool_data->AddTool( ID_DEV_ROW_DOWN, wxT("tool"), wxBitmap( table_row_down_xpm ), wxNullBitmap, wxITEM_NORMAL, wxT("Row Down"), wxEmptyString );
    m_tool_data->AddSeparator();
    m_tool_data->AddTool( ID_EDIT_CONF, wxT("tool"), wxBitmap( table_edit_xpm ), wxNullBitmap, wxITEM_NORMAL, wxT("Edit Configure"), wxEmptyString );
    m_tool_data->AddTool( ID_DEV_SEARCH, wxT("tool"), wxBitmap( search_xpm ), wxNullBitmap, wxITEM_NORMAL, wxT("Explore of net"), wxEmptyString );
    m_tool_data->AddSeparator();
    m_dev_COM_Text = new wxStaticText( m_tool_data, wxID_ANY, wxT("COM port: "), wxDefaultPosition, wxDefaultSize, 0 );
    m_dev_COM_Text->Wrap( -1 );
    m_tool_data->AddControl( m_dev_COM_Text );
    wxArrayString m_dev_COM_choiceChoices;
    m_dev_COM_choice = new wxChoice( m_tool_data, wxID_ANY, wxDefaultPosition, wxSize( 70,-1 ), m_dev_COM_choiceChoices, 0 );
    m_dev_COM_choice->SetSelection( 0 );
    m_tool_data->AddControl( m_dev_COM_choice );
    m_staticText51 = new wxStaticText( m_tool_data, wxID_ANY, wxT("-"), wxDefaultPosition, wxDefaultSize, 0 );
    m_staticText51->Wrap( -1 );
    m_staticText51->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );
    m_staticText51->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

    m_tool_data->AddControl( m_staticText51 );
    m_dev_com_bitmap = new wxStaticBitmap( m_tool_data, wxID_ANY, wxBitmap( l_green_xpm ), wxDefaultPosition, wxDefaultSize, 0 );
    m_tool_data->AddControl( m_dev_com_bitmap );
    m_staticText61 = new wxStaticText( m_tool_data, wxID_ANY, wxT("-"), wxDefaultPosition, wxDefaultSize, 0 );
    m_staticText61->Wrap( -1 );
    m_staticText61->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );
    m_staticText61->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

    m_tool_data->AddControl( m_staticText61 );
    m_tool_data->AddSeparator();
    m_tool_data->AddTool( ID_DEV_RUN, wxT("tool"), wxBitmap( play_xpm ), wxNullBitmap, wxITEM_NORMAL, wxT("Show values"), wxEmptyString );
    m_tool_data->AddSeparator();
    m_dev_tool_msg = new wxTextCtrl( m_tool_data, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 370,-1 ), 0|wxNO_BORDER );
    m_dev_tool_msg->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

    m_tool_data->AddControl( m_dev_tool_msg );
    m_tool_data->Realize();

    bSizer41->Add( m_tool_data, 0, wxEXPAND, 5 );

    m_staticline12 = new wxStaticLine( m_device_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    bSizer41->Add( m_staticline12, 0, wxEXPAND|wxBOTTOM, 5 );

    wxBoxSizer* bSizer51;
    bSizer51 = new wxBoxSizer( wxVERTICAL );

    m_dev_grid = new wxGrid( m_device_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

    m_dev_grid->CreateGrid( 0, 0 );
    m_dev_grid->EnableEditing( true );
    m_dev_grid->EnableGridLines( true );
    m_dev_grid->EnableDragGridSize( false );
    m_dev_grid->SetMargins( 0, 0 );

    m_dev_grid->EnableDragColMove( false );
    m_dev_grid->EnableDragColSize( true );
    m_dev_grid->SetColLabelSize( 30 );
    m_dev_grid->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );

    m_dev_grid->EnableDragRowSize( true );
    m_dev_grid->SetRowLabelSize( 80 );
    m_dev_grid->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );

    m_dev_grid->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
    bSizer51->Add( m_dev_grid, 1, wxALL|wxEXPAND, 5 );

    bSizer41->Add( bSizer51, 1, wxEXPAND, 5 );

    m_device_panel->SetSizer( bSizer41 );
    m_device_panel->Layout();
    bSizer41->Fit( m_device_panel );
    m_auinotebook->AddPage( m_device_panel, wxT("Devices"), true, wxNullBitmap );
    m_interfaces_window = new wxScrolledWindow( m_auinotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
    m_interfaces_window->SetScrollRate( 5, 5 );
    wxBoxSizer* bSizer7;
    bSizer7 = new wxBoxSizer( wxVERTICAL );

    sbSizerInterfaces = new wxStaticBoxSizer( new wxStaticBox( m_interfaces_window, wxID_ANY, wxT("Interfaces") ), wxHORIZONTAL );

    sbSizerSerial = new wxStaticBoxSizer( new wxStaticBox( m_interfaces_window, wxID_ANY, wxT("Serial") ), wxHORIZONTAL );

    wxBoxSizer* bSizer8;
    bSizer8 = new wxBoxSizer( wxHORIZONTAL );

    m_tool_UART = new wxToolBar( m_interfaces_window, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_FLAT|wxTB_HORIZONTAL|wxTB_NODIVIDER );
    m_tool_UART->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );
    m_tool_UART->SetToolTip( wxT("UART1 config") );

    m_check_UART = new wxCheckBox( m_tool_UART, ID_UART, wxT("UART1"), wxDefaultPosition, wxDefaultSize, 0 );
    m_tool_UART->AddControl( m_check_UART );
    m_tool_UART->AddTool( wxID_ANY, wxT("tool"), wxBitmap( setting_tools_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString );
    m_tool_UART->Realize();

    bSizer8->Add( m_tool_UART, 0, wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );

    sbSizerSerial->Add( bSizer8, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );

    bSizerUSB = new wxBoxSizer( wxHORIZONTAL );

    m_staticline25 = new wxStaticLine( m_interfaces_window, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
    bSizerUSB->Add( m_staticline25, 0, wxEXPAND|wxLEFT, 5 );

    wxBoxSizer* bSizer28;
    bSizer28 = new wxBoxSizer( wxVERTICAL );

    m_check_USB_VCP = new wxCheckBox( m_interfaces_window, ID_USB_VCP, wxT("USB VCP"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer28->Add( m_check_USB_VCP, 0, wxLEFT, 5 );

    m_check_USB_console = new wxCheckBox( m_interfaces_window, wxID_ANY, wxT("USB as Console"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer28->Add( m_check_USB_console, 0, wxLEFT, 5 );

    bSizerUSB->Add( bSizer28, 1, wxEXPAND, 5 );

    sbSizerSerial->Add( bSizerUSB, 0, wxEXPAND, 5 );

    wxBoxSizer* bSizer26;
    bSizer26 = new wxBoxSizer( wxHORIZONTAL );

    m_staticline24 = new wxStaticLine( m_interfaces_window, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
    bSizer26->Add( m_staticline24, 0, wxEXPAND|wxLEFT, 5 );

    wxBoxSizer* bSizer27;
    bSizer27 = new wxBoxSizer( wxVERTICAL );

    m_check_UART2 = new wxCheckBox( m_interfaces_window, ID_UART2, wxT("UART2"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer27->Add( m_check_UART2, 0, wxLEFT, 5 );

    m_check_UART2_485 = new wxCheckBox( m_interfaces_window, wxID_ANY, wxT("UART2 as RS-485"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer27->Add( m_check_UART2_485, 0, wxLEFT, 5 );

    bSizer26->Add( bSizer27, 1, wxEXPAND, 5 );

    m_toolBar9 = new wxToolBar( m_interfaces_window, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_FLAT|wxTB_HORIZONTAL|wxTB_NODIVIDER );
    m_toolBar9->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

    m_toolBar9->AddTool( ID_UART2_CONFIG, wxT("tool"), wxBitmap( setting_tools_xpm ), wxNullBitmap, wxITEM_NORMAL, wxT("UART2 config"), wxEmptyString );
    m_toolBar9->Realize();

    bSizer26->Add( m_toolBar9, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );

    sbSizerSerial->Add( bSizer26, 1, wxEXPAND, 5 );

    sbSizerInterfaces->Add( sbSizerSerial, 0, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 5 );

    sbSizerCAN = new wxStaticBoxSizer( new wxStaticBox( m_interfaces_window, wxID_ANY, wxT("CAN") ), wxHORIZONTAL );

    m_tool_CAN = new wxToolBar( m_interfaces_window, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_FLAT|wxTB_HORIZONTAL|wxTB_NODIVIDER );
    m_tool_CAN->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

    m_check_CAN_Internal = new wxCheckBox( m_tool_CAN, ID_CAN, wxT("bxCAN"), wxDefaultPosition, wxDefaultSize, 0 );
    m_tool_CAN->AddControl( m_check_CAN_Internal );
    m_tool_CAN->AddTool( ID_CAN_CFG, wxT("tool"), wxBitmap( setting_tools_xpm ), wxNullBitmap, wxITEM_NORMAL, wxT("CAN config"), wxEmptyString );
    m_tool_CAN->Realize();

    sbSizerCAN->Add( m_tool_CAN, 0, wxALIGN_CENTER_VERTICAL|wxEXPAND|wxRIGHT|wxLEFT, 5 );

    sbSizerInterfaces->Add( sbSizerCAN, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );

    sbSizerEth = new wxStaticBoxSizer( new wxStaticBox( m_interfaces_window, wxID_ANY, wxT("Ethernet") ), wxHORIZONTAL );

    m_tool_Ethernet = new wxToolBar( m_interfaces_window, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_FLAT|wxTB_HORIZONTAL|wxTB_NODIVIDER );
    m_tool_Ethernet->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

    m_check_W5500 = new wxCheckBox( m_tool_Ethernet, ID_W5500, wxT("W5500"), wxDefaultPosition, wxDefaultSize, 0 );
    m_tool_Ethernet->AddControl( m_check_W5500 );
    m_tool_Ethernet->AddTool( ID_ETH_CFG, wxT("tool"), wxBitmap( setting_tools_xpm ), wxNullBitmap, wxITEM_NORMAL, wxT("Ethernet config"), wxEmptyString );
    m_tool_Ethernet->Realize();

    sbSizerEth->Add( m_tool_Ethernet, 0, wxALIGN_CENTER_VERTICAL|wxEXPAND|wxRIGHT|wxLEFT, 5 );

    sbSizerInterfaces->Add( sbSizerEth, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );

    bSizer7->Add( sbSizerInterfaces, 0, wxALL, 5 );

    m_staticline_interfaces = new wxStaticLine( m_interfaces_window, wxID_ANY, wxDefaultPosition, wxSize( -1,5 ), wxLI_HORIZONTAL );
    bSizer7->Add( m_staticline_interfaces, 0, wxEXPAND|wxBOTTOM, 5 );

    sbSizerSensors = new wxStaticBoxSizer( new wxStaticBox( m_interfaces_window, wxID_ANY, wxT("Sensors I2C1") ), wxHORIZONTAL );

    m_toolBarSensor = new wxToolBar( m_interfaces_window, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_FLAT|wxTB_HORIZONTAL|wxTB_NODIVIDER );
    m_toolBarSensor->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

    m_check_BME280 = new wxCheckBox( m_toolBarSensor, ID_BME280, wxT("BME280"), wxDefaultPosition, wxDefaultSize, 0 );
    m_toolBarSensor->AddControl( m_check_BME280 );
    m_toolBarSensor->AddSeparator();
    m_staticText10 = new wxStaticText( m_toolBarSensor, wxID_ANY, wxT("-"), wxDefaultPosition, wxDefaultSize, 0 );
    m_staticText10->Wrap( -1 );
    m_staticText10->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

    m_toolBarSensor->AddControl( m_staticText10 );
    m_check_BH1750 = new wxCheckBox( m_toolBarSensor, ID_BH1750, wxT("BH1750"), wxDefaultPosition, wxDefaultSize, 0 );
    m_toolBarSensor->AddControl( m_check_BH1750 );
    m_toolBarSensor->AddSeparator();
    m_staticText11 = new wxStaticText( m_toolBarSensor, wxID_ANY, wxT("-"), wxDefaultPosition, wxDefaultSize, 0 );
    m_staticText11->Wrap( -1 );
    m_staticText11->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

    m_toolBarSensor->AddControl( m_staticText11 );
    m_check_CCS811 = new wxCheckBox( m_toolBarSensor, ID_CCS811, wxT("CCS811"), wxDefaultPosition, wxDefaultSize, 0 );
    m_toolBarSensor->AddControl( m_check_CCS811 );
    m_toolBarSensor->AddSeparator();
    m_staticText12 = new wxStaticText( m_toolBarSensor, wxID_ANY, wxT("-"), wxDefaultPosition, wxDefaultSize, 0 );
    m_staticText12->Wrap( -1 );
    m_staticText12->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

    m_toolBarSensor->AddControl( m_staticText12 );
    m_check_EC11 = new wxCheckBox( m_toolBarSensor, ID_EC11, wxT("Encoder EC11"), wxDefaultPosition, wxDefaultSize, 0 );
    m_toolBarSensor->AddControl( m_check_EC11 );
    m_toolBarSensor->AddTool( ID_EC11_CONFIG, wxT("tool"), wxBitmap( setting_tools_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString );
    m_toolBarSensor->Realize();

    sbSizerSensors->Add( m_toolBarSensor, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );

    bSizer7->Add( sbSizerSensors, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );

    m_staticline_sensors = new wxStaticLine( m_interfaces_window, wxID_ANY, wxDefaultPosition, wxSize( -1,5 ), wxLI_HORIZONTAL );
    bSizer7->Add( m_staticline_sensors, 0, wxEXPAND|wxBOTTOM, 5 );

    sbSizerIndicators = new wxStaticBoxSizer( new wxStaticBox( m_interfaces_window, wxID_ANY, wxT("Indicators") ), wxHORIZONTAL );

    sbSizerLED = new wxStaticBoxSizer( new wxStaticBox( m_interfaces_window, wxID_ANY, wxT("LED") ), wxHORIZONTAL );

    m_check_PC13 = new wxCheckBox( m_interfaces_window, ID_PC13, wxT("LED blink (PC13)"), wxDefaultPosition, wxDefaultSize, 0 );
    sbSizerLED->Add( m_check_PC13, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

    sbSizerIndicators->Add( sbSizerLED, 1, wxBOTTOM|wxRIGHT|wxLEFT, 5 );

    wxStaticBoxSizer* sb1602_4;
    sb1602_4 = new wxStaticBoxSizer( new wxStaticBox( m_interfaces_window, wxID_ANY, wxT("LCD 1602") ), wxHORIZONTAL );

    m_check_LCD1602_4 = new wxCheckBox( m_interfaces_window, ID_1602_4, wxT("LCD 1602 (4 bits)"), wxDefaultPosition, wxDefaultSize, 0 );
    sb1602_4->Add( m_check_LCD1602_4, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

    sbSizerIndicators->Add( sb1602_4, 0, wxBOTTOM|wxLEFT|wxRIGHT, 5 );

    sbSizerDisplayI2C = new wxStaticBoxSizer( new wxStaticBox( m_interfaces_window, wxID_ANY, wxT("Display I2C1") ), wxHORIZONTAL );

    m_staticline5 = new wxStaticLine( m_interfaces_window, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
    sbSizerDisplayI2C->Add( m_staticline5, 0, wxEXPAND|wxBOTTOM|wxLEFT, 5 );

    wxBoxSizer* bSizer10;
    bSizer10 = new wxBoxSizer( wxVERTICAL );

    m_staticline3 = new wxStaticLine( m_interfaces_window, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    bSizer10->Add( m_staticline3, 0, wxEXPAND|wxBOTTOM, 5 );

    m_check_LCD1602 = new wxCheckBox( m_interfaces_window, ID_1602, wxT("LCD 1602"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer10->Add( m_check_LCD1602, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

    m_staticline4 = new wxStaticLine( m_interfaces_window, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    bSizer10->Add( m_staticline4, 0, wxEXPAND|wxTOP|wxBOTTOM, 5 );

    wxBoxSizer* bSizer11;
    bSizer11 = new wxBoxSizer( wxHORIZONTAL );

    m_check_8574 = new wxCheckBox( m_interfaces_window, ID_PCF8574, wxT("PCF8574(T)"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer11->Add( m_check_8574, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

    m_check_8574A = new wxCheckBox( m_interfaces_window, ID_PCF8574T, wxT("PCF8574A(T)"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer11->Add( m_check_8574A, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

    bSizer10->Add( bSizer11, 1, wxEXPAND, 5 );

    m_staticline11 = new wxStaticLine( m_interfaces_window, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    bSizer10->Add( m_staticline11, 0, wxEXPAND|wxTOP|wxBOTTOM, 5 );

    sbSizerDisplayI2C->Add( bSizer10, 1, wxEXPAND, 5 );

    m_staticline6 = new wxStaticLine( m_interfaces_window, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
    sbSizerDisplayI2C->Add( m_staticline6, 0, wxEXPAND|wxBOTTOM, 5 );

    wxBoxSizer* bSizer12;
    bSizer12 = new wxBoxSizer( wxVERTICAL );

    m_staticline8 = new wxStaticLine( m_interfaces_window, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    bSizer12->Add( m_staticline8, 0, wxEXPAND|wxBOTTOM, 5 );

    m_check_SSD1306 = new wxCheckBox( m_interfaces_window, ID_SSD1306, wxT("SSD1306"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer12->Add( m_check_SSD1306, 0, wxALL, 5 );

    m_staticline9 = new wxStaticLine( m_interfaces_window, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    bSizer12->Add( m_staticline9, 0, wxEXPAND|wxTOP|wxBOTTOM, 5 );

    m_staticText7 = new wxStaticText( m_interfaces_window, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    m_staticText7->Wrap( -1 );
    bSizer12->Add( m_staticText7, 1, wxALL|wxEXPAND, 5 );

    m_staticline10 = new wxStaticLine( m_interfaces_window, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    bSizer12->Add( m_staticline10, 0, wxEXPAND|wxTOP|wxBOTTOM, 5 );

    sbSizerDisplayI2C->Add( bSizer12, 0, 0, 5 );

    m_staticline7 = new wxStaticLine( m_interfaces_window, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
    sbSizerDisplayI2C->Add( m_staticline7, 0, wxEXPAND|wxBOTTOM|wxRIGHT, 5 );

    sbSizerIndicators->Add( sbSizerDisplayI2C, 0, wxBOTTOM|wxLEFT|wxRIGHT, 5 );

    bSizer7->Add( sbSizerIndicators, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );

    m_staticline_indicators = new wxStaticLine( m_interfaces_window, wxID_ANY, wxDefaultPosition, wxSize( -1,5 ), wxLI_HORIZONTAL );
    bSizer7->Add( m_staticline_indicators, 0, wxEXPAND|wxBOTTOM, 5 );

    sbSizerSystem = new wxStaticBoxSizer( new wxStaticBox( m_interfaces_window, wxID_ANY, wxT("System") ), wxHORIZONTAL );

    m_toolBarSystem = new wxToolBar( m_interfaces_window, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_FLAT|wxTB_HORIZONTAL|wxTB_NODIVIDER );
    m_toolBarSystem->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

    m_check_WatchDog = new wxCheckBox( m_toolBarSystem, ID_WATCHDOG, wxT("WatchDog"), wxDefaultPosition, wxDefaultSize, 0 );
    m_toolBarSystem->AddControl( m_check_WatchDog );
    m_toolBarSystem->AddSeparator();
    m_staticText13 = new wxStaticText( m_toolBarSystem, wxID_ANY, wxT("-"), wxDefaultPosition, wxDefaultSize, 0 );
    m_staticText13->Wrap( -1 );
    m_staticText13->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

    m_toolBarSystem->AddControl( m_staticText13 );
    m_check_MCO = new wxCheckBox( m_toolBarSystem, ID_MCO, wxT("MCO"), wxDefaultPosition, wxDefaultSize, 0 );
    m_toolBarSystem->AddControl( m_check_MCO );
    m_toolBarSystem->AddSeparator();
    m_staticText14 = new wxStaticText( m_toolBarSystem, wxID_ANY, wxT("-"), wxDefaultPosition, wxDefaultSize, 0 );
    m_staticText14->Wrap( -1 );
    m_staticText14->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

    m_toolBarSystem->AddControl( m_staticText14 );
    m_text_ibt_fix_time = new wxStaticText( m_toolBarSystem, wxID_ANY, wxT("iButton fix time (sec): "), wxDefaultPosition, wxDefaultSize, 0 );
    m_text_ibt_fix_time->Wrap( -1 );
    m_toolBarSystem->AddControl( m_text_ibt_fix_time );
    m_ibt_fix_time = new wxTextCtrl( m_toolBarSystem, ID_IBUTTON, wxT("5"), wxDefaultPosition, wxSize( 40,-1 ), 0 );
    m_toolBarSystem->AddControl( m_ibt_fix_time );
    m_staticText9 = new wxStaticText( m_toolBarSystem, wxID_ANY, wxT("-"), wxDefaultPosition, wxDefaultSize, 0 );
    m_staticText9->Wrap( -1 );
    m_staticText9->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

    m_toolBarSystem->AddControl( m_staticText9 );
    m_toolBarSystem->AddSeparator();
    m_staticText15 = new wxStaticText( m_toolBarSystem, wxID_ANY, wxT("-"), wxDefaultPosition, wxDefaultSize, 0 );
    m_staticText15->Wrap( -1 );
    m_staticText15->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

    m_toolBarSystem->AddControl( m_staticText15 );
    m_check_Timer = new wxCheckBox( m_toolBarSystem, ID_TIMER, wxT("Timer"), wxDefaultPosition, wxDefaultSize, 0 );
    m_toolBarSystem->AddControl( m_check_Timer );
    m_toolBarSystem->AddTool( ID_TIMER_CONFIG, wxT("tool"), wxBitmap( setting_tools_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString );
    m_toolBarSystem->Realize();

    sbSizerSystem->Add( m_toolBarSystem, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );

    m_staticline22 = new wxStaticLine( m_interfaces_window, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
    sbSizerSystem->Add( m_staticline22, 0, wxEXPAND|wxBOTTOM|wxLEFT, 5 );

    wxBoxSizer* bSizer24;
    bSizer24 = new wxBoxSizer( wxVERTICAL );

    m_staticline19 = new wxStaticLine( m_interfaces_window, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    bSizer24->Add( m_staticline19, 0, wxEXPAND, 5 );

    m_check_PWM = new wxCheckBox( m_interfaces_window, ID_PWM, wxT("PWM"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer24->Add( m_check_PWM, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

    m_staticline20 = new wxStaticLine( m_interfaces_window, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    bSizer24->Add( m_staticline20, 0, wxEXPAND, 5 );

    wxBoxSizer* bSizer25;
    bSizer25 = new wxBoxSizer( wxHORIZONTAL );

    m_check_PWM_PB6 = new wxCheckBox( m_interfaces_window, ID_PWM_PB6, wxT("PB6"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer25->Add( m_check_PWM_PB6, 0, wxALL, 5 );

    m_check_PWM_PB7 = new wxCheckBox( m_interfaces_window, ID_PWM_PB7, wxT("PB7"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer25->Add( m_check_PWM_PB7, 0, wxALL, 5 );

    m_check_PWM_PB8 = new wxCheckBox( m_interfaces_window, ID_PWM_PB8, wxT("PB8"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer25->Add( m_check_PWM_PB8, 0, wxALL, 5 );

    m_check_PWM_PB9 = new wxCheckBox( m_interfaces_window, ID_PWM_PB9, wxT("PB9"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer25->Add( m_check_PWM_PB9, 0, wxALL, 5 );

    bSizer24->Add( bSizer25, 1, wxEXPAND, 5 );

    m_staticline21 = new wxStaticLine( m_interfaces_window, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    bSizer24->Add( m_staticline21, 0, wxEXPAND|wxBOTTOM, 5 );

    sbSizerSystem->Add( bSizer24, 1, wxEXPAND, 5 );

    m_staticline23 = new wxStaticLine( m_interfaces_window, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
    sbSizerSystem->Add( m_staticline23, 0, wxEXPAND|wxBOTTOM|wxRIGHT, 5 );

    bSizer7->Add( sbSizerSystem, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );

    m_staticline_system = new wxStaticLine( m_interfaces_window, wxID_ANY, wxDefaultPosition, wxSize( -1,5 ), wxLI_HORIZONTAL );
    bSizer7->Add( m_staticline_system, 0, wxEXPAND|wxBOTTOM, 5 );

    sbSizerProtocols = new wxStaticBoxSizer( new wxStaticBox( m_interfaces_window, wxID_ANY, wxT("Protocols") ), wxHORIZONTAL );

    wxBoxSizer* bSizer29;
    bSizer29 = new wxBoxSizer( wxHORIZONTAL );

    wxStaticBoxSizer* sbSizer12;
    sbSizer12 = new wxStaticBoxSizer( new wxStaticBox( m_interfaces_window, wxID_ANY, wxT("MODBUS") ), wxHORIZONTAL );

    m_check_MODBUS = new wxCheckBox( m_interfaces_window, ID_MODBUS, wxT("Select"), wxDefaultPosition, wxDefaultSize, 0 );
    sbSizer12->Add( m_check_MODBUS, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 5 );

    m_toolBarMODBUS = new wxToolBar( m_interfaces_window, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_FLAT|wxTB_HORIZONTAL|wxTB_NODIVIDER );
    m_toolBarMODBUS->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

    m_toolBarMODBUS->AddTool( ID_MODBUS_CONFIG, wxT("tool"), wxBitmap( setting_tools_xpm ), wxNullBitmap, wxITEM_NORMAL, wxT("MODBUS config"), wxEmptyString );
    m_toolBarMODBUS->Realize();

    sbSizer12->Add( m_toolBarMODBUS, 0, wxALIGN_CENTER_VERTICAL, 5 );

    bSizer29->Add( sbSizer12, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );

    sbSizerProtocols->Add( bSizer29, 0, 0, 5 );

    bSizer7->Add( sbSizerProtocols, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );

    m_staticline26 = new wxStaticLine( m_interfaces_window, wxID_ANY, wxDefaultPosition, wxSize( -1,5 ), wxLI_HORIZONTAL );
    bSizer7->Add( m_staticline26, 0, wxEXPAND|wxBOTTOM, 5 );

    m_interfaces_window->SetSizer( bSizer7 );
    m_interfaces_window->Layout();
    bSizer7->Fit( m_interfaces_window );
    m_auinotebook->AddPage( m_interfaces_window, wxT("Interfaces/Sensors"), false, wxNullBitmap );
    m_config_panel = new wxPanel( m_auinotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
    wxBoxSizer* bSizer4;
    bSizer4 = new wxBoxSizer( wxVERTICAL );

    m_header = new wxStaticText( m_config_panel, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
    m_header->Wrap( -1 );
    m_header->SetFont( wxFont( 12, 70, 90, 92, false, wxEmptyString ) );

    bSizer4->Add( m_header, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

    m_staticline18 = new wxStaticLine( m_config_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    bSizer4->Add( m_staticline18, 0, wxEXPAND|wxBOTTOM, 5 );

    m_tool_config = new wxToolBar( m_config_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_FLAT|wxTB_HORIZONTAL|wxTB_NODIVIDER );
    m_tool_config->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

    m_tool_config->AddTool( ID_CFG_ADD_ROW, wxT("tool"), wxBitmap( table_row_insert_xpm ), wxNullBitmap, wxITEM_NORMAL, wxT("Insert row"), wxEmptyString );
    m_tool_config->AddTool( wxID_ANY, wxT("tool"), wxBitmap( table_row_delete_xpm ), wxNullBitmap, wxITEM_NORMAL, wxT("Delete row"), wxEmptyString );
    m_tool_config->AddTool( wxID_ANY, wxT("tool"), wxBitmap( table_row_up_xpm ), wxNullBitmap, wxITEM_NORMAL, wxT("Row Up"), wxEmptyString );
    m_tool_config->AddTool( wxID_ANY, wxT("tool"), wxBitmap( table_row_down_xpm ), wxNullBitmap, wxITEM_NORMAL, wxT("Row Down"), wxEmptyString );
    m_tool_config->AddSeparator();
    m_tool_config->AddTool( wxID_ANY, wxT("tool"), wxBitmap( table_replace_xpm ), wxNullBitmap, wxITEM_NORMAL, wxT("Sync Device"), wxEmptyString );
    m_tool_config->AddTool( wxID_ANY, wxT("tool"), wxBitmap( make_fw_xpm ), wxNullBitmap, wxITEM_NORMAL, wxT("Firmware code generate (F8)"), wxEmptyString );
    m_tool_config->AddSeparator();
    m_COM_Text = new wxStaticText( m_tool_config, wxID_ANY, wxT("COM port: "), wxDefaultPosition, wxDefaultSize, 0 );
    m_COM_Text->Wrap( -1 );
    m_tool_config->AddControl( m_COM_Text );
    wxArrayString m_COM_choiceChoices;
    m_COM_choice = new wxChoice( m_tool_config, wxID_ANY, wxDefaultPosition, wxSize( 70,-1 ), m_COM_choiceChoices, 0 );
    m_COM_choice->SetSelection( 0 );
    m_tool_config->AddControl( m_COM_choice );
    m_staticText5 = new wxStaticText( m_tool_config, wxID_ANY, wxT("-"), wxDefaultPosition, wxDefaultSize, 0 );
    m_staticText5->Wrap( -1 );
    m_staticText5->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );
    m_staticText5->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

    m_tool_config->AddControl( m_staticText5 );
    m_com_bitmap = new wxStaticBitmap( m_tool_config, wxID_ANY, wxBitmap( l_green_xpm ), wxDefaultPosition, wxDefaultSize, 0 );
    m_tool_config->AddControl( m_com_bitmap );
    m_staticText6 = new wxStaticText( m_tool_config, wxID_ANY, wxT("-"), wxDefaultPosition, wxDefaultSize, 0 );
    m_staticText6->Wrap( -1 );
    m_staticText6->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );
    m_staticText6->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

    m_tool_config->AddControl( m_staticText6 );
    m_tool_config->AddSeparator();
    m_tool_config->AddTool( wxID_ANY, wxT("tool"), wxBitmap( play_xpm ), wxNullBitmap, wxITEM_NORMAL, wxT("Show values"), wxEmptyString );
    m_tool_config->AddSeparator();
    m_tool_msg = new wxTextCtrl( m_tool_config, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 370,-1 ), 0|wxNO_BORDER );
    m_tool_msg->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

    m_tool_config->AddControl( m_tool_msg );
    m_tool_config->Realize();

    bSizer4->Add( m_tool_config, 0, wxEXPAND, 5 );

    m_staticline1 = new wxStaticLine( m_config_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    bSizer4->Add( m_staticline1, 0, wxEXPAND|wxBOTTOM, 5 );

    wxBoxSizer* bSizer5;
    bSizer5 = new wxBoxSizer( wxVERTICAL );

    m_grid = new wxGrid( m_config_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

    m_grid->CreateGrid( 0, 0 );
    m_grid->EnableEditing( true );
    m_grid->EnableGridLines( true );
    m_grid->EnableDragGridSize( false );
    m_grid->SetMargins( 0, 0 );

    m_grid->EnableDragColMove( false );
    m_grid->EnableDragColSize( true );
    m_grid->SetColLabelSize( 30 );
    m_grid->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );

    m_grid->EnableDragRowSize( true );
    m_grid->SetRowLabelSize( 80 );
    m_grid->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );

    m_grid->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
    bSizer5->Add( m_grid, 1, wxALL|wxEXPAND, 5 );

    bSizer4->Add( bSizer5, 1, wxEXPAND, 5 );

    m_config_panel->SetSizer( bSizer4 );
    m_config_panel->Layout();
    bSizer4->Fit( m_config_panel );
    m_auinotebook->AddPage( m_config_panel, wxT("Configure"), false, wxNullBitmap );
    m_log_panel = new wxPanel( m_auinotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
    wxBoxSizer* bSizer6;
    bSizer6 = new wxBoxSizer( wxVERTICAL );

    m_log = new wxTextCtrl( m_log_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY );
    bSizer6->Add( m_log, 1, wxALL|wxEXPAND, 5 );

    m_log_panel->SetSizer( bSizer6 );
    m_log_panel->Layout();
    bSizer6->Fit( m_log_panel );
    m_auinotebook->AddPage( m_log_panel, wxT("log"), false, wxNullBitmap );
    m_v = new wxPanel( m_auinotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
    wxBoxSizer* bSizer14;
    bSizer14 = new wxBoxSizer( wxVERTICAL );

    m_g = new wxGrid( m_v, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

    m_g->CreateGrid( 0, 0 );
    m_g->EnableEditing( true );
    m_g->EnableGridLines( true );
    m_g->EnableDragGridSize( false );
    m_g->SetMargins( 0, 0 );

    m_g->EnableDragColMove( false );
    m_g->EnableDragColSize( true );
    m_g->SetColLabelSize( 30 );
    m_g->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );

    m_g->EnableDragRowSize( true );
    m_g->SetRowLabelSize( 80 );
    m_g->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );

    m_g->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
    bSizer14->Add( m_g, 0, wxALL, 5 );

    m_v->SetSizer( bSizer14 );
    m_v->Layout();
    bSizer14->Fit( m_v );
    m_auinotebook->AddPage( m_v, wxT("var"), false, wxNullBitmap );

    bSizer2->Add( m_auinotebook, 1, wxEXPAND, 5 );

    m_panel1->SetSizer( bSizer2 );
    m_panel1->Layout();
    bSizer2->Fit( m_panel1 );
    bSizer1->Add( m_panel1, 1, wxEXPAND, 5 );

    this->SetSizer( bSizer1 );
    this->Layout();

    this->Centre( wxBOTH );

    m_dev_COM_choice->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyFrameFB::COM_OnChoice ), NULL, this );
    m_dev_grid->Connect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( MyFrameFB::OnDevGridLeftClick ), NULL, this );
    m_dev_grid->Connect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( MyFrameFB::OnDevGridLeftDClick ), NULL, this );
    m_dev_grid->Connect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( MyFrameFB::OnDevGridLabelLeftClick ), NULL, this );
    m_check_UART->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrameFB::On_check_UART1 ), NULL, this );
    m_check_USB_VCP->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrameFB::On_check_USB_VCP ), NULL, this );
    m_check_USB_console->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrameFB::On_check_USB_console ), NULL, this );
    m_check_CAN_Internal->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrameFB::On_check_CAN_Internal ), NULL, this );
    m_check_W5500->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrameFB::On_check_W5500 ), NULL, this );
    m_check_BME280->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrameFB::On_check_BME280 ), NULL, this );
    m_check_BH1750->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrameFB::On_check_BH1750 ), NULL, this );
    m_check_LCD1602->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrameFB::On_check_LCD1602 ), NULL, this );
    m_check_8574->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrameFB::On_check_PCF8574 ), NULL, this );
    m_check_8574A->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrameFB::On_check_PCF8574A ), NULL, this );
    m_check_SSD1306->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrameFB::On_check_SSD1306 ), NULL, this );
    m_check_MCO->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrameFB::On_check_MCO ), NULL, this );
    m_check_Timer->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrameFB::On_check_TIMER ), NULL, this );
    m_COM_choice->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyFrameFB::COM_OnChoice ), NULL, this );
}

MyFrameFB::~MyFrameFB()
{
    m_dev_COM_choice->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyFrameFB::COM_OnChoice ), NULL, this );
    m_dev_grid->Disconnect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( MyFrameFB::OnDevGridLeftClick ), NULL, this );
    m_dev_grid->Disconnect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( MyFrameFB::OnDevGridLeftDClick ), NULL, this );
    m_dev_grid->Disconnect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( MyFrameFB::OnDevGridLabelLeftClick ), NULL, this );
    m_check_UART->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrameFB::On_check_UART1 ), NULL, this );
    m_check_USB_VCP->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrameFB::On_check_USB_VCP ), NULL, this );
    m_check_USB_console->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrameFB::On_check_USB_console ), NULL, this );
    m_check_CAN_Internal->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrameFB::On_check_CAN_Internal ), NULL, this );
    m_check_W5500->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrameFB::On_check_W5500 ), NULL, this );
    m_check_BME280->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrameFB::On_check_BME280 ), NULL, this );
    m_check_BH1750->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrameFB::On_check_BH1750 ), NULL, this );
    m_check_LCD1602->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrameFB::On_check_LCD1602 ), NULL, this );
    m_check_8574->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrameFB::On_check_PCF8574 ), NULL, this );
    m_check_8574A->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrameFB::On_check_PCF8574A ), NULL, this );
    m_check_SSD1306->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrameFB::On_check_SSD1306 ), NULL, this );
    m_check_MCO->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrameFB::On_check_MCO ), NULL, this );
    m_check_Timer->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrameFB::On_check_TIMER ), NULL, this );
    m_COM_choice->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyFrameFB::COM_OnChoice ), NULL, this );
}

New_Project_FB::New_Project_FB( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    this->SetSizeHints( wxDefaultSize, wxDefaultSize );
    this->SetFont( wxFont( 10, 70, 90, 90, false, wxEmptyString ) );

    wxBoxSizer* bSizer15;
    bSizer15 = new wxBoxSizer( wxVERTICAL );

    m_panel6 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
    wxBoxSizer* bSizer16;
    bSizer16 = new wxBoxSizer( wxVERTICAL );

    wxFlexGridSizer* fgSizer1;
    fgSizer1 = new wxFlexGridSizer( 2, 2, 0, 0 );
    fgSizer1->SetFlexibleDirection( wxBOTH );
    fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

    m_staticText19 = new wxStaticText( m_panel6, wxID_ANY, wxT("MCU / Device :"), wxDefaultPosition, wxDefaultSize, 0 );
    m_staticText19->Wrap( -1 );
    fgSizer1->Add( m_staticText19, 0, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );

    wxArrayString m_choice_MCUChoices;
    m_choice_MCU = new wxChoice( m_panel6, wxID_ANY, wxDefaultPosition, wxSize( 200,-1 ), m_choice_MCUChoices, 0 );
    m_choice_MCU->SetSelection( 0 );
    fgSizer1->Add( m_choice_MCU, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );

    m_staticText20 = new wxStaticText( m_panel6, wxID_ANY, wxT("Project Name :"), wxDefaultPosition, wxDefaultSize, 0 );
    m_staticText20->Wrap( -1 );
    fgSizer1->Add( m_staticText20, 0, wxALIGN_RIGHT|wxBOTTOM|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );

    m_project_name = new wxTextCtrl( m_panel6, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 400,-1 ), 0 );
    fgSizer1->Add( m_project_name, 0, wxBOTTOM|wxRIGHT|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );

    m_staticText21 = new wxStaticText( m_panel6, wxID_ANY, wxT("Project path and Name :"), wxDefaultPosition, wxDefaultSize, 0 );
    m_staticText21->Wrap( -1 );
    fgSizer1->Add( m_staticText21, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxLEFT, 5 );

    wxBoxSizer* bSizer17;
    bSizer17 = new wxBoxSizer( wxHORIZONTAL );

    m_path_project_name = new wxTextCtrl( m_panel6, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 400,-1 ), 0 );
    bSizer17->Add( m_path_project_name, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxLEFT, 5 );

    m_dir = new wxDirPickerCtrl( m_panel6, wxID_ANY, wxEmptyString, wxT("Select a folder"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
    bSizer17->Add( m_dir, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );

    fgSizer1->Add( bSizer17, 1, wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );

    m_staticText23 = new wxStaticText( m_panel6, wxID_ANY, wxT("Comment :"), wxDefaultPosition, wxDefaultSize, 0 );
    m_staticText23->Wrap( -1 );
    fgSizer1->Add( m_staticText23, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxBOTTOM|wxLEFT, 5 );

    m_comment = new wxTextCtrl( m_panel6, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 400,-1 ), 0 );
    fgSizer1->Add( m_comment, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

    bSizer16->Add( fgSizer1, 1, wxTOP|wxBOTTOM, 5 );

    m_staticline16 = new wxStaticLine( m_panel6, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    bSizer16->Add( m_staticline16, 0, wxEXPAND, 5 );

    m_sdb = new wxStdDialogButtonSizer();
    m_sdbOK = new wxButton( m_panel6, wxID_OK );
    m_sdb->AddButton( m_sdbOK );
    m_sdbCancel = new wxButton( m_panel6, wxID_CANCEL );
    m_sdb->AddButton( m_sdbCancel );
    m_sdb->Realize();
    bSizer16->Add( m_sdb, 0, wxALIGN_RIGHT|wxTOP|wxBOTTOM, 5 );

    m_panel6->SetSizer( bSizer16 );
    m_panel6->Layout();
    bSizer16->Fit( m_panel6 );
    bSizer15->Add( m_panel6, 1, wxEXPAND, 5 );

    this->SetSizer( bSizer15 );
    this->Layout();
    bSizer15->Fit( this );

    this->Centre( wxBOTH );
}

New_Project_FB::~New_Project_FB()
{
}

Open_Project_FB::Open_Project_FB( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    this->SetSizeHints( wxDefaultSize, wxDefaultSize );
    this->SetFont( wxFont( 10, 70, 90, 90, false, wxEmptyString ) );

    wxBoxSizer* bSizer18;
    bSizer18 = new wxBoxSizer( wxVERTICAL );

    m_panel7 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
    wxBoxSizer* bSizer19;
    bSizer19 = new wxBoxSizer( wxVERTICAL );

    wxBoxSizer* bSizer20;
    bSizer20 = new wxBoxSizer( wxHORIZONTAL );

    m_staticText24 = new wxStaticText( m_panel7, wxID_ANY, wxT("File :"), wxDefaultPosition, wxDefaultSize, 0 );
    m_staticText24->Wrap( -1 );
    bSizer20->Add( m_staticText24, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );

    m_file = new wxFilePickerCtrl( m_panel7, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("*.*"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE );
    bSizer20->Add( m_file, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

    bSizer19->Add( bSizer20, 1, wxEXPAND, 5 );

    m_staticline17 = new wxStaticLine( m_panel7, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    bSizer19->Add( m_staticline17, 0, wxEXPAND|wxTOP|wxBOTTOM, 5 );

    m_sdbSizer2 = new wxStdDialogButtonSizer();
    m_sdbSizer2OK = new wxButton( m_panel7, wxID_OK );
    m_sdbSizer2->AddButton( m_sdbSizer2OK );
    m_sdbSizer2Cancel = new wxButton( m_panel7, wxID_CANCEL );
    m_sdbSizer2->AddButton( m_sdbSizer2Cancel );
    m_sdbSizer2->Realize();
    bSizer19->Add( m_sdbSizer2, 1, wxEXPAND|wxALIGN_RIGHT|wxBOTTOM, 5 );

    m_panel7->SetSizer( bSizer19 );
    m_panel7->Layout();
    bSizer19->Fit( m_panel7 );
    bSizer18->Add( m_panel7, 1, wxEXPAND, 5 );

    this->SetSizer( bSizer18 );
    this->Layout();

    this->Centre( wxBOTH );
}

Open_Project_FB::~Open_Project_FB()
{
}

Set_COM_SPEED_FB::Set_COM_SPEED_FB( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    this->SetSizeHints( wxDefaultSize, wxDefaultSize );
    this->SetFont( wxFont( 10, 70, 90, 90, false, wxEmptyString ) );

    wxBoxSizer* bSizer21;
    bSizer21 = new wxBoxSizer( wxVERTICAL );

    m_panel8 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
    wxBoxSizer* bSizer22;
    bSizer22 = new wxBoxSizer( wxVERTICAL );

    wxFlexGridSizer* fgSizer2;
    fgSizer2 = new wxFlexGridSizer( 1, 2, 0, 0 );
    fgSizer2->SetFlexibleDirection( wxBOTH );
    fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

    wxBoxSizer* bSizer23;
    bSizer23 = new wxBoxSizer( wxHORIZONTAL );

    bSizer23->Add( 20, 0, 1, wxEXPAND, 5 );

    m_staticText25 = new wxStaticText( m_panel8, wxID_ANY, wxT("COM speed : "), wxDefaultPosition, wxDefaultSize, 0 );
    m_staticText25->Wrap( -1 );
    bSizer23->Add( m_staticText25, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxTOP|wxBOTTOM|wxLEFT, 5 );

    fgSizer2->Add( bSizer23, 1, wxEXPAND, 5 );

    wxString m_choice4Choices[] = { wxT("300"), wxT("600"), wxT("1200"), wxT("2400"), wxT("4800"), wxT("9600"), wxT("19200"), wxT("38400"), wxT("57600"), wxT("115200"), wxT("230400"), wxT("460800"), wxT("921600") };
    int m_choice4NChoices = sizeof( m_choice4Choices ) / sizeof( wxString );
    m_choice4 = new wxChoice( m_panel8, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice4NChoices, m_choice4Choices, 0 );
    m_choice4->SetSelection( 9 );
    fgSizer2->Add( m_choice4, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxRIGHT, 5 );

    bSizer22->Add( fgSizer2, 1, wxEXPAND|wxLEFT|wxRIGHT|wxTOP, 5 );

    m_sdbSizer3 = new wxStdDialogButtonSizer();
    m_sdbSizer3OK = new wxButton( m_panel8, wxID_OK );
    m_sdbSizer3->AddButton( m_sdbSizer3OK );
    m_sdbSizer3Cancel = new wxButton( m_panel8, wxID_CANCEL );
    m_sdbSizer3->AddButton( m_sdbSizer3Cancel );
    m_sdbSizer3->Realize();
    bSizer22->Add( m_sdbSizer3, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxBOTTOM|wxLEFT|wxTOP, 5 );

    m_panel8->SetSizer( bSizer22 );
    m_panel8->Layout();
    bSizer22->Fit( m_panel8 );
    bSizer21->Add( m_panel8, 1, wxEXPAND, 5 );

    this->SetSizer( bSizer21 );
    this->Layout();
    bSizer21->Fit( this );

    this->Centre( wxBOTH );
}

Set_COM_SPEED_FB::~Set_COM_SPEED_FB()
{
}

MyDialog4::MyDialog4( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    this->SetSizeHints( wxDefaultSize, wxDefaultSize );

    wxBoxSizer* bSizer30;
    bSizer30 = new wxBoxSizer( wxVERTICAL );

    m_panel9 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
    bSizer30->Add( m_panel9, 1, wxEXPAND, 5 );

    this->SetSizer( bSizer30 );
    this->Layout();
    bSizer30->Fit( this );

    this->Centre( wxBOTH );
}

MyDialog4::~MyDialog4()
{
}
