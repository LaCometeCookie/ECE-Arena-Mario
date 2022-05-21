///------------------------Structure joueur------------------------///
typedef struct joueur{
int pv;             //nombre de PV du joueur
int pa;             //nombre de PA du joueur
int pm;             //nombre de PM du joueur
int num_joueur;     //le numéro du joueur
int classe_joueur;  //(1: Mario, 2: Bowser, 3: Yoshi, 4: Toad)
int pos_x;          //Position horizontale du joueur
int pos_y;          //Position verticale du   joueur
}t_joueur;
///-------------------Fin de la structure joueur-------------------///

///------------------------Sous prog Initialisation des joueurs------------------------///
                    //////////////////////////////////////////////////
                    //      Le sous prog prend en paramètres:       //
                    //          le nombre de joueurs (int)          //
                    //      le tableau de structure tableau_joueur  //
                    //////////////////////////////////////////////////
int initialisation_joueur(int nbjoueurs, t_joueur* tableau_joueur)
{
    for(int i = 0; i<nbjoueurs; i++)
    {
        tableau_joueur[i].pv = 20;
        tableau_joueur[i].pa = 3;
        tableau_joueur[i].num_joueur = i;
        tableau_joueur[i].classe_joueur = i+1;
        tableau_joueur[i].pos_x = 0;
        tableau_joueur[i].pos_y = 0;
    }
}
///----------------------Fin sous prog Initialisation des joueurs----------------------///
