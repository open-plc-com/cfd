/*
	Name:			read_write_cfg.cpp
	Purpose:		CFM
	Author:			www.open-plc.com
	Created:		2020/07
	Modified by:
	RCS-ID:
	Copyright:
	Licence:		The MIT License (MIT)
*/


#include "tinyxml2.cpp"
namespace XML = tinyxml2;

// ===========================================================================
int MyFrame::OnPathInit( void )
// ===========================================================================
{
	wxString	s;

	wxStandardPathsBase &stdp = wxStandardPaths::Get();
	s = wxStandardPaths().GetExecutablePath();
	wxFileName::SplitPath( s, &WORK_PATH, &S_NAME, &S_EXT );
	PATH_SEP	= wxFileName::DirName( s ).GetPathSeparator();
	EXEC_PATH	= stdp.GetExecutablePath();
	DATA_DIR	= stdp.GetUserLocalDataDir();

//_log->AppendText( wxT( "WORK_PATH=" ) + WORK_PATH );    _log->AppendText( "\n" );
//_log->AppendText( wxT( "S_NAME=" )    + S_NAME );       _log->AppendText( "\n" );
//_log->AppendText( wxT( "S_EXT=" )     + S_EXT );        _log->AppendText( "\n" );
//_log->AppendText( wxT( "DATA_DIR=" )  + DATA_DIR );     _log->AppendText( "\n" );

	if( S_NAME != wxT( "cfm" ) )
	{
		wxMessageBox( wxT( "Wrong task name" ), wxT( "ERROR" ), wxICON_ERROR );
		return 1;
	}

	if( !wxDir::Exists( DATA_DIR ) )
	{
		if( !wxMkdir( DATA_DIR ) )
		{
			s = wxT( "Can't create dir\n\"" );
			s = s + DATA_DIR;
			s = s + wxT( "\"" );
			wxMessageBox( s, wxT( "ERROR" ), wxICON_ERROR );
			return 1;
		}
	}
	return 0;
}
// ===========================================================================


// ===========================================================================
int MyFrame::Read_Cfg()
// ===========================================================================
{
	long				 vl;
	wxString			 s;
	XML::XMLDocument	 doc;
	XML::XMLElement		*r1, *e1;

	s = DATA_DIR + wxT( PATH_SEP ) + S_NAME + wxT( ".cfg" );
	//s = S_NAME + wxT( ".cfg" );

	if( !doc.LoadFile( s.c_str() ) )
	{
		r1 = doc.FirstChildElement( "CFG" );
		if( r1 )
		{
			// ---------------------------------------------------------------------------
			e1 = r1->FirstChildElement( "Win_MaxSize" );
			// ---------------------------------------------------------------------------
			if( e1 )
			{
				s = wxT( e1->GetText() );
				if( s == wxT( "T" ) )
				{
					Read_Win_MaxSize = true;
				}
				else
				{
					Read_Win_MaxSize = false;
				}
			}

			// ---------------------------------------------------------------------------
			e1 = r1->FirstChildElement( "Win_PosX" );
			// ---------------------------------------------------------------------------
			if( e1 )
			{
				s = wxT( e1->GetText() );
				if( s.ToLong( &vl ) )
				{
					Win_PosX = vl;
				}
			}

			// ---------------------------------------------------------------------------
			e1 = r1->FirstChildElement( "Win_PosY" );
			// ---------------------------------------------------------------------------
			if( e1 )
			{
				s = wxT( e1->GetText() );
				if( s.ToLong( &vl ) )
				{
					Win_PosY = vl;
				}
			}

			// ---------------------------------------------------------------------------
			e1 = r1->FirstChildElement( "Win_SizeX" );
			// ---------------------------------------------------------------------------
			if( e1 )
			{
				s = wxT( e1->GetText() );
				if( s.ToLong( &vl ) )
				{
					Win_SizeX = vl;
				}
			}

			// ---------------------------------------------------------------------------
			e1 = r1->FirstChildElement( "Win_SizeY" );
			// ---------------------------------------------------------------------------
			if( e1 )
			{
				s = wxT( e1->GetText() );
				if( s.ToLong( &vl ) )
				{
					Win_SizeY = vl;
				}
			}

			// ---------------------------------------------------------------------------
			e1 = r1->FirstChildElement( "COM_NN" );
			// ---------------------------------------------------------------------------
			if( e1 )
			{
				s = wxT( e1->GetText() );
				if( s.ToLong( &vl ) )
				{
					COM_NN = vl;
				}
			}

//			// ---------------------------------------------------------------------------
//			e1 = r1->FirstChildElement( "COM_SPEED" );
//			// ---------------------------------------------------------------------------
//			if( e1 )
//			{
//				s = wxT( e1->GetText() );
//				if( s.ToLong( &vl ) )
//				{
//					COM_SPEED = vl;
//				}
//			}

//			// ---------------------------------------------------------------------------
//			e1 = r1->FirstChildElement( "Prj_Name" );
//			// ---------------------------------------------------------------------------
//			if( e1 )
//			{
//				PRJ_NAME = wxT( e1->GetText() );
//			}
			//}
		}
		doc.Clear();
		return 0;
	}
	else
	{
		return 1;
	}
}
// ===========================================================================


