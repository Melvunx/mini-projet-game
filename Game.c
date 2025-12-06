#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Game.h"
#include "Affichage.h"

struct Bonus BONUS_DISPONIBLES[NB_TYPES_BONUS] = {
  {
    .nom = "Détecteur aguérri",
    .effet = "Révèle une bombe aléatoire dans la grille !",
    .action = AFFICHE_BOMBE
  },
  {
    .nom = "Safe place",
    .effet = "Révèle une case sûre dans la grille !",
    .action = AFFICHE_CASE
  },
  {
    .nom = "Bouclier anti-bombe",
    .effet = "Protection contre la prochaine bombe !",
    .action = BOUCLIER
  }
};

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
    d.nb_bonus = 1;
    d.esquive = 10;
    break;
    
    case DIFF_MID:
    strcpy(d.niveau, "Moyen");
    d.taille = 5;
    d.nb_bonus = 2;
    d.nb_bombe = 8;
    d.esquive = 5;
    break;
    
    case DIFF_HARD:
    strcpy(d.niveau, "Difficle");
    d.taille = 6;
    d.nb_bonus = 3;
    d.nb_bombe = 12;
    d.esquive = 0;
    break;
    
    default:
    strcpy(d.niveau, "facile");
    d.taille = 4;
    d.nb_bombe = 5;
    d.nb_bonus = 1;
    d.esquive = 10;
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
      g.plateau[i].index_bonus = -1;
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
  bombe_generee = 0;
  int position;
  

  while(bombe_generee < g.diff.nb_bombe)
  {
    position = rand() % nbcase;

    if (g.plateau[position].val != BOMBE) 
    {
      g.plateau[position].val = BOMBE;

      g = detecter_bombe_proche(g, position);

      bombe_generee++;
    }
  }

  printf("\nNombre de bombes placées : %d\n\n", bombe_generee);
  return g;
}

struct Grille generer_bonus(struct Grille g)
{
  int nbcase = g.diff.taille * g.diff.taille, 
  bonus_genere = 0;
  int position;

  while (bonus_genere < g.diff.nb_bonus)
  {
    position = rand() % nbcase;

    if (g.plateau[position].val == VIDE)
    {
      g.plateau[position].val = BONUS;
      g.plateau[position].index_bonus = rand() % NB_TYPES_BONUS;
      bonus_genere++;
    }
  }

  printf("\nNombre de bonus placés : %d\n\n", bonus_genere);

  return g;
}

struct Grille reveler_bombe(struct Grille g)
{
  int nbcases = g.diff.taille * g.diff.taille;
  int bombes_cachees[MAX_CASE];
  int nb_bombes_cachees = 0;

  for (int i = 0; i < nbcases; i++)
  {
    if (g.plateau[i].val == BOMBE && g.plateau[i].visible == 0)
    {
      bombes_cachees[nb_bombes_cachees] = i;
      nb_bombes_cachees++;
    }
  }

  if (nb_bombes_cachees > 0)
  {
    int index = rand() % nb_bombes_cachees;
    int position = bombes_cachees[index];
    g.plateau[position].visible = 1;

    printf("Bombe révélée en (%d; %d) !\n", g.plateau[position].x, g.plateau[position].y);
  }

  else printf("Aucune bombe cachée à révéler.\n");

}

struct Grille reveler_case_sure(struct Grille g)
{
  int nbcases = g.diff.taille * g.diff.taille;
  int case_sures[MAX_CASE];
  int nbcases_sures = 0;

  for (int i = 0; i < nbcases; i++)
  {
    if ((g.plateau[i].val == VIDE || g.plateau[i].val == PROCHE) && g.plateau[i].visible == 0)
    {
      case_sures[nbcases_sures] = i;
      nbcases_sures++;
    }
  }

  if (nbcases_sures > 0)
  {
    int index = rand() % nbcases_sures;
    int position = case_sures[index];
    g.plateau[position].visible = 1;

    printf("Case sûre révélée en (%d; %d) !\n", g.plateau[position].x, g.plateau[position].y);
  }

