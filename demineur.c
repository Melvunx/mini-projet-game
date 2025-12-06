#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Affichage.h"
#include "Game.h"

int main() {

  srand(time(NULL)); //Initialisation du rand
  int choix_joueur;
  struct Partie p;
  struct Statistique stat = {.total_score = 0, .max_score = 0, .nb_bonus = 0, .nb_partie = 0};

  explication_jeu();
  
  do
  {
    p = commencer_partie();
    stat = generer_stat(stat, p);

    printf("\n");
    printf("Voulez-vous recommencer la partie ? (1 pour oui, 0 pour non) : ");
    scanf("%d", &choix_joueur);
    printf("\n");
  } while (choix_joueur == 1);

  recapitulatif_partie(stat);

  return 0;
}
