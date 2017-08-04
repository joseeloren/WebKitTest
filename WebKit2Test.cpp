#include <webkit2/webkit2.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include <glib.h>
#include <glib/gstdio.h>


static void
webview_webkit_load_changed(GtkWidget *webview,
                            WebKitLoadEvent load_event,
                            GObject *)
{
    if (load_event == WEBKIT_LOAD_FINISHED)
    {
        printf("WEBKIT_LOAD_FINISHED triggered!\n");
    }
}

static void
activate (GtkApplication* app,
          gpointer        user_data)
{
    GtkWidget *window;

    window = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (window), "Window");
    gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);
    GMainLoop* loop;

     GtkWidget* webview;
    
     webview = webkit_web_view_new();
    
    gtk_container_add(GTK_CONTAINER(window), webview);
    
    g_signal_connect_after(webview, "load-changed",
                           G_CALLBACK(webview_webkit_load_changed),
                           NULL);

    webkit_web_view_load_uri((WebKitWebView*)webview, "about:blank");

    gtk_widget_show_all (window);

}

int main(int    argc, char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}

