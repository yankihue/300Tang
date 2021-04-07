#include <gtk/gtk.h>
#include <glib.h>
#include <ctype.h>

gchar* content();
static void
toggled_cb (GtkToggleButton    *,
             gpointer );
//TODO: GNU style indentation
static void
activate (GtkApplication *app,
          gpointer        user_data)
{
  GtkWidget *window;
  GtkWidget *label;
  GtkWidget *checkbutton;
  GtkWidget *grid;
  /*Create a window with a title and a default size*/
  window = gtk_application_window_new (app);
  gtk_window_set_application (GTK_WINDOW (window), GTK_APPLICATION (app));
  gtk_window_set_title (GTK_WINDOW (window),"300Tang");
  gtk_window_set_default_size (GTK_WINDOW (window), 200,100);
  //gtk_window_set_decorated(GTK_WINDOW(window),TRUE); //set window decoration
  gtk_window_set_keep_below(GTK_WINDOW(window),TRUE); //keep window below
  gtk_window_stick(GTK_WINDOW(window)); //stick window, make it appear on all user desktops
  /* Setting the line wrap to TRUE makes 
  the label break lines if the text exceeds the widget's size. When set to 
  FALSE the text gets cut off by the edge of the widget*/
  label = gtk_label_new (content());
  gtk_label_set_justify (GTK_LABEL (label), GTK_JUSTIFY_CENTER);
  gtk_label_set_line_wrap (GTK_LABEL (label), FALSE);
  checkbutton = gtk_check_button_new_with_label ("I've decided on the location of the box.");
  gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (checkbutton), FALSE);
  g_signal_connect (GTK_TOGGLE_BUTTON (checkbutton), "toggled", G_CALLBACK (toggled_cb), window);

  grid = gtk_grid_new();
  gtk_grid_attach (GTK_GRID (grid), label, 0, 0, 15, 15);
  gtk_grid_attach (GTK_GRID (grid), checkbutton, 7, 15, 1, 1);

  gtk_container_add (GTK_CONTAINER (window), GTK_WIDGET (grid));
  gtk_widget_show_all (GTK_WIDGET (window));
}


int
main (int argc, char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example",G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);
  return status;
}


//trim whitespace
char *trim(char *str)
{
    size_t len = 0;
    char *frontp = str;
    char *endp = NULL;

    if( str == NULL ) { return NULL; }
    if( str[0] == '\0' ) { return str; }

    len = strlen(str);
    endp = str + len;
    while( isspace((unsigned char) *frontp) ) { ++frontp; }
    if( endp != frontp )
    {
        while( isspace((unsigned char) *(--endp)) && endp != frontp ) {}
    }

    if( frontp != str && endp == frontp )
            *str = '\0';
    else if( str + len - 1 != endp )
            *(endp + 1) = '\0';
    endp = str;
    if( frontp != str )
    {
            while( *frontp ) { *endp++ = *frontp++; }
            *endp = '\0';
    }

    return str;
}

//function to read poems.txt and return contents
gchar* content(){
gchar *contents;
GError *err = NULL;

g_file_get_contents ("poems.txt", &contents, NULL, &err);
g_assert ((contents == NULL && err != NULL) || (contents != NULL && err == NULL));
if (err != NULL)
  {
    // Report error to user, and free error
    g_assert (contents == NULL);
    fprintf (stderr, "Unable to read file: %s\n", err->message);
    g_error_free (err);
  }
else
  {
    // Use file contents
    g_assert (contents != NULL);
    contents=trim(contents);  
    return contents; 
  }
 
}

/*signal handler for toggle button */

static void
toggled_cb (GtkToggleButton *toggle_button,
            gpointer         user_data)
{
  GtkWindow *window = user_data;

  if (gtk_toggle_button_get_active (toggle_button)){
    gtk_window_set_decorated(GTK_WINDOW(window),FALSE);
    /*only removing or hiding widget resets the alignment of other widgets
    so setting opacity to 0 is better to keep center justify*/
    gtk_widget_set_opacity (GTK_WIDGET(toggle_button),0); 

    }
  else{

    gtk_window_set_decorated(GTK_WINDOW(window),TRUE);
   // gtk_widget_hide(GTK_WIDGET(toggle_button));
    //gtk_widget_destroy(GTK_WIDGET(toggle_button));
    //couldnt find another workaround
  }

}