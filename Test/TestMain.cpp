/***************************************************************
 * Name:      TestMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Ikenna Paul Abonyi ()
 * Created:   2021-01-04
 * Copyright: Ikenna Paul Abonyi ()
 * License:
 **************************************************************/

#include "TestMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(TestFrame)
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

//(*IdInit(TestFrame)
const long TestFrame::ID_TEXTCTRL1 = wxNewId();
const long TestFrame::ID_TEXTCTRL2 = wxNewId();
const long TestFrame::ID_STATICTEXT1 = wxNewId();
const long TestFrame::ID_STATICTEXT2 = wxNewId();
const long TestFrame::ID_BUTTON1 = wxNewId();
const long TestFrame::ID_TEXTCTRL3 = wxNewId();
const long TestFrame::ID_MENUITEM1 = wxNewId();
const long TestFrame::idMenuAbout = wxNewId();
const long TestFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(TestFrame,wxFrame)
    //(*EventTable(TestFrame)
    //*)
END_EVENT_TABLE()

TestFrame::TestFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(TestFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(400,204));
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("Text"), wxPoint(96,24), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, _("Text"), wxPoint(96,56), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Label"), wxPoint(40,24), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Label"), wxPoint(40,56), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    Button1 = new wxButton(this, ID_BUTTON1, _("Label"), wxPoint(112,96), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, _("Text"), wxPoint(96,136), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
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
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&TestFrame::OnTextCtrl2Text);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TestFrame::OnButton1Click1);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&TestFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&TestFrame::OnAbout);
    //*)
}

TestFrame::~TestFrame()
{
    //(*Destroy(TestFrame)
    //*)
}

void TestFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void TestFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}



void TestFrame::OnButton1Click1(wxCommandEvent& event)
{
    long a = 0, b = 0;
    wxString rac = wxT("");
    if(TextCtrl1->GetValue().ToLong((&a)) and TextCtrl2->GetValue().ToLong((&b)))
    {
        rac<<a+b;
        TextCtrl3->SetValue(rac);
    }else wxMessageBox((wxT("There is an error!")));
}
