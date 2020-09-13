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
// Virtual event handlers
// ===========================================================================


void MyFrame::OnAuiChanged( wxAuiNotebookEvent& event )
{
int n1;
wxString s;

n1 = m_auinotebook->GetSelection();
//n2 = m_auinotebook->GetPageIndex( m_device_panel );
//if( n1 == 2 )
//{
//m_tool_data->Hide();
//m_grid->Hide();
//s.Printf( wxT( "n1=%d\n" ), n1 );
//_log->AppendText( s );
//}

//int row, col;

//row = 0;

	//row = event.GetRow();
	//col = event.GetCol();

//s.Printf( wxT( "row=%d, col=%d\n" ), row, col );

//_log->AppendText( s );

//_log->AppendText( wxT( "on1\n" ) );
//if(n1)

event.Skip();

}



//// ===========================================================================
//void MyFrame::OnChoice_COM( wxCommandEvent &WXUNUSED( event ) )
//// ===========================================================================
//{
//wxString s, s_sel;
//int i, n, com_nn;
//
//
//_log->AppendText( wxT( "!!!\n" ) );
//
//
////for( n = 0; n < 2; n++ )
////{
////s.Printf( "%d %s\n", n, port_list[n].c_str() );
////_log->AppendText( s );
////}
//
//	//int			x, y, i, m, com_nn;
//
////Disconnect !!!
//
//IO_COM->GetPortList( &port_list );
//com_nn = port_list.Count();
//m_choice_COM->Clear();
//if( com_nn )
//{
//m_choice_COM->Append( wxEmptyString );
//for( i = 0; i < com_nn; i++ )
//{
//	m_choice_COM->Append( port_list[i] );
//}
//
//n = m_choice_COM->GetCurrentSelection();
//if( n )
//{
//s_sel = m_choice_COM->GetStringSelection();
//s.Printf( "COM Str = %s\n", s_sel.c_str() );
//_log->AppendText( s );
//
//s = s_sel.Mid( 3 );
//s.Printf( "COM Nn = %s\n", s.c_str() );
//_log->AppendText( s );
//
//
//
//}
//}
////s.Printf( "COM Nn= %d\n", n );
////_log->AppendText( s );
////s_sel = m_choice_COM->GetStringSelection();
////s.Printf( "COM Str = %s\n", s_sel.c_str() );
////_log->AppendText( s );
//
////if( s_sel != wxEmptyString )
////{
////s = s_sel.Mid( 3 );
////s.Printf( "COM = %s\n", s_sel.c_str() );
////_log->AppendText( s );
////COM_NN
//
////}
//
////s.Printf( "OnChoice_COM %d %s\n", n, port_list[n].c_str() );
////_log->AppendText( s );
//}
//// ===========================================================================


//// ===========================================================================
//void MyFrame::OnLeftDown_COM( wxMouseEvent &event )
//// ===========================================================================
//{
//
//int i, com_nn;
////wxString s;
//
//IO_COM->GetPortList( &port_list );
//com_nn = port_list.Count();
//m_choice_COM->Clear();
//if( com_nn )
//{
//m_choice_COM->Append( wxEmptyString );
//for( i = 0; i < com_nn; i++ )
//{
//m_choice_COM->Append( port_list[i] );
//}
//}
//
//
//_log->AppendText( wxT( "vvv\n" ) );
//event.Skip();
//}
// ===========================================================================




//void MyFrame::OnGridCellLeftClick( wxGridEvent &event )
//{
//	unsigned int	row, col;
//	wxString		s;
//
//	row = event.GetRow();
//	col = event.GetCol();
//
//s.Printf( wxT( "row=%d, col=%d\n" ), row, col );
//
//_log->AppendText( s );
//
//
////const wxString choices[] =
////{
////_T("Please select a choice"),
////_T("This takes two cells"),
////_T("Another choice"),
////};
//
////wxGridCellChoiceEditor *ce;
//
////ce = new wxGridCellChoiceEditor(WXSIZEOF(choices));
//
////choices[0] = _T("1");
////choices[1] = _T("2");
////choices[2] = _T("3");
//
//
//
////ce->SetParameters(choices);
//
//if( col == 1 )
//{
//
//
//for( int i = 0; i < 7; i++ )
//{
//s.Printf( wxT( "%d" ), i );
//a1[i] = s;
//
////_log->AppendText( wxT( "IsAlive\n" ) );
//}
//
//
////wxGridCellChoiceEditor *ce = new wxGridCellChoiceEditor(WXSIZEOF(a1), a1);
////m_grid->SetCellEditor(1,1, ce);
////m_grid->SetCellValue(row, col, choices[0]);
//
//if(ce->IsCreated())
//{
//ce->Destroy();
////ce = 0;
//_log->AppendText( wxT( "Del ce\n" ) );
//
//}
//ce = new wxGridCellChoiceEditor(6, a1);
//m_grid->SetCellEditor(row,col, ce);
////ce->SetParameters(*a1);
//
////wxGridCellChoiceEditor::SetParameters
////void SetParameters(const wxString& params)
////Parameters string format is "item1[,item2[...,itemN]]"
//
//
//
//
//
//
//
////m_grid->SetCellEditor(row, col, new wxGridCellChoiceEditor(WXSIZEOF(choices), choices));
////m_grid->SetCellEditor(row, col, ce);
////m_grid->SetCellSize(row, 0, 1, 2);
////m_grid->SetCellValue(row, col, choices[0]);
////m_grid->SetCellOverflow(row, col, false);
//}
//
//event.Skip();
//}
//
//
////long keycode = event.GetKeyCode();
//void MyFrame::OnChar( wxKeyEvent& event )
//{
//	wxString		s;
//
//long keycode = event.GetKeyCode();
//
//s.Printf( wxT( "code=%ld\n" ), keycode );
//
//_log->AppendText( s );
//
//event.Skip();
//}
//
//void MyFrame::OnGridLabelLeftClick( wxGridEvent& event )
//{
//wxString s;
//int i;
//i = event.GetRow();
//s.Printf( wxT( "Label=%d\n" ), i );
//_log->AppendText( s );
//m_grid->SelectBlock(-1,-1,-1,-1);
//
//m_grid->ClearSelection();
//m_grid->SelectRow( i );
//
////event.Skip();
//}
