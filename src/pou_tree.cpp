/*
    Name:        pou_tree.cpp
    Purpose:     Open-PLC Tools
    Author:      www.open-plc.com
    Created:     2023/10
    Modified by:
    RCS-ID:
    Copyright:   (c) Open-PLC
    Licence:     The MIT License (MIT)
*/


//#include <vector>
#include "myframe.h"
#include "pou_tree.h"


// ============================================================================
void MyFrame::Init_POU_Tree()
// ============================================================================
{
    int i, m, n, k;
    wxString s;

    // --- POU Tree list ---
    m_POU.clear();
    m_pou_tree->DeleteAllItems();

    // ---  1 Standard function blocks ----------------------------------------

    POU_Tree.Nn        = NN_0101;
    POU_Tree.Level     = LVL_0101;
    POU_Tree.Name      = NAME_0101;
    POU_Tree.Comment   = "";
    POU_Tree.POU_InOut = "";
    m_POU.push_back( POU_Tree );

    POU_Tree.Nn        = NN_0102;
    POU_Tree.Level     = LVL_0102;
    POU_Tree.Name      = NAME_0102;
    POU_Tree.Comment   = COMMENT_0102;
    POU_Tree.POU_InOut = POU_INOUT_0102;
    m_POU.push_back( POU_Tree );

    POU_Tree.Nn        = NN_0103;
    POU_Tree.Level     = LVL_0103;
    POU_Tree.Name      = NAME_0103;
    POU_Tree.Comment   = COMMENT_0103;
    POU_Tree.POU_InOut = POU_INOUT_0103;
    m_POU.push_back( POU_Tree );

    POU_Tree.Nn        = NN_0104;
    POU_Tree.Level     = LVL_0104;
    POU_Tree.Name      = NAME_0104;
    POU_Tree.Comment   = COMMENT_0104;
    POU_Tree.POU_InOut = POU_INOUT_0104;
    //m_POU.push_back( POU_Tree );

    POU_Tree.Nn        = NN_0105;
    POU_Tree.Level     = LVL_0105;
    POU_Tree.Name      = NAME_0105;
    POU_Tree.Comment   = COMMENT_0105;
    POU_Tree.POU_InOut = POU_INOUT_0105;
    //m_POU.push_back( POU_Tree );

    POU_Tree.Nn        = NN_0106;
    POU_Tree.Level     = LVL_0106;
    POU_Tree.Name      = NAME_0106;
    POU_Tree.Comment   = COMMENT_0106;
    POU_Tree.POU_InOut = POU_INOUT_0106;
    //m_POU.push_back( POU_Tree );

    POU_Tree.Nn        = NN_0107;
    POU_Tree.Level     = LVL_0107;
    POU_Tree.Name      = NAME_0107;
    POU_Tree.Comment   = COMMENT_0107;
    POU_Tree.POU_InOut = POU_INOUT_0107;
    //m_POU.push_back( POU_Tree );

    POU_Tree.Nn        = NN_0108;
    POU_Tree.Level     = LVL_0108;
    POU_Tree.Name      = NAME_0108;
    POU_Tree.POU_InOut = POU_INOUT_0108;
    //m_POU.push_back( POU_Tree );

    POU_Tree.Nn        = NN_0109;
    POU_Tree.Level     = LVL_0109;
    POU_Tree.Name      = NAME_0109;
    POU_Tree.POU_InOut = POU_INOUT_0109;
    //m_POU.push_back( POU_Tree );

    POU_Tree.Nn        = NN_0110;
    POU_Tree.Level     = LVL_0110;
    POU_Tree.Name      = NAME_0110;
    POU_Tree.POU_InOut = POU_INOUT_0110;
    //m_POU.push_back( POU_Tree );

    POU_Tree.Nn        = NN_0111;
    POU_Tree.Level     = LVL_0111;
    POU_Tree.Name      = NAME_0111;
    POU_Tree.POU_InOut = POU_INOUT_0111;
    //m_POU.push_back( POU_Tree );

    POU_Tree.Nn        = NN_0112;
    POU_Tree.Level     = LVL_0112;
    POU_Tree.Name      = NAME_0112;
    POU_Tree.Comment   = COMMENT_0112;
    POU_Tree.POU_InOut = POU_INOUT_0112;
    //m_POU.push_back( POU_Tree );

    POU_Tree.Nn        = NN_0113;
    POU_Tree.Level     = LVL_0113;
    POU_Tree.Name      = NAME_0113;
    POU_Tree.POU_InOut = POU_INOUT_0113;
    //m_POU.push_back( POU_Tree );

    POU_Tree.Nn        = NN_0114;
    POU_Tree.Level     = LVL_0114;
    POU_Tree.Name      = NAME_0114;
    POU_Tree.POU_InOut = POU_INOUT_0114;
    //m_POU.push_back( POU_Tree );

    POU_Tree.Nn        = NN_0115;
    POU_Tree.Level     = LVL_0115;
    POU_Tree.Name      = NAME_0115;
    POU_Tree.POU_InOut = POU_INOUT_0115;
    //m_POU.push_back( POU_Tree );

    POU_Tree.Nn        = NN_0116;
    POU_Tree.Level     = LVL_0116;
    POU_Tree.Name      = NAME_0116;
    POU_Tree.POU_InOut = POU_INOUT_0116;
    //m_POU.push_back( POU_Tree );

    POU_Tree.Nn        = NN_0117;
    POU_Tree.Level     = LVL_0117;
    POU_Tree.Name      = NAME_0117;
    POU_Tree.Comment   = COMMENT_0117;
    POU_Tree.POU_InOut = POU_INOUT_0117;
    m_POU.push_back( POU_Tree );

    POU_Tree.Nn        = NN_0118;
    POU_Tree.Level     = LVL_0118;
    POU_Tree.Name      = NAME_0118;
    POU_Tree.POU_InOut = POU_INOUT_0118;
    m_POU.push_back( POU_Tree );

    POU_Tree.Nn        = NN_0119;
    POU_Tree.Level     = LVL_0119;
    POU_Tree.Name      = NAME_0119;
    POU_Tree.POU_InOut = POU_INOUT_0119;
    //m_POU.push_back( POU_Tree );

    POU_Tree.Nn        = NN_0120;
    POU_Tree.Level     = LVL_0120;
    POU_Tree.Name      = NAME_0120;
    POU_Tree.POU_InOut = POU_INOUT_0120;
    //m_POU.push_back( POU_Tree );

    POU_Tree.Nn        = NN_0121;
    POU_Tree.Level     = LVL_0121;
    POU_Tree.Name      = NAME_0121;
    POU_Tree.POU_InOut = POU_INOUT_0121;
    //m_POU.push_back( POU_Tree );

    POU_Tree.Nn        = NN_0122;
    POU_Tree.Level     = LVL_0122;
    POU_Tree.Name      = NAME_0122;
    POU_Tree.Comment   = COMMENT_0122;
    POU_Tree.POU_InOut = POU_INOUT_0122;
    //m_POU.push_back( POU_Tree );

    POU_Tree.Nn        = NN_0123;
    POU_Tree.Level     = LVL_0123;
    POU_Tree.Name      = NAME_0123;
    POU_Tree.POU_InOut = POU_INOUT_0123;
    //m_POU.push_back( POU_Tree );

    POU_Tree.Nn        = NN_0124;
    POU_Tree.Level     = LVL_0124;
    POU_Tree.Name      = NAME_0124;
    POU_Tree.POU_InOut = POU_INOUT_0124;
    //m_POU.push_back( POU_Tree );

    // ---  2 Additional function blocks --------------------------------------

    //POU_Tree.Nn        = NN_0201;
    //POU_Tree.Level     = LVL_0201;
    //POU_Tree.Name      = NAME_0201;
    //POU_Tree.Comment   = "";
    //POU_Tree.POU_InOut = "";
    //m_POU.push_back( POU_Tree );

    //POU_Tree.Nn        = NN_0202;
    //POU_Tree.Level     = LVL_0202;
    //POU_Tree.Name      = NAME_0202;
    //POU_Tree.Comment   = COMMENT_0202;
    //POU_Tree.POU_InOut = POU_INOUT_0202;
    //m_POU.push_back( POU_Tree );

    //POU_Tree.Nn        = NN_0203;
    //POU_Tree.Level     = LVL_0203;
    //POU_Tree.Name      = NAME_0203;
    //POU_Tree.Comment   = COMMENT_0203;
    //POU_Tree.POU_InOut = POU_INOUT_0203;
    //m_POU.push_back( POU_Tree );

    //POU_Tree.Nn        = NN_0204;
    //POU_Tree.Level     = LVL_0204;
    //POU_Tree.Name      = NAME_0204;
    //POU_Tree.Comment   = COMMENT_0204;
    //POU_Tree.POU_InOut = POU_INOUT_0204;
    //m_POU.push_back( POU_Tree );

    //POU_Tree.Nn        = NN_0205;
    //POU_Tree.Level     = LVL_0205;
    //POU_Tree.Name      = NAME_0205;
    //POU_Tree.Comment   = COMMENT_0205;
    //POU_Tree.POU_InOut = POU_INOUT_0205;
    //m_POU.push_back( POU_Tree );

    //POU_Tree.Nn        = NN_0206;
    //POU_Tree.Level     = LVL_0206;
    //POU_Tree.Name      = NAME_0206;
    //POU_Tree.Comment   = COMMENT_0206;
    //POU_Tree.POU_InOut = POU_INOUT_0206;
    //m_POU.push_back( POU_Tree );

    //POU_Tree.Nn        = NN_0207;
    //POU_Tree.Level     = LVL_0207;
    //POU_Tree.Name      = NAME_0207;
    //POU_Tree.Comment   = COMMENT_0207;
    //POU_Tree.POU_InOut = POU_INOUT_0207;
    //m_POU.push_back( POU_Tree );

    // ---  3 Types Conversion ---

    //POU_Tree.Nn        = NN_0301;
    //POU_Tree.Level     = LVL_0301;
    //POU_Tree.Name      = NAME_0301;
    //POU_Tree.Comment   = "";
    //POU_Tree.POU_InOut = "";
    //m_POU.push_back( POU_Tree );

    // ---  4 Mathematical functions ---

    //POU_Tree.Nn        = NN_0401;
    //POU_Tree.Level     = LVL_0401;
    //POU_Tree.Name      = NAME_0401;
    //POU_Tree.Comment   = "";
    //POU_Tree.POU_InOut = "";
    //m_POU.push_back( POU_Tree );

    //POU_Tree.Nn        = NN_0402;
    //POU_Tree.Level     = LVL_0402;
    //POU_Tree.Name      = NAME_0402;
    //POU_Tree.Comment   = COMMENT_0402;
    //POU_Tree.POU_InOut = POU_INOUT_0402;
    //m_POU.push_back( POU_Tree );

    //POU_Tree.Nn        = NN_0403;
    //POU_Tree.Level     = LVL_0403;
    //POU_Tree.Name      = NAME_0403;
    //POU_Tree.Comment   =  COMMENT_0403;
    //POU_Tree.POU_InOut = POU_INOUT_0403;
    //m_POU.push_back( POU_Tree );

    //POU_Tree.Nn        = NN_0404;
    //POU_Tree.Level     = LVL_0404;
    //POU_Tree.Name      = NAME_0404;
    //POU_Tree.Comment   =  COMMENT_0404;
    //POU_Tree.POU_InOut = POU_INOUT_0404;
    //m_POU.push_back( POU_Tree );

    //POU_Tree.Nn        = NN_0405;
    //POU_Tree.Level     = LVL_0405;
    //POU_Tree.Name      = NAME_0405;
    //POU_Tree.Comment   =  COMMENT_0405;
    //POU_Tree.POU_InOut = POU_INOUT_0405;
    //m_POU.push_back( POU_Tree );

    //POU_Tree.Nn        = NN_0406;
    //POU_Tree.Level     = LVL_0406;
    //POU_Tree.Name      = NAME_0406;
    //POU_Tree.Comment   =  COMMENT_0406;
    //POU_Tree.POU_InOut = POU_INOUT_0406;
    //m_POU.push_back( POU_Tree );

    //POU_Tree.Nn        = NN_0407;
    //POU_Tree.Level     = LVL_0407;
    //POU_Tree.Name      = NAME_0407;
    //POU_Tree.Comment   =  COMMENT_0407;
    //POU_Tree.POU_InOut = POU_INOUT_0407;
    //m_POU.push_back( POU_Tree );

    //POU_Tree.Nn        = NN_0408;
    //POU_Tree.Level     = LVL_0408;
    //POU_Tree.Name      = NAME_0408;
    //POU_Tree.Comment   =  COMMENT_0408;
    //POU_Tree.POU_InOut = POU_INOUT_0408;
    //m_POU.push_back( POU_Tree );

    //POU_Tree.Nn        = NN_0409;
    //POU_Tree.Level     = LVL_0409;
    //POU_Tree.Name      = NAME_0409;
    //POU_Tree.Comment   =  COMMENT_0409;
    //POU_Tree.POU_InOut = POU_INOUT_0409;
    //m_POU.push_back( POU_Tree );

    //POU_Tree.Nn        = NN_0410;
    //POU_Tree.Level     = LVL_0410;
    //POU_Tree.Name      = NAME_0410;
    //POU_Tree.Comment   =  COMMENT_0410;
    //POU_Tree.POU_InOut = POU_INOUT_0410;
    //m_POU.push_back( POU_Tree );

    //POU_Tree.Nn        = NN_0411;
    //POU_Tree.Level     = LVL_0411;
    //POU_Tree.Name      = NAME_0411;
    //POU_Tree.Comment   =  COMMENT_0411;
    //POU_Tree.POU_InOut = POU_INOUT_0411;
    //m_POU.push_back( POU_Tree );

    //POU_Tree.Nn        = NN_0412;
    //POU_Tree.Level     = LVL_0412;
    //POU_Tree.Name      = NAME_0412;
    //POU_Tree.Comment   =  COMMENT_0412;
    //POU_Tree.POU_InOut = POU_INOUT_0412;
    //m_POU.push_back( POU_Tree );

    // --- 5 Mathematics ---

    //POU_Tree.Nn        = NN_0501;
    //POU_Tree.Level     = LVL_0501;
    //POU_Tree.Name      = NAME_0501;
    //POU_Tree.Comment   = "";
    //POU_Tree.POU_InOut = "";
    //m_POU.push_back( POU_Tree );

    //POU_Tree.Nn        = NN_0502;
    //POU_Tree.Level     = LVL_0502;
    //POU_Tree.Name      = NAME_0502;
    //POU_Tree.Comment   = COMMENT_0502;
    //POU_Tree.POU_InOut = POU_INOUT_0502;
    //m_POU.push_back( POU_Tree );

    //POU_Tree.Nn        = NN_0503;
    //POU_Tree.Level     = LVL_0503;
    //POU_Tree.Name      = NAME_0503;
    //POU_Tree.Comment   = COMMENT_0503;
    //POU_Tree.POU_InOut = POU_INOUT_0503;
    //m_POU.push_back( POU_Tree );

    //POU_Tree.Nn        = NN_0504;
    //POU_Tree.Level     = LVL_0504;
    //POU_Tree.Name      = NAME_0504;
    //POU_Tree.Comment   = COMMENT_0504;
    //POU_Tree.POU_InOut = POU_INOUT_0504;
    //m_POU.push_back( POU_Tree );

    //POU_Tree.Nn        = NN_0505;
    //POU_Tree.Level     = LVL_0505;
    //POU_Tree.Name      = NAME_0505;
    //POU_Tree.Comment   = COMMENT_0505;
    //POU_Tree.POU_InOut = POU_INOUT_0505;
    //m_POU.push_back( POU_Tree );

    //POU_Tree.Nn        = NN_0506;
    //POU_Tree.Level     = LVL_0506;
    //POU_Tree.Name      = NAME_0506;
    //POU_Tree.Comment   = COMMENT_0506;
    //POU_Tree.POU_InOut = POU_INOUT_0506;
    //m_POU.push_back( POU_Tree );

    //POU_Tree.Nn        = NN_0507;
    //POU_Tree.Level     = LVL_0507;
    //POU_Tree.Name      = NAME_0507;
    //POU_Tree.Comment   = COMMENT_0507;
    //POU_Tree.POU_InOut = POU_INOUT_0507;
    //m_POU.push_back( POU_Tree );

    //POU_Tree.Nn        = NN_0508;
    //POU_Tree.Level     = LVL_0508;
    //POU_Tree.Name      = NAME_0508;
    //POU_Tree.Comment   = COMMENT_0508;
    //POU_Tree.POU_InOut = POU_INOUT_0508;
    //m_POU.push_back( POU_Tree );

	// --- 6 Time ---

	//POU_Tree.Nn        = NN_0601;
	//POU_Tree.Level     = LVL_0601;
	//POU_Tree.Name      = NAME_0601;
	//POU_Tree.Comment   = "";
	//POU_Tree.POU_InOut = "";
	//m_POU.push_back( POU_Tree );

    // --- 7 Shear operations ---

    //POU_Tree.Nn        = NN_0701;
    //POU_Tree.Level     = LVL_0701;
    //POU_Tree.Name      = NAME_0701;
    //POU_Tree.Comment   = "";
    //POU_Tree.POU_InOut = "";
    //m_POU.push_back( POU_Tree );

    //POU_Tree.Nn        = NN_0702;
    //POU_Tree.Level     = LVL_0702;
    //POU_Tree.Name      = NAME_0702;
    //POU_Tree.Comment   = COMMENT_0702;
    //POU_Tree.POU_InOut = POU_INOUT_0702;
    //m_POU.push_back( POU_Tree );

    //POU_Tree.Nn        = NN_0703;
    //POU_Tree.Level     = LVL_0703;
    //POU_Tree.Name      = NAME_0703;
    //POU_Tree.Comment   = COMMENT_0703;
    //POU_Tree.POU_InOut = POU_INOUT_0703;
    //m_POU.push_back( POU_Tree );

    //POU_Tree.Nn        = NN_0704;
    //POU_Tree.Level     = LVL_0704;
    //POU_Tree.Name      = NAME_0704;
    //POU_Tree.Comment   = COMMENT_0704;
    //POU_Tree.POU_InOut = POU_INOUT_0704;
    //m_POU.push_back( POU_Tree );

    //POU_Tree.Nn        = NN_0705;
    //POU_Tree.Level     = LVL_0705;
    //POU_Tree.Name      = NAME_0705;
    //POU_Tree.Comment   = COMMENT_0705;
    //POU_Tree.POU_InOut = POU_INOUT_0705;
    //m_POU.push_back( POU_Tree );

    // --- 8 Bit operations ---

    //POU_Tree.Nn        = NN_0801;
    //POU_Tree.Level     = LVL_0801;
    //POU_Tree.Name      = NAME_0801;
    //POU_Tree.Comment   = "";
    //POU_Tree.POU_InOut = "";
    //m_POU.push_back( POU_Tree );

    //POU_Tree.Nn        = NN_0802;
    //POU_Tree.Level     = LVL_0802;
    //POU_Tree.Name      = NAME_0802;
    //POU_Tree.Comment   = COMMENT_0802;
    //POU_Tree.POU_InOut = POU_INOUT_0802;
    //m_POU.push_back( POU_Tree );

    //POU_Tree.Nn        = NN_0803;
    //POU_Tree.Level     = LVL_0803;
    //POU_Tree.Name      = NAME_0803;
    //POU_Tree.Comment   = COMMENT_0803;
    //POU_Tree.POU_InOut = POU_INOUT_0803;
    //m_POU.push_back( POU_Tree );

    //POU_Tree.Nn        = NN_0804;
    //POU_Tree.Level     = LVL_0804;
    //POU_Tree.Name      = NAME_0804;
    //POU_Tree.Comment   = COMMENT_0804;
    //POU_Tree.POU_InOut = POU_INOUT_0804;
    //m_POU.push_back( POU_Tree );

    //POU_Tree.Nn        = NN_0805;
    //POU_Tree.Level     = LVL_0805;
    //POU_Tree.Name      = NAME_0805;
    //POU_Tree.Comment   = COMMENT_0805;
    //POU_Tree.POU_InOut = POU_INOUT_0805;
    //m_POU.push_back( POU_Tree );

    // --- 9 Choice ---

    //POU_Tree.Nn        = NN_0901;
    //POU_Tree.Level     = LVL_0901;
    //POU_Tree.Name      = NAME_0901;
    //POU_Tree.Comment   = "";
    //POU_Tree.POU_InOut = "";
    //m_POU.push_back( POU_Tree );

    //POU_Tree.Nn        = NN_0902;
    //POU_Tree.Level     = LVL_0902;
    //POU_Tree.Name      = NAME_0902;
    //POU_Tree.Comment   = COMMENT_0902;
    //POU_Tree.POU_InOut = POU_INOUT_0902;
    //m_POU.push_back( POU_Tree );

    //POU_Tree.Nn        = NN_0903;
    //POU_Tree.Level     = LVL_0903;
    //POU_Tree.Name      = NAME_0903;
    //POU_Tree.Comment   = COMMENT_0903;
    //POU_Tree.POU_InOut = POU_INOUT_0903;
    //m_POU.push_back( POU_Tree );

    //POU_Tree.Nn        = NN_0904;
    //POU_Tree.Level     = LVL_0904;
    //POU_Tree.Name      = NAME_0904;
    //POU_Tree.Comment   = COMMENT_0904;
    //POU_Tree.POU_InOut = POU_INOUT_0904;
    //m_POU.push_back( POU_Tree );

    //POU_Tree.Nn        = NN_0905;
    //POU_Tree.Level     = LVL_0905;
    //POU_Tree.Name      = NAME_0905;
    //POU_Tree.Comment   = COMMENT_0905;
    //POU_Tree.POU_InOut = POU_INOUT_0905;
    //m_POU.push_back( POU_Tree );

    //POU_Tree.Nn        = NN_0906;
    //POU_Tree.Level     = LVL_0906;
    //POU_Tree.Name      = NAME_0906;
    //POU_Tree.Comment   = COMMENT_0906;
    //POU_Tree.POU_InOut = POU_INOUT_0906;
    //m_POU.push_back( POU_Tree );

	//// --- 10 Comparison ---

	//POU_Tree.Nn        = NN_1001;
	//POU_Tree.Level     = LVL_1001;
	//POU_Tree.Name      = NAME_1001;
    //POU_Tree.Comment   = "";
    //POU_Tree.POU_InOut = "";
	//m_POU.push_back( POU_Tree );

	//// --- 11 String operations ---

	//POU_Tree.Nn        = NN_1101;
	//POU_Tree.Level     = LVL_1101;
	//POU_Tree.Name      = NAME_1101;
    //POU_Tree.Comment   = "";
    //POU_Tree.POU_InOut = "";
	//m_POU.push_back( POU_Tree );

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	//	POU_Tree.Nn			=
	//	POU_Tree.Level		=
	//	POU_Tree.Name		=
	//	POU_Tree.Comment	=
	//	POU_Tree.POU_InOut	=
	//	m_POU.push_back( POU_Tree );

    // --- Make POU tree ------------------------------------------------------

    pou_item_root = m_pou_tree->AddRoot( PDU_TREE_HEAD );
    pou_item_prev = 0;

    k = 0;
    m = m_prj_tree->GetNumberRows(); // Number of Rows
    n = m_prj_tree->GetNumberCols(); // Number of Cols

    for( i = 0; i < m; i++ )
    {
        s = m_prj_tree->GetCellValue( i, (n-2) );
        if( ( s == wxT( "LD" ) ) || ( s == wxT( "ST" ) ) || ( s == wxT( "FBD" ) ) )
        {
            k++;
        }
    }

    if( k ) // User POU; 10001 ...
    {
        POU_Tree.Nn        = NN_10001;
        POU_Tree.Level     = LVL_10001;
        POU_Tree.Name      = NAME_10001;
        POU_Tree.Comment   = COMMENT_10001;   // Empty String
        POU_Tree.POU_InOut = POU_INOUT_10001; // Empty String
        m_POU.push_back( POU_Tree );

        for( i = 0; i < m; i++ ) // Add User POU
        {
            s = m_prj_tree->GetCellValue( i, (n-2) );
            if( ( s == wxT( "LD" ) ) || ( s == wxT( "ST" ) ) || ( s == wxT( "FBD" ) ) )
            {
                s = m_prj_tree->GetCellValue( i, 4 );
                POU_Tree.Nn        = NN_10001 + i + 1;
                POU_Tree.Level     = 2;
                POU_Tree.Name      = s;
                POU_Tree.Comment   = "";
                POU_Tree.POU_InOut = "(BOOL:RESET) => (INT:OUT)";
                m_POU.push_back( POU_Tree );
            }
        }
    }

    for( i = 0; i < (int) m_POU.size(); i++ )
    {
        if( m_POU[i].Level == 1 )
        {
            pou_item_prev = m_pou_tree->AppendItem( pou_item_root, m_POU[i].Name );
        }
        else if (m_POU[i].Level == 2)
        {
            if (pou_item_prev)
            {
                m_pou_tree->AppendItem( pou_item_prev, m_POU[i].Name );
            }
        }
    }
    m_pou_tree->Expand( pou_item_root );
}
// ============================================================================


