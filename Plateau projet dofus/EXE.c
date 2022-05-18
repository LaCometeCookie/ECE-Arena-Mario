#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>

        /// ######## DEFINE ######## ///
#define COL 1200
#define LIN 700
#define T_CASE 50


        /// ######## PROTOTYPES ######## ///
int init();
int creationPlateau(BITMAP *buffer, BITMAP *padMvmt, int souris_lin, int souris_col, int souris_gauche);


        /// ######## MAIN ######## ///
int EXE()
{
    BITMAP *buffer; // Bitmap double buffer
    BITMAP *sprite;
    BITMAP *padMvmt;

    init(); // Sous programme d'initialisation d'allegro


    sprite=load_bitmap("sprite test.bmp",NULL); // On charge
    if (!sprite){
        allegro_message("pas pu trouver sprite.bmp"); // On test si bien chargé
        exit(EXIT_FAILURE);}
    padMvmt=load_bitmap("Pad mouvement.bmp",NULL); // Pareil
    if (!padMvmt){
        allegro_message("pas pu trouver padMvmt.bmp");
        exit(EXIT_FAILURE);}
    buffer =create_bitmap(COL,LIN); // Création de la bitmap du buffer (vu qu'elle n'est pas chargée)

    show_mouse(screen); // Affiche la souris à l'écran


    ///         Variables        ///
    int souris_lin =0, souris_col =0; // Variables de la position de la souris (varie entre 0 et 20)
    int boutonDep =0;
    int souris_gauche =0;

//  while(menu ==1){ //Boucle du menu

        //menu(); //Sous programme qui affiche et gère le menu

    while(!key[KEY_ESC]){ //Boucle de partie
        positionSouris(&souris_lin, &souris_col, &souris_gauche); /* Sous programme qui passe par adresse la case de la souris
                                                                     et si on clique (souris_lin, souris_col, souris_gauche) */

        creationPlateau(buffer, padMvmt, souris_lin, souris_col, souris_gauche); //Sous programme de création du plateau
        deplacements(souris_gauche); //Sous programme de déplacements


        blit(buffer,screen, 0,0,0,0, COL, LIN); //On termine par affiche le buffer
    }//FinBouclePartie
 // }//FinBoucleMenu
    return 0;
}

        /// ######## SOUS PROGRAMMES ######## ///

void positionSouris(int *souris_lin, int *souris_col, int *souris_gauche){
    *souris_lin =(mouse_y/50); //Recup la position en pixels de la souris et la divise par 50 pour avoir la case
    *souris_col =(mouse_x/50);
    *souris_gauche =mouse_b&1; // Vaut 0 si pas de clique, vaut 1 si
}

int creationPlateau(BITMAP *buffer, BITMAP *padMvmt, int souris_lin, int souris_col, int souris_gauche){
    int ligne =10, colonne =20;

    for(int i =0; i <colonne; i++){
        for(int u =0; u <ligne; u++){
            rect(buffer,i*T_CASE,u*T_CASE,(i+1)*T_CASE,(u+1)*T_CASE, makecol(255,255,255));
        }
    }

    rectfill(buffer, 1050, 0, 1200, 20, makecol(0,0,0));
    textprintf_ex(buffer, font, 1010, 10, makecol(255,255,255), -1, "lin: %d col: %d clic: %d", souris_lin, souris_col, souris_gauche);

    draw_sprite(buffer, padMvmt, 1002, 30);
}

int deplacements(int souris_gauche){

    if(souris_gauche ==1 && mouse_x >1002 && mouse_y >30 && mouse_y <230 && dep ==0){
        dep =1;
    }
    if(souris_gauche ==1 && mouse_x >1002 && mouse_y >30 && mouse_y <230 && dep ==1){
        dep =0;
    }
}

int init(){
    allegro_init();
    install_mouse();
    install_keyboard();

    set_color_depth(desktop_color_depth());
    if((set_gfx_mode(GFX_AUTODETECT_WINDOWED,(COL),(LIN),0,0))!=0){
        allegro_message("Pb de mode graphique");
        allegro_exit();
        exit(EXIT_FAILURE);}
}
