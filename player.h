typedef struct {
    char name[20];
    int id;
} Player;

void registerPlayer(Player *player);

/**
 * Cette fonction prend un joueur en paramètre et lui demande de jouer.
 *
 * @return un tableau de deux entiers représentant la ligne et la colonne où le joueur veut placer son jeton. 
 * @note [ligne, colonne]
 */
int *playerPlay(Player *player);