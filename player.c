#include "player.h"
#include <stdio.h>
#include <stdlib.h>

int playerPlay(int playerCross) {
    system("cls");

    if (playerCross == 1) {
        printf("Au tour de ❌\n");
    } else {
        printf("Au tour de 🟢\n");
    }

    printf("Entrez la colonne: ");
    int column;
    scanf("%d", &column);

    return column;
}