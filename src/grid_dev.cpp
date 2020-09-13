void MyFrame::Init_Grid_Dev( void )
{
int i, n_col, n_row;

n_col = 7;
n_row = 7;

m_dev_grid->SetColMinimalAcceptableWidth( 0 );
m_dev_grid->SetRowMinimalAcceptableHeight( 0 );
m_dev_grid->SetDefaultCellBackgroundColour( m_device_panel->GetBackgroundColour() );

m_dev_grid->SetRowLabelSize( 24 );
m_dev_grid->SetColLabelSize( 20 );

m_dev_grid->DisableDragRowSize();
m_dev_grid->DisableDragColSize();

m_dev_grid->EnableDragGridSize( false );
m_dev_grid->EnableDragColSize( false );

m_dev_grid->AppendCols( n_col );
m_dev_grid->AppendRows( n_row );

wxGridCellAttr *pAttr = new wxGridCellAttr;
pAttr->SetBackgroundColour( wxColour( 255, 255, 255 ) );
pAttr->SetReadOnly( true );
for( i = 0; i < n_col; i++ )
{
m_dev_grid->SetColAttr( i, pAttr );
}

m_dev_grid->SetReadOnly( 0, 3, false );
m_dev_grid->SetReadOnly( 1, 3, false );
m_dev_grid->SetReadOnly( 3, 3, false );

for( i = 0; i < n_row; i++ )
{
m_dev_grid->SetRowLabelValue( i, wxEmptyString );
}

m_dev_grid->SetColSize( 0, 20 );
m_dev_grid->SetColSize( 1, 20 );
m_dev_grid->SetColSize( 2, 20 );
m_dev_grid->SetColSize( 3, 180 );
m_dev_grid->SetColSize( 4, 180 );
m_dev_grid->SetColSize( 5, 60 );
m_dev_grid->SetColSize( 6, 100 );

m_dev_grid->SetColLabelValue( 0, wxEmptyString );
m_dev_grid->SetColLabelValue( 1, wxEmptyString );
m_dev_grid->SetColLabelValue( 2, wxEmptyString );

m_dev_grid->SetColLabelValue( 3, wxT( "Name" ) );
m_dev_grid->SetColLabelValue( 4, wxT( "Type" ) );
m_dev_grid->SetColLabelValue( 5, wxT( "Port" ) );
m_dev_grid->SetColLabelValue( 6, wxT( "Value" ) );

m_dev_grid->SetCellValue( 0, 0, wxT( "PLC GW" ) );
m_dev_grid->SetCellSize( 0, 0, 1, 3 );
m_dev_grid->SetCellAlignment( 0, 0, wxALIGN_LEFT, wxALIGN_CENTRE );
//m_dev_grid->SetCellRenderer( 0, 0, new myImageGridCellRenderer( gw_xpm ) );
//m_dev_grid->SetCellValue( 0, 0, wxT( "???" ) );

//m_dev_grid->SetCellRenderer( 0, 0, new myImageGridCellRenderer( dev_20_xpm ) );
m_dev_grid->SetCellRenderer( 1, 0, new myImageGridCellRenderer( c_20_0_xpm ) );
m_dev_grid->SetCellRenderer( 1, 1, new myImageGridCellRenderer( dev_20_xpm ) );
m_dev_grid->SetCellRenderer( 1, 2, new myImageGridCellRenderer( l_red_18_xpm ) );

m_dev_grid->SetCellRenderer( 2, 0, new myImageGridCellRenderer( c_20_2_xpm ) );
m_dev_grid->SetCellRenderer( 2, 1, new myImageGridCellRenderer( c_20_4_xpm ) );
m_dev_grid->SetCellRenderer( 2, 2, new myImageGridCellRenderer( c_20_5_xpm ) );

m_dev_grid->SetCellRenderer( 3, 0, new myImageGridCellRenderer( c_20_1_xpm ) );
m_dev_grid->SetCellRenderer( 3, 1, new myImageGridCellRenderer( dev_20_xpm ) );

m_dev_grid->SetCellRenderer( 4, 1, new myImageGridCellRenderer( c_20_3_xpm ) );
m_dev_grid->SetCellRenderer( 5, 1, new myImageGridCellRenderer( c_20_3_xpm ) );
m_dev_grid->SetCellRenderer( 6, 1, new myImageGridCellRenderer( c_20_4_xpm ) );
m_dev_grid->SetCellRenderer( 4, 2, new myImageGridCellRenderer( c_20_5_xpm ) );
m_dev_grid->SetCellRenderer( 5, 2, new myImageGridCellRenderer( c_20_5_xpm ) );
m_dev_grid->SetCellRenderer( 6, 2, new myImageGridCellRenderer( c_20_5_xpm ) );



////m_dev_grid->SetColSize( 1, 0 );
//m_dev_grid->SetColSize( 1, 100 );
////m_dev_grid->SetColSize( 1, 20 );
//m_dev_grid->SetColSize( 2, 180 );
//m_dev_grid->SetColSize( 3, 60 );
//m_dev_grid->SetColSize( 4, 400 );
////m_dev_grid->SetColSize( 5, 20 );
//m_dev_grid->SetColSize( 5, 100 );

m_dev_grid->SetRowLabelValue( 2, wxT( "99" ) );


//m_dev_grid->SetColLabelValue( 0, wxEmptyString );
////m_dev_grid->SetColLabelValue( 0, wxT( "Name" ) );



//m_dev_grid->SetColLabelValue( 1, wxT( "Value" ) );
////m_dev_grid->SetColLabelValue( 1, wxT( "" ) );
//m_dev_grid->SetColLabelValue( 2, wxT( "Type" ) );
//m_dev_grid->SetColLabelValue( 3, wxT( "Port" ) );
//m_dev_grid->SetColLabelValue( 4, wxT( "Comment" ) );
//m_dev_grid->SetColLabelValue( 5, wxT( "Sync" ) );
////m_dev_grid->SetColLabelValue( 5, wxT( "" ) );

//m_dev_grid->SetColSize( 0, 20 );
////m_dev_grid->SetColSize( 1, 0 );
//m_dev_grid->SetColSize( 1, 100 );
////m_dev_grid->SetColSize( 1, 20 );
//m_dev_grid->SetColSize( 2, 180 );
//m_dev_grid->SetColSize( 3, 60 );
//m_dev_grid->SetColSize( 4, 400 );
////m_dev_grid->SetColSize( 5, 20 );
//m_dev_grid->SetColSize( 5, 100 );

////m_dev_grid->SetRowSize( 1, 0 );
////m_dev_grid->SetRowSize( 2, 0 );
////m_dev_grid->SetRowSize( 3, 0 );
////m_dev_grid->SetRowSize( 4, 0 );
////m_dev_grid->SetRowSize( 5, 0 );
////m_dev_grid->SetRowSize( 6, 0 );

//wxGridCellAttr *pAttr = new wxGridCellAttr;
//pAttr->SetBackgroundColour( wxColour( 255, 255, 255 ) );

//m_dev_grid->SetColAttr( 0, pAttr );
//m_dev_grid->SetColAttr( 1, pAttr );
//m_dev_grid->SetColAttr( 2, pAttr );
//m_dev_grid->SetColAttr( 3, pAttr );
//m_dev_grid->SetColAttr( 4, pAttr );
//m_dev_grid->SetColAttr( 5, pAttr );


//m_dev_grid->SetCellRenderer(0, 0, new myImageGridCellRenderer(dev_20_xpm));
//m_dev_grid->SetCellRenderer(1, 0, new myImageGridCellRenderer(c_20_4_xpm));
//m_dev_grid->SetCellRenderer(2, 0, new myImageGridCellRenderer(c_20_1_xpm));
//m_dev_grid->SetCellRenderer(3, 0, new myImageGridCellRenderer(c_20_2_xpm));
//m_dev_grid->SetCellRenderer(4, 0, new myImageGridCellRenderer(c_20_3_xpm));

}
//void Init_...( void ){}
