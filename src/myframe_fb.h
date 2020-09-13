/*
	Name:
	Purpose:
	Author:			www.open-plc.com
	Created:		2020/07
	Modified by:
	RCS-ID:
	Copyright:
	Licence:		The MIT License (MIT)
*/


#ifndef __myframe_fb__
#define __myframe_fb__
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/statusbr.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/toolbar.h>
#include <wx/choice.h>
#include <wx/statbmp.h>
#include <wx/statline.h>
#include <wx/grid.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/checkbox.h>
#include <wx/statbox.h>
#include <wx/scrolwin.h>
#include <wx/aui/auibook.h>
#include <wx/frame.h>
#define ID_TOOL_NEW_PRJ 1000
#define ID_TOOL_OPEN_PRJ 1001
#define ID_TOOL_SAVE 1002
#define ID_TOOL_CLOSE_PRJ 1003
#define ID_TOOL_EXIT 1004
#define ID_TOOL_SHVAL 1005
#define ID_TOOL_GENERATE 1006
#define ID_TOOL_INS_DEV_ROW 1007
#define ID_TOOL_DEL_DEV_ROW 1008
#define ID_TOOL_DEV_ROW_UP 1009
#define ID_TOOL_DEV_ROW_DOWN 1010
#define ID_DEV_TOOL_RUN 1011
#define ID_UART 1012
#define ID_USB_VCP 1013
#define ID_CAN 1014
#define ID_TOOL_CAN_CFG 1015
#define ID_W5500 1016
#define ID_TOOL_ETH_CFG 1017
#define ID_BME280 1018
#define ID_BH1750 1019
#define ID_CCS811 1020
#define ID_EC11 1021
#define ID_TOOL_EC11_CONFIG 1022
#define ID_PC13 1023
#define ID_1602_4 1024
#define ID_1602 1025
#define ID_SSD1306 1026
#define ID_MCO 1027
#define ID_TOOL_TIMER_CONFIG 1028
#define ID_TOOL_INS_ROW 1029
#define ID_TOOL_DEL_ROW 1030
#define ID_TOOL_ROW_UP 1031
#define ID_TOOL_ROW_DOWN 1032
#define ID_TOOL_RUN 1033
class MyFrameFB : public wxFrame
{
private:
protected:
wxMenuBar *m_menubar;
wxMenu *m_menu_file;
wxMenu *m_menu_tools;
wxStatusBar *m_statusBar1;
wxPanel *m_panel1;
wxToolBar *m_main_tool;
wxStaticText *m_staticText1;
wxTextCtrl *m_text_mcu;
wxStaticText *m_staticText3;
wxStaticText *m_staticText2;
wxTextCtrl *m_text_comment;
wxAuiNotebook *m_auinotebook;
wxPanel *m_device_panel;
wxToolBar *m_tool_data1;
wxStaticText *m_dev_COM_Text;
wxChoice *m_dev_COM_choice;
wxStaticText *m_staticText51;
wxStaticBitmap *m_dev_com_bitmap;
wxStaticText *m_staticText61;
wxTextCtrl *m_dev_tool_msg;
wxStaticLine *m_staticline12;
wxScrolledWindow *m_interfaces_window;
wxToolBar *m_tool_UART;
wxCheckBox *m_check_UART;
wxCheckBox *m_check_USB_VCP;
wxCheckBox *m_check_USB_console;
wxToolBar *m_tool_CAN;
wxCheckBox *m_check_CAN_Internal;
wxToolBar *m_tool_Ethernet;
wxCheckBox *m_check_W5500;
wxStaticLine *m_staticline_interfaces;
wxToolBar *m_toolBarSensor;
wxCheckBox *m_check_BME280;
wxStaticText *m_staticText10;
wxCheckBox *m_check_BH1750;
wxStaticText *m_staticText11;
wxCheckBox *m_check_CCS811;
wxStaticText *m_staticText12;
wxCheckBox *m_check_EC11;
wxStaticLine *m_staticline_sensors;
wxCheckBox *m_check_PC13;
wxCheckBox *m_check_LCD1602_4;
wxStaticLine *m_staticline5;
wxStaticLine *m_staticline3;
wxCheckBox *m_check_LCD1602;
wxStaticLine *m_staticline4;
wxCheckBox *m_check_8574;
wxCheckBox *m_check_8574A;
wxStaticLine *m_staticline11;
wxStaticLine *m_staticline6;
wxStaticLine *m_staticline8;
wxCheckBox *m_check_SSD1306;
wxStaticLine *m_staticline9;
wxStaticText *m_staticText7;
wxStaticLine *m_staticline10;
wxStaticLine *m_staticline7;
wxStaticLine *m_staticline_indicators;
wxToolBar *m_toolBarSystem;
wxCheckBox *m_check_WatchDog;
wxStaticText *m_staticText13;
wxCheckBox *m_check_MCO;
wxStaticText *m_staticText14;
wxStaticText *m_text_ibt_fix_time;
wxTextCtrl *m_ibt_fix_time;
wxStaticText *m_staticText9;
wxStaticText *m_staticText15;
wxCheckBox *m_check_Timer;
wxStaticLine *m_staticline_system;
wxPanel *m_config_panel;
wxToolBar *m_tool_data;
wxStaticText *m_COM_Text;
wxChoice *m_COM_choice;
wxStaticText *m_staticText5;
wxStaticBitmap *m_com_bitmap;
wxStaticText *m_staticText6;
wxTextCtrl *m_tool_msg;
wxStaticLine *m_staticline1;
wxGrid *m_grid;
wxPanel *m_log_panel;
wxTextCtrl *m_log;
wxPanel *m_v;
virtual void OnAuiChanged( wxAuiNotebookEvent &event ) { event.Skip(); }
virtual void COM_OnChoice( wxCommandEvent &event ) { event.Skip(); }
virtual void OnToolRUN( wxCommandEvent &event ) { event.Skip(); }
virtual void On_check_UART1( wxCommandEvent &event ) { event.Skip(); }
virtual void On_check_USB_VCP( wxCommandEvent &event ) { event.Skip(); }
virtual void On_check_USB_console( wxCommandEvent &event ) { event.Skip(); }
virtual void On_check_CAN_Internal( wxCommandEvent &event ) { event.Skip(); }
virtual void On_check_W5500( wxCommandEvent &event ) { event.Skip(); }
virtual void On_check_BME280( wxCommandEvent &event ) { event.Skip(); }
virtual void On_check_BH1750( wxCommandEvent &event ) { event.Skip(); }
virtual void On_check_LCD1602( wxCommandEvent &event ) { event.Skip(); }
virtual void On_check_PCF8574( wxCommandEvent &event ) { event.Skip(); }
virtual void On_check_PCF8574A( wxCommandEvent &event ) { event.Skip(); }
virtual void On_check_SSD1306( wxCommandEvent &event ) { event.Skip(); }
virtual void On_check_MCO( wxCommandEvent &event ) { event.Skip(); }
virtual void On_check_TIMER( wxCommandEvent &event ) { event.Skip(); }
public:
wxGrid *m_dev_grid;
wxStaticBoxSizer *sbSizerInterfaces;
wxStaticBoxSizer *sbSizerSerial;
wxBoxSizer *bSizerUSB;
wxStaticBoxSizer *sbSizerCAN;
wxStaticBoxSizer *sbSizerEth;
wxStaticBoxSizer *sbSizerSensors;
wxStaticBoxSizer *sbSizerIndicators;
wxStaticBoxSizer *sbSizerLED;
wxStaticBoxSizer *sbSizerDisplayI2C;
wxStaticBoxSizer *sbSizerSystem;
wxGrid *m_g;
MyFrameFB( wxWindow *parent, wxWindowID id = wxID_ANY, const wxString &title = wxEmptyString, const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxSize( 800,600 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
~MyFrameFB();
};
#endif
