/*
	Name:			gbl.h
	Purpose:		CFM
	Author:			www.open-plc.com
	Created:		2020/07
	Modified by:
	RCS-ID:
	Copyright:		(c) Open-PLC
	Licence:		The MIT License (MIT)
*/


#ifndef __GBL__
#define __GBL__

#ifdef WIN32	// if Win then declare nix-like types
	#define		int8_t		__int8
	#define		int16_t		__int16
	#define		int32_t		__int32
	#define		int64_t		__int64
	#define		uint8_t		unsigned __int8
	#define		uint16_t	unsigned __int16
	#define		uint32_t	unsigned __int32
	#define		uint64_t	unsigned __int64
#endif			// WIN32

#define MAX_GRID_NN 256

#define WW ID_W5500




//#include "dataio_com.h"

static wxString		EXEC_PATH;
static wxString		DATA_DIR;
static wxString		WORK_PATH;
static wxChar		PATH_SEP;
static wxString		S_NAME;
static wxString		S_EXT;
static wxString		PROJECT_DIR;

static bool			Win_MaxSize			= false;
static bool			Read_Win_MaxSize	= false;
static int			Win_PosX			= 0;
static int			Win_PosY			= 0;
static int			Win_SizeX			= 0;
static int			Win_SizeY			= 0;

static volatile bool	PRJ_CHANGED		= false;
static wxString			PRJ_NAME		= wxEmptyString;
static wxString			PRJ_MCU			= wxEmptyString;
static wxString			PRJ_COMMENT		= wxEmptyString;

#define MAX_PORT_NN 49
static volatile int				PORT_NN	= 0;
static volatile unsigned int	FW_SN	= 0;
static wxString SEL_PORT[MAX_PORT_NN];

static int				COM_NN			= -1;
static int				COM_SPEED		= -1;
//DataIO_Com				*IO_COM			= new DataIO_Com();
static volatile bool	ENABLE_CONNECT	= false;
static volatile bool	TRY_TO_CONNECT	= false;
static volatile bool	IS_CONNECTED	= false;
static volatile bool	RUN				= false;

static int				UART1_SPEED		= -1;

//wxGrid *c_grid;

const wxString DEV_TYPES[] =
{
	wxT( "STM32F103C8T6" ),
	wxT( "STM32F303CBT6" ),
	wxT( "STM32F303CBT6/PLC" ),
//	wxT( "" ),
};

const wxString VAR_1XX_TYPES[] =
{
	wxEmptyString,
	wxT( "bool" ),
	wxT( "int8" ),
	wxT( "unsigned int8" ),
	wxT( "int16" ),
	wxT( "unsigned int16" ),
	wxT( "int32" ),
	wxT( "unsigned int32" ),
	wxT( "int64" ),
	wxT( "unsigned int64" ),
	wxT( "float" ),
	wxT( "double" ),

	wxT( "GPIO_Mode_AIN" ),
	wxT( "GPIO_Mode_IN_FLOATING" ),
	wxT( "GPIO_Mode_IPD" ),
	wxT( "GPIO_Mode_IPU" ),
	wxT( "GPIO_Mode_Out_OD" ),
	wxT( "GPIO_Mode_Out_PP" ),

	wxT( "DS18B20" ),
	wxT( "iButton" ),
	wxT( "LCD_1602_STR_1" ),
	wxT( "LCD_1602_STR_2" ),
	wxT( "BME_T" ),
	wxT( "BME_P" ),
	wxT( "BME_H" ),
	wxT( "BH_L" ),
	wxT( "CCS_CO2" ),
	wxT( "CCS_TVOC" ),
};
/*
GPIO_Mode_AIN           — Analog input
GPIO_Mode_IN_FLOATING   — Input without pull (Float)
GPIO_Mode_IPD           — Input with a Pull-down
GPIO_Mode_IPU           — Input with a Pull-up
GPIO_Mode_Out_OD        — Open Drain output
GPIO_Mode_Out_PP        — Push-Pull output
GPIO_Mode_AF_OD         — Open drain output for alternative functions.
                          Used when pins are controlled by peripherals,
                          which may be involved in this conclusion.
                          For example USART, I2C and the like.
GPIO_Mode_AF_PP         — The same as before, but with two states.
*/

///*
const wxString VAR_3XX_TYPES[] =
{
	wxT( "bool" ),
	wxT( "int8" ),
	wxT( "unsigned int8" ),
	wxT( "int16" ),
	wxT( "unsigned int16" ),
	wxT( "int32" ),
	wxT( "unsigned int32" ),
	wxT( "int64" ),
	wxT( "unsigned int64" ),
	wxT( "float" ),

	wxT( "GPIO_Mode_IN" ),		// *!< GPIO Input Mode
	wxT( "GPIO_Mode_OUT" ),		// *!< GPIO Output Mode
	wxT( "GPIO_Mode_AF" ),		// *!< GPIO Alternate function Mode
	wxT( "GPIO_Mode_AN" ),		// *!< GPIO Analog In/Out Mode

//	wxT( "DS18B20" ),
//	wxT( "iButton" ),
//	wxT( "LCD_1602_STR_1" ),
//	wxT( "LCD_1602_STR_2" ),
//	wxT( "BME_T" ),
//	wxT( "BME_P" ),
//	wxT( "BME_H" ),
//	wxT( "BH_L" ),
//	wxT( "CCS_CO2" ),
//	wxT( "CCS_TVOC" ),
//	wxT( "" ),
//	wxT( wxEmptyString ),
};

const wxString VAR_3XX_O_TYPES[] =
{
	wxT( "GPIO_OType_PP" ),
	wxT( "GPIO_OType_OD" ),
};

const wxString VAR_3XX_PUPD_TYPES[] =
{
	wxT( "GPIO_PuPd_NOPULL" ),
	wxT( "GPIO_PuPd_UP" ),
	wxT( "GPIO_PuPd_DOWN" ),
};
//*/

wxTextCtrl *_log;

#endif //__GBL__
