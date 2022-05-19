#include <stdio.h>
#include <stdlib.h>

///------------------------Structure joueur------------------------///
typedef struct joueur{
int pv;             //nombre de PV du joueur
int pa;             //nombre de PA du joueur
int pm;             //nombre de PM du joueur
int num_joueur;     //le numéro du joueur
int classe_joueur;  //(1: Mario, 2: Bowser, 3: Yoshi, 4: Toad)
int pos_x;
int pos_y;
}t_joueur;
///-------------------Fin de la structure joueur-------------------///
