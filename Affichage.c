#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Affichage.h"
#include "Game.h"

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

char cases_proche[MAX_MESSAGE][TAILLE_MESSAGE] = {
  "Attention, une bombe est proche !\n", 
  "Aïe\n on a eu chaud !\n", 
  "Cela passe sur le fil !\n", 
  "Vous avez les mains moitent non ?\n", 
  "Contrôlez vos angles morts !\nVous êtes proche d'une bombe\n"
};

char cases_bonus[MAX_MESSAGE][TAILLE_MESSAGE] = {
  "Un bonus à été trouvé !\n", 
  "Olala un bonus !\n", 
  "Attention !\nUn bonus sauvage apparaît !\n", 
  "Bonuuuuuuuus !\n", 
  "Bonus débloquer !!\n"
};

void afficher_bonus()
{
  for (int i = 0; i < NB_TYPES_BONUS; i++)
  {
    printf(
      "Bonus n°%d \n\t* %s *\n\t%s\n",
      i + 1,
      BONUS_DISPONIBLES[i].nom,
      BONUS_DISPONIBLES[i].effet
    );
  }
}

void explication_jeu()
{
  printf("\n");
  printf("\t\t\t***************************\n");
  printf("\t\t\t*     ¤ Le Démineur ¤     *\n");
  printf("\t\t\t***************************\n\n\n");

  sleep(2);

  printf("\t\t\t\t\t\t$ By Melvunx $\n\n");

  sleep(2);

  printf("RÈGLES DU JEU :\n");
  printf("   → Déminez toutes les cases du plateau sans tomber sur une bombe\n");
  printf("   → Trois niveaux de difficulté : Facile, Moyen et Difficile\n");
  printf("   → Plus le niveau est élevé, plus il y a de bombes !\n");
  printf("   → Vous avez une petite chance d'esquiver une bombe (selon la difficulté)\n\n");
  sleep(4);

  printf("BONUS DISPONIBLES : %d types\n\n", NB_TYPES_BONUS);
  printf("════════════════════════════════════════════════════════════════════════════\n");
  afficher_bonus();
  printf("════════════════════════════════════════════════════════════════════════════\n\n");
  sleep(4);
  
  printf("COMMENT JOUER ?\n");
  printf("   → Saisissez les coordonnées de la case à déminer (ligne, colonne)\n");
  printf("   → Utilisez vos bonus stratégiquement pour maximiser vos chances\n");
  printf("   → Faites attention aux indices révélés sur le plateau\n\n");
  sleep(3);

  printf("Conseil : Commencez par les coins, c'est souvent plus sûr !\n\n");

  printf("════════════════════════════════════════════════════════════════════════════\n");
  printf("                    Bonne chance et amusez-vous bien !\n");
  printf("════════════════════════════════════════════════════════════════════════════\n\n");
  sleep(2);

  printf("Appuyez sur Entrée pour commencer...");
  getchar(); // Attend que l'utilisateur appuie sur Entrée
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

void afficher_difficulte(struct Difficulte diff)
{
  printf("\nVotre difficulté est : %s\n\n", diff.niveau);
}

void afficher_val_cases(struct Case c)
{
  if (!c.visible) printf("#");

  else {
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

    case BONUS:
      switch (c.index_bonus)
      {
      case DETECTEUR:
        printf("¤");
        break;

      case CASE_SUR:
        printf("+");
        break;

      case ESQUIVE:
        printf("@");
        break;
      
      // index_bonus == -1
      default:
        printf("□");
        break;
      }
    }
  }
}

void afficher_case(struct Case c)
{
  printf("(x:%d; y:%d)\n", c.x, c.y);
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

void recapitulatif_partie(struct Statistique stat)
{
  printf("\n");
  printf("\t\t*************************\n");
  printf("\t\t*     Récapitulatif     *\n");
  printf("\t\t*************************\n\n");

  printf(
    "\nscore total : %2d/%2d\n\nNombre de bonus trouvé : %2d\n\nNombre de partie joué : %2d\n\n", 
    stat.total_score,
    stat.max_score,
    stat.nb_bonus, 
    stat.nb_partie
  );

}

void afficher_toutes_case(struct Grille g)
{
  int nbcases = g.diff.taille * g.diff.taille;
  struct Case c;
  for (int i = 0; i < nbcases; i++)
  {
    c = g.plateau[i];
    printf("Case n° = %2d | x:%d y:%d val:%2d | visible:%d | bonus:%2d |\n", 
      i + 1, c.x, c.y, c.val, c.visible, c.index_bonus);
  }
}