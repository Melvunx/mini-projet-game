#include <stdio.h>
#include <string.h>
#include "Game.h"

struct Grille initialiser_plateau(struct Grille g, int taille)
{
  for (int i = 0; i < taille; i++)
  {
    for (int j = 0; j < taille; j++)
    {
      g.plateau[i][j] = 0;
      g.visible[i][j] = 0;
    }
  }

  return g;
}

struct Difficulte initialiser_difficulte()
{
  struct Difficulte d;
  int player_choice;

  printf(
    "**************************************************\n"
    "Choisissez le niveau de difficulté\n"
    "\tNiveau facile :%d\tNiveau moyen :%d\tNiveau difficile :%d\n",
    DIFF_EASY, DIFF_MID, DIFF_HARD
  );

  scanf("%d", &player_choice);
  
  while (player_choice > 3 || player_choice < 0)
  {
    printf("Attention !\nVeuillez choisir un niveau de difficulté entre %d, %d et %d : ", DIFF_EASY, DIFF_MID, DIFF_HARD);
    scanf("%d", &player_choice);
  }

  switch (player_choice)
  {
  case DIFF_EASY:
    strcpy(d.niveau, "Facile");
    d.taille = 4;
    d.nb_bombe = 6;
    break;
    
    case DIFF_MID:
    strcpy(d.niveau, "Moyen");
    d.taille = 5;
    d.nb_bombe = 10;
    break;
    
    case DIFF_HARD:
    strcpy(d.niveau, "Difficle");
    d.taille = 6;
    d.nb_bombe = 14;
    break;
  
  default:
    strcpy(d.niveau, "facile");
    d.nb_bombe = 6;
    d.taille = 4;
  }

  return d;
}

struct Grille initialiser_grille()
{
  struct Grille g;

  // Initialisation de la difficulté
  g.diff = initialiser_difficulte();

  g = initialiser_plateau(g, g.diff.taille);

  return g;
}