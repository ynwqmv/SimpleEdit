/* 
    ** VERSION: 0.2.0 

    ** ~AUTHOR: @ynwqmv
    ** "SIMPLEEDIT" - ABS. FREE & OPEN-SOURCE PROJECT.
    ** FOR MORE INFORMATION, OPEN THIS LINK IN YOUR BROWSER:
    ~ https://github.com/ynwqmv/

*/


// For compilers that/ supports precompilation , includes "wx/wx.h"
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <wx/toolbar.h>
#include <wx/artprov.h>
#include <wx/stattext.h>
#include <wx/app.h>
#include <wx/filedlg.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/bmpbuttn.h>
#include <wx/settings.h>
#include <GL/glut.h>

class App : public wxApp {
public:
    virtual bool OnInit();
};

class TextFrame : public wxFrame
{
public:

    /** Constructor. Creates a new TextFrame */
    TextFrame();



    /** Processes menu File|Open */
    void OnMenuFileOpen(wxCommandEvent &event);

    /** Processes menu File|Save */
    void OnMenuFileSave(wxCommandEvent &event);

    /** Processes menu File|Quit */
    void OnMenuFileQuit(wxCommandEvent &event);

    /** Processes menu About|Info */
    void OnMenuHelpAbout(wxCommandEvent &event);
    /** Closing Window|LogMessage*/
    void OnClose(wxCloseEvent& event);

    /** Counts entering strings */
    void OnStr(wxCommandEvent &event);
 

protected:

    DECLARE_EVENT_TABLE()

private:
    wxTextCtrl *m_pTextCtrl;
    wxMenuBar *m_pMenuBar;
    wxMenu *m_pFileMenu;
    wxMenu *m_pHelpMenu;

};

enum {
    ID_TEXT = 1
};

TextFrame::TextFrame()
: wxFrame(nullptr,wxID_ANY, "SimpleEdit")
{
    
    m_pTextCtrl = new wxTextCtrl(this, ID_TEXT, _T("\t\t\t\t\t\t  WELCOME\n\n[SimpleEdit v0.2.0]\t\t\t\t\t\t\t\t\t\t\n\n       Simple Text Editor for UNIX, OSX and Windows platforms!\n\nFor more information, check [GitHub] repository!\nProgram works without any LICENSE. 'SimpleEdit' - fully free & open-source app for any platforms! Write Documents here are very simple! Enjoy! For AppGuide, check 'Info'\n\nGitHub: https://github.com/ywnqmv"),
        wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);

    

    CreateStatusBar(3);
    SetStatusText(_T("Ready"), 0);

    m_pMenuBar = new wxMenuBar();
    // File menu
    m_pFileMenu = new wxMenu();
    m_pFileMenu->Append(wxID_OPEN, _T("&Open"), _T("Opens an existing file"));
    m_pFileMenu->Append(wxID_SAVE, _T("&Save"), _T("Save the file"));
    m_pFileMenu->Append(wxID_PRINT, _T("&Print"), _T("Print (Soon)"));
    m_pFileMenu->AppendSeparator();
    m_pFileMenu->Append(wxID_EXIT, _T("&Quit"), _T("Quit the application"));
    m_pMenuBar->Append(m_pFileMenu, _T("&File"));
     
    // About menu
    m_pHelpMenu = new wxMenu();
    m_pHelpMenu->Append(wxID_ABOUT, _T("&About"), _T("Shows information about the application"));
    m_pMenuBar->Append(m_pHelpMenu, _T("&Info"));
 
    ///////

    // Close Window
    this->Bind(wxEVT_CLOSE_WINDOW, &TextFrame::OnClose, this);      
     ///////

    /*
        **ynwqmv (C) :: if you use this close-dialog button without event.Skip(), 
        program won't exit. !ALSO BE CAREFUL WITH SEGMENTATION FAULT ERROR! 
        DONT MAKE FREE() WIDGETS, WX WILL DELETE IT BY ITSELF.
    */


    SetMenuBar(m_pMenuBar);
 
    Layout();
}

bool App::OnInit() {

    TextFrame *frame = new TextFrame();
    frame->Show(true);
    return true;
}
// If you're doing an application by inheriting from wxApp
// be sure to change wxFrame to wxApp (or whatever component
// you've inherited your class from).
BEGIN_EVENT_TABLE(TextFrame, wxFrame)
    EVT_MENU(wxID_OPEN, TextFrame::OnMenuFileOpen)
    EVT_MENU(wxID_SAVE, TextFrame::OnMenuFileSave)
    EVT_MENU(wxID_EXIT, TextFrame::OnMenuFileQuit)
    EVT_MENU(wxID_ABOUT, TextFrame::OnMenuHelpAbout)
    EVT_TEXT(ID_TEXT, TextFrame::OnStr)
END_EVENT_TABLE()

 
void TextFrame::OnMenuFileOpen(wxCommandEvent &event)
{   
    wxFileDialog *OpenDialog= new wxFileDialog(this, _T("Choose a file"), _(""), _(""), _("*.*"), wxFD_OPEN);
    if ( OpenDialog->ShowModal() == wxID_OK )
    {
        m_pTextCtrl->LoadFile(OpenDialog->GetPath()) ?
            SetStatusText(_T("Loaded")) :
            SetStatusText(_T("Load Failed")) ;
    }
    OpenDialog->Close(); // Or OpenDialog->Destroy() ?
}

void TextFrame::OnMenuFileSave(wxCommandEvent &event)
{
    wxFileDialog *SaveDialog= new wxFileDialog(this, _T("Choose a file"), _(""), _(""), _("*.*"), wxFD_SAVE);
    if ( SaveDialog->ShowModal() == wxID_OK )
    {
        m_pTextCtrl->SaveFile(SaveDialog->GetPath()) ?
            SetStatusText(_T("Saved successfully")) :
            SetStatusText(_T("Save Failed"));

    }
    SaveDialog->Close();
}

void TextFrame::OnMenuFileQuit(wxCommandEvent &event)
{
    Close(false);
}

void TextFrame::OnMenuHelpAbout(wxCommandEvent &event)
{
    wxLogMessage(_T("SimpleEdit\n\nv0.2.0b\n\nCreators: @ywnqmv"));
}

/* **OnClose Dialog */
void TextFrame::OnClose(wxCloseEvent& event)
{
    wxLogMessage("Closed successfully");
    event.Skip();
}


void TextFrame::OnStr(wxCommandEvent &event)
{   
    static int i;
    i++;

    wxString str = wxString::Format("S: %d",i);
    wxLogStatus(str);

    
}

wxIMPLEMENT_APP(App);


// EOF

