#include <gtk/gtk.h>

enum
{
   SPLINE_NONE = 0,
   SPLINE_LINE,
   SPLINE_CATMULL_ROM,
   NO_TYPES
};

typedef struct _Data Data;
struct _Data
{
   GArray    *points;
   gboolean   visible[NO_TYPES];
   gdouble    spline_factor;
   GtkWidget *draw;
};

static void
cb_value( GtkSpinButton *button,
        Data          *data )
{
   data->spline_factor = gtk_spin_button_get_value( button );
   gtk_widget_queue_draw( data->draw );
}

static void
cb_toggled( GtkToggleButton *button,
         Data            *data )
{
   gint index =
      GPOINTER_TO_INT( g_object_get_data( G_OBJECT( button ), "type" ) );

   data->visible[index] = gtk_toggle_button_get_active( button );

   gtk_widget_queue_draw( data->draw );
}

static void
draw_points( cairo_t *cr,
          gdouble *coords,
          gint     size )
{
   gint i;

   cairo_set_source_rgb( cr, 1, 0, 0 );
   for( i = 0; i < size; i += 2 )
   {
      cairo_move_to( cr, coords[i], coords[i + 1] );
      cairo_arc( cr, coords[i], coords[i + 1], 2, 0, 2 * G_PI );
   }
   cairo_stroke( cr );
}

static void
draw_line( cairo_t *cr,
         gdouble *coords,
         gint     size )
{
   gint i;

   cairo_set_source_rgb( cr, 0, 0, 1 );
   cairo_move_to( cr, coords[0], coords[1] );
   for( i = 2; i < size; i += 2 )
   {
      cairo_line_to( cr, coords[i], coords[i + 1] );
   }
   cairo_stroke( cr );
}

static void
draw_catmull_rom( cairo_t *cr,
              gdouble *coords,
              gint     size,
              double   spline_factor )
{
   gint i;
   gdouble ctrl_points[4];

   /* Initial calculations */
   ctrl_points[2] = ( coords[2] - coords[0] ) / spline_factor;
   ctrl_points[3] = ( coords[3] - coords[1] ) / spline_factor;

   cairo_set_source_rgb( cr, 0, 1, 0 );
   cairo_move_to( cr, coords[0], coords[1] );
   for( i = 2; i < size - 2; i += 2 )
   {
      ctrl_points[0] = ctrl_points[2];
      ctrl_points[1] = ctrl_points[3];
      ctrl_points[2] = ( coords[i + 2] - coords[i - 2] ) / spline_factor;
      ctrl_points[3] = ( coords[i + 3] - coords[i - 1] ) / spline_factor;

      cairo_curve_to( cr, coords[i - 2] + ctrl_points[0],
                     coords[i - 1] + ctrl_points[1],
                     coords[i]     - ctrl_points[2],
                     coords[i + 1] - ctrl_points[3],
                     coords[i],
                     coords[i + 1] );
   }

   /* Draw the last segment */
   ctrl_points[0] = ctrl_points[2];
   ctrl_points[1] = ctrl_points[3];
   ctrl_points[2] = ( coords[i] - coords[i - 2] ) / spline_factor;
   ctrl_points[3] = ( coords[i + 1] - coords[i - 1] ) / spline_factor;

   cairo_curve_to( cr, coords[i - 2] + ctrl_points[0],
                  coords[i - 1] + ctrl_points[1],
                  coords[i]     - ctrl_points[2],
                  coords[i + 1] - ctrl_points[3],
                  coords[i],
                  coords[i + 1] );

   cairo_stroke( cr );
}

static gboolean
cb_expose( GtkWidget      *draw,
         GdkEventExpose *expose,
         Data           *data )
{
   cairo_t  *cr;
   gdouble  *coords;
   gint      i;

   if( data->points->len == 0 )
      return( FALSE );

   /* Draw spline */
   cr = gdk_cairo_create( draw->window );
   cairo_set_line_width( cr, 5 );

   coords = (gdouble *)data->points->data;

   /* Special case - if only one point is present, draw it no matter what
    * spline type is set. */
   if( data->points->len == 2 && data->visible[SPLINE_NONE] )
   {
      draw_points( cr, coords, data->points->len );
      cairo_destroy( cr );
      return( FALSE );
   }

   if( data->visible[SPLINE_LINE] )
      draw_line( cr, coords, data->points->len );

   if( data->visible[SPLINE_CATMULL_ROM] )
      draw_catmull_rom( cr, coords, data->points->len, data->spline_factor );

   if( data->visible[SPLINE_NONE] )
      draw_points( cr, coords, data->points->len );
   
   cairo_destroy( cr );

   return( FALSE );
}

