#include <stdio.h>
#include <stdlib.h>
#include "demo.h"
#include "player.c"

int main(void) {
    // int sizeMap =
    // char** map = malloc(sizeof(char*) * 10);
    // for(int i = 1; i < 194; i++) {
    //     if(i % 4 == 0) {
    //         printf( "|");
    //     }
    //     else {
    //         printf( " ");
    //     }
    //     if(i%32 == 0) {
    //         printf( "\n");
    //     }
    // }

    // int playerPlaying = 1;

    Player player1 = {
        .id = 1
    };

    Player player2 = {
        .id = 2
    };

    registerPlayer(&player1);
    registerPlayer(&player2);

    playerPlay(&player1);

    return 0;
}
