#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#define SCREEN_W 1200
#define SCREEN_H 700
void initialisation_allegro()
{
    allegro_init();
    install_keyboard();
    install_mouse();
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,SCREEN_W,SCREEN_H,0,0)!=0)
    {
        // message et sortie de prog. si échec
        allegro_message("probleme gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
}

int main()
{
    int lin = 275;
    int col = 600;
    int i=0;
    initialisation_allegro();
    BITMAP *buffy;
    buffy=create_bitmap(SCREEN_W, SCREEN_H);
    show_mouse(screen);

    while(!key[KEY_ESC])
    {
        //test zones d'attaque portée 2
        if(mouse_b)
        {
            if(0<mouse_x && mouse_x<50 && 0<mouse_y && mouse_y<50)
            {
                for(i=0; i<3; i++) // carrés colonne gauche
                {
                    rectfill(buffy, (col-2*50), (lin-1*50+i*50),(col-1*50), (lin+i*50), makecol(255, 0, 0));
                }
                for(i=0; i<3; i++) // carrés colonne droite
                {
                    rectfill(buffy, (col+2*50), (lin-1*50+i*50),(col+3*50), (lin+i*50), makecol(255, 0, 0));
                }
                for(i=0; i<3; i++) // carrés ligne haute
                {
                    rectfill(buffy, (col-1*50+i*50), (lin-2*50),(col+i*50), (lin-1*50), makecol(255, 0, 0));
                }
                for(i=0; i<3; i++) // carrés ligne basse
                {
                    rectfill(buffy, (col-50+(i*50)), (lin+2*50),(col+i*50), (lin+3*50), makecol(255, 0, 0));
                }
            }
        }
        //test zones d'attaque portée 3
        for(i=0; i<5; i++)//colonne gauche
        {
            rectfill(buffy, (col-3*50), (lin-2*50+i), (col-2*50), (lin-1*50+i*50), makecol(0, 255, 0));
        }
        for(i=0; i<5; i++)//colonne droite
        {
            rectfill(buffy, (col+3*50), (lin-2*50+i*50), (col+4*50), (lin-1*50+i*50), makecol(0, 255, 0));
        }
        for(i=0; i<5; i++) //ligne haute
        {
            rectfill(buffy, (col-2*50+i*50), (lin-3*50),(col-1*50+i*50), (lin-2*50), makecol(0, 255, 0));
        }
        for(i=0; i<5; i++) //ligne basse
        {
            rectfill(buffy, (col-2*50+i*50), (lin+3*50),(col-1*50+i*50), (lin+4*50), makecol(0, 255, 0));
        }

        //test zones d'attaque portée 4
        for(i=0; i<7; i++)//colonne gauche
        {
            rectfill(buffy, (col-4*50), (lin-3*50+i*50), (col-3*50), (lin-2*50+i*50), makecol(0, 0, 255));
        }
        for(i=0; i<7; i++)//colonne droite
        {
            rectfill(buffy, (col+4*50), (lin-3*50+i*50), (col+5*50), (lin-2*50+i*50), makecol(0, 0, 255));
        }
        for(i=0; i<7; i++) //ligne haute
        {
            rectfill(buffy, (col-3*50+i*50), (lin-4*50),(col-2*50+i*50), (lin-3*50), makecol(0, 0, 255));
        }
        for(i=0; i<7; i++) //ligne basse
        {
            rectfill(buffy, (col-3*50+i*50), (lin+4*50),(col-2*50+i*50), (lin+5*50), makecol(0, 0, 255));
        }

        //test zones d'attaques diagonales
        for(i=0; i<3; i++)//diagonale haut gauche
        {
            rectfill(buffy, (col-4*50+i*50), (lin-4*50+i*50), (col-3*50+i*50), (lin-3*50+i*50), makecol(255, 255, 0));
        }
        for(i=0; i<3; i++)//diagonale bas gauche
        {
            rectfill(buffy, (col-4*50+i*50), (lin+4*50-i*50), (col-3*50+i*50), (lin+5*50-i*50), makecol(255, 255, 0));
        }
        for(i=0; i<3; i++)//diagonale haut droite
        {
            rectfill(buffy, (col+2*50+i*50), (lin-2*50-i*50), (col+3*50+i*50), (lin-1*50-i*50), makecol(255, 255, 0));
        }
        for(i=0; i<3; i++)//diagonale bas droite
        {
            rectfill(buffy, (col+2*50+i*50), (lin+2*50+i*50), (col+3*50+i*50), (lin+3*50+i*50), makecol(255, 255, 0));
        }
        blit(buffy, screen, 0, 0, 0, 0, 1200, 700);
    }
    allegro_exit();
    return 0;
}END_OF_MAIN();