// ============================================================================
void MyFrame::OnPOUTreeSelChanged( wxTreeEvent &event )
// ============================================================================
{
    uint32_t    i;
    wxString    s;
    std::string s_std;

    m_pou_text->Clear();

    if (event.GetItem() != m_pou_tree->GetRootItem())
    {
        wxTreeItemId m_draggedItem = event.GetItem();
        s = m_pou_tree->GetItemText( m_draggedItem );

        for( i = 0; i < m_POU.size(); i++ )
        {
            if( m_POU[i].Level == 2 )
            {
                if( m_POU[i].Name == (const char*) s.c_str() )
                {
                    if( m_POU[i].Comment != "" )
                    {
                        m_pou_text->AppendText( m_POU[i].Comment );
                        m_pou_text->AppendText( wxT( "\n\n ") );
                    }
                    m_pou_text->AppendText( m_POU[i].POU_InOut );
                    break;
                }
            }
        }
    }
    event.Skip();
}
// ============================================================================


// ============================================================================
void MyFrame::OnPOUEnter( wxMouseEvent& event )
// ============================================================================
{
//printf( "MyFrame::OnPOUEnter\n" );
	event.Skip();
}
// ============================================================================


// ============================================================================
void MyFrame::OnPOULeave( wxMouseEvent& event )
{
//printf( "MyFrame::OnPOULeave\n" );
	event.Skip();
}
// ============================================================================


// ============================================================================
void MyFrame::onPOUBeginDrag( wxTreeEvent& event )
// ============================================================================
{
printf( "onPOUBeginDrag\n" );

wxTreeItemId m_draggedItem = event.GetItem();
wxString s = m_pou_tree->GetItemText( m_draggedItem );
printf( "POU=%s\n", (const char*) s.c_str() );

	event.Skip();
}
// ============================================================================