  else printf("Aucune case sûre à révéler.\n");
}

struct Grille activer_bonus(struct Partie p, struct Bonus bonus)
{
  switch (bonus.action)
  {
  case AFFICHE_BOMBE:
    p.grille = reveler_bombe(p.grille);
    break;
  
  case AFFICHE_CASE:
    p.grille = reveler_case_sure(p.grille);
    break;

  case BOUCLIER:
    p.grille.diff.esquive += 100; // 100% d'esquive pour le prochain déminage
    printf("\nVous êtes protégé contre la prochaine bombe !\n\n");
    break;
  }

  p.bonus_trouve++;
  return p.grille;
}

struct Case coordonnee_case(int taille)
{
  struct Case case_joueur = {.val = VIDE, .index_bonus = -1, .visible = 1};

  do
  {
    printf("Saisissez les coordonnées d'une case du jeu entre 1 et %d\nExemple : x:2 y:1\n|", taille);
    scanf("%d %d", &case_joueur.x, &case_joueur.y);
  } while (case_joueur.x > taille || case_joueur.x < 1 || case_joueur.y > taille || case_joueur.y < 1);
  
  printf("\nVous avez saisis les coordonnées ");
  afficher_case(case_joueur);
  
  return case_joueur;
}

struct Partie action_case(struct Partie p, int position)
{
  struct Case case_actuelle = p.grille.plateau[position];
  int esquive_bombe = (rand() % POURCENT) + 1;

  switch (case_actuelle.val)
  {
    case VIDE:
      p.score++;
      printf("%s\n", cases_vide[rand() % MAX_MESSAGE]);
      break;

    case BOMBE:
      if (p.grille.diff.esquive >= 100)
      {
        printf("\n\nBouclier activé !\nVous avez esquivé la bombe !\n\n");
        p.grille.diff.esquive -= 100; // Consommation du bouclier
      }
      else if (p.grille.diff.esquive >= esquive_bombe)
      {
        printf("\n\nOn a eu chaud !\nVous avez esquivé la bombe !\n\n");
      }
      else {
        printf("%s\n", cases_bombe[rand() % MAX_MESSAGE]);
        p.terminer = 1;
        p.stat = DEFAITE;
      }
      break;

    case PROCHE:
      p.score++;
      printf("%s\n", cases_proche[rand() % MAX_MESSAGE]);
      break;

    case BONUS:
      if (case_actuelle.index_bonus != -1) 
      {
        p.grille = activer_bonus(p, BONUS_DISPONIBLES[case_actuelle.index_bonus]);

        printf("%s\n\n"
          "*********************\n"
          "%s\n"
          "%s\n"
          "*********************\n", 
          cases_bonus[rand() % MAX_MESSAGE], 
          BONUS_DISPONIBLES[case_actuelle.index_bonus].nom,
          BONUS_DISPONIBLES[case_actuelle.index_bonus].effet
        );

        p.score++;
      }
      break;
  }
  return p;
}

struct Partie deminer_case(struct Partie p)
{
  int taille = p.grille.diff.taille;
  struct Case case_joueur = coordonnee_case(taille);

  int position = rechercher_case(p.grille, case_joueur),
  case_vide = (taille * taille) - p.grille.diff.nb_bombe;

  p.grille.plateau[position].visible = case_joueur.visible;

  p = action_case(p, position);
  
  if (p.score == case_vide) 
  {
    p.terminer = 1;
    p.stat = VICTOIRE;
  }
  
  printf("\n");
  return p;
}

struct Partie commencer_partie()
{
  struct Partie p = {.score = 0, .terminer = 0, .bonus_trouve = 0,.stat = INDETERMINE};

  p.grille = initialiser_grille(p.grille);

  p.grille = generer_bombes(p.grille);

  p.grille = generer_bonus(p.grille);

  do
  {
    afficher_score(p);
    printf("\n");
    afficher_grille(p.grille);
    p = deminer_case(p);
    printf("\n");
  } while (!p.terminer);
  
  fin_partie(p);

  return p;
}