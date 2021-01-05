/***************************************************************
 * Name:      TestApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Ikenna Paul Abonyi ()
 * Created:   2021-01-04
 * Copyright: Ikenna Paul Abonyi ()
 * License:
 **************************************************************/

#include "TestApp.h"

//(*AppHeaders
#include "TestMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(TestApp);

bool TestApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	TestFrame* Frame = new TestFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
