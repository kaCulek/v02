#include "nwpwin.h"
#include "res.h"


// TODO: prepare classes (Edit, Button, ListBox) for child windows
class Button : public Window{
public:
	std::string ClassName() { return "BUTTON"; }
};

class Edit : public Window{
public:
	std::string ClassName() { return "EDIT"; }
};

class ListBox : public Window{
public:
	std::string ClassName() { return "LISTBOX"; }
};
// TODO: derive from Window, override ClassName


class MainWindow : public Window
{
protected:
	int OnCreate(CREATESTRUCT* pcs);
	void OnCommand(int id);
	void OnDestroy();
};

int MainWindow::OnCreate(CREATESTRUCT* pcs)
{
	// TODO: create all child windows
	Edit edit; edit.Create(*this, WS_CHILD | WS_VISIBLE | WS_BORDER, "" ,IDC_EDIT ,250, 25, 100, 100);
	Button button_add; button_add.Create(*this, WS_CHILD | WS_VISIBLE, "Add" ,IDC_ADD, 250, 150, 100, 50);
	Button button_remove; button_remove.Create(*this, WS_CHILD | WS_VISIBLE, "Remove",IDC_REMOVE, 250, 225, 100, 50);
	ListBox listbox; listbox.Create(*this, WS_CHILD | WS_VISIBLE | WS_BORDER, "", IDC_LB, 100, 25, 100, 200);
	// TODO: disable "Remove" button
	EnableWindow(button_remove, FALSE);
	return 0;
}

void MainWindow::OnCommand(int id){
	switch(id){
		case ID_FILE_EXIT:
			// TODO: close main window
			OnDestroy();
			break;
		case ID_HELP_ABOUT:
			// TODO: show dialog with text
			MessageBox(*this, "Upi�i tekst u edit i klikni Add za dodavanje u listbox. Remove mi�e tekst iz listboxa.", "NWP 2", MB_OK);
			break;
		case IDC_ADD:
			// TODO: get text from edit control
			// TODO: add string to listbox control
			// TODO: enable "Remove" button
			break;
		case IDC_REMOVE:
			// TODO: get listbox selection
			// TODO: if there is a selection, delete selected string
			// TODO: disable "Remove" button if listbox is empty
			break;
	}
}

void MainWindow::OnDestroy(){
	::PostQuitMessage(0);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hp, LPSTR cmdLine, int nShow)
{
	HMENU hMenu = LoadMenu(hInstance, MAKEINTRESOURCE(IDM_V2));
	MainWindow wnd; 
	wnd.Create(NULL, WS_OVERLAPPEDWINDOW | WS_VISIBLE, "NWP 2", (int)hMenu);	
	// set icons
	HICON hib = (HICON)LoadImage(hInstance, MAKEINTRESOURCE(IDI_V2), IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
	PostMessage(wnd, WM_SETICON, ICON_BIG, reinterpret_cast<LPARAM>(hib));
	HICON his = (HICON)LoadImage(hInstance, MAKEINTRESOURCE(IDI_V2), IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR);
	PostMessage(wnd, WM_SETICON, ICON_SMALL, reinterpret_cast<LPARAM>(his));

	Application app; 
	return app.Run();
}
