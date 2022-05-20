#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#define T_CASE 50
#define COL 1200
#define LIN 700

void initialisation_allegro()
{
    allegro_init();
    install_keyboard();
    install_mouse();
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, COL, LIN,0,0)!=0)
    {
        allegro_message("probleme gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
}

void ZoneAttaque(BITMAP *buffer)//rajouter le paramètre afin de connaître la position du joueur
{
    int i=0;
    int col = 18; //à remplacer par la variable position du joueur
    int lin = 8; //idem
    // coordonnées : [y][x] avec y = lin et x = col
    if(mouse_b)//clic souris
    {
        clear_bitmap(buffer);
        rectfill(buffer, 0, 550, 100, 650, makecol(255, 0, 0));
        rectfill(buffer, 110, 550, 210, 650, makecol(255, 0, 0));
        rectfill(buffer, 220, 550, 320, 650, makecol(255, 0, 0));
        rectfill(buffer, 330, 550, 430, 650, makecol(255, 0, 0));
        if(550<mouse_y && mouse_y<650 && 0<mouse_x && mouse_x<100) //bouton sort 1
        {
            for(i=0; i<3; i++) // colonne gauche
            {
                if((col-2)>=0 && (col-1)<=20 && (lin-1+i)>=0 && (lin+i)<=10) //toutes les conditions servent à ne pas montrer les zones d'attaques en dehors du plateau
                rectfill(buffer, (col-2)*T_CASE, (lin-1+i)*T_CASE,(col-1)*T_CASE, (lin+i)*T_CASE, makecol(255, 0, 0));
            }
            for(i=0; i<3; i++) // colonne droite
            {
                if((col+2)>=0 && (col+3)<=20 && (lin-1+i)>=0 && (lin+i)<=10)
                rectfill(buffer, (col+2)*T_CASE, (lin-1+i)*T_CASE,(col+3)*T_CASE, (lin+i)*T_CASE, makecol(255, 0, 0));
            }
            for(i=0; i<3; i++) // carrés ligne haute
            {
                if((lin-2)>=0 && (lin-1)<=10 && (col-1+i)>=0 && (col+i)<=20)
                rectfill(buffer, (col-1+i)*T_CASE, (lin-2)*T_CASE,(col+i)*T_CASE, (lin-1)*T_CASE, makecol(255, 0, 0));
            }
            for(i=0; i<3; i++) // carrés ligne basse
            {
                if((lin+2)>=0 && (lin+3)<=10 && (col-1+i)>=0 && (col+i)<=20)
                rectfill(buffer, (col-1+i)*T_CASE, (lin+2)*T_CASE,(col+i)*T_CASE, (lin+3)*T_CASE, makecol(255, 0, 0));
            }
        }
        else if(550<mouse_y && mouse_y<650 && 110<mouse_x && mouse_x<210) //bouton sort 2
        {
            for(i=0; i<5; i++)//colonne gauche
            {
                if((col-3)>=0 && (col-2)<=20 && (lin-2+i)>=0 && (lin-1+i)<=10)
                rectfill(buffer, (col-3)*T_CASE, (lin-2+i)*T_CASE, (col-2)*T_CASE, (lin-1+i)*T_CASE, makecol(255, 0, 0));
            }
            for(i=0; i<5; i++)//colonne droite
            {
                if((col+3)>=0 && (col+4)<=20 && (lin-2+i)>=0 && (lin-1+i)<=10)
                rectfill(buffer, (col+3)*T_CASE, (lin-2+i)*T_CASE, (col+4)*T_CASE, (lin-1+i)*T_CASE, makecol(255, 0, 0));
            }
            for(i=0; i<5; i++) //ligne haute
            {
                if((lin-3)>=0 && (lin-2)<=10 && (col-2+i)>=0 && (col-1+i)<=20)
                rectfill(buffer, (col-2+i)*T_CASE, (lin-3)*T_CASE,(col-1+i)*T_CASE, (lin-2)*T_CASE, makecol(255, 0, 0));
            }
            for(i=0; i<5; i++) //ligne basse
            {
                if((lin+3)>=0 && (lin+4)<=10 && (col-2+i)>=0 && (col-1+i)<=20)
                rectfill(buffer, (col-2+i)*T_CASE, (lin+3)*T_CASE,(col-1+i)*T_CASE, (lin+4)*T_CASE, makecol(255, 0, 0));
            }
        }
        else if(550<mouse_y && mouse_y<650 && 220<mouse_x && mouse_x<320) //bouton sort 3
        {
            for(i=0; i<7; i++)//colonne gauche
            {
                if((col-4)>=0 && (col-3)<=20 && (lin-3+i)>=0 && (lin-2+i)<=10)
                rectfill(buffer, (col-4)*T_CASE, (lin-3+i)*T_CASE, (col-3)*T_CASE, (lin-2+i)*T_CASE, makecol(255, 0, 0));
            }
            for(i=0; i<7; i++)//colonne droite
            {
                if((col+4)>=0 && (col+5)<=20 && (lin-3+i)>=0 && (lin-2+i)<=10)
                rectfill(buffer, (col+4)*T_CASE, (lin-3+i)*T_CASE, (col+5)*T_CASE, (lin-2+i)*T_CASE, makecol(255, 0, 0));
            }
            for(i=0; i<7; i++) //ligne haute
            {
                if((lin-4)>=0 && (lin-3)<=10 && (col-3+i)>=0 && (col-2+i)<=20)
                rectfill(buffer, (col-3+i)*T_CASE, (lin-4)*T_CASE,(col-2+i)*T_CASE, (lin-3)*T_CASE, makecol(255, 0, 0));
            }
            for(i=0; i<7; i++) //ligne basse
            {
                if((lin+4)>=0 && (lin+5)<=10 && (col-3+i)>=0 && (col-2+i)<=20)
                rectfill(buffer, (col-3+i)*50, (lin+4)*50,(col-2+i)*50, (lin+5)*50, makecol(255, 0, 0));
            }
        }
        else if(550<mouse_y && mouse_y<650 && 330<mouse_x && mouse_x<430) //bouton sort 4
        {
            for(i=0; i<3; i++)//diagonale haut gauche
            {
                if((lin-4+i)>=0 && (lin-3+i)<=10 && (col-4+i)>=0 && (col-3+i)<=20)
                rectfill(buffer, (col-4+i)*T_CASE, (lin-4+i)*T_CASE, (col-3+i)*T_CASE, (lin-3+i)*T_CASE, makecol(255, 0, 0));
            }
            for(i=0; i<3; i++)//diagonale bas gauche
            {
                if((lin+4-i)>=0 && (lin+5-i)<=10 && (col-4+i)>=0 && (col-3+i)<=20)
                rectfill(buffer, (col-4+i)*T_CASE, (lin+4-i)*T_CASE, (col-3+i)*T_CASE, (lin+5-i)*T_CASE, makecol(255, 0, 0));
            }
            for(i=0; i<3; i++)//diagonale haut droite
            {
                if((col+4-i)>=0 && (col+5-i)<=20 && (lin-4+i)>=0 && (lin-3+i)<=10)
                rectfill(buffer, (col+4-i)*T_CASE, (lin-4+i)*T_CASE, (col+5-i)*T_CASE, (lin-3+i)*T_CASE, makecol(255, 0, 0));
            }
            for(i=0; i<3; i++)//diagonale bas droite
            {
                if((col+4-i)>=0 && (col+5-i)<=20 && (lin+4-i)>=0 && (lin+5-i)<=10)
                rectfill(buffer, (col+4-i)*T_CASE, (lin+4-i)*T_CASE, (col+5-i)*T_CASE, (lin+5-i)*T_CASE, makecol(255, 0, 0));
            }
        }
    }
}
int main()
{
    initialisation_allegro();
    BITMAP *buffer;
    buffer =create_bitmap(COL,LIN);
    show_mouse(screen);
    while(!key[KEY_ESC])
    {
        rectfill(buffer, 0, 550, 100, 650, makecol(255, 0, 0));   //carrés représentant les 4 boutons des choix de sorts
        rectfill(buffer, 110, 550, 210, 650, makecol(255, 0, 0)); //à remplacer par les vrais visuels des boutons
        rectfill(buffer, 220, 550, 320, 650, makecol(255, 0, 0)); // éventuellement changer les emplacements
        rectfill(buffer, 330, 550, 430, 650, makecol(255, 0, 0));
        ZoneAttaque(buffer); // appeler avant la création du plateau pour que ça marche ? (à voir)
        blit(buffer,screen, 0,0,0,0, COL, LIN);
    }
    destroy_bitmap(buffer);
    allegro_exit();
    return 0;
}END_OF_MAIN();
