#include <wx/wx.h>

class Notepad : public wxFrame {
    public:
        Notepad(); // our default constructor

    private:
        wxMenuBar *menu; // the menu bar
        wxMenu *file; // the file menu (keep this simple
        wxTextCtrl *text; // the main text area
        void OnSave(wxCommandEvent &event); // the click event for "save"
        void OnOpen(wxCommandEvent &event); // the click event for "open"
        void OnExit(wxCommandEvent &event); // the click event for "close"
        // declare some ID values for our menu items
        // these can be anything, but I personally tend to start from 1,000
        enum MenuControls {
            idSave = 1000,
            idOpen, idExit
        };
        // this bit's important~
        // it's a macro, which is basically saying we want to define some events
        // (events such as clicking menu items in the menu)
        DECLARE_EVENT_TABLE()
};

// this is our event table, where we assign functions to specific events
// using those IDs we created earlier
// basically, by passing a number and a method name, we assign that method name a value, or a key
// this key is then assigned to items later (in this case, menu items) as the event handler
// don't worry if this doesn't make sense right now, it will become clear later on
BEGIN_EVENT_TABLE(Notepad, wxFrame) // begin the event table for our Notepad class, which inherits wxFrame
    EVT_MENU(idSave, Notepad::OnSave) // set an event for our idSave, and the function OnSave
    EVT_MENU(idOpen, Notepad::OnOpen) // set an event for open
    EVT_MENU(idExit, Notepad::OnExit) // set an event for exit
END_EVENT_TABLE() // end the event table

// our constructor, which does all this stuff for the wxFrame constructor
// this makes it easier to simply create our notepad object later~
Notepad::Notepad() : wxFrame(NULL, wxID_ANY, wxT("wxNotepad"), wxDefaultPosition, wxSize(650,500)) {
    this->menu = new wxMenuBar(); // instantiate our menu bar
    this->file = new wxMenu(); // instantiate our file menu for our menu bar
    this->file->Append(idSave, wxT("&Save File\tCtrl-S")); // add a save option to the menu bar
    // note how we passed "idSave" as the first argument? This means that we're assigning OnSave
    // as an event handler when the user clicks the save menu item
    // now we do the same for our "open" option, assigning the OnOpen event to it
    this->file->Append(idOpen, wxT("&Open File\tCtrl-O"));
    this->file->AppendSeparator(); // add a separator (between our file I/O options and our exit option
    this->file->Append(idExit, wxT("E&xit\tCtrl-F4")); // add an exit option to the file menu
    this->menu->Append(file, wxT("&File")); // add the file menu to the menubar, and give it the title "File"
    this->SetMenuBar(menu); // set our menu bar to be visible on the application

    // lastly in our constructor, we're going to add the text area~ we need to pass quite a few parameters here
    // the first parameter is the parent, so we pass this (this is the owner)
    // wxID_ANY ~ the ID of the control. Since it doesn't matter, we can just pass wxID_ANY
    // the third, wxt("") is the text to put in the text area straight away. We pass an empty string here
    // wxDefaultPosition: the position of the control
    // wxDefaultSize: the size of the control
    // and lastly, we have the style~ we want two styles here, wxTE_MULTILINE and wxTE_PROCESS_ENTER
    // this way, we enable multi-line editing, and allow the user to press enter to move on to a new line
    this->text = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER | wxTE_MULTILINE);
}

// now it's time to define our save event (for when the user clicks "Save"
void Notepad::OnSave(wxCommandEvent &event) {
    // first, we create a wxFileDialog, which takes a number of parameters
    // this ~ the parent of the object
    // wxt("Save File~") ~ the title of the dialog
    // the next two, I've passed empty strings. These are the default directory, and the default file
    // (you can define them if you wish, but you don't have to)
    // next, we have the filter. The filter accepts a specific format:
    // "the text to display|*.filetype|another type|*.otherfiletype
    // and lastly, the style of the dialog: wxSAVE, since we want a save dialog
    wxFileDialog *saveDialog = new wxFileDialog(this, wxT("Save File~"), wxT(""), wxT(""),
                                                wxT("Text Files (*.txt)|*.txt|C++ Files (*.cpp)|*.cpp"), wxSAVE);
    // next, we display the dialog box
    // it will return one of 2 values: wxID_OK, or wxID_CANCEL (whichever button the user clicked)
    int response = saveDialog->ShowModal();
    if (response == wxID_OK) { // if the user clicked OK, we should save the text
        this->text->SaveFile(saveDialog->GetPath()); // this is pretty cool. we can save it with just one line!
        // wxTextCtrl has a member function called SaveFile, which you simple pass the path to and it will save
        // our dialog has a member function called GetPath, which will return the entire path and file name
    }
} // end of the event handler

// next, we have our open dialog, which is practically the same as our save dialog, so I won't go into detail
// note how we pass wxOPEN instead of wxSAVE as the style though~
void Notepad::OnOpen(wxCommandEvent &event) {
    wxFileDialog *openDialog = new wxFileDialog(this, wxT("Open File~"), wxT(""), wxT(""),
                                                wxT("Text Files (*.txt)|*.txt|C++ Files (*.cpp)|*.cpp"), wxOPEN);
    int response = openDialog->ShowModal();
    if (response == wxID_OK) {
        this->text->LoadFile(openDialog->GetPath());
    }
}

// if the user clicks exit (from the menu) then we should close the window
void Notepad::OnExit(wxCommandEvent &event) {
    this->Destroy(); // close the window, and get clear any resources used (eg, memory)
}

// now all that's left is the implementation! we need to create our MainApp class
class MainApp : public wxApp {
    public: // remember this from part 2? very simple from here on in, we're almost done
        virtual bool OnInit();
};

bool MainApp::OnInit() {
    // create a new Notepad (we used a wxFrame in part 2)
    Notepad *main = new Notepad();
    main->Show(true); // show it

    return true;
}

// and lastly, we just have to implement our application!
IMPLEMENT_APP(MainApp)
