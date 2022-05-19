#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>

void initialisation_allegro()
{
    allegro_init(); // appel obligatoire (var.globales, recup. infos syst�me ...)
    install_keyboard(); //pour utiliser le clavier
    install_mouse(); //pour utiliser la souris
    srand(time(NULL));//pour utiliser de l'al�atoire
    //pour choisir la profondeur de couleurs (8,16,24 ou 32 bits)
    //ici : identique � celle du bureau
    set_color_depth(desktop_color_depth());
    //s�lection du mode graphique


    // avec choix d'un driver+mode+r�solution de l'�cran
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,1280,720,0,0)!=0) //R�solution choisie de 1280x720
    {
        // message et sortie de prog. si �chec
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
}


int main(){
//appel proc�dure d'initialisation
initialisation_allegro();

//d�claration des ressources


///---------reste du code---------///

 while(!key[KEY_SPACE])
{


}

///---------fin  du  code---------///

allegro_exit();
return 0;

}END_OF_MAIN(); //obligatoire (compatibilit� multi plateforme)


                ///------Sous programme attaque------///
//////////////////////////////////////////////////////////////////////////
//Le sous prog prend en param�tres:                                     //
//                                                                      //
//le num�ro du joueur qui joue (=1 si joueur 1, =3 si joueur 3 etc...)  //
//le nb de pa que co�te le sort                                         //
//le nb de pv inflig� par le sort                                       //                               //
//le nb de pv du joueur 1 (pointeur)                                    //
//le nb de pv du joueur 2 (pointeur)                                    //
//le nb de pv du joueur 3 (pointeur)                                    //
//le nb de pv du joueur 4 (pointeur)                                    //
//le nb de pa du joueur 1 (pointeur)                                    //
//le nb de pa du joueur 2 (pointeur)                                    //
//le nb de pa du joueur 3 (pointeur)                                    //
//le nb de pa du joueur 4 (pointeur)                                    //
//////////////////////////////////////////////////////////////////////////
int attaque(int tour_joueur, int pa, int pv, int matrice, int* pv_joueur1, int* pv_joueur2, int* pv_joueur3, int* pv_joueur4, int* pa_joueur1, int* pa_joueur2, int* pa_joueur3, int* pa_joueur4)
{
    int couleur_rouge = makecol(256, 0, 0);
    if(mouse_b & 1)//Test si clique gauche
    {
        int couleur_case = getpixel(screen , mouse_x, mouse_y);//R�cup�ration de la couleur de la case

        if(couleur_case == couleur_rouge)//Si la case est rouge (=case � port�e)
        {
            if(tour_joueur == 1) *pa_joueur1 = *pa_joueur1 - pa;
            if(tour_joueur == 2) *pa_joueur1 = *pa_joueur1 - pa;
            if(tour_joueur == 3) *pa_joueur1 = *pa_joueur1 - pa;
            if(tour_joueur == 4) *pa_joueur1 = *pa_joueur1 - pa;

            if(matrice != 0)//Si pr�sence d'un joueur
            {
                int joueur = 0;
                if(matrice == 1) joueur = 1;//Si pr�sence joueur 1
                if(matrice == 2) joueur = 2;//Si pr�sence joueur 2
                if(matrice == 3) joueur = 3;//Si pr�sence joueur 3
                if(matrice == 4) joueur = 4;//Si pr�sence joueur 4

                srand(time(NULL));//Initialisation rand()
                int proba_echec = rand()%12;
                if(proba_echec != 0)//Si l'attaque n'a pas �chou�
                {
                    int pv_infliges = 0;
                    int pv_max = pv + 1;
                    int pv_min = pv - 1;
                    srand(time(NULL));//Initialisation rand()
                    pv_infliges = pv_min + rand()%(pv_max-pv_min+1);//PV inflig�s g�n�r�s al�atoirement

                    if(joueur == 1) {*pv_joueur1 = *pv_joueur1 - pv_infliges;}//Application des d�g�ts joueur 1
                    if(joueur == 2) {*pv_joueur2 = *pv_joueur2 - pv_infliges;}//Application des d�g�ts joueur 2
                    if(joueur == 3) {*pv_joueur3 = *pv_joueur3 - pv_infliges;}//Application des d�g�ts joueur 3
                    if(joueur == 4) {*pv_joueur4 = *pv_joueur4 - pv_infliges;}//Application des d�g�ts joueur 4
                }

                else//Si l'attaque a �chou�e
                {
                    allegro_message("Quel dommage votre attaque a echoue");//Message d erreur
                }
            }

            else//Si case vide
            {
                allegro_message("Vous avez tire dans le vide");//Message d echec
            }
        }
    }
}
            ///------Fin sous programme attaque------///
