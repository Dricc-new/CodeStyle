//////////////////////////////////////////////////////////////////////////////
// File:        edit.h
// Purpose:     STC test module
// Maintainer:  Wyo
// Created:     2003-09-01
// Copyright:   (c) wxGuide
// Licence:     wxWindows licence
//////////////////////////////////////////////////////////////////////////////

#ifndef _EDIT_H_
#define _EDIT_H_

//----------------------------------------------------------------------------
// information
//----------------------------------------------------------------------------


//----------------------------------------------------------------------------
// headers
//----------------------------------------------------------------------------

//! wxWidgets headers

//! wxWidgets/contrib headers
#include <wx/stc/stc.h>  // styled text control

//! application headers
#include "prefs.h"       // preferences


//============================================================================
// declarations
//============================================================================

//----------------------------------------------------------------------------
//! Edit
class Edit: public wxStyledTextCtrl {
public:
    //! constructor
    Edit (wxWindow *parent, wxWindowID id = wxID_ANY,
          const wxPoint &pos = wxDefaultPosition,
          const wxSize &size = wxDefaultSize,
          long style =
#ifndef __WXMAC__
          wxSUNKEN_BORDER|
#endif
          wxVSCROLL
         );

    //! destructor
    ~Edit ();

    // event handlers
    // common
    void OnSize( wxSizeEvent &event );
    // edit
    void OnEditRedo (wxCommandEvent &event);
    void OnEditUndo (wxCommandEvent &event);
    void OnEditClear (wxCommandEvent &event);
    void OnEditCut (wxCommandEvent &event);
    void OnEditCopy (wxCommandEvent &event);
    void OnEditPaste (wxCommandEvent &event);
    // find
    void OnFind (wxCommandEvent &event);
    void OnFindNext (wxCommandEvent &event);
    void OnReplace (wxCommandEvent &event);
    void OnReplaceNext (wxCommandEvent &event);
    void OnBraceMatch (wxCommandEvent &event);
    void OnGoto (wxCommandEvent &event);
    void OnEditIndentInc (wxCommandEvent &event);
    void OnEditIndentRed (wxCommandEvent &event);
    void OnEditSelectAll (wxCommandEvent &event);
    void OnEditSelectLine (wxCommandEvent &event);
    //! view
    void OnHighlightLang (wxCommandEvent &event);
    void OnDisplayEOL (wxCommandEvent &event);
    void OnIndentGuide (wxCommandEvent &event);
    void OnLineNumber (wxCommandEvent &event);
    void OnLongLineOn (wxCommandEvent &event);
    void OnWhiteSpace (wxCommandEvent &event);
    void OnFoldToggle (wxCommandEvent &event);
    void OnSetOverType (wxCommandEvent &event);
    void OnSetReadOnly (wxCommandEvent &event);
    void OnWrapmodeOn (wxCommandEvent &event);
    void OnUseCharset (wxCommandEvent &event);
    // annotations
    void OnAnnotationAdd(wxCommandEvent& event);
    void OnAnnotationRemove(wxCommandEvent& event);
    void OnAnnotationClear(wxCommandEvent& event);
    void OnAnnotationStyle(wxCommandEvent& event);
    //! extra
    void OnChangeCase (wxCommandEvent &event);
    void OnConvertEOL (wxCommandEvent &event);
    void OnMultipleSelections(wxCommandEvent& event);
    void OnMultiPaste(wxCommandEvent& event);
    void OnMultipleSelectionsTyping(wxCommandEvent& event);
    void OnCustomPopup(wxCommandEvent& evt);
    void OnTechnology(wxCommandEvent& event);
    // stc
    void OnMarginClick (wxStyledTextEvent &event);
    void OnCharAdded  (wxStyledTextEvent &event);
    void OnCallTipClick(wxStyledTextEvent &event);

    void OnKeyDown(wxKeyEvent &event);

    // call tips
    void ShowCallTipAt(int position);

    //! language/lexer
    wxString DeterminePrefs (const wxString &filename);
    bool InitializePrefs (const wxString &filename);
    LanguageInfo const* GetLanguageInfo () {return m_language;}

    //! load/save file
    bool LoadFile ();
    bool LoadFile (const wxString &filename);
    bool SaveFile ();
    bool SaveFile (const wxString &filename);
    bool Modified ();
    wxString GetFilename () {return m_filename;}
    void SetFilename (const wxString &filename) {m_filename = filename;}
    void onfuncion (wxStyledTextEvent &event);

private:
    // file
    wxString m_filename;

    // language properties
    LanguageInfo const* m_language;

    // margin variables
    int m_LineNrID;
    int m_LineNrMargin;
    int m_FoldingID;
    int m_FoldingMargin;
    int m_DividerID;

    // call tip data
    int m_calltipNo;

    wxDECLARE_EVENT_TABLE();
};

#endif // _EDIT_H_