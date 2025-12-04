#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Game.h"
#include "Affichage.h"


struct Difficulte initialiser_difficulte()
{
  struct Difficulte d;
  int player_choice;
  
  do
  {
    printf(
      "**************************************************\n"
      "Choisissez le niveau de difficulté\n"
      "Niveau facile :%d\tNiveau moyen :%d\tNiveau difficile :%d\n",
      DIFF_EASY, DIFF_MID, DIFF_HARD
    );
    
    scanf("%d", &player_choice);
  } while (player_choice > 3 || player_choice < 0);
  
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

struct Grille initialiser_grille()
{
  struct Grille g;
  
  // Initialisation de la difficulté
  g.diff = initialiser_difficulte();
  
  g = initialiser_case(g);
  
  return g;
}

struct Case generer_case(int taille)
{

  struct Case c = {.val = 0};
  int x_aleatoire;
  int y_aleatoire;

  // Génération des coordonnées aléatoires
  x_aleatoire = (rand() % taille) + 1;
  y_aleatoire = (rand() % taille) + 1;

  c.x = x_aleatoire;
  c.y = y_aleatoire;

  printf("x_aleatoire : %d y_aleatoire : %d\n", x_aleatoire, y_aleatoire);

  return c;
}


int rechercher_case(struct Grille g, struct Case c)
{
  int nbcase = g.diff.taille * g.diff.taille;
  int i = 0, trouve = 0;

  while (i < nbcase && !trouve)
  {
    if (g.visible[i].x == c.x && g.visible[i].y == c.y) 
      trouve = 1;
    
    else i++;
  }
  
  if (!trouve) return -1;

  return i;
}

 








// void commencer_partie(struct Grille grille)
// {
//   struct Partie p = {.score = 0, .terminer = 0};
//   char r; //Recommencer la partie ou non

//   grille = initialiser_grille(grille);

//   p.grille = grille;

//   do
//   {
    
//   } while (!p.terminer);
  
//   fin_partie(p);
// }