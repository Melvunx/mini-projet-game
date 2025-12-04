#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Affichage.h"
#include "Game.h"

int main() {

  srand(time(NULL)); //Initialisation du rand
  int choix_joueur;

  do
  {
    commencer_partie();
    printf("Voulez-vous recommencer la partie ? (1 pour oui, 0 pour non) : ");
    scanf("%d", &choix_joueur);
  } while (choix_joueur == 1);

  return 0;
}
