// Compilar com gcc janela_mtk.c -o janela_mtk `pkg-config --cflags --libs gtk+-3.0` *

#include <gtk/gtk.h>

int main(int argc, char **argv){
	
    GtkWidget *window;
    
    gtk_init(&argc, &argv);
    
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_widget_show(window);
    
    gtk_main();
    
    return 0;
}

