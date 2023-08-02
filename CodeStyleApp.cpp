/***************************************************************
 * Name:      CodeStyleApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2021-09-27
 * Copyright:  ()
 * License:
 **************************************************************/

#include "CodeStyleApp.h"

//(*AppHeaders
#include "CodeStyleMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(CodeStyleApp);

bool CodeStyleApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	CodeStyleFrame* Frame = new CodeStyleFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
