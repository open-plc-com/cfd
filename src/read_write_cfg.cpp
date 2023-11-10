/*
    Name:           read_write_cfg.cpp
    Purpose:        Open-PLC Tools
    Author:         www.open-plc.com
    Created:        2023/10
    Modified by:
    RCS-ID:
    Copyright:      (c) Open-PLC
    Licence:        The MIT License (MIT)
*/


#include <wx/filename.h>
#include <wx/stdpaths.h>
#include <wx/dir.h>
#include <wx/string.h>

#include "myframe.h"
#include "tinyxml2.h"

#include "./pict/project.xpm"
#include "./pict/st.xpm"
#include "./pict/fbd.xpm"
#include "./pict/ld.xpm"
#include "./pict/var_inout.xpm"
#include "./pict/f.xpm"


// ============================================================================
int MyFrame::PathInit( void )
// ============================================================================
{
    int      pos;
    wxString s;

    wxStandardPathsBase &stdp = wxStandardPaths::Get();
    wxFileName          f( wxStandardPaths::Get().GetExecutablePath() );
    wxString            appPath( f.GetPath() );
    wxFileName::SplitPath( appPath, &WORK_PATH, &s, &S_EXT );
    PATH_SEP  = wxFileName::DirName( appPath ).GetPathSeparator();
    EXEC_PATH = stdp.GetExecutablePath();
    DATA_DIR  = stdp.GetUserLocalDataDir();

    pos = DATA_DIR.Find( PATH_SEP, true ) + 1;
    S_NAME = DATA_DIR.Mid( pos );

//printf( "WORK_PATH=%s\n", (const char*) WORK_PATH.c_str() );
//printf( "S_EXT=%s\n", (const char*) S_EXT.c_str() );
//printf( "PATH_SEP=%c\n", PATH_SEP );
//printf( "EXEC_PATH=%s\n", (const char*) EXEC_PATH.c_str() );
//printf( "DATA_DIR=%s\n", (const char*) DATA_DIR.c_str() );
//printf( "S_NAME=%s\n", (const char*) S_NAME.c_str() );

    if( !wxDir::Exists( DATA_DIR ) )
    {
        if( !wxMkdir( DATA_DIR ) )
        {
            s = wxT( "Can't create dir\n\"" );
            s = s + DATA_DIR;
            s = s + PATH_SEP;
            wxMessageBox( s, wxT( "ERROR" ), wxICON_ERROR );
            return 1;
        }
    }
    return 0;
}
// ============================================================================


// ============================================================================
void MyFrame::ReadCfg()
// ============================================================================
{
    long                  vl;
    wxString              s, s1, s2;
    int                   n, n_start, n_end, nc, nc_start, nc_end;
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLElement  *r1, *e1;
    wxString              aui_cur = m_mgr1.SavePerspective();

    s = DATA_DIR + PATH_SEP + S_NAME + wxT( ".cfg" );

    if( !doc.LoadFile( (const char*) s.c_str() ) )
    {
        r1 = doc.FirstChildElement( "CFG" );
        if( r1 )
        {
            // ---------------------------------------------------------------------------
            e1 = r1->FirstChildElement( "OPT_VER" );
            // ---------------------------------------------------------------------------
            if( e1 )
            {
                s = e1->GetText();
//printf( "Load OPT_VER=%s\n", (const char*) s.c_str() );
            }
            else
            {
                s = wxEmptyString;
            }

if( s != wxT( OPT_VER ) )
{
//printf( "=== OPT_VER ===\n" );
return;
} // === OPT_VER ===

            // ---------------------------------------------------------------------------
            e1 = r1->FirstChildElement( "Win_MaxSize" );
            // ---------------------------------------------------------------------------
            if( e1 )
            {
                s = e1->GetText();
                if( s == wxT( "T" ) )
                {
                    Win_MaxSize = true;
                }
                else
                {
                    Win_MaxSize = false;
                }
            }

            // ---------------------------------------------------------------------------
            e1 = r1->FirstChildElement( "Win_PosX" );
            // ---------------------------------------------------------------------------
            if( e1 )
            {
                s = e1->GetText();
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
                s = e1->GetText();
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
                s = e1->GetText();
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
                s = e1->GetText();
                if( s.ToLong( &vl ) )
                {
                    Win_SizeY = vl;
                }
            }

            // ---------------------------------------------------------------------------
            e1 = r1->FirstChildElement( "AUI" );
            // ---------------------------------------------------------------------------
            if( e1 )
            {
                s = e1->GetText();
                n_start = 0;
                nc_start = 0;

                do
                {
                    n = s.find( wxT("name="), n_start );
                    nc = aui_cur.find( wxT("name="), nc_start );
                    n_start = n;
                    nc_start = nc;

                    if( n > 0 )
                    {
                        n_end = s.find( ';', n_start );
                        nc_end = aui_cur.find( ';', nc_start );
                        if( ( n_end - n_start) > 10 )
                        {
                            s1 = s.SubString( n_start, n_end );
                            s2 = aui_cur.SubString( nc_start, nc_end );
                            s.Replace( s1, s2 );
                        }
                    }
                    n_start++;
                    nc_start++;
                } while( n > 0 );
                aui_cur = s;
            }
            else
            {
                aui_cur = wxEmptyString;
            }

            // ---------------------------------------------------------------------------
            e1 = r1->FirstChildElement( "Prj_File" );
            // ---------------------------------------------------------------------------
            if( e1 )
            {
                PRJ_FILE = e1->GetText();
            }

            if( Win_MaxSize )
            {
                Maximize();
            }

            if( Win_SizeX && Win_SizeY  )
            {
                // Restore size & position
                if( ( Win_PosX >= 0 ) && ( Win_PosY >= 0 ) )
                {
                    Move( Win_PosX, Win_PosY );
                }
                if( Win_SizeX && Win_SizeY )
                {
                    SetSize( wxSize( Win_SizeX, Win_SizeY ) );
                }
            }

            if( aui_cur != wxEmptyString )
            {
                m_mgr1.LoadPerspective( aui_cur );

                m_mgr1.GetPane( m_nb_shape ).Show( false );
                m_mgr1.GetPane( m_nb_edit ).Show( false );
                m_mgr1.GetPane( m_nb_grid ).Show( false );

                m_mgr1.GetPane( m_st_tool).Show( false );
                m_mgr1.GetPane( m_fbd_tool).Show( false );
                m_mgr1.GetPane( m_ld_tool).Show( false );
                m_mgr1.GetPane( m_add_tool).Show( false );

                m_mgr1.Update();
            }
        }
        doc.Clear();
    }
}
// ============================================================================


