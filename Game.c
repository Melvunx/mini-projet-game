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
      "| Niveau facile : %d | Niveau moyen : %d | Niveau difficile : %d |\n",
      DIFF_EASY, DIFF_MID, DIFF_HARD
    );
    
    scanf("%d", &player_choice);
  } while (player_choice > 3 || player_choice < 0);
  
  switch (player_choice)
  {
    case DIFF_EASY:
    strcpy(d.niveau, "Facile");
    d.taille = 4;
    d.nb_bombe = 5;
    break;
    
    case DIFF_MID:
    strcpy(d.niveau, "Moyen");
    d.taille = 5;
    d.nb_bombe = 8;
    break;
    
    case DIFF_HARD:
    strcpy(d.niveau, "Difficle");
    d.taille = 6;
    d.nb_bombe = 12;
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
      g.plateau[i].x = x;
      g.plateau[i].y = y;
      g.plateau[i].val = 0;
      g.plateau[i].visible = 0;
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
  
  return g;
}

int rechercher_case(struct Grille g, struct Case c)
{
  int nbcase = g.diff.taille * g.diff.taille;

  for (int i = 0; i < nbcase; i++)
  {
    if (g.plateau[i].x == c.x && g.plateau[i].y == c.y) return i;
  }
  return -1;
}

struct Grille detecter_bombe_proche(struct Grille g, int position)
{
  int taille = g.diff.taille,
  // Coordonnée de la case sélectionnée
  x = position % taille,
  y = position / taille;

  // On verifie la case à gauche si elle n'est pas au bord gauche de la grille
  if (x > 0)
  {
    int index_gauche = y * taille + (x - 1);
    
    if (g.plateau[index_gauche].val == VIDE)
    g.plateau[index_gauche].val = PROCHE;
  }
  
  // On verifie la case à droite si elle n'est pas au bord droit de la grille
  if (x < taille - 1)
  {
    int index_droite = y * taille + (x + 1);

    if (g.plateau[index_droite].val == VIDE)
      g.plateau[index_droite].val = PROCHE;
  }

  return g;
}

struct Grille generer_bombes(struct Grille g)
{
  int nbcase = g.diff.taille * g.diff.taille, 
  bombe_genereted = 0;
  int position;
  

  while(bombe_genereted < g.diff.nb_bombe)
  {
    position = rand() % nbcase;

     if (g.plateau[position].val != BOMBE) 
    {
      g.plateau[position].val = BOMBE;

      g = detecter_bombe_proche(g, position);

      bombe_genereted++;
    }
  }

  printf("\nNombre de bombes placées : %d\n\n", bombe_genereted);
  return g;
}

struct Case coordonnee_case(int taille)
{
  struct Case case_joueur = {.val = VIDE, .visible = 1};

  do
  {
    printf("Saisissez les coordonnées d'une case du jeu entre 1 et %d\nExemple : x:2 y:1\n|", taille);
    scanf("%d %d", &case_joueur.x, &case_joueur.y);
  } while (case_joueur.x > taille || case_joueur.x < 1 || case_joueur.y > taille || case_joueur.y < 1);
  
  printf("Vous avez saisis les coordonnées ");
  afficher_case(case_joueur);
  
  return case_joueur;
}


struct Partie deminer_case(struct Partie p)
{
  int taille = p.grille.diff.taille;
  struct Case case_joueur = coordonnee_case(taille);
  int position = rechercher_case(p.grille, case_joueur);
  int case_vide = (taille * taille) - p.grille.diff.nb_bombe;

  p.grille.plateau[position].visible = case_joueur.visible;

  if (p.grille.plateau[position].val == VIDE || p.grille.plateau[position].val == PROCHE) p.score++;
  else 
  {
    p.terminer = 1;
    p.stat = DEFAITE;
  }
  
  if (p.score == case_vide) 
  {
    p.terminer = 1;
    p.stat = VICTOIRE;
  }

  
  printf("\n");
  afficher_deminage(p.grille.plateau[position].val);
  
  // p.grille = detecter_bombe_proche(p.grille, position);
  return p;
}

void commencer_partie()
{
  struct Partie p = {.score = 0, .terminer = 0, .stat = INDETERMINE};

  p.grille = initialiser_grille(p.grille);

  p.grille = generer_bombes(p.grille);

  afficher_all_case(p.grille);

  do
  {
    afficher_score(p);
    printf("\n");
    afficher_grille(p.grille);
    p = deminer_case(p);
    printf("\n");
  } while (!p.terminer);
  
  fin_partie(p);
}