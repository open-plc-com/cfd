/*
    Name:        dialogs.cpp
    Purpose:     Open-PLC Tools
    Author:      www.open-plc.com
    Created:     2023/11
    Modified by:
    RCS-ID:
    Copyright:   (c) Open-PLC
    Licence:     The MIT License (MIT)
*/


#include "dialogs.h"
#include "msg.h"


// ============================================================================
PrjAdd::PrjAdd( wxWindow       *parent,
                wxWindowID     id,
                const wxString &title,
                const wxPoint  &pos,
                const wxSize   &size,
                long           style )
       : PrjAddFB( parent, id, title, pos, size, style )
// ============================================================================
{
    if( !PRJ_FILE_SELECT )
    {
        m_file_name->Show( false );
        m_file_set->Show( false );
    }
}
// ============================================================================


// ============================================================================
PrjAdd::~PrjAdd() {}
// ============================================================================


// ============================================================================
void PrjAdd::onOK( wxCommandEvent &WXUNUSED( event ) )
// ============================================================================
{
    unsigned int c;
    unsigned int i, j, k, m, n;
    bool         err = false;
    wxString     s, s_ext, s2;
    long         l;
    int          max_nval = 0x7FFF;
    std::vector<long> lval;

    s = m_text_name->GetValue();
    s.Trim(false).Trim(true);
    m_text_name->SetValue(s);

    for( i = 0; i < s.Length(); i++ )
    {
        c = s[i].GetValue();
        if( ( c < 0x30 ) && ( c != 0x2E ) )
        {
            err = true;
        }
        else
        if( ( c > 0x39 ) && ( c < 0x41 ) )
        {
            err = true;
        }
        else
        if( ( c > 0x5A ) && ( c < 0x61 ) && ( c != 0x5F ) )
        {
            err = true;
        }
        else
        if( c > 0x7A )
        {
            err = true;
        }
    }

    if( err )
    {
        wxMessageBox( wxT( "The name can only consist\nof printable characters" ), wxT( "Error" ), wxOK | wxICON_ERROR );
        m_text_name->SetFocus();
    }

    if( s == wxEmptyString )
    {
        wxMessageBox( wxT( "Name must be entered" ), wxT( "Error" ), wxOK | wxICON_ERROR );
        m_text_name->SetFocus();
        err = true;
    }

    if( !err )
    {
        m = grid->GetNumberRows();
        for( i = 0; i < m; i++ )
        {
            if( m_text_name->GetValue() == grid->GetCellValue( i, 3 ) )
            {
                err = true;
            }
            if( m_text_name->GetValue() == grid->GetCellValue( i, 4 ) )
            {
                err = true;
            }
        }

        if( !err )
        {
            if( m_pou->size() )
            {
                for( i = 0; i < m_pou->size(); i++ )
                {
                    if( m_pou->at(i).Level == 2 )
                    {
                        s2 = m_pou->at(i).Name;
                        if( s == s2 )
                        {
                            err = true;
                        }
                    }
                }
            }
        }

        if( err )
        {
            wxMessageBox( wxT( "The name already in use" ), wxT( "Error" ), wxOK | wxICON_ERROR );
            m_text_name->SetFocus();
        }
    }

    if( PRJ_FILE_SELECT && !err )
    {
        s = m_file_set->GetPath();
        if( s == wxEmptyString )
        {
            wxMessageBox( wxT( "File Name must be selected" ), wxT( "Error" ), wxOK | wxICON_ERROR );
            m_text_name->SetFocus();
            err = true;
        }
    }

    if( ( grid != 0 ) && !err )
    {
        m = grid->GetNumberRows(); // Number of Rows
        n = grid->GetNumberCols(); // Number of Cols
        lval.clear();
        nval.clear();
        nval.resize( max_nval );

        for( i = 0; i < nval.size(); i++ )
        {
            nval[i] = -1;
        }

        for( i = 0; i < m; i++ )
        {
            s = grid->GetCellValue( i, (n-1) );
            if( s.ToLong( &l ) )
            {
                if( l > 0 )
                {
                    lval.push_back( l );
                }
            }
        }

        // Search max free Nn
        ReturnNn = -1;
        k = lval.size();
        if( k )
        {
            for( i = 0; i < k; i++ )
            {
                j = lval[i];
                if( j < nval.size() )
                {
                    nval[j] = lval[i];
                }
            }

            for( i = 1; i < nval.size(); i++ )
            {
                if( nval[i] < 0 )
                {
                    ReturnNn = i;
                    break;
                }
            }
        }
    }

    s = m_file_set->GetPath();
    k = s.Find( '.' );
    if( k != wxNOT_FOUND )
    {
        s_ext = s.Mid( k );
        if( s_ext != wxT( ".prj" ) )
        {
            s = s + wxT( ".prj" );
            m_file_set->SetPath( s );
        }
    }
    else
    {
        s = s + wxT( ".prj" );
        m_file_set->SetPath( s );
    }

    if( !err )
    {
        ON_OK = true;
        Close();
    }
}
// ============================================================================


// ============================================================================
void PrjAdd::OnCANCEL( wxCommandEvent &WXUNUSED( event ) )
// ============================================================================
{
    Close();
}
// ============================================================================


// ============================================================================
void PrjAdd::OnChar( wxKeyEvent &event )
// ============================================================================
{
    wxUint32 key;
    key = event.GetKeyCode();
    if( key == WXK_ESCAPE )
    {
        Close();
    }
    event.Skip();
}
// ============================================================================


BEGIN_EVENT_TABLE( PrjAdd, PrjAddFB )
    EVT_CHAR_HOOK( PrjAdd::OnChar )
END_EVENT_TABLE()
