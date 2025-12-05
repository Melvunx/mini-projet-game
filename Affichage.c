#include <stdio.h>
#include <stdlib.h>
#include "Affichage.h"
#include "Game.h"

// Faire un switch pour séparer les cas
void afficher_val_cases(struct Case c)
{
  // if (!c.visible) printf("#");

  // else {
    switch (c.val)
    {
    case VIDE:
      printf("□");
      break;

    case BOMBE:
      printf("o");
      break;

    case PROCHE:
      printf("_");
      break;

    default:
      printf("#");
      break;
    // }
  }
}

void afficher_grille(struct Grille g)
{
  int i = 0;
  
  printf("\n");
  for (int y = 1; y <= g.diff.taille; y++)
  {
    for (int x = 1; x <= g.diff.taille; x++)
    {
      if ((g.plateau[i].y == y) && (g.plateau[i].x == x))
      {
        afficher_val_cases(g.plateau[i]);
        i++;
      }
    }
    printf("\n");
  }
  printf("\n");
}

void afficher_case(struct Case c)
{
  printf("(x:%d ; y:%d)\n", c.x, c.y);
}

void afficher_all_case(struct Grille g)
{
  int nbcases = g.diff.taille * g.diff.taille;
  for (int i = 0; i < nbcases; i++)
  {
    printf("Case n° = %2d | x:%d y:%d val:%2d |\n", 
      i + 1, g.plateau[i].x, g.plateau[i].y, g.plateau[i].val);
  }
}

void afficher_deminage(int val)
{
  char cases_vide[MAX_MESSAGE][TAILLE_MESSAGE] = {
    "Ouf c'est une case vide !\n",
    "Une case vide !\n",
    "Yes !!\nUne case vide\n",
    "Oh...\nUne case vide \n",
    "Une\nCase\nVide\n"
  };

  char cases_bombe[MAX_MESSAGE][TAILLE_MESSAGE] = {
    "Oh...\nUne bombe :'(\n",
    "Une bombe...\n",
    "Et c'est la bombe\n",
    "Une bombe sauvage est apparu !\n",
    "KABOOM !!!!\n"
  };

  // char cases_bonus[MAX_MESSAGE][TAILLE_MESSAGE] = {"\n", "\n", "\n", "\n", "\n"};

    switch (val)
  {
  case VIDE:
    printf("%s\n", cases_vide[rand() % MAX_MESSAGE]);
    break;
    
    case BOMBE:
    printf("%s\n", cases_bombe[rand() % MAX_MESSAGE]);
    break;
  
  default:
    break;
  }
}

void afficher_score(struct Partie p)
{
  printf(
    "************\n"
    "score = %2d\n"
    "************\n",
    p.score);
}

void afficher_bombes(struct Grille g)
{
  int nbcases = g.diff.taille * g.diff.taille;

  for (int i = 0; i < nbcases; i++)
  {
    if (g.plateau[i].val == BOMBE && g.plateau[i].visible == 0)
      g.plateau[i].visible = 1;
  }

  afficher_grille(g);
}

void fin_partie(struct Partie p)
{
  int nbcases = p.grille.diff.taille * p.grille.diff.taille;
  int case_vide = nbcases - p.grille.diff.nb_bombe;

  
  switch (p.stat)
  {
    case DEFAITE:
    afficher_bombes(p.grille);
    printf("Dommage !\nVous avez perdu!\nVotre score : %2d/%2d\n", p.score, case_vide);
    break;
    
    case VICTOIRE:
    afficher_grille(p.grille);
    printf("Bravo vous avez réussi !\n %2d/%2d !\n", p.score, p.score);
    break;
  
  default:
    printf("Vous êtes toujours en jeu ou bien ?\n");
    break;
  }
}