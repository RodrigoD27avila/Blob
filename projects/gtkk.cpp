#include <gtk/gtk.h>

class Widget : GtkWidget
{
public:
    GtkWidget *obj;

    Widget() 
    {
        obj = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    }

    ~Widget()
    {
    }

    void show()
    {
        gtk_widget_show(obj);
    }

    void onDestroy(void (*callback)(), void *data)
    {
        g_signal_connect_swapped(G_OBJECT(obj), "destroy",
            G_CALLBACK(callback), data);
    }
};

int main(int argc, char **argv)
{
    gtk_init(&argc, &argv);
    Widget w;
    w.show();
    w.onDestroy(gtk_main_quit, NULL);
    gtk_main();
    return 0;
}
