#include <stdio.h>
#include <stdlib.h>
#include <graph.h>


#include "gestion_chrono.h"
#include "gestion_serpent.h"
#define LARGEUR 20
#define HAUTEUR 20
#define TAILLEX 60
#define TAILLEY 40
#define CYCLE 130000L
#define MAX_TAILLE_ESPACES 100 




void setup(int snakeX[2400],int snakeY[2400],int*gameOver,int*direction, int *pomme,int *pommesPourries, int pommex[5],int pommey[5],int pommesPourriesX[10],int pommesPourriesY[10],int *snakeLength) {
  int ChargerSprite(char *file);
  int i;
  int p;
  int pp;
  unsigned long micros = Microsecondes();

    InitialiserGraphique();
    CreerFenetre(40,40, (TAILLEX+2)*LARGEUR, (TAILLEY+6)*HAUTEUR);
    ChoisirCouleurDessin(CouleurParNom("black"));
    RemplirRectangle(0, 0, (TAILLEX+2)*LARGEUR,  (TAILLEY+6)*HAUTEUR);
    ChoisirCouleurDessin(CouleurParNom("green"));
    RemplirRectangle(HAUTEUR, LARGEUR, TAILLEX*LARGEUR, TAILLEY*HAUTEUR);
  
   for (i = 0; i < *snakeLength; i++) {
    snakeX[i] = TAILLEX/2;
    snakeY[i] = TAILLEY/2  ;
}
     srand(micros);
   *pomme=ChargerSprite("pomme.png");
    for (p = 0; p < 5; p++) {
        pommex[p] = ((rand() % (58)+1));
        pommey[p] = ((rand() % (35)+1));
        AfficherSprite(*pomme, pommex[p]*LARGEUR,pommey[p]*HAUTEUR);
    }
    
			       
srand(micros+1);

    for (pp = 0; pp < 10; pp++) {
      *pommesPourries = ChargerSprite("pomme_pourrie.png");
        pommesPourriesX[pp] = (rand() % 58) + 1;
        pommesPourriesY[pp] = (rand() % 35) + 1;
        AfficherSprite(*pommesPourries, pommesPourriesX[pp] * LARGEUR, pommesPourriesY[pp] * HAUTEUR);
    }

 
}



void attendre(){

    unsigned long suivant = Microsecondes() + CYCLE;

    while (Microsecondes() < suivant) {
        
    }
}


       
    




  
int main() {
   int snakeLength = 4;
    int snakeX[2400];
    int snakeY[2400];
    
    int gameOver = 0;
    int direction = XK_Right;
    
    int pomme;
    int pommesPourries;
    int pommex[5];
    int pommey[5];
    int pommesPourriesX[10];
    int pommesPourriesY[10];
    int jeuEnPausePrecedent = 0;
    unsigned long prochaineMiseAJour = 0;
    int jeuEnPause = 0; 
    unsigned long debutDuJeu = 0;
  

 
   int score = 0;
    int touche;
    
    
    setup( snakeX, snakeY, &gameOver, &direction, &pomme, &pommesPourries, pommex, pommey, pommesPourriesX, pommesPourriesY, &snakeLength);
   debutDuJeu = 0;
   
  debutDuJeu = Microsecondes();
  dessinerSerpent(snakeX, snakeY, snakeLength);

     while (!gameOver) {
     

   
       
       if (ToucheEnAttente()) {
            touche = Touche();
           
            if (touche == XK_Left && direction != XK_Right) {
                direction = XK_Left;
            } else if (touche == XK_Right && direction != XK_Left) {
                direction = XK_Right;
            } else if (touche == XK_Up && direction != XK_Down) {
                direction = XK_Up;
            } else if (touche == XK_Down && direction != XK_Up) {
                direction = XK_Down;
            }else if (touche == XK_Escape) {
                gameOver = 1; 
            }
            else if (touche == XK_space) {
                jeuEnPause = !jeuEnPause; 
               
            if (!jeuEnPause && Microsecondes() > prochaineMiseAJour) {
                 
                ChoisirCouleurDessin(CouleurParNom("green"));
                RemplirRectangle(100, 100, 200, 50);
            }
          }

        }
     

     if (!jeuEnPause) {
     
       effacerSerpent(snakeX, snakeY, snakeLength);
       deplacerSerpent(snakeX, snakeY, &gameOver, direction, &pomme, &pommesPourries, pommex, pommey, pommesPourriesX,  pommesPourriesY, &snakeLength, &score);


	dessinerSerpent(snakeX, snakeY, snakeLength);
   prochaineMiseAJour = Microsecondes() + CYCLE;
   chrono(&debutDuJeu,jeuEnPause);

	}
  if (jeuEnPause) {
            chrono(&debutDuJeu, jeuEnPause);
            ChoisirCouleurDessin(CouleurParNom("white"));
            RemplirRectangle(100, 100, 200, 50);
            ChoisirCouleurDessin(CouleurParNom("black"));
            EcrireTexte(110, 120, "Jeu en pause", 2);

        }
      
        jeuEnPausePrecedent = jeuEnPause;
     
	attendre(CYCLE);
	

        
}
   
       
    FermerGraphique();
    
    return EXIT_SUCCESS;
      }

