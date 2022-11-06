#ifndef _MAIN_H
#define _MAIN_H

class TextFrame : public wxFrame
{
public:

	/** Constructor. Creates a new TextFrame */
	TextFrame(const wxChar *title, int xpos, int ypos, int width, int height);

	/** Processes menu File|Open */
	void OnMenuFileOpen(wxCommandEvent &event);

	/** Processes menu File|Save */
	void OnMenuFileSave(wxCommandEvent &event);

	/** Processes menu File|Quit */
	void OnMenuFileQuit(wxCommandEvent &event);

	/** Processes menu About|Info */
	void OnMenuHelpAbout(wxCommandEvent &event);

protected:

	DECLARE_EVENT_TABLE()

private:

	wxTextCtrl *m_pTextCtrl;
	wxMenuBar *m_pMenuBar;
	wxMenu *m_pFileMenu;
	wxMenu *m_pHelpMenu;
};

#endif _MAIN_H
