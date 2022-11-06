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

 
    void OnHelp(wxCommandEvent& event);
 

protected:

    DECLARE_EVENT_TABLE()

private:
    wxTextCtrl *m_pTextCtrl;
    wxMenuBar *m_pMenuBar;
    wxMenu *m_pFileMenu;
    wxMenu *m_pHelpMenu;

};

enum {
    ID_TEXT = 1,
    ID_BITMAP = 1,
    ID_NEW = 1,
    ID_SAVEE = 2,
    ID_PRINT = 1,
    ID_HELPP = 3
};

TextFrame::TextFrame()
: wxFrame(nullptr,wxID_ANY, "SimpleEdit")
{
    
    m_pTextCtrl = new wxTextCtrl(this, ID_TEXT, _T("\t\t\t\t\t\t  WELCOME\n\n[SimpleEdit v0.2.1]\t\t\t\t\t\t\t\t\t\t\n\n       Simple Text Editor for UNIX, OSX and Windows platforms!\n\nFor more information, check [GitHub] repository!\nProgram works without any LICENSE. 'SimpleEdit' - fully free & open-source app for any platforms! Write Documents here are very simple! Enjoy! For AppGuide, check 'Info'\n\nGitHub: https://github.com/ywnqmv"),
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

    wxToolBar* toolbar = CreateToolBar();
 
    toolbar->AddTool(ID_NEW, _("New"), wxArtProvider::GetBitmap("wxART_NEW"));
    toolbar->Realize();
	toolbar->AddSeparator();	
	toolbar->AddSeparator();

   	toolbar->AddTool(ID_SAVEE, _("Save"), wxArtProvider::GetBitmap("wxART_FILE_SAVE"));
    toolbar->Realize();

    toolbar->AddTool(wxID_ANY, _("Print"), wxArtProvider::GetBitmap("wxART_PRINT"));
    toolbar->Realize();


    toolbar->AddTool(ID_HELPP, _("Help"), wxArtProvider::GetBitmap("wxART_INFORMATION"));
    toolbar->Realize();
     
    
     
    // About menu
    m_pHelpMenu = new wxMenu();
    m_pHelpMenu->Append(wxID_ABOUT, _T("&About"), _T("Shows information about the application"));
    m_pMenuBar->Append(m_pHelpMenu, _T("&Info"));
    m_pHelpMenu->Append(wxID_ABOUT, _T("&About"), _T("Shows information about the application"));
    
 
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
    EVT_MENU(ID_BITMAP, TextFrame::OnMenuFileOpen)
    EVT_MENU(ID_SAVEE, TextFrame::OnMenuFileSave)
    EVT_MENU(ID_NEW, TextFrame::OnMenuFileOpen)
    EVT_MENU(ID_HELPP, TextFrame::OnHelp)
 



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

void TextFrame::OnHelp(wxCommandEvent& event) {
	wxMessageBox("SimpleEdit     v0.2.1\n\nFor more information goto\nhttps://github.com/ynwqmv/\n\nFor other questions about app,\nplease contact <lexpycode0@gmail.com>\n\nCreators: @ynwqmv\nThanks for using our App!", "Info", wxOK |wxICON_INFORMATION);
}

 

wxIMPLEMENT_APP(App);


// EOF

