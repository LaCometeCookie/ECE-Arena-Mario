///---------------------------------Structure classe---------------------------------///
typedef struct classe{
char nom_de_classe[30];
int tab_degats_attaques[5];     //tableau contenant les dégâts infligés par les attaques
int tab_PA_attaques[5];         //tableau contenant les côuts des attaques
}t_classe;
///----------------------------Fin de la structure classe----------------------------///

///--------------------Initialisations tableaux dégâts et PA attaques--------------------///
            //////////////////////////////////////////////////
            //          Le sous prog prend en paramètres:   //
            //        un élément de la structure t_classe   //
            //////////////////////////////////////////////////
int ini_classe(t_classe classe)
{
    classe.tab_degats_attaques[0] = 2;     //Initialisation dégâts attaques corps à corps
    classe.tab_degats_attaques[1] = 8;     //Initialisation dégâts attaques 1
    classe.tab_degats_attaques[2] = 5;     //Initialisation dégâts attaques 2
    classe.tab_degats_attaques[3] = 4;     //Initialisation dégâts attaques 3
    classe.tab_degats_attaques[4] = 5;     //Initialisation dégâts attaques 4

    classe.tab_PA_attaques[0] = 2;         //Attaques corps à corps
    classe.tab_PA_attaques[1] = 3;         //Attaques n°1
    classe.tab_PA_attaques[2] = 4;         //Attaques n°2
    classe.tab_PA_attaques[3] = 8;         //Attaques n°3
    classe.tab_PA_attaques[4] = 6;         //Attaques n°4
}
///------------------Fin initialisations tableaux dégâts et PA attaques-------------------///
