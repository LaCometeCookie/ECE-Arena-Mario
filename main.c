#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro.h>
///----------------------------------------------------------------------------------------------///
///---------------------------------------------Main---------------------------------------------///
int main()
{
t_joueur *tableau_joueur = malloc(nbjoueurs * sizeof(t_joueur)); //Tableau joueurs, nécessite le nombre de joueurs: nbjoueurs
t_classe *classe;
initialisation_allegro();
return 0;
}
///------------------------------------------Fin du Main------------------------------------------///
///-----------------------------------------------------------------------------------------------///
