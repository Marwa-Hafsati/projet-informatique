#include <stdlib.h>
#include<stdio.h>
#include<graph.h>
#include "gestion_serpent.h"


void dessinerSerpent(int snakeX[2400],int snakeY[2400],int snakeLength) {
  int j;
    ChoisirCouleurDessin(CouleurParNom("black"));
    for (j = 0; j < snakeLength; j++) {
        RemplirRectangle(snakeX[j]*LARGEUR, snakeY[j]*HAUTEUR, LARGEUR, HAUTEUR);
    }
}
void effacerSerpent(int snakeX[2400],int snakeY[2400],int snakeLength) {
  int m;
    ChoisirCouleurDessin(CouleurParNom("green"));
    for (m = 0; m < snakeLength; m++) {
        RemplirRectangle(snakeX[m]*LARGEUR, snakeY[m]*HAUTEUR, LARGEUR, HAUTEUR);
    }

}
void deplacerSerpent(int snakeX[2400],int snakeY[2400],int*gameOver,int direction,int *pomme, int *pommesPourries,int pommex[5],int pommey[5],int pommesPourriesX[10], int pommesPourriesY[10], int *snakeLength,int *score) {
  int t;
  int l;
  int p;
  int pp;
  
  int ateApplePourrie=0; 
int ateApple = 0;
 
 char affiche_score[4];
     int nouvelleTeteX = snakeX[0];
      int nouvelleTeteY = snakeY[0];
     
     
 if (direction == XK_Left) {
        nouvelleTeteX -= 1;
    } else if (direction == XK_Right) {
        nouvelleTeteX += 1;
    } else if (direction == XK_Up) {
        nouvelleTeteY -= 1;
    } else if (direction == XK_Down) {
        nouvelleTeteY += 1;
    }
     
    if (nouvelleTeteX <1 || nouvelleTeteX >= TAILLEX || nouvelleTeteY < 1 || nouvelleTeteY >= TAILLEY) {
       *gameOver = 1;
       return;
   }
    for (l= 1; l< *snakeLength; ++l) {
        if (nouvelleTeteX == snakeX[l] && nouvelleTeteY == snakeY[l]) {
            *gameOver = 1;
            return;
        }
    }
   for (pp = 0; pp < 10; pp++) {
    if (nouvelleTeteX == pommesPourriesX[pp] && nouvelleTeteY == pommesPourriesY[pp]) {
        ateApplePourrie = 1;
        pommesPourriesX[pp] = ((rand() % (58) + 1)); 
        pommesPourriesY[pp] = ((rand() % (35) + 1));
        AfficherSprite(*pommesPourries, pommesPourriesX[pp] * LARGEUR, pommesPourriesY[pp] * HAUTEUR);

        if (*snakeLength > 1 && ateApplePourrie) {
            *snakeLength -= 2;
	    
        }
        if (*snakeLength < TAILLE_MINIMALE_SERPENT) {
               
                *gameOver = 1;
            }
    }
}

      
for ( p = 0; p< 5; p++) {
        if (nouvelleTeteX == pommex[p] && nouvelleTeteY == pommey[p]) {
            ateApple = 1;
            pommex[p] = ((rand() % (58)+1)); 
            pommey[p] = ((rand() % (35)+1));
            AfficherSprite(*pomme, pommex[p]*LARGEUR, pommey[p]*HAUTEUR);
	    

        }
     }
 
     if (ateApple) {
        (*snakeLength)++;
        snakeX[*snakeLength - 1] = snakeX[*snakeLength - 2];
        snakeY[*snakeLength - 1] = snakeY[*snakeLength - 2];
		   *score =*score +5;
	    
	    sprintf(affiche_score,"%d",*score);
        
	  ChoisirCouleurDessin(CouleurParNom("black")); 
	    RemplirRectangle(1200,850,100,100);
	     ChoisirCouleurDessin(CouleurParNom("white")); 
	    	 EcrireTexte(1200,870,affiche_score,2);

}
   
      

 for(t=*snakeLength-1;t>0;t--){
   snakeX[t]=snakeX[t-1];
    snakeY[t]=snakeY[t-1];

 }
 snakeX[0]=nouvelleTeteX;
 snakeY[0]=nouvelleTeteY;

 
}
