#include <gtk/gtk.h>
#include <glib.h>
#include <ctype.h>

gchar* content();

//TODO: GNU style indentation
static void
activate (GtkApplication *app,
          gpointer        user_data)
{
  GtkWidget *window;
  GtkWidget *label;
  char display[]="Welcome to GNOME";
  /*Create a window with a title and a default size*/
  window = gtk_application_window_new (app);
  gtk_window_set_application (GTK_WINDOW (window), GTK_APPLICATION (app));
  gtk_window_set_title (GTK_WINDOW (window),"300Tang");
  gtk_window_set_default_size (GTK_WINDOW (window), 200,100);
   
  /*Create a label and set its alignment. Setting the line wrap to TRUE makes 
  the label break lines if the text exceeds the widget's size. When set to 
  FALSE the text gets cut off by the edge of the widget*/
  label = gtk_label_new (content());
  gtk_label_set_justify (GTK_LABEL (label), GTK_JUSTIFY_CENTER);
  gtk_label_set_line_wrap (GTK_LABEL (label), FALSE);

  gtk_container_add (GTK_CONTAINER (window), GTK_WIDGET (label));

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
  }
contents=trim(contents);  
return contents;  
}