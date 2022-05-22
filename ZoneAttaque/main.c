#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#define T_CASE 50
#define COL 1200
#define LIN 700
typedef struct joueur{
int pv;             //nombre de PV du joueur à savoir 20
int pa;             //nombre de PA du joueur
int num_joueur;     //le numéro du joueur
int classe_joueur;  //(1: Mario, 2: Bowser, 3: Yoshi, 4: Toad)
int pos_x;
int pos_y;
}t_joueur;
void AffichageBouton(BITMAP *buffer)
{
    rectfill(buffer, 400, 550, 500, 650, makecol(255, 0, 0)); //bouton corps à corps
    rectfill(buffer, 520, 550, 620, 650, makecol(255, 0, 0)); //sort 1
    rectfill(buffer, 640, 550, 740, 650, makecol(255, 0, 0)); //sort 2
    rectfill(buffer, 760, 550, 860, 650, makecol(255, 0, 0)); //sort 3
    rectfill(buffer, 880, 550, 980, 650, makecol(255, 0, 0)); // sort 4
    textprintf_ex(buffer, font, 430, 575, makecol(255,255,255), -1, "CORPS");
    textprintf_ex(buffer, font, 445, 595, makecol(255,255,255), -1, "A");
    textprintf_ex(buffer, font, 430, 615, makecol(255,255,255), -1, "CORPS");
    textprintf_ex(buffer, font, 547, 595, makecol(255,255,255), -1, "SORT 1");
    textprintf_ex(buffer, font, 667, 595, makecol(255,255,255), -1, "SORT 2");
    textprintf_ex(buffer, font, 787, 595, makecol(255,255,255), -1, "SORT 3");
    textprintf_ex(buffer, font, 907, 595, makecol(255,255,255), -1, "SORT 4");
}

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

void ZoneAttaque(BITMAP *buffer, t_joueur *tableau_joueur)
{
    int i=0;
    int col = tableau_joueur[i].pos_x; // on utilise 2 variables pour désigner la position du joueur qui joue
    int lin = tableau_joueur[i].pos_y; //idem
    // coordonnées : [y][x] avec y = lin et x = col
    if(mouse_b)//clic souris
    {
        clear_bitmap(buffer);
        AffichageBouton(buffer);
        if(550<mouse_y && mouse_y<650 && 520<mouse_x && mouse_x<620) //si bouton sort 1 emplacement cliqué
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
        else if(550<mouse_y && mouse_y<650 && 640<mouse_x && mouse_x<740) //bouton sort 2
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
        else if(550<mouse_y && mouse_y<650 && 760<mouse_x && mouse_x<860) //bouton sort 3
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
        else if(550<mouse_y && mouse_y<650 && 880<mouse_x && mouse_x<980) //bouton sort 4
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
        else if(550<mouse_y && mouse_y<650 && 400<mouse_x && mouse_x<500)//attaque cors à corps
        {
            for(i=0; i<3; i++)//colonne gauche
            {
                if((col-1)>=0 && (col)<=20 && (lin-1+i)>=0 && (lin+i)<=10)
                rectfill(buffer, (col-1)*T_CASE, (lin-1+i)*T_CASE, (col)*T_CASE, (lin+i)*T_CASE, makecol(255, 0, 0));
            }
            for(i=0; i<3; i++)//colonne droite
            {
                if((col+1)>=0 && (col+2)<=20 && (lin-1+i)>=0 && (lin+i)<=10)
                rectfill(buffer, (col+1)*T_CASE, (lin-1+i)*T_CASE, (col+2)*T_CASE, (lin+i)*T_CASE, makecol(255, 0, 0));
            }
            for(i=0; i<1; i++) //carré juste en haut de la case du perso
            {
                if((lin-1)>=0 && (lin)<=10 && (col)>=0 && (col+1)<=20)
                rectfill(buffer, (col)*T_CASE, (lin-1)*T_CASE,(col+1)*T_CASE, (lin)*T_CASE, makecol(255, 0, 0));
            }
            for(i=0; i<1; i++) //carré juste en dessous de la case d perso
            {
                if((lin+1)>=0 && (lin+2)<=10 && (col)>=0 && (col+1)<=20)
                rectfill(buffer, (col)*T_CASE, (lin+1)*T_CASE,(col+1)*T_CASE, (lin+2)*T_CASE, makecol(255, 0, 0));
            }
        }
    }
}
int main()
{
    int nbjoueurs;
    initialisation_allegro();
    BITMAP *buffer;
    buffer =create_bitmap(COL,LIN);
    show_mouse(screen);
    t_joueur* tableau_joueur = malloc(nbjoueurs * sizeof(t_joueur));
    while(!key[KEY_ESC])
    {
        AffichageBouton(buffer);
        ZoneAttaque(buffer, tableau_joueur); // appeler avant la création du plateau pour que ça marche ? (à voir)
        blit(buffer,screen, 0,0,0,0, COL, LIN);
    }
    destroy_bitmap(buffer);
    allegro_exit();
    return 0;
}END_OF_MAIN();
