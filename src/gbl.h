/*
    Name:        gbl.h
    Purpose:     Open-PLC Tools
    Author:      www.open-plc.com
    Created:     2023/11
    Modified by:
    RCS-ID:
    Copyright:   (c) Open-PLC
    Licence:     The MIT License (MIT)
*/


#ifndef __GBL__
#define __GBL__

#include <wx/treebase.h>

#ifdef WIN32 // if Win then declare nix-like types
#   define int8_t   __int8
#   define int16_t  __int16
#   define int32_t  __int32
#   define int64_t  __int64
#   define uint8_t  unsigned __int8
#   define uint16_t unsigned __int16
#   define uint32_t unsigned __int32
#   define uint64_t unsigned __int64
#endif // WIN32

#define OPT_VER "000"
//#define SHOW_T1 // Show hidden cells in prj tree

#define FONT_SIZE 10


enum Shape_Type
{
	BOX,     // box shape (FB)
	LINE,    // poliline (connect line)
	TXT,     // text block (comment)
	CONNECT, // connection
	CMT,     // Comment
	POWER,   // line power
	VAR,
	COIL,
	CONTACT,
};

enum Tools_Type
{
	NONE_TOOL,
	ADD_TOOL,
	FBD_TOOL,
	LD_TOOL,
};

enum MenuIDs
{
	MENU_ID_CONTEXT_1 = 11001,
	MENU_ID_CONTEXT_2,
	MENU_ID_CONTEXT_3,
};

struct Line_Struct
{
	unsigned int Nn;
	unsigned int Shape_ID_1; // reference to shape 1
	unsigned int Shape_ID_2; // reference to shape 2
	wxPoint      Pt_1;       // Segment starting point
	wxPoint      Pt_2;       // Segment end point
	bool         Selected;
};

struct Link_Point_Struct
{
	unsigned int Nn;
	unsigned int Shape_ID; // reference to shape Id
	unsigned int In_Out;   // in=1 out=2
	wxPoint      Pos;      // Point position
	wxString     Name_IO;  // in/out name
	wxString     Name_Obj; // POU name
	wxString     Type;
	wxString     Name;
};

struct Shape_Struct
{
    unsigned int ID;           // Unique shape ID
    unsigned int Block_ID;     // Nn of block in project (m_prj_tree)
    wxString     Name;         // Name in project
    wxPoint      Name_Pos;     // Position of name
    wxString     Name_POU;     // POU Name
    wxPoint      Name_POU_Pos; //
    wxPoint      Anchor;
    wxPoint      Size;
    wxPoint      Min_Size;
    unsigned int Min_Input_Nn;
    unsigned int Max_Input_Nn;
    bool         Selected;
};

struct POU_Struct
{
	int          Nn;
	int          Level;
	std::string  Name;
	std::string  Comment;
	std::string  POU_InOut;
	wxTreeItemId Tree_Id;
};

struct IN_OUT_Decode_Struct
{
	int         Nn;
	int         InOut; // 1-In; 2-Out
	std::string Type;
	std::string Name;
};


#endif //__GBL__