// ============================================================================
void MyFrame::WriteCfg()
// ============================================================================
{
    wxString              s;
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLElement  *e1;
    tinyxml2::XMLNode     *pRoot = doc.NewElement( "CFG" );

    doc.InsertEndChild( doc.NewDeclaration( "xml version=\"1.0\"" ) );
    //doc.InsertEndChild( doc.NewDeclaration() );
    doc.InsertEndChild( pRoot );

    // ------------------------------------------------------------------------
    s.Printf( wxT( "%d" ), LANG );
    // ------------------------------------------------------------------------
    e1 = doc.NewElement( "LANG" );
    e1->SetText( (const char*) s.c_str() );
    pRoot->InsertEndChild( e1 );

    // ------------------------------------------------------------------------
    e1 = doc.NewElement( "OPT_VER" ); // Version
    // ------------------------------------------------------------------------
    e1->SetText( OPT_VER );
    pRoot->InsertEndChild( e1 );

    // ------------------------------------------------------------------------
    e1 = doc.NewElement( "Win_MaxSize" );
    // ------------------------------------------------------------------------
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
    s.Printf( wxT( "%d" ), Win_PosX );
    // ---------------------------------------------------------------------------
    e1 = doc.NewElement( "Win_PosX" );
    e1->SetText( (const char*) s.c_str() );
    pRoot->InsertEndChild( e1 );

    // ---------------------------------------------------------------------------
    s.Printf( wxT( "%d" ), Win_PosY );
    // ---------------------------------------------------------------------------
    e1 = doc.NewElement( "Win_PosY" );
    e1->SetText( (const char*) s.c_str() );
    pRoot->InsertEndChild( e1 );

    // ---------------------------------------------------------------------------
    s.Printf( wxT( "%d" ), Win_SizeX );
    // ---------------------------------------------------------------------------
    e1 = doc.NewElement( "Win_SizeX" );
    e1->SetText( (const char*) s.c_str() );
    pRoot->InsertEndChild( e1 );

    // ---------------------------------------------------------------------------
    s.Printf( wxT( "%d" ), Win_SizeY );
    // ---------------------------------------------------------------------------
    e1 = doc.NewElement( "Win_SizeY" );
    e1->SetText( (const char*) s.c_str() );
    pRoot->InsertEndChild( e1 );

    s = m_mgr1.SavePerspective();

    // ---------------------------------------------------------------------------
    e1 = doc.NewElement( "AUI" );
    // ---------------------------------------------------------------------------
    e1->SetText( (const char*) s.c_str() );
    pRoot->InsertEndChild( e1 );

    // ---------------------------------------------------------------------------
    if( PRJ_FILE != wxEmptyString ) // Project FileName
    // ---------------------------------------------------------------------------
    {
        e1 = doc.NewElement( "Prj_File" );
        e1->SetText( PRJ_FILE.c_str() );
        pRoot->InsertEndChild( e1 );
    }

    s = DATA_DIR + PATH_SEP + S_NAME + wxT( ".cfg" );
    doc.SaveFile( (const char*) s.c_str() );
    doc.Clear();
}
// ============================================================================


