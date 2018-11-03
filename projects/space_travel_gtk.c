/*
gcc -Wall space_travel_gtk.c -o space_travel_gtk `pkg-config --cflags --libs gtk+-3.0`
*/

#include <gtk/gtk.h>
#include <glib/gprintf.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

const float minute = 60.0;
const float hour = 60.0;
const float day = 24.0;
const float week = 7.0;
const float month = 30.0;
const float year = 365.25;

long double distance = 9.4607305e12;
long double speed = 299792.458;

typedef struct
{
   GtkWidget *window;
   GtkWidget *instruct;
   GtkWidget *instruct2;
   GtkWidget *label;
   GtkWidget *entry;
   GtkWidget *entry2;
   GtkWidget *table;
   GtkWidget *radio_button_1;
   GtkWidget *radio_button_2;
   GtkWidget *radio_button_3;
   GtkWidget *radio_button_4;
} GtkObj;

gboolean delete (GtkWidget *widget, GdkEvent *event, gpointer data)
{
   return FALSE;
}

static void distance_travel_time(GtkObj *obj)
{
   long double x_distance;
   long double x_speed;
   long double check;
   gchar *label_str = NULL;

   const gchar *str = gtk_entry_get_text(GTK_ENTRY(obj->entry));
   x_distance = strtod(str, NULL);

   str = gtk_entry_get_text(GTK_ENTRY(obj->entry2));
   x_speed = strtod(str, NULL);

   check = (x_distance * distance)/speed/x_speed/minute/hour/day/year;
   if(check >= 1)
      label_str = g_strdup_printf("Travel time: %0.8Lf years", (x_distance * distance)/speed/x_speed/minute/hour/day/year);
   else if(check < 1 && check >= 1/year)
      label_str = g_strdup_printf("Travel time: %0.8Lf days", (x_distance * distance)/speed/x_speed/minute/hour/day);
   else if(check < 1/year && check >= 1/year/day)
      label_str = g_strdup_printf("Travel time: %0.8Lf hours", (x_distance * distance)/speed/x_speed/minute/hour);
   else if(check < 1/year/day && check >= 1/year/day/hour)
      label_str = g_strdup_printf("Travel time: %0.8Lf minutes", (x_distance * distance)/speed/x_speed/minute);
   else
      label_str = g_strdup_printf("Travel time: %0.8Lf seconds", (x_distance * distance)/speed/x_speed);

   gtk_label_set_text(GTK_LABEL(obj->label), label_str);
   g_free(label_str);
}

static void clicked_callback_radio_button(GdkEventKey *event, GtkObj *object)
{
   long double x_distance;
   const gchar *str = gtk_entry_get_text(GTK_ENTRY(object->entry2));
   x_distance = strtod(str, NULL);

   if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(object->radio_button_1)))
      distance = 9.4607305e12;
   else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(object->radio_button_2)))
      distance = 1.0;

   if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(object->radio_button_3)))
   {
      speed = 299792.458;
      if(x_distance>1.0)
         gtk_entry_set_text(GTK_ENTRY(object->entry2), "1.0");
   }
   else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(object->radio_button_4)))
      speed = 1.0 / minute / hour;

   distance_travel_time(object);
}

static gboolean clicked_callback_entry(GtkWidget *entry, GdkEventKey *event, GtkObj *object)
{
   long double x_distance;
   const gchar *str = gtk_entry_get_text(GTK_ENTRY(object->entry2));
   x_distance = strtod(str, NULL);
   if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(object->radio_button_3)) && x_distance>1.0)
      gtk_entry_set_text(GTK_ENTRY(object->entry2), "1.0");

   distance_travel_time(object);

   return FALSE;
}

int main(int argc, char *argv[])
{
   GtkObj *obj;

   gtk_init (&argc, &argv);

   obj = g_new(GtkObj, 1);   
   obj->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
   gtk_window_set_default_size(GTK_WINDOW(obj->window), 350, 100);
   gtk_container_set_border_width(GTK_CONTAINER(obj->window),10);
   gtk_window_set_urgency_hint(GTK_WINDOW(obj->window), TRUE);
   gtk_window_set_title(GTK_WINDOW(obj->window),"Space Travel");
   
   g_signal_connect(G_OBJECT(obj->window), "delete_event", G_CALLBACK(delete), NULL);
   //g_signal_connect(G_OBJECT(obj->window), "destroy", G_CALLBACK(destroy), NULL);
   
   obj->table = gtk_table_new (7, 2, TRUE);
   gtk_container_add(GTK_CONTAINER(obj->window), obj->table);

   obj->instruct = gtk_label_new ("Enter your distance:");               
   gtk_table_attach_defaults (GTK_TABLE (obj->table), obj->instruct, 0, 2, 0, 1);

   obj->radio_button_1 = gtk_radio_button_new_with_label(NULL, "in light-years");
   gtk_table_attach_defaults (GTK_TABLE (obj->table), obj->radio_button_1, 0, 1, 1, 2);

   obj->radio_button_2 = gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON(obj->radio_button_1), "in km");
   gtk_table_attach_defaults (GTK_TABLE (obj->table), obj->radio_button_2, 1, 2, 1, 2);

   obj->entry = gtk_entry_new();
   gtk_table_attach_defaults (GTK_TABLE (obj->table), obj->entry, 0, 2, 2, 3);
   gtk_widget_grab_focus(obj->entry);

   obj->instruct2 = gtk_label_new ("Enter your speed:");
   gtk_table_attach_defaults (GTK_TABLE (obj->table), obj->instruct2, 0, 2, 3, 4);

   obj->radio_button_3 = gtk_radio_button_new_with_label(NULL, "in speed-of-light");
   gtk_table_attach_defaults (GTK_TABLE (obj->table), obj->radio_button_3, 0, 1, 4, 5);

   obj->radio_button_4 = gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON(obj->radio_button_3), "in km/h");
   gtk_table_attach_defaults (GTK_TABLE (obj->table), obj->radio_button_4, 1, 2, 4, 5);

   obj->entry2 = gtk_entry_new();
   gtk_entry_set_text(GTK_ENTRY(obj->entry2), "1.0");
   gtk_table_attach_defaults (GTK_TABLE (obj->table), obj->entry2, 0, 2, 5, 6);

   obj->label = gtk_label_new (NULL);
   gtk_table_attach_defaults (GTK_TABLE (obj->table), obj->label, 0, 2, 6, 7);

   g_signal_connect(G_OBJECT(obj->entry), "key-release-event", G_CALLBACK(clicked_callback_entry), (gpointer) obj);
   g_signal_connect(G_OBJECT(obj->entry2), "key-release-event", G_CALLBACK(clicked_callback_entry), (gpointer) obj);

   g_signal_connect(G_OBJECT(obj->radio_button_1), "clicked", G_CALLBACK(clicked_callback_radio_button), (gpointer) obj);
   g_signal_connect(G_OBJECT(obj->radio_button_2), "clicked", G_CALLBACK(clicked_callback_radio_button), (gpointer) obj);
   g_signal_connect(G_OBJECT(obj->radio_button_3), "clicked", G_CALLBACK(clicked_callback_radio_button), (gpointer) obj);
   g_signal_connect(G_OBJECT(obj->radio_button_4), "clicked", G_CALLBACK(clicked_callback_radio_button), (gpointer) obj);

   gtk_widget_show_all(GTK_WIDGET(obj->window));

   gtk_main ();

   g_free(obj);

   return 0;
} 