static gboolean
cb_press( GtkWidget      *draw,
        GdkEventButton *event,
        Data           *data )
{
   if( event->state & GDK_SHIFT_MASK )
   {
      gint     i;
      gdouble *coords = (gdouble *)data->points->data;

      for( i = 0; i < data->points->len - 1; i += 2 )
      {
         if( event->x > ( coords[i] - 5 ) &&
            event->x < ( coords[i] + 5 ) )
         {
            if( event->y > ( coords[i + 1] - 5 ) &&
               event->y < ( coords[i + 1] + 5 ) )
            {
               g_print( "Delete point at (%f, %f)\n", event->x, event->y );
               g_array_remove_range( data->points, i, 2 );
               break;
            }
         }
      }
   }
   else
   {
      gdouble point[] = { event->x, event->y };

      g_print( "Create point at (%f, %f)\n", event->x, event->y );
      g_array_append_vals( data->points, (gconstpointer)point, 2 );
   }

   gtk_widget_queue_draw( draw );

   return( TRUE );
}

int
main( int    argc,
     char **argv )
{
   GtkWidget *window;
   GtkWidget *hbox;
   GtkWidget *vbox, *vbox_main;
   GtkWidget *frame;
   GtkWidget *button;
   GtkWidget *draw;
   Data       data;


   data.points = g_array_sized_new( FALSE, FALSE, sizeof( gdouble ), 10 );
   data.spline_factor = 5;
   data.visible[0] = TRUE;
   data.visible[1] = TRUE;
   data.visible[2] = FALSE;

   gtk_init( &argc, &argv );

   window = gtk_window_new( GTK_WINDOW_TOPLEVEL );
   gtk_window_set_default_size( GTK_WINDOW( window ), 400, 300 );
   g_signal_connect( G_OBJECT( window ), "destroy",
                 G_CALLBACK( gtk_main_quit ), NULL );

   hbox = gtk_hbox_new( FALSE, 6 );
   gtk_container_add( GTK_CONTAINER( window ), hbox );

   frame = gtk_frame_new( "Drawing area" );
   gtk_box_pack_start( GTK_BOX( hbox ), frame, TRUE, TRUE, 0 );

   draw = gtk_drawing_area_new();
   data.draw = draw;
   gtk_widget_add_events( draw, GDK_BUTTON_PRESS_MASK );
   g_signal_connect( G_OBJECT( draw ), "expose-event",
                 G_CALLBACK( cb_expose ), &data );
   g_signal_connect( G_OBJECT( draw ), "button-press-event",
                 G_CALLBACK( cb_press ), &data );
   gtk_container_add( GTK_CONTAINER( frame ), draw );

   vbox_main = gtk_vbox_new( FALSE, 6 );
   gtk_box_pack_start( GTK_BOX( hbox ), vbox_main, FALSE, FALSE, 0 );

   /* Interpolation type */
   frame = gtk_frame_new( "Interpolation" );
   gtk_box_pack_start( GTK_BOX( vbox_main ), frame, FALSE, FALSE, 0 );

   vbox = gtk_vbox_new( TRUE, 6 );
   gtk_container_add( GTK_CONTAINER( frame ), vbox );

   button = gtk_check_button_new_with_label( "Points" );
   gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON( button ), TRUE );
   g_object_set_data( G_OBJECT( button ), "type",
                  GINT_TO_POINTER( SPLINE_NONE ) );
   g_signal_connect( G_OBJECT( button ), "toggled",
                 G_CALLBACK( cb_toggled ), &data );
   gtk_box_pack_start( GTK_BOX( vbox ), button, FALSE, FALSE, 0 );

   button = gtk_check_button_new_with_label( "Lines" );
   gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON( button ), TRUE );
   g_object_set_data( G_OBJECT( button ), "type",
                  GINT_TO_POINTER( SPLINE_LINE ) );
   g_signal_connect( G_OBJECT( button ), "toggled",
                 G_CALLBACK( cb_toggled ), &data );
   gtk_box_pack_start( GTK_BOX( vbox ), button, FALSE, FALSE, 0 );

   button = gtk_check_button_new_with_label( "Cardinal spline" );
   g_object_set_data( G_OBJECT( button ), "type",
                  GINT_TO_POINTER( SPLINE_CATMULL_ROM ) );
   g_signal_connect( G_OBJECT( button ), "toggled",
                 G_CALLBACK( cb_toggled ), &data );
   gtk_box_pack_start( GTK_BOX( vbox ), button, FALSE, FALSE, 0 );

   /* Spline factor */
   frame = gtk_frame_new( "Cardinal spline factor" );
   gtk_box_pack_start( GTK_BOX( vbox_main ), frame, FALSE, FALSE, 0 );

   button = gtk_spin_button_new_with_range( 0.1, 100, 0.1 );
   gtk_spin_button_set_numeric( GTK_SPIN_BUTTON( button ), TRUE );
   gtk_spin_button_set_value( GTK_SPIN_BUTTON( button ), 5. );
   g_signal_connect( G_OBJECT( button ), "value-changed",
                 G_CALLBACK( cb_value ), &data );
   gtk_container_add( GTK_CONTAINER( frame ), button );


   gtk_widget_show_all( window );

   gtk_main();

   g_array_free( data.points, TRUE );

   return( 0 );
}