// ===========================================================================
void MyFrame::Write_Cfg()
// ===========================================================================
{
	wxString			 s;
	XML::XMLDocument	 doc;
	XML::XMLElement		*e1;
	XML::XMLNode		*pRoot = doc.NewElement( "CFG" );

	doc.InsertEndChild( doc.NewDeclaration( "xml version=\"1.0\"" ) );
	//doc.InsertEndChild( doc.NewDeclaration() );
	doc.InsertEndChild( pRoot );

	// ---------------------------------------------------------------------------
	// Win_MaxSize
	// ---------------------------------------------------------------------------
	e1 = doc.NewElement( "Win_MaxSize" );
	if( Win_MaxSize )
	{
		e1->SetText( "T" );
	}
	else
	{
		e1->SetText( "F" );
	}
	pRoot->InsertEndChild( e1 );

	// ---------------------------------------------------------------------------
	// Win_PosX
	// ---------------------------------------------------------------------------
	s.Printf( wxT( "%d" ), Win_PosX );
	e1 = doc.NewElement( "Win_PosX" );
	e1->SetText( s.c_str() );
	pRoot->InsertEndChild( e1 );

	// ---------------------------------------------------------------------------
	// Win_PosY
	// ---------------------------------------------------------------------------
	s.Printf( wxT( "%d" ), Win_PosY );
	e1 = doc.NewElement( "Win_PosY" );
	e1->SetText( s.c_str() );
	pRoot->InsertEndChild( e1 );

	// ---------------------------------------------------------------------------
	// Win_SizeX
	// ---------------------------------------------------------------------------
	s.Printf( wxT( "%d" ), Win_SizeX );
	e1 = doc.NewElement( "Win_SizeX" );
	e1->SetText( s.c_str() );
	pRoot->InsertEndChild( e1 );

	// ---------------------------------------------------------------------------
	// Win_SizeY
	// ---------------------------------------------------------------------------
	s.Printf( wxT( "%d" ), Win_SizeY );
	e1 = doc.NewElement( "Win_SizeY" );
	e1->SetText( s.c_str() );
	pRoot->InsertEndChild( e1 );

//	// ---------------------------------------------------------------------------
//	// Project Name+Path
//	// ---------------------------------------------------------------------------
//	if( PRJ_NAME != wxEmptyString )
//	{
//		e1 = doc.NewElement( "Prj_Name" );
//		e1->SetText( PRJ_NAME.c_str() );
//		pRoot->InsertEndChild( e1 );
//	}

	// ---------------------------------------------------------------------------
	// COM-port
	// ---------------------------------------------------------------------------
	s.Printf( wxT( "%d" ), COM_NN );
	e1 = doc.NewElement( "COM_NN" );
	e1->SetText( s.c_str() );
	pRoot->InsertEndChild( e1 );
//	s.Printf( wxT( "%d" ), COM_SPEED );
//	e1 = doc.NewElement( "COM_SPEED" );
//	e1->SetText( s.c_str() );
//	pRoot->InsertEndChild( e1 );

//	s = S_NAME + wxT( ".cfg" );
	s = DATA_DIR + wxT( PATH_SEP ) + S_NAME + wxT( ".cfg" );
	doc.SaveFile( s.c_str() );
	doc.Clear();
}
// ===========================================================================
