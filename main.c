#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro.h>
///----------------------------------------------------------------------------------------------///
///---------------------------------------------Main---------------------------------------------///
int main()
{
  initialisation_allegro();
    t_joueur* tableau_joueur = malloc(nbjoueurs * sizeof(t_joueur));
    t_classe* classe;

    initialisation_joueur(nbjoueurs, tableau_joueur); //Initialise les joueurs, nécessite le nombre de joueurs: "nbjoueurs" et le tableau: "tableau_joueur"
    ini_classe(classe); //Initialise les classes, nécessite le tableau: "classe"

return 0;
}
///------------------------------------------Fin du Main------------------------------------------///
///-----------------------------------------------------------------------------------------------///
