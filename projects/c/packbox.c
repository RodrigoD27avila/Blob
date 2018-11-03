#include <stdio.h>
#include <stdlib.h>

#include <gtk/gtk.h>

static gboolean
delete_event(GtkWidget *widget,
             GdkEvent  *event,
             gpointer   data)
{
    gtk_main_quit();
    return FALSE;
}

static GtkWidge
*make_box(gboolean homogeneos,
          gint     spacing,
          gboolean expand,
          gboolean fill,
          guint    padding)
{
    GtkWidget *box;
    GtkWidget *button;
    char       padstr[80];

    box = gtk_hbox_new(homogeneos, spacing);

    button = gtk_button_new_with_label("gtk_box_pack");
    gtk_box_pack_start(GTK_BOX(box), button, expand, fill, padding);
    gtk_widget_show(button);

    button = gtk_button_new_with_label("(box, ");
    gtk_box_pack_start(GTK_BOX(box), button, expand, fill, padding);
    gtk_widget_show(button);

    button = gtk_button_new_with_label("button, ");
    gtk_box_pack_start(GTK_BOX(box), button, expand, fill, padding);
    gtk_widget_show(button);

    button = gtk_button_new_with_label(expand ? "TRUE, " : "FALSE, ");
    gtk_box_pack_start(GTK_BOX(box), button, expand, fill, padding);
    gtk_widget_show(button);
    
    button = gtk_button_new_with_label(fill ? "TRUE, " : "FALSE, ");
    gtk_box_pack_start(GTK_BOX(box), button, expand, fill, padding);
    gtk_widget_show(button);

    sprintf(padstr, "%d);", padding);
    
    button = gtk_button_new_with_label(padstr);
    gtk_box_pack_start(GTK_BOX(box), button, expand, fill, padding);
    gtk_widget_show(button);
}

int main (int argc, char **argv)
{
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *box1;
    GtkWidget *box2;
    GtkWidget *separator;
    GtkWidget *label;
    GtkWidget *quitbox;

    int which;
}
