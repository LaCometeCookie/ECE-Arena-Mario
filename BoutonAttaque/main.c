#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>

#define COL 1200
#define LIN 700

int initialisation_allegro(){
    allegro_init();
    install_mouse();
    install_keyboard();

    set_color_depth(desktop_color_depth());
    if((set_gfx_mode(GFX_AUTODETECT_WINDOWED,(COL),(LIN),0,0))!=0){
        allegro_message("Pb de mode graphique");
        allegro_exit();
        exit(EXIT_FAILURE);}
}

void AffichageBouton(BITMAP *buffer) //affichage des boutons d'attaques
{
    rectfill(buffer, 400, 550, 500, 650, makecol(255, 0, 0)); //bouton attaque au corps à corps
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
int main()
{
    BITMAP *buffer;
    initialisation_allegro();
    buffer =create_bitmap(COL,LIN);
    show_mouse(screen); // affichage souris à l'écran
    while(!key[KEY_ESC]){
        AffichageBouton(buffer);
        blit(buffer,screen, 0,0,0,0, COL, LIN); //afficher le buffer à l'écran
    }
    destroy_bitmap(buffer);
    allegro_exit();
    return 0;
}END_OF_MAIN();
