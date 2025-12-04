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

struct Grille initialiser_cases(struct Grille g)
{
  int i = 0;
  
  for (int y = 1; y <= g.diff.taille; y++)
  {
    for (int x = 1; x <= g.diff.taille; x++)
    {
      g.visible[i].x = x;
      g.visible[i].y = y;
      g.visible[i].val = 0;
      i++;
    }
  }
  
  return g;
}

struct Grille initialiser_grille()
{
  struct Grille g;
  
  // Initialisation de la difficulté
  g.diff = initialiser_difficulte();
  
  g = initialiser_cases(g);

  // afficher_all_case(g);
  
  return g;
}

struct Grille generer_bombe(struct Grille g)
{
  int nbcase = g.diff.taille * g.diff.taille;
  int position, bombe_genereted = 0;

  while(bombe_genereted < g.diff.nb_bombe)
  {
    position = rand() % nbcase;

     if (g.visible[position].val != BOMBE) 
    {
      g.visible[position].val = BOMBE;
      bombe_genereted++;
      // printf("Bombe placée à l'indice %2d (x:%d, y:%d)\n\n", 
      //        position, g.visible[position].x, g.visible[position].y);
    }
  }

  // afficher_all_case(g);

  printf("Nombre de bombes placées : %d\n\n", bombe_genereted);
  return g;
}

struct Case coordonnee_case(int taille)
{
  struct Case case_joueur = {.val = 0};

  do
  {
    printf("Saisissez les coordonnées d'une case du jeu entre 1 et %d\nExemple : x:2 y:1\t|", taille);
    scanf("%d %d", &case_joueur.x, &case_joueur.y);
  } while (case_joueur.x > taille || case_joueur.x < 1 || case_joueur.y > taille || case_joueur.y < 1);
  
  printf("Vous avez saisis les coordonnées ");
  afficher_case(case_joueur);
  
  return case_joueur;
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