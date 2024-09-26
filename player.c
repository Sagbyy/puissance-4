#include "player.h"
#include <stdio.h>
#include <stdlib.h>

void registerPlayer(Player* player) {
    printf("Joueur %d, entrez votre nom: ", player->id);
    scanf("%s", player->name);
    printf("Bienvenue %s !\n", player->name);
}

int *playerPlay(Player* player) {
    printf("%s, à vous de jouer !\n", player->name);

    printf("Entrez la ligne où vous voulez placer votre jeton: ");
    int line;
    scanf("%d", &line);

    printf("\r\033[K");
    printf("Entrez la colonne où vous voulez placer votre jeton: ");
    int column;
    scanf("%d", &column);

    int *position = malloc(sizeof(int) * 2);

    position[0] = line;
    position[1] = column;

    printf("\33[2K\r");
    printf("Vous avez placé votre jeton en ligne : %d et colonne : %d\n", line, column);

    return position;
}