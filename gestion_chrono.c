#include <stdlib.h>
#include <stdio.h>
#include <graph.h>

#include "gestion_chrono.h"




void chrono(unsigned long *debutDuJeu, int jeuEnPause) {
    static unsigned long dernierTemps = 0;
     unsigned long tempsEnPause = 0; /* Variable pour stocker le temps écoulé pendant la pause */
   
    unsigned long maintenant = Microsecondes();
    unsigned long tempsEcoule = maintenant - dernierTemps;
    /* Calcul du temps total écoulé (en prenant en compte le temps passé en pause) */
    unsigned long tempsTotal;
    /* Conversion en minutes et secondes */
    unsigned long minutes;
    unsigned long secondes;

    int taillePolice = 2;
    char tempsTexte[20];
    int xTexte = 70;
    int yTexte = 60 + 800;

    if (*debutDuJeu == 0) {
        *debutDuJeu = maintenant;
        dernierTemps = maintenant;
    }

    if (!jeuEnPause) {
      tempsTotal = (maintenant - *debutDuJeu - tempsEnPause) / 1000000;
       minutes = tempsTotal / 60;
        secondes = tempsTotal % 60;

        if (maintenant - dernierTemps >= CYCLE) {
            ChoisirEcran(0);
            ChoisirCouleurDessin(CouleurParNom("black"));

            /* Formater le texte pour l'affichage */
            snprintf(tempsTexte, sizeof(tempsTexte), "Temps: %02lu:%02lu", minutes, secondes);

            RemplirRectangle(0, 840, 250, 800);
            ChoisirCouleurDessin(CouleurParComposante(255, 255, 255));
            EcrireTexte(xTexte, yTexte, tempsTexte, taillePolice);
            dernierTemps = maintenant;
        }
    } else {
        /* Si le jeu est en pause, ajuster le temps de pause pour éviter les erreurs d'affichage */
       dernierTemps = maintenant;
        
	jeuEnPause = 0;

        /* Réinitialiser le dernier temps pour éviter les écarts de temps après la pause */

    }
}