// ============================================================================
int MyFrame::ReadPrj()
// ============================================================================
{
    int                   i, j, n;
    const char            *AttributeText = 0;
    wxString              s;
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLElement  *r1, *e1;

    if( !doc.LoadFile( (const char*) PRJ_FILE.c_str() ) )
    {
        r1 = doc.FirstChildElement( "OPEN-PLC_PRJ" );
        if( r1 )
        {
            // ----------------------------------------------------------------
            e1 = r1->FirstChildElement( "PRJ_NAME" );
            // ----------------------------------------------------------------
            if( e1 )
            {
                s = e1->GetText();
                PRJ_NAME = s;
            }

            // ----------------------------------------------------------------
            e1 = r1->FirstChildElement( "PRJ_GRID" );
            // ----------------------------------------------------------------
            i = 0;
            while( e1 )
            {
                for( j = 0; j < m_prj_tree->GetNumberCols(); j++ )
                {
                    s.Printf( "C%d", j );
                    AttributeText = e1->Attribute( (const char*) s.c_str() );
                    m_prj_tree->SetCellValue( i, j, AttributeText );
                }

                e1 = e1->NextSiblingElement( "PRJ_GRID" );
                i++;
                if( e1 )
                {
                    m_prj_tree->AppendRows();
                }
            }

            n = m_prj_tree->GetNumberCols();
            for( i = 0; i < m_prj_tree->GetNumberRows(); i++ )
            {
                s = m_prj_tree->GetCellValue( i, (n-2) );

                if( s == wxT( "PRJ" ) )
                {
                    m_prj_tree->SetCellRenderer( i, 0, new GridBitmap( wxBitmap( project_xpm ) ) );
                    m_prj_tree->SetCellSize( i, 1, 1, 4 );
                }
                else
                if( s == wxT( "FUNC" ) )
                {
                    m_prj_tree->SetCellSize( i, 2, 1, 3 );
                    m_prj_tree->SetCellRenderer( i, 1, new GridBitmap( wxBitmap( f_xpm ) ) );
                }
                else
                if( s == wxT( "ST" ) )
                {
                    m_prj_tree->SetCellRenderer( i, 2, new GridBitmap( wxBitmap( st_xpm ) ) );
                }
                else
                if( s == wxT( "FBD" ) )
                {
                    m_prj_tree->SetCellRenderer( i, 2, new GridBitmap( wxBitmap( fbd_xpm ) ) );
                }
                else
                if( s == wxT( "LD" ) )
                {
                    m_prj_tree->SetCellRenderer( i, 2, new GridBitmap( wxBitmap( ld_xpm ) ) );
                }
                else
                if( s == wxT( "PRG" ) )
                {
                    m_prj_tree->SetCellSize( i, 3, 1, 2 );
                    m_prj_tree->SetCellRenderer( i, 1, new GridBitmap( wxBitmap( var_inout_xpm ) ) );
                    m_prj_tree->SetCellRenderer( i, 2, new GridBitmap( wxBitmap( fbd_xpm ) ) );
                }
            }

            PRJ_CHANGED = false;
        }
        else
        {
            doc.Clear();
            return 1;
        }
        doc.Clear();
        return 0;
    }
    else
    {
        return 2;
    }
}
// ============================================================================


// ============================================================================
void MyFrame::WritePrj()
// ============================================================================
{
    int                   i, j;
    wxString              s, s_attr, s_val;
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLElement  *e1;
    tinyxml2::XMLNode     *pRoot = doc.NewElement( "OPEN-PLC_PRJ" );

    doc.InsertEndChild( doc.NewDeclaration( "xml version=\"1.0\"" ) );
    //doc.InsertEndChild( doc.NewDeclaration() );
    doc.InsertEndChild( pRoot );

    // ------------------------------------------------------------------------
    if( PRJ_NAME != wxEmptyString ) // Project Name
    // ------------------------------------------------------------------------
    {
        e1 = doc.NewElement( "PRJ_NAME" );
        e1->SetText( PRJ_NAME.c_str() );
        pRoot->InsertEndChild( e1 );
    }

    // ---------------------------------------------------------------------------
    // m_prj_tree
    // ---------------------------------------------------------------------------
    for( i = 0; i < m_prj_tree->GetNumberRows(); i++ )
    {
        e1 = doc.NewElement( "PRJ_GRID" );
        for( j = 0; j < m_prj_tree->GetNumberCols(); j++ )
        {
            s_attr.Printf( "%d", j );
            s = wxT( "C" ) + s_attr;
            s_val = m_prj_tree->GetCellValue( i, j );
            e1->SetAttribute( (const char*) s.c_str(), s_val.c_str() );
        }
        pRoot->InsertEndChild( e1 );
    }

    doc.SaveFile( (const char*) PRJ_FILE.c_str() );
    doc.Clear();

    PRJ_CHANGED = false;
}
// ============================================================================
