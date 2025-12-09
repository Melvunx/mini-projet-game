    ============================================================
      Le Démineur | Déminer un plateau en evitant les bombes !
    ============================================================

Programmeur : Melvin Augustine

|DESCRIPTION DU JEU
| "Le Démineur" consiste a déminer des cases d'un plateau sans tomber sur une bombe.
| Pour gagner, il faut déminer toutes les cases du plateau sans que les bombes explosent.
| Il y a 3 niveaux de difficulté qui augmentent le nombre de bombe à éviter ainsi que le nombre de case à déminer.
| Plus la difficultée est élevée, moins il sera facile d'éviter une bombe !
|  
| Pour vous aidez, il existe 3 bonus dans le jeu qui facilite votre déminage :
|  
| - Le bouclier anti-bombe : '@'
| - Le détecteur aguérri : '¤'
| - La safe place* : '+'
|  
| * la zone sûr

|INSTALLATION
| Dézipper les programmes de Demineur.
| Dans un terminal Linux/Unix, se placer dans le répertoire du jeu et tapper les commandes :
| $ gcc Demineur.c Grille.c Affichier.c -o Demineur
| $ .\Demineur

|COMMENT JOUER
| Lancer les commandes ci-dessus
| Le jeu vous propose de choisir entre 3 niveaux de difficultée
| Saisissez les coordonnées d'une case /!\ Attention ! les coordonnées de x et y commencent par 1! non par 0
| Les lignes sont représentées par y et les colonnes par x
| Qaund vous terminer votre partie, vous pouvez rejouer ou quitter le programme.

|DESCRIPTION DU GENERATEUR D'INSTANCES
| Les instances sont générées au début de chaque partie.
| Les bombes, 'o', sont générées aléatoirement dans la grille et les cases proches, '\_', sont générées à proximitée des bombes.
| Les bonus , '@', '¤', '+', sont générées aléatoirement sur une case vide, '□'.
| Chaque case est invisible pour le joueur, '#', à chaque déminage la case deviens visible.
| En fonction de la valeur de la case, une action est faite pour déterminer la nature de la case.

|DETAILS IMPORTANT
| Le jeu peut encore être amélioré en ajoutant un système de "drapeau" comme dans le jeu original.
| N'oubliez pas de bien saisir 2 coordonnées (et non pas 1) sous peine de casser le jeu et
| vous devrez le redémarer. Ce qui signifie que vous allez perdre votre partie en cours

|DIFFICULTEES RENCONTREES ET PLAISIR D'AVOIR CODER CE JEU
| J'ai rencontré quelques difficultées dans la génération des bombes et des cases proches des bombes.
| Notamment lors de l'attribution des cases à proximitées des bombes.
|
| Le rendu final et l'affichage du jeu correspond à mes attentes.
| Le jeu peut encore être optimiser pour qu'il ne soit pas trop frustrant mais je pense que les niveaux
| sont assez équilibrés.
