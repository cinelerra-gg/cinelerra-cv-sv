#ifndef BROWSEBUTTON_H
#define BROWSEBUTTON_H

#include "guicast.h"
#include "mwindow.inc"
#include "thread.h"


class BrowseButton : public BC_Button, public Thread
{
public:
	BrowseButton(MWindow *mwindow, 
		BC_WindowBase *parent_window, 
		BC_TextBox *textbox, 
		int x, 
		int y, 
		char *init_directory, 
		char *title, 
		char *caption, 
		int want_directory = 0);
	~BrowseButton();
	
	int handle_event();
	void run();
	int want_directory;
	char result[1024];
	char *title;
	char *caption;
	char *init_directory;
	BC_TextBox *textbox;
	MWindow *mwindow;
	BC_WindowBase *parent_window;
};

class BrowseButtonWindow : public BC_FileBox
{
public:
	BrowseButtonWindow(MWindow *mwindow,
		BC_WindowBase *parent_window, 
		char *init_directory, 
		char *title, 
		char *caption, 
		int want_directory);
	~BrowseButtonWindow();
};





#endif
