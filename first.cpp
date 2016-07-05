#include <gtk/gtk.h>

static void button_clicked(GtkWidget* widget, gpointer data)
{
        gtk_label_set_text(GTK_LABEL(data),"you clicked the button");
}

int main(int argc,char* argv[])
{
        gtk_init(&argc,&argv); //initialize the gtk
        GtkWidget *window,*label,*button,*hbox; //declare the needed variables
        window=gtk_window_new(GTK_WINDOW_TOPLEVEL); //create the window
        //if the 'X' was clicked, then exit from the program
        g_signal_connect(window,"delete_event",G_CALLBACK(gtk_main_quit),NULL);
        //our program starts from here

        label=gtk_label_new("Hello world");
        button=gtk_button_new_with_label("Click me!");
        g_signal_connect(button,"clicked",G_CALLBACK(button_clicked),(gpointer)label);
        hbox=gtk_vbox_new(0,0);
        gtk_box_pack_start(GTK_BOX(hbox),label,1,1,0);
        gtk_box_pack_start(GTK_BOX(hbox),button,1,1,0);
        gtk_container_add(GTK_CONTAINER(window),hbox);

        gtk_widget_show_all(window); //we show all widgets
        gtk_main(); //start the main loop
        return 0;
}
