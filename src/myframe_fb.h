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
#include <wx/filepicker.h>
#include <wx/button.h>
#include <wx/dialog.h>

#define ID_TOOL_NEW_PRJ 1000
#define ID_TOOL_OPEN_PRJ 1001
#define ID_TOOL_SAVE 1002
#define ID_TOOL_CLOSE_PRJ 1003
#define ID_TOOL_EXIT 1004
#define ID_TOOL_SHVAL 1005
#define ID_TOOL_GENERATE 1006
#define ID_DEV_ADD_ROW 1007
#define ID_DEV_DEL_ROW 1008
#define ID_DEV_ROW_UP 1009
#define ID_DEV_ROW_DOWN 1010
#define ID_EDIT_CONF 1011
#define ID_DEV_SEARCH 1012
#define ID_DEV_RUN 1013
#define ID_UART 1014
#define ID_USB_VCP 1015
#define ID_UART2 1016
#define ID_UART2_CONFIG 1017
#define ID_CAN 1018
#define ID_CAN_CFG 1019
#define ID_W5500 1020
#define ID_ETH_CFG 1021
#define ID_BME280 1022
#define ID_BH1750 1023
#define ID_CCS811 1024
#define ID_EC11 1025
#define ID_EC11_CONFIG 1026
#define ID_PC13 1027
#define ID_1602_4 1028
#define ID_1602 1029
#define ID_PCF8574 1030
#define ID_PCF8574T 1031
#define ID_SSD1306 1032
#define ID_WATCHDOG 1033
#define ID_MCO 1034
#define ID_IBUTTON 1035
#define ID_TIMER 1036
#define ID_TIMER_CONFIG 1037
#define ID_PWM 1038
#define ID_PWM_PB6 1039
#define ID_PWM_PB7 1040
#define ID_PWM_PB8 1041
#define ID_PWM_PB9 1042
#define ID_MODBUS 1043
#define ID_MODBUS_CONFIG 1044
#define ID_CFG_ADD_ROW 1045

class MyFrameFB : public wxFrame
{
    private:
    protected:
        wxMenuBar* m_menubar;
        wxMenu* m_menu_file;
        wxMenu* m_menu_tools;
        wxStatusBar* m_statusBar1;
        wxPanel* m_panel1;
        wxToolBar* m_main_tool;
        wxStaticText* m_staticText1;
        wxTextCtrl* m_text_mcu;
        wxStaticText* m_staticText3;
        wxStaticText* m_staticText2;
        wxTextCtrl* m_text_comment;
        wxAuiNotebook* m_auinotebook;
        wxPanel* m_device_panel;
        wxToolBar* m_tool_data;
        wxStaticText* m_dev_COM_Text;
        wxChoice* m_dev_COM_choice;
        wxStaticText* m_staticText51;
        wxStaticBitmap* m_dev_com_bitmap;
        wxStaticText* m_staticText61;
        wxTextCtrl* m_dev_tool_msg;
        wxStaticLine* m_staticline12;
        wxScrolledWindow* m_interfaces_window;
        wxToolBar* m_tool_UART;
        wxCheckBox* m_check_UART;
        wxStaticLine* m_staticline25;
        wxCheckBox* m_check_USB_VCP;
        wxCheckBox* m_check_USB_console;
        wxStaticLine* m_staticline24;
        wxCheckBox* m_check_UART2;
        wxCheckBox* m_check_UART2_485;
        wxToolBar* m_toolBar9;
        wxToolBar* m_tool_CAN;
        wxCheckBox* m_check_CAN_Internal;
        wxToolBar* m_tool_Ethernet;
        wxCheckBox* m_check_W5500;
        wxStaticLine* m_staticline_interfaces;
        wxToolBar* m_toolBarSensor;
        wxCheckBox* m_check_BME280;
        wxStaticText* m_staticText10;
        wxCheckBox* m_check_BH1750;
        wxStaticText* m_staticText11;
        wxCheckBox* m_check_CCS811;
        wxStaticText* m_staticText12;
        wxCheckBox* m_check_EC11;
        wxStaticLine* m_staticline_sensors;
        wxCheckBox* m_check_PC13;
        wxCheckBox* m_check_LCD1602_4;
        wxStaticLine* m_staticline5;
        wxStaticLine* m_staticline3;
        wxCheckBox* m_check_LCD1602;
        wxStaticLine* m_staticline4;
        wxCheckBox* m_check_8574;
        wxCheckBox* m_check_8574A;
        wxStaticLine* m_staticline11;
        wxStaticLine* m_staticline6;
        wxStaticLine* m_staticline8;
        wxCheckBox* m_check_SSD1306;
        wxStaticLine* m_staticline9;
        wxStaticText* m_staticText7;
        wxStaticLine* m_staticline10;
        wxStaticLine* m_staticline7;
        wxStaticLine* m_staticline_indicators;
        wxToolBar* m_toolBarSystem;
        wxCheckBox* m_check_WatchDog;
        wxStaticText* m_staticText13;
        wxCheckBox* m_check_MCO;
        wxStaticText* m_staticText14;
        wxStaticText* m_text_ibt_fix_time;
        wxTextCtrl* m_ibt_fix_time;
        wxStaticText* m_staticText9;
        wxStaticText* m_staticText15;
        wxCheckBox* m_check_Timer;
        wxStaticLine* m_staticline22;
        wxStaticLine* m_staticline19;
        wxCheckBox* m_check_PWM;
        wxStaticLine* m_staticline20;
        wxCheckBox* m_check_PWM_PB6;
        wxCheckBox* m_check_PWM_PB7;
        wxCheckBox* m_check_PWM_PB8;
        wxCheckBox* m_check_PWM_PB9;
        wxStaticLine* m_staticline21;
        wxStaticLine* m_staticline23;
        wxStaticLine* m_staticline_system;
        wxCheckBox* m_check_MODBUS;
        wxToolBar* m_toolBarMODBUS;
        wxStaticLine* m_staticline26;
        wxPanel* m_config_panel;
        wxStaticText* m_header;
        wxStaticLine* m_staticline18;
        wxToolBar* m_tool_config;
        wxStaticText* m_COM_Text;
        wxChoice* m_COM_choice;
        wxStaticText* m_staticText5;
        wxStaticBitmap* m_com_bitmap;
        wxStaticText* m_staticText6;
        wxTextCtrl* m_tool_msg;
        wxStaticLine* m_staticline1;
        wxGrid* m_grid;
        wxPanel* m_log_panel;
        wxTextCtrl* m_log;
        wxPanel* m_v;

        virtual void COM_OnChoice( wxCommandEvent& event ) { event.Skip(); }
        virtual void OnDevGridLeftClick( wxGridEvent& event ) { event.Skip(); }
        virtual void OnDevGridLeftDClick( wxGridEvent& event ) { event.Skip(); }
        virtual void OnDevGridLabelLeftClick( wxGridEvent& event ) { event.Skip(); }
        virtual void On_check_UART1( wxCommandEvent& event ) { event.Skip(); }
        virtual void On_check_USB_VCP( wxCommandEvent& event ) { event.Skip(); }
        virtual void On_check_USB_console( wxCommandEvent& event ) { event.Skip(); }
        virtual void On_check_CAN_Internal( wxCommandEvent& event ) { event.Skip(); }
        virtual void On_check_W5500( wxCommandEvent& event ) { event.Skip(); }
        virtual void On_check_BME280( wxCommandEvent& event ) { event.Skip(); }
        virtual void On_check_BH1750( wxCommandEvent& event ) { event.Skip(); }
        virtual void On_check_LCD1602( wxCommandEvent& event ) { event.Skip(); }
        virtual void On_check_PCF8574( wxCommandEvent& event ) { event.Skip(); }
        virtual void On_check_PCF8574A( wxCommandEvent& event ) { event.Skip(); }
        virtual void On_check_SSD1306( wxCommandEvent& event ) { event.Skip(); }
        virtual void On_check_MCO( wxCommandEvent& event ) { event.Skip(); }
        virtual void On_check_TIMER( wxCommandEvent& event ) { event.Skip(); }

    public:
        wxGrid* m_dev_grid;
        wxStaticBoxSizer* sbSizerInterfaces;
        wxStaticBoxSizer* sbSizerSerial;
        wxBoxSizer* bSizerUSB;
        wxStaticBoxSizer* sbSizerCAN;
        wxStaticBoxSizer* sbSizerEth;
        wxStaticBoxSizer* sbSizerSensors;
        wxStaticBoxSizer* sbSizerIndicators;
        wxStaticBoxSizer* sbSizerLED;
        wxStaticBoxSizer* sbSizerDisplayI2C;
        wxStaticBoxSizer* sbSizerSystem;
        wxStaticBoxSizer* sbSizerProtocols;
        wxGrid* m_g;
        MyFrameFB( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,600 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
        ~MyFrameFB();
};

class New_Project_FB : public wxDialog
{
    private:
    protected:
        wxPanel* m_panel6;
        wxStaticText* m_staticText19;
        wxChoice* m_choice_MCU;
        wxStaticText* m_staticText20;
        wxTextCtrl* m_project_name;
        wxStaticText* m_staticText21;
        wxTextCtrl* m_path_project_name;
        wxDirPickerCtrl* m_dir;
        wxStaticText* m_staticText23;
        wxTextCtrl* m_comment;
        wxStaticLine* m_staticline16;
        wxStdDialogButtonSizer* m_sdb;
        wxButton* m_sdbOK;
        wxButton* m_sdbCancel;

    public:
        New_Project_FB( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Create new project"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
        ~New_Project_FB();
};

class Open_Project_FB : public wxDialog
{
    private:
    protected:
        wxPanel* m_panel7;
        wxStaticText* m_staticText24;
        wxFilePickerCtrl* m_file;
        wxStaticLine* m_staticline17;
        wxStdDialogButtonSizer* m_sdbSizer2;
        wxButton* m_sdbSizer2OK;
        wxButton* m_sdbSizer2Cancel;

    public:
        Open_Project_FB( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Open project"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 700,-1 ), long style = wxDEFAULT_DIALOG_STYLE );
        ~Open_Project_FB();
};

class Set_COM_SPEED_FB : public wxDialog
{
    private:
    protected:
        wxPanel* m_panel8;
        wxStaticText* m_staticText25;
        wxChoice* m_choice4;
        wxStdDialogButtonSizer* m_sdbSizer3;
        wxButton* m_sdbSizer3OK;
        wxButton* m_sdbSizer3Cancel;

    public:
        Set_COM_SPEED_FB( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Set COM speed"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE );
        ~Set_COM_SPEED_FB();
};

class MyDialog4 : public wxDialog
{
    private:
    protected:
        wxPanel* m_panel9;

    public:
        MyDialog4( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
        ~MyDialog4();
};

#endif
