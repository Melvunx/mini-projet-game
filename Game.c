#include <stdio.h>
#include <string.h>
#include "Game.h"
#include "Affichage.h"

struct Grille initialiser_case(struct Grille g)
{
  int nbcase = g.diff.taille * g.diff.taille;
  
  for (int i = 0; i < nbcase; i++)
  {
    g.visible[i].val = 0;
  }

  for (int j = 0; j < g.diff.taille; j++)
  {
    for (int k = 0; k < g.diff.taille; k++)
    {
      g.visible[k].y = j + 1;
      g.visible[k].x = k + 1;
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

struct Grille generer_plateau(struct Grille g)
{
  for (int i = 0; i < g.diff.taille; i++)
  {
    for (int j = 0; j < g.diff.taille; j++)
    {
      g.plateau[i][j] = '#';
    }
  }

  g = initialiser_case(g);

  return g;
}


struct Grille initialiser_grille()
{
  struct Grille g;

  // Initialisation de la difficulté
  g.diff = initialiser_difficulte();

  g = generer_plateau(g);

  return g;
}

void commencer_partie(struct Grille grille)
{
  struct Partie p = {.score = 0, .terminer = 0};
  char r; //Recommencer la partie ou non

  grille = initialiser_grille(grille);

  p.grille = grille;

  do
  {
    
  } while (!p.terminer);
  
  fin_partie(p);


}