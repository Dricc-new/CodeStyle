/***************************************************************
 * Name:      CodeStyleMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2021-09-27
 * Copyright:  ()
 * License:
 **************************************************************/

#include "CodeStyleMain.h"
#include <wx/msgdlg.h>
#include "wx/wxprec.h"


// for all others, include the necessary headers (this file is usually all you
// need because it includes almost all 'standard' wxWidgets headers)
    #include "wx/wx.h"
    #include "wx/textdlg.h"

//! wxWidgets headers
#include "wx/file.h"     // raw file io support
#include "wx/filename.h"

//(*InternalHeaders(CodeStyleFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(CodeStyleFrame)
const long CodeStyleFrame::ID_NOTEBOOK1 = wxNewId();
const long CodeStyleFrame::ID_MENUITEM1 = wxNewId();
const long CodeStyleFrame::idMenuAbout = wxNewId();
//*)

BEGIN_EVENT_TABLE(CodeStyleFrame,wxFrame)
    //(*EventTable(CodeStyleFrame)
    //*)
END_EVENT_TABLE()

CodeStyleFrame::CodeStyleFrame(wxWindow* parent,wxWindowID id)
{
        sizer = new wxBoxSizer(wxVERTICAL);
    //(*Initialize(CodeStyleFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(1019,600));
    Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxPoint(0,80), wxSize(1019,520), 0, _T("ID_NOTEBOOK1"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, ID_MENUITEM1, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);

    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CodeStyleFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CodeStyleFrame::OnAbout);
    //*)

    MenuBar1->SetBackgroundColour(wxColor(20,200,200));
    code = new Edit(Notebook1,wxID_ANY);
   // code->SetMarginWidth(1,25);
    //code->StyleSetForeground(wxSTC_STYLE_LINENUMBER,wxColor(200,200,200));
    //code->StyleSetBackground(wxSTC_STYLE_LINENUMBER,wxColor(20,20,25));
    code->SetMarginType(1,wxSTC_MARGIN_NUMBER);
    code->SetWrapMode(wxSTC_WRAP_WORD);
    code->SetLexer(wxSTC_LEX_HTML);
    code->StyleSetForeground(wxSTC_H_DOUBLESTRING,wxColor(255,0,0));
    code->StyleSetForeground(wxSTC_H_SINGLESTRING,wxColor(255,0,0));
    code->StyleSetForeground(wxSTC_H_ENTITY,wxColor(255,0,0));
    code->StyleSetForeground(wxSTC_H_TAG,wxColor(0,150,0));
    code->StyleSetForeground(wxSTC_H_TAGUNKNOWN,wxColor(0,150,0));
    code->StyleSetForeground(wxSTC_H_ATTRIBUTE,wxColor(0,0,150));
    code->StyleSetForeground(wxSTC_H_ATTRIBUTEUNKNOWN,wxColor(0,0,150));
    code->StyleSetForeground(wxSTC_H_COMMENT,wxColor(150,150,150));
    wxColor black(24,24,32);
    wxColor black2(32,32,45);
    wxColor withe(150,150,150);
    codeCPP = new Edit(Notebook1,wxID_ANY);

    codeCPP->LoadFile();
//    codeCPP->OnLineNumber(NULL);

    Notebook1->AddPage(codeCPP,_("Code C++"));
    Notebook1->AddPage(code,_("Code HTML"));

    sizer->Add(Notebook1,1,wxEXPAND);
    SetSizer(sizer);
    Connect(wxEVT_STC_MARGINCLICK,wxStyledTextEventHandler(CodeStyleFrame::OnMarginClick),NULL,this);
}

CodeStyleFrame::~CodeStyleFrame()
{
    //(*Destroy(CodeStyleFrame)
    //*)
}

void CodeStyleFrame::OnMarginClick(wxStyledTextEvent& event){

}

void CodeStyleFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void CodeStyleFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

