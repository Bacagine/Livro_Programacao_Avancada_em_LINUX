/*
 * Minimal XWindow Toolkit (mtk)
 *
 * Gleicon S. Moraes - Gleicon@terra.com.br
 *
 * gcc mtk.c -o mtk_demo -02 -L/usr/X11R6/lib -lX11 ; ./mtk_demo
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <X11/Xlib.h>

#define DOT frpintf(stderr,".");

#define FALSE 0
#define TRUE 1

struct _mtk_x{
    int x,y,w,h,d;              // Posição: x, y - Tamanho: w, h - Resolução d
    Display *display;           // display
    Window win, rootwindow;     // Primeira janela, janela root
    GC gc;                      // Contexto gráfico (GC)
    int screen;                 // Número da tela (screen number)
    char *display_name;         // getenv (DISPLAY)
};

typedef struct _mtk_x MTK_RESOURCES;
// Abre display, inicializa a estrutura principal
int T_init (MTK_RESOURCES *tips_x);

// Recebe tips_x ja com x,y,h,w, inicializa, e cria janela
int T_init(MTK_RESOURCES *tips_x);

// Destrói janela e estrutura
int T_init(MTK_RESOURCES *tips_x);

int getnamedcolor(char *name, MTK_RESOURCES *tips_x){
    XColor color;
    XAllocNamedColor(tips_x->display,
        DefaultColormap(tips_x->display, tips_x->screen), name, &color,&color);
    return(color.pixel);
}

int T_init(MTK_RESOURCES *tips_x){  // Abre display, inicializa a estrutura ppal
    
    tips_x->display=XOpenDisplay(getenv("DISPLAY")); // open
    if(!tips_x->display){
        fprintf(stderr,"Erro ao conectar no display: %s\n", getenv ("DISPLAY"));
        return FALSE;
    }
    tips_x->screen = DefaultScreen(tips_x->display);
    return TRUE;
}

int T_creat_window(MTK_RESOURCES *tips_x){
// Recebe tips_x ja com x,y,h,w, inicializada e cria janela
    int win_border_width = 2;
    
    XGCValues values;
    unsigned int line_width = 2;
    int line_style = LineSolid;
    int cap_style = CapButt;
    int join_style = JoinBevel;
    unsigned long valuemask = 0;
    
    tips_x->win=XCreateSimpleWindow(tips_x->display,
        RootWindow(tips_x->display, tips_x->screen),
        tips_x->x, tips_x->y, tips_x->w, tips_x->h, win_border_width,
        BlackPixel(tips_x->display, tips_x->screen),
        WhitePixel(tips_x->display, tips_x->screen));
    
    XMapWindow(tips_x->display, tips_x->win);
    XFlush(tips_x->display);
    tips_x->gc=XCreateGC(tips_x->display, tips_x->win, valuemask, &values);
    if(tips_x->gc < 0){
        fprintf(stderr,"Erro na função XCreateGC\n");
        return FALSE;
    }
    
    XSetForeground(tips_x->display, tips_x->gc,
        BlackPixel(tips_x->display, tips_x->screen));
    XSetBackground(tips_x->display, tips_x->gc,
        WhitePixel(tips_x->display, tips_x->screen));
    XSetLineAttributes(tips_x->display, tips_x->gc,
        line_width, line_style, cap_style, join_style);
    XSetFillStyle(tips_x->display, tips_x->gc, FillSolid);
    
    return TRUE;
    
}


int T_creat_subwindow(MTK_RESOURCES *tips_x){
    XSetWindowAttributes attributes;
    XGCValues values;
    unsigned int line_width = 2;
    int line_style = LineSolid;
    int cap_style = CapButt;
    int join_style = JoinBevel;
    unsigned long valuemask = 0;
    
    attributes.save_under = True;
    attributes.override_redirect = True;
    
    tips_x->win = XCreateWindow(tips_x->display, tips_x->rootwindow,
        tips_x->x, tips_x->y, tips_x->w, tips_x->h, 0, CopyFromParent,
        InputOutput, CopyFromParent, CWSaveUnder|CWOverrideRedirect, &attributes);
    if(!tips_x->win){
        fprintf(stderr,"Erro na função CreatSubWindow\n");
        return FALSE;
    }
    
    XSelectInput(tips_x->display, tips_x->win,
        ExposureMask |
        ButtonPressMask |
        ButtonReleaseMask |
        ButtonMotionMask);
    XMapWindow(tips_x->display, tips_x->win);
    
    return TRUE;
}

int T_destroy(MTK_RESOURCES *tips_x){  // Destrói janela e estrutura
    XCloseDisplay(tips_x->display);
    return TRUE;
}

void main(int argc, char **argv){
    MTK_RESOURCES mytx, button;
    XEvent event;
    int a;
    
    // tenta inicializar
    
    if(!T_init(&mytx)){
        fprintf(stderr,"Erro ao inicializar estrutura\n");
        exit(1);
    }
    
    // tamanho e dimensão
    
    mytx.x = 1;
    mytx.y = 1;
    mytx.w = 500;
    mytx.h = 300;
    
    // tenta criar janela
    if(!T_creat_window(&mytx)){
        fprintf(stderr,"Erro ao criar janela\n");
        exit(1);
    }
    
    button.display = mytx.display;
    button.screen = mytx.screen;
    button.x = 1;
    button.y = 1;
    button.h = 60;
    button.w = 120;
    
    if(!T_creat_subwindow(&button)){
        fprintf(stderr,"Erro ao criar janela\n");
        exit(1);
    }
    
    XDrawRectangle(mytx.display, button.win, button.gc, 2, 2, 100, 30);
    
    XSync(mytx.display, False);
    
    while(1){
        fprintf(stderr,"Laço de eventos\n");
        
        do{
            XNextEvent(mytx.display, &event);
            fprintf(stderr,"Trara próximo evento:\n");
            
            switch(event.type){
                case ButtonPress:
                XSetForeground(mytx.display, button.gc,
                    getnamedcolor("white", &mytx));
                XDrawRectangle(mytx.display, button.win, button.gc, 2, 2, 100, 30);
                fprintf(stderr,"Evento: ButtonPress\n");
                break;
            }
        fprintf(stderr,"Evento Pendente\n");
        } while(XPending(mytx.display));
        
    XFlush(mytx.display);
    fprintf(stderr,"XFlush\n");
    }
    
    sleep(4);
    
    // finaliza
    if(!T_destroy(&mytx)){
        fprintf(stderr,"Erro no destroy()\n");
        exit(1);
    }
    
}
