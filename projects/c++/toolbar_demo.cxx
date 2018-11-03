#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Pack.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Pixmap.H>
//
// Example of how to make a toolbar widget with icons
// erco 1.0 05/24/10
//
static const char *open_xpm[] = {                       // XPM
    "25 25 16 1",
    "     c #766E67", ".    c #817C78", "+    c #B18563", "@    c #E97E25",
    "#    c #D28445", "$    c #9D9791", "%    c #F4882A", "a    c #F1963B",
    "*    c #AFAAA3", "=    c #F4AB6E", "-    c #C8C5C1", ";    c #F2C092",
    "x    c #F7CCA4", ",    c #DEDDDA", "'    c #F3DECD", ")    c None",
    ")))))))))))))))))))))))))",                        // open icon (nabbed from linux staroffice -- use your own!)
    ")))))))-..........)))))))",
    "))))))).)))))))),,*))))))",
    "))))))).)))))))),,)*)))))",
    "))))))).)))))))),-))*))))",
    "))))))).)),-,))),*--,*)))",
    "),$$$$$ ))))))))-*  $$*))",
    ")*))))).)),,,,,,--$$*-.))",
    ")*)x===+)),,,,,,,--*-,.))",
    ")*))))).),,,-,,,,,--,,.))",
    ")*))))).),,,,-*$$$$$** -)",
    ")*)),.. $$$$$*x'''''''=*)",
    ")*),+''''''''';;;;====#-)",
    ")$)-====xxxxxxx;;;;;;;+,)",
    ")$)*====;;;;;;;;;;;;;=+))",
    ")$)+====;=======aaaaaa.))",
    ")$,#===#=aaaaaaaaaaaa#.))",
    ")$-#a%%@aaaaaaaaaaaaa+.))",
    ")$+@%@%@aaaaaaaaaaaaa*.))",
    ")$#%%%%%%%%%%%%%%%%%a.*))",
    ").#@@@@@@aaaaaaaaaaa#-)))",
    ")-.                 $-,))",
    ")),,,,,,,,,,,,,,,,,,,,)))",
    ")))))))))))))))))))))))))",
    ")))))))))))))))))))))))))"
};

static const char *save_xpm[] = {                       // XPM
    "25 25 16 1",
    "     c #684467", ".    c #7A5279", "+    c #626461", "@    c #757172",
    "#    c #9D6D9C", "$    c #888382", "%    c #969499", "a    c #ACA7AC",
    "*    c #BABAC4", "=    c #CACBD4", "-    c #D2D3DD", ";    c #E5E3E8",
    "x    c #E9E9F3", ",    c None",    "'    c #F7F6FA", ")    c #FEFFFC",
    ",,,,,,,,,,,,,,,,,,,,,,,,,",
    ",,,,,,,,,,,,,,,,,,,,,,,,,",                        // save icon (nabbed from linux staroffice -- use your own!)
    ",a$$$$$$$@$$$$$$$$@$$$=,,",
    ",$';xxxxx%))))))))%--;$,,",
    ",$x=-****%xxxx%%%'%**x$,,",
    ",$x=-****%xxxx%*%'a**x$,,",
    ",$x=-****%xxxx%*%'a**x$,,",
    ",$x=-****%xxxx%*%;%**x$,,",
    ",$x=-****%xx;;%%%;%**x$,,",
    ",$x--****%x;;;)));%==x$,,",
    ",$x--****%%%%%%%%%%==x$,,",
    ",$x----------------==x$,,",
    ",$x--**************==x$,,",
    ",$x--''''''''''''''==x$,,",
    ",$x--''''''''''''''==x$,,",
    ",$x--';;;;;;;;;;;;'==x$,,",
    ",$x--''''''''''''''==x$,,",
    ",$x--';;;;;;;;;;;;'==x$,,",
    ",$x==''''''''''''''==x$,,",
    ",$x==';;;;;;;;;;;;'==x$,,",
    ",$x==''''''''''''''==x$,,",
    ",$aaa###########...**x$,,",
    ",$xxx.........     xxx$,,",
    ",a@++++++++++++++++++@a,,",
    ",,,,,,,,,,,,,,,,,,,,,,,,,"
}; 
class MyToolbar : public Fl_Pack {
public:
    // CTOR
    MyToolbar(int X,int Y,int W,int H):Fl_Pack(X,Y,W,H) {
        type(Fl_Pack::HORIZONTAL);    // horizontal packing of buttons
    box(FL_UP_FRAME);
    spacing(4);            // spacing between buttons
        end();
    }
    // ADD A TOOLBAR BUTTON TO THE PACK
    void AddButton(const char *name, Fl_Pixmap *img=0, Fl_Callback *cb=0, void *data=0) {
    begin();
            Fl_Button *b = new Fl_Button(0,0,30,30);
        b->box(FL_FLAT_BOX);    // buttons won't have 'edges'
        b->clear_visible_focus();
            if ( name ) b->tooltip(name);
            if ( img  ) b->image(img);
            if ( cb   ) b->callback(cb,data);
        end();
    }
}; 
void Open_CB(Fl_Widget*,void*) {
    printf("Open..\n");
} 
void Save_CB(Fl_Widget*,void*) {
    printf("Save..\n");
} 
int main() {
    // CREATE MAIN WINDOW
    Fl_Window win(720,486,"toolbar demo");
    win.begin();
      // CREATE TOOLBAR
      Fl_Pixmap *open_pixmap = new Fl_Pixmap(open_xpm);
      Fl_Pixmap *save_pixmap = new Fl_Pixmap(save_xpm);
      MyToolbar toolbar(0,0,win.w(),30);
      toolbar.AddButton(0, open_pixmap, Open_CB);
      toolbar.AddButton(0, save_pixmap, Save_CB);
      toolbar.AddButton(0, open_pixmap, Open_CB);           // (repeated to simulate several icons)
      toolbar.AddButton(0, save_pixmap, Save_CB);
      toolbar.AddButton(0, open_pixmap, Open_CB);
      toolbar.AddButton(0, save_pixmap, Save_CB);
    win.end();
    win.show();
    return(Fl::run());
}
