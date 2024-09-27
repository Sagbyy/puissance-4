#include "player.h"
#include <stdio.h>
#include <stdlib.h>

int playerPlay(int playerCross) {
    if (playerCross == 1) {
        printf("Au tour de ❌\n");
    } else {
        printf("Au tour de 🟢\n");
    }

    printf("Entrez la colonne: ");
    int column;
    scanf("%d", &column);

    while(column <0 || column > COLUMN) {
        printf("veuillez saisir un chiffre compris entre 0 et %d : ", COLUMN);
        scanf("%d", &column);
    }

    return column;
}