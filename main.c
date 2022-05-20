#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro.h>
///----------------------------------------------------------------------------------------------///
///---------------------------------------------Main---------------------------------------------///
int main()
{
  initialisation_allegro();
  t_joueur *tableau_joueur = malloc(nbjoueurs * sizeof(t_joueur)); //Tableau joueurs, nécessite le nombre de joueurs: "nbjoueurs"
  t_classe *classe;
  initialisation_allegro();
  initialisation_joueur(nbjoueurs, t_joueur* tableau_joueur); //Initialise les joueurs, nécessite le nombre de joueurs: "nbjoueurs" et le tableau: "tableau_joueur"
  ini_classe(t_classe *classe); //Initialise les classes, nécessite le tableau: "classe"

return 0;
}
///------------------------------------------Fin du Main------------------------------------------///
///-----------------------------------------------------------------------------------------------///
