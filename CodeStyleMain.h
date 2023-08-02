/***************************************************************
 * Name:      CodeStyleMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2021-09-27
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef CODESTYLEMAIN_H
#define CODESTYLEMAIN_H

//(*Headers(CodeStyleFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/notebook.h>
//*)

#include <wx/stc/stc.h>
#include <wx/sizer.h>
#include "Edit.h"

class CodeStyleFrame: public wxFrame
{
    public:

        CodeStyleFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~CodeStyleFrame();

    private:

        //(*Handlers(CodeStyleFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnNotebook1PageChanged(wxNotebookEvent& event);
        //*)

        void OnMarginClick(wxStyledTextEvent& event);
        //(*Identifiers(CodeStyleFrame)
        static const long ID_NOTEBOOK1;
        static const long ID_MENUITEM1;
        static const long idMenuAbout;
        //*)

        //(*Declarations(CodeStyleFrame)
        wxNotebook* Notebook1;
        //*)
        wxBoxSizer *sizer;
        Edit *code;
        Edit *codeCPP;
        DECLARE_EVENT_TABLE()
};

#endif // CODESTYLEMAIN_H
