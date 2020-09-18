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


// ===========================================================================
// Static event handlers
// ===========================================================================

//	ID_TOOL_NEW_PRJ		1000
//	ID_TOOL_OPEN_PRJ	1001
//	ID_TOOL_SAVE		1002
//	ID_TOOL_CLOSE_PRJ	1003
//	ID_TOOL_EXIT		1004
//	ID_TOOL_SHVAL		1005
//	ID_TOOL_GENERATE	1006

//	ID_DEV_ADD_ROW		1007
//	ID_DEV_DEL_ROW		1008
//	ID_DEV_ROW_UP		1009
//	ID_DEV_ROW_DOWN		1010
//	ID_EDIT_CONF		1011
//	ID_DEV_SEARCH		1012
//	ID_DEV_RUN			1013

//	ID_CFG_ADD_ROW 1045


// ===========================================================================
void MyFrame::OnTool_Edit_Conf( wxCommandEvent &event )		// ID_EDIT_CONF
// ===========================================================================
{
_log->AppendText( wxT( "OnTool_Edit_Conf\n" ) );

////n2 = m_auinotebook->GetPageIndex( m_config_panel );
////if( n1 == m_auinotebook->GetPageIndex( m_config_panel ) )
////if( n1 == m_auinotebook->GetPageIndex( m_device_panel ) )
////if( n1 == 3 ) conf_changed = true;
////if( ( n1 == 0 ) && conf_changed )
////{
////m_dev_grid->ClearGrid();
////m_dev_grid->DeleteRows(0, 3);
////Refresh();
////conf_changed = false;

////m_tool_data->Show(false);
////m_grid->Show(false);
////m_staticline18->Show(false);
////m_staticline1->Show(false);
////Refresh();




m_auinotebook->SetSelection( m_auinotebook->GetPageIndex( m_config_panel ) );

	event.Skip();
}
// ===========================================================================


// ===========================================================================
// ===========================================================================
// ===========================================================================
