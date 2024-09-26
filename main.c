#include <stdio.h>
#include <stdlib.h>
#include "demo.h"
typedef struct {
    char* entré;
    char* plat;
    char* dessert;
}Repas;
int main(void) {
    /*Repas *p = malloc(sizeof(Repas));
    p->entré = "caca";
    p->plat = "caca";
    p->dessert = "caca";
    display();
    printf("Mahamadou aime le %s et le %s et aussi le %s\n",p->dessert, p->dessert,p->plat);*/
    int sizeMap =
    char** map = malloc(sizeof(char*) * 10);
    for(int i = 1; i < 194; i++) {
        if(i % 4 == 0) {
            printf( "|");
        }
        else {
            printf( " ");
        }
        if(i%32 == 0) {
            printf( "\n");
        }
    }
    return 0;
}
