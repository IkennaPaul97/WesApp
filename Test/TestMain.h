/***************************************************************
 * Name:      TestMain.h
 * Purpose:   Defines Application Frame
 * Author:    Ikenna Paul Abonyi ()
 * Created:   2021-01-04
 * Copyright: Ikenna Paul Abonyi ()
 * License:
 **************************************************************/

#ifndef TESTMAIN_H
#define TESTMAIN_H

//(*Headers(TestFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class TestFrame: public wxFrame
{
    public:

        TestFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~TestFrame();

    private:

        //(*Handlers(TestFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnTextCtrl1Text(wxCommandEvent& event);
        void OnTextCtrl1Text1(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnTextCtrl1Text2(wxCommandEvent& event);
        void OnTextCtrl2Text(wxCommandEvent& event);
        void OnButton1Click1(wxCommandEvent& event);
        void OnTextCtrl1Text3(wxCommandEvent& event);
        void OnTextCtrl3Text(wxCommandEvent& event);
        //*)

        //(*Identifiers(TestFrame)
        static const long ID_MENUITEM1;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(TestFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // TESTMAIN_H
