///-------------------------------------Sous programme attaque-------------------------------------///
    ///////////////////////////////////////////////////////////////////////////////////
    //Le sous prog prend en paramètres:
    //
    //le numéro du joueur qui joue (=1 si joueur 1, =3 si joueur 3 etc...)
    //la matrice: tabChose[20][10]
    //la classe
    //le tableau joueur
    //le numéro de l'ttaque utilisée (0: corps à corps, 1: sort n°1, 2: sort n°2 etc...
    ///////////////////////////////////////////////////////////////////////////////////
int attaque(int num_joueur, int tabChose[20][10], t_classe* classe, t_joueur* tableau_joueur, int numero_attaque)
{
    int couleur_rouge = makecol(255, 0, 0);
    if(mouse_b & 1)//Test si clique gauche
    {
        int souris_lin = 0;
        int souris_col = 0;
        souris_lin =(mouse_y/50);
        souris_col =(mouse_x/50);

        int couleur_case = getpixel(screen , mouse_x, mouse_y);//Récupération de la couleur de la case

        if(couleur_case == couleur_rouge)//Si la case est rouge (=case à portée)
        {
            tableau_joueur[num_joueur].pa = tableau_joueur[num_joueur].pa - classe->tab_PA_attaques[numero_attaque];//L'attaquant perd des PA

            if(tabChose[souris_col][souris_lin] != 0)//Si présence d'un joueur
                {
                    int victime = 0;
                    if(tabChose[souris_col][souris_lin] == 1) victime = 1;//Si présence joueur 1
                    if(tabChose[souris_col][souris_lin] == 2) victime = 2;//Si présence joueur 2
                    if(tabChose[souris_col][souris_lin] == 3) victime = 3;//Si présence joueur 3
                    if(tabChose[souris_col][souris_lin] == 4) victime = 4;//Si présence joueur 4

                    srand(time(NULL));//Initialisation rand()
                    int proba_echec = rand()%12;
                    if(proba_echec != 0)//Si l'attaque n'a pas échoué
                    {
                        //Permet de générer aléatoirement le nb de dégâts infligés//
                        int pv_infliges = 0;
                        int pv_max = classe->tab_degats_attaques[numero_attaque] + 1;
                        int pv_min = classe->tab_degats_attaques[numero_attaque] - 1;
                        pv_infliges = pv_min + rand()%(pv_max-pv_min+1);
                        ////////////////////////////////////////////////////////////

                        tableau_joueur[victime].pv = tableau_joueur[victime].pv - pv_infliges;//Application des dégâts au joueur victime de l'attaque
                    }
                }

                else//Si l'attaque a échouée
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
///-----------------------------------Fin Sous programme attaque-----------------------------------///
