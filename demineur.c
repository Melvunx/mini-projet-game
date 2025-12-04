#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Affichage.h"
#include "Game.h"

int main() {

  srand(time(NULL)); //Initialisation du rand
  char r;
do
{
  r = commencer_partie();
} while (r != 'n' || r != 'N');

  

  return 0;
}
