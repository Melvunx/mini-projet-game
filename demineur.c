#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Affichage.h"
#include "Game.h"

int main() {

  srand(time(NULL)); //Initialisation du rand
  int choix_joueur,
  nb_partie = 0,
  score = 0,
  nb_bonus = 0;

  explication_jeu();
  
  do
  {
    struct Partie p = commencer_partie();
    score += p.score;
    nb_bonus += p.bonus_trouve;
    nb_partie++;

    printf("Voulez-vous recommencer la partie ? (1 pour oui, 0 pour non) : ");
    scanf("%d", &choix_joueur);
  } while (choix_joueur == 1);

  printf("score total : %2d\nNombre de bonus : %2d\nNombre de partie : %2d\n", score, nb_bonus, nb_partie);

  return 0;
}
