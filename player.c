#include "player.h"
#include <stdio.h>
#include <stdlib.h>

int playerPlay(int playerCross, TableSize *tableSize) {
    if (playerCross == 1) {
        printf("Au tour de ❌\n");
    } else {
        printf("Au tour de 🟢\n");
    }

    printf("Entrez la colonne: ");

    char value[100];
    int res;

    do {
        printf("Veuillez saisir un chiffre compris entre 1 et %d : ", tableSize->column);
        fgets(value, 100, stdin);
        res = atoi(value);
    } while(!(res !=0 && res > 0 && res <= tableSize->column));

    return res;
}