#include <stdio.h>
#include <stdlib.h>
#include "demo.h"
typedef struct {
    int joueur;
    int index;
}Jeton;

void affichage(Jeton **jeton) {
    int sizePlayGround = 194;
    int sizeLine = 7*2;
    int sizeColumn = 6;
    char** map = malloc(sizeLine*sizeof(char*));

    for (int i = 0; i < sizePlayGround; i++) {
        map[i] = malloc(sizeof(char) * sizePlayGround/sizeColumn);
    }

    for(int i = 1; i < sizeColumn +1; i++) {
        for(int j = 0; j < sizeLine; j++) {
            if(j%2 == 0) {
                map[i][j] = '|';
                printf(" %c ",map[i][j]);
            }
            else {
                map[i][j] = ' ';
                printf("%c",map[i][j]);
            }
            if(j == sizeLine -1) {
                printf(" |");
            }
            if(jeton[i][j].joueur != -1 && jeton[i][j].index == j) {
                printf("%c",jeton[i][j].joueur);
            }
        }
        printf("\n");
    }
    for (int i = 0; i < sizePlayGround; i++) {
        free(map[i]);
    }
    free(map);
}
int main(void) {
    Jeton **jeton = malloc(sizeof(Jeton*)*6);
    for (int i = 0; i < 6; i++) {
        jeton[i] = calloc(7,sizeof(Jeton));
        if(i == 5) {
            jeton[5]->joueur = 1;
        }
    }


    affichage(jeton);

    return 0;
}
