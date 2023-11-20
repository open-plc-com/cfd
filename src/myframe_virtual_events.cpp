/*
    Name:        myframe_virtual_events.cpp
    Purpose:     Open-PLC Tools
    Author:      www.open-plc.com
    Created:     2023/11
    Modified by:
    RCS-ID:
    Copyright:   (c) Open-PLC
    Licence:     The MIT License (MIT)
*/


#include "myframe.h"


// ============================================================================
void MyFrame::OnPrjSelectCell( wxGridEvent &event )
// ============================================================================
{
	int      m, n, col, row;
	int      row_prev, row_next;
	long     l;
	wxString s, s2, s_name;

	//m_mgr1.GetPane( m_st_tool).Show( false );
	//m_mgr1.GetPane( m_fbd_tool).Show( false );
	//m_mgr1.GetPane( m_ld_tool).Show( false );
	//m_mgr1.GetPane( m_add_tool).Show( false );
	//m_mgr1.Update();

	m_shape->m_tool = NONE_TOOL;

    if ( event.Selecting() )
    {
		row = event.GetRow();
		col = event.GetCol();
		Select_Row = row;

//printf( "select row=%d col=%d\n", row, col );

		m = m_prj_tree->GetNumberRows();
		n = m_prj_tree->GetNumberCols();

		s = m_prj_tree->GetCellValue( row, (n-1) );
		s.ToLong( &l );
		Block_ID = l;
		Block_Name = wxEmptyString;
		m_shape->block_id = l;
		m_shape->block_name = Block_Name;
		s = m_prj_tree->GetCellValue( row, (n-2) );
		m_prj_tool->EnableTool( ID_PRJ_EDIT, false );

		m_mgr1.GetPane( m_st_tool).Show( false );
		m_mgr1.GetPane( m_fbd_tool).Show( false );
		m_mgr1.GetPane( m_ld_tool).Show( false );
		m_mgr1.GetPane( m_add_tool).Show( false );
		m_mgr1.Update();

		if( s == wxT( "PRJ" ) )
		{
			m_prj_tree->SelectBlock( row, 1, row, 1, false );
			if( !Start )
			{
				m_mgr1.GetPane(m_nb_shape).Show(false);
				m_mgr1.GetPane(m_nb_edit).Show(false);
				m_mgr1.GetPane(m_nb_grid).Show(false);
				m_mgr1.GetPane( m_add_tool).Show( true );
				m_mgr1.Update();
				Refresh();
			}
			//m_prj_tool->EnableTool( ID_PRJ_EDIT, true );
		}
		else
		if( s == wxT( "FUNC" ) )
		{
			m_prj_tree->SelectBlock( row, 2, row, 2, false );
			if( !Start )
			{
				m_mgr1.GetPane(m_nb_shape).Show(false);
				m_mgr1.GetPane(m_nb_edit).Show(false);
				m_mgr1.GetPane(m_nb_grid).Show(false);
				m_mgr1.GetPane( m_st_tool).Show( true );
				m_mgr1.Update();
				Refresh();
			}
		}
		else
		if( s == wxT( "PRG" ) )
		{
			m_prj_tree->SelectBlock( row, 3, row, 3, false );
		}
		else
		{
			m_prj_tree->SelectBlock( row, 4, row, 4, false );
		}

		s2 = m_prj_tree->GetCellValue( row, (n-3) ); // show var grid (F/T)
		if( s == wxT( "PRG" ) )
		{
			s_name = m_prj_tree->GetCellValue( row, 3 );
			s_name = wxT( "Program name: " ) + s_name;
			m_shape_name->SetLabel( s_name );
			if( !Start )
			{
				if( s2 == wxT( "T" ) )
				{
					m_mgr1.GetPane(m_nb_grid).Show(true);
				}
				else
				{
					m_mgr1.GetPane(m_nb_grid).Show(false);
				}
				m_mgr1.GetPane(m_nb_shape).Show(true);
				m_mgr1.GetPane(m_nb_edit).Show(false);
				m_mgr1.GetPane( m_fbd_tool).Show( true );
				m_mgr1.Update();
				Refresh();
			}
			m_shape->m_tool = FBD_TOOL;
		}
		else
		if( s == wxT( "ST" ) )
		{
			s_name = m_prj_tree->GetCellValue( row, 4 );
			Block_Name = s_name;
			m_shape->block_name = Block_Name;
			s_name = wxT( "(ST) Function block name: " ) + s_name;
			m_edit_name->SetLabel( s_name );

			if( !Start )
			{
				if( s2 == wxT( "T" ) )
				{
					m_mgr1.GetPane(m_nb_grid).Show(true);
				}
				else
				{
					m_mgr1.GetPane(m_nb_grid).Show(false);
				}
				m_mgr1.GetPane(m_nb_shape).Show(false);
				m_mgr1.GetPane(m_nb_edit).Show(true);
				m_mgr1.GetPane( m_st_tool).Show( true );
				m_mgr1.Update();
				Refresh();
			}
		}
		else
		if( s == wxT( "FBD" ) )
		{
			s_name = m_prj_tree->GetCellValue( row, 4 );
			Block_Name = s_name;
			m_shape->block_name = Block_Name;
			s_name = wxT( "(FBD) Function block name: " ) + s_name;
			m_shape_name->SetLabel( s_name );
			if( !Start )
			{
				if( s2 == wxT( "T" ) )
				{
					m_mgr1.GetPane(m_nb_grid).Show(true);
				}
				else
				{
					m_mgr1.GetPane(m_nb_grid).Show(false);
				}
				m_mgr1.GetPane(m_nb_shape).Show(true);
				m_mgr1.GetPane(m_nb_edit).Show(false);
				m_mgr1.GetPane( m_fbd_tool).Show( true );
				m_mgr1.Update();
				Refresh();
			}
			m_shape->m_tool = FBD_TOOL;
		}
		else
		if( s == wxT( "LD" ) )
		{
			s_name = m_prj_tree->GetCellValue( row, 4 );
			Block_Name = s_name;
			m_shape->block_name = Block_Name;
			s_name = wxT( "(LD) Function block name: " ) + s_name;
			m_shape_name->SetLabel( s_name );
			if( !Start )
			{
				if( s2 == wxT( "T" ) )
				{
					m_mgr1.GetPane(m_nb_grid).Show(true);
				}
				else
				{
					m_mgr1.GetPane(m_nb_grid).Show(false);
				}
				m_mgr1.GetPane(m_nb_shape).Show(true);
				m_mgr1.GetPane(m_nb_edit).Show(false);
				m_mgr1.GetPane( m_ld_tool).Show( true );
				m_mgr1.Update();
				Refresh();
			}
			m_shape->m_tool = LD_TOOL;
		}

		row_prev = -1;
		row_next = -1;
		if( ( s == wxT( "ST" ) ) || ( s == wxT( "FBD" ) ) || ( s == wxT( "LD" ) ) )
		{
			s2 = m_prj_tree->GetCellValue( (row-1), (n-2) );

			if( row > 0 )
			{
				if( ( s2 == wxT( "ST" ) ) || ( s2 == wxT( "FBD" ) ) || ( s2 == wxT( "LD" ) ) )
				{
					row_prev = row - 1;
				}
			}

			s2 = m_prj_tree->GetCellValue( (row+1), (n-2) );
			if( row < (n-1) )
			{
				if( ( s2 == wxT( "ST" ) ) || ( s2 == wxT( "FBD" ) ) || ( s2 == wxT( "LD" ) ) )
				{
					row_next = row + 1;
				}
			}
		}

		if( row_prev > 0 )
		{
			m_prj_tool->EnableTool( ID_PRJ_UP, true );
		}
		else
		{
			m_prj_tool->EnableTool( ID_PRJ_UP, false );
		}

		if( row_next > 0 )
		{
			m_prj_tool->EnableTool( ID_PRJ_DOWN, true );
		}
		else
		{
			m_prj_tool->EnableTool( ID_PRJ_DOWN, false );
		}
	}

	event.Skip();
}
// ============================================================================


// ============================================================================
void MyFrame::OnPrjSize( wxSizeEvent &event )
// ============================================================================
{
    int w, h, m, w_set;

    m_prj_tree->GetClientSize( &w, &h );
    m = m_prj_tree->GetColSize(0) + m_prj_tree->GetColSize(1) + m_prj_tree->GetColSize(2) + m_prj_tree->GetColSize(3);

#ifdef SHOW_T1 // define in gbl.h
    w_set = w - m*2 - m_prj_tree->GetColSize(0); // For view info cells
#else
    w_set = w - m;
    if( w_set < m )
    {
        w_set = m;
    }
#endif

    m_prj_tree->SetColSize( 4, w_set );
    event.Skip();
}
// ============================================================================
