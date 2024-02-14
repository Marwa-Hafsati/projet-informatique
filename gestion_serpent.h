#ifndef GESTION_SERPENT_H
#define GESTION_SERPENT_H
#include <stdio.h>
#include <stdlib.h>
#include <graph.h>

#define LARGEUR 20
#define HAUTEUR 20
#define TAILLEX 60
#define TAILLEY 40
#define CYCLE 130000L
#define MAX_TAILLE_ESPACES 100
#define NB_OBSTACLES 10
#define TAILLE_MINIMALE_SERPENT 4 
void dessinerSerpent(int snakeX[2400],int snakeY[2400],int snakeLength);
void effacerSerpent(int snakeX[2400],int snakeY[2400],int snakeLength);
void deplacerSerpent(int snakeX[2400],int snakeY[2400],int*gameOver,int direction,int *pomme, int *pommesPourries,int pommex[5],int pommey[5],int pommePourrieX[10], int pommePourrieY[10], int *snakeLength,int *score );



#endif
