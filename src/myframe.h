/*
	Name:			myframe.h
	Purpose:		MIOC
	Author:			www.open-plc.com
	Created:		2019/07
	Modified by:
	RCS-ID:
	Copyright:		(c) Open-PLC
	Licence:		The MIT License (MIT)
*/


#ifndef __MyFrame__
#define __MyFrame__

#include <wx/msgdlg.h>
#include "myframe_fb.h"

//class Run_Thread;
//class Data_Thread;
class Read_COM_Thread;
class Write_COM_Thread;


// ===========================================================================
class MyFrame : public MyFrameFB
// ===========================================================================
{
	private:
		DECLARE_EVENT_TABLE()

	public:
		MyFrame( wxWindow		*parent,
				 wxWindowID		 id		= wxID_ANY,
				 const wxString	&title	= wxEmptyString,
				 const wxPoint	&pos	= wxDefaultPosition,
				 const wxSize	&size	= wxSize( 800,600 ),
				 long			 style	= wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL );
		~MyFrame();

//		wxGridCellChoiceEditor	*ce2, *ce3, *ce5;
//		wxString				 cs5[3];
		wxArrayString			 port_list;

void Init_Grid_Dev( void );
//void Init_Grid_Dev( void );




//		volatile struct M_Grid_Struct
//		{
//			wxString	c0;
//			int			c2;
//			int			c3;
//			wxString	c4;
//			int			c5;
//		};
//		//} m_grid_rc;
//		M_Grid_Struct	m_grid_r[MAX_GRID_NN];
//		M_Grid_Struct	m_grid_rc;
//
////		DataIO_Com		*io_com;
//
//		void	Help( char *str, int len );
//		int		OnPathInit();
//		int		Read_Prj();
//		void	Write_Prj();
//		int		Read_Cfg();
//		void	Write_Cfg();
//
//		// Config
//		void	Disable_Config( void );
//		void	Enable_Config( void );
//		int		Set_Lists( void );
//		void	Clear_Project( void );
//		bool	Parse_Port( wxString port, unsigned int *port_name, unsigned int *port_nn );
//		bool	Check_Port( wxString port, unsigned int row );
//		void	Check_Config( void );
//
//		wxBitmap	wxGetBitmapFromMemory( const void *data, size_t length );
//
//		//bool					CheckStartStop;
//		//static volatile bool	IsRun;
//
//		Read_COM_Thread		*Create_Read_COM_Thread(), *read_com_thread_ptr;
//		Write_COM_Thread	*Create_Write_COM_Thread(), *write_com_thread_ptr;
//
////void Set_MDK_prj_stm32f103c8( wxString *buf, wxString prj_name );

		// Static event handlers
// 		void OnTool_New_Prj( wxCommandEvent &event );
//		void OnTool_Open_Prj( wxCommandEvent &event );
//		void OnTool_Close_Prj( wxCommandEvent &event );
// 		void OnTool_Save_Prj( wxCommandEvent &event );
// 		void OnExit( wxCommandEvent &event );
//
//		void OnMaximized( wxMaximizeEvent &event );
//		void OnSize( wxSizeEvent &event );
//		void OnMove( wxMoveEvent &event );
//
//		void OnTool_COM_config( wxCommandEvent &event );
//		void OnTool_UART1_config( wxCommandEvent &event );
//		void OnTool_UART_help( wxCommandEvent &event );
//		void OnTool_connect( wxCommandEvent &event );
//		void OnTool_COM_connect( wxCommandEvent &event );
//		void OnTool_COM_disconnect( wxCommandEvent &event );
//		void OnTool_Run( wxCommandEvent &event );
//
//		void OnTool_I2C_help( wxCommandEvent &event );
//		void OnTool_BME280_Help( wxCommandEvent &event );
//		void OnTool_BH1750_Help( wxCommandEvent &event );
//		void OnTool_CCS811_Help( wxCommandEvent &event );
//
//		void OnCANHelp( wxCommandEvent &event );
//		void OnMyAbout( wxCommandEvent &event );
//		void OnMyFunctions( wxCommandEvent &event );
//		void OnTool_Generate_FW( wxCommandEvent &event );
//		void Asc_to_Save( void );

		// Grid handlers
//		void OnCellValueChanged( wxGridEvent& );
//		void Save_Rows( void );
//		void OnDelRow( wxCommandEvent &event );
//		void OnInsRow( wxCommandEvent &event );
//		void OnRowUp( wxCommandEvent &event );
//		void OnRowDown( wxCommandEvent &event );

//		void OnConnect( wxCommandEvent &event );
//		void OnRefresh( wxCommandEvent &event );
//		void OnRun( wxCommandEvent &event );
//		void OnStop( wxCommandEvent &event );
//		void OnFile( wxCommandEvent &event );
//		void ActualSize( wxCommandEvent &event );
//		void ZoneSize( wxCommandEvent &event );

		// Virtual event handlers
		void OnAuiChanged( wxAuiNotebookEvent& event );

//		void On_check_UART1( wxCommandEvent &event );
//		void On_check_USB_VCP( wxCommandEvent &event );
//		void On_check_USB_console( wxCommandEvent &event );
//		void On_check_CAN_Internal( wxCommandEvent& event );
//		void On_check_CAN_MCP2515( wxCommandEvent& event );
//		void On_check_W5500( wxCommandEvent& event );
//		void On_check_PC13( wxCommandEvent& event );
//		void On_check_LCD1602( wxCommandEvent& event );
//		void On_check_PCF8574( wxCommandEvent& event );
//		void On_check_PCF8574A( wxCommandEvent& event );
//		void On_check_SSD1306( wxCommandEvent& event );
//		void On_check_BME280( wxCommandEvent& event );
//		void On_check_BH1750( wxCommandEvent& event );
//		void On_check_WATCHDOG( wxCommandEvent& event );
//		void On_check_MCO( wxCommandEvent& event );
//		void On_check_TIMER( wxCommandEvent& event );
};
// ===========================================================================


// ===========================================================================
class myImageGridCellRenderer : public wxGridCellStringRenderer
// ===========================================================================
{
    public:
        wxBitmap bitmap;
        myImageGridCellRenderer( wxBitmap bm ) { bitmap = bm; }

        virtual void Draw( wxGrid           &grid,
                           wxGridCellAttr   &attr,
                           wxDC             &dc,
                           const wxRect     &rect,
                           int               row,
                           int               col,
                           bool              isSelected )
        {
            wxGridCellStringRenderer::Draw( grid, attr, dc, rect, row, col, isSelected );
            dc.DrawBitmap( bitmap, rect.x, rect.y );
        }
};
// ===========================================================================


#endif	// __MyFrame__
