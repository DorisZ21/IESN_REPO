#include <stdio.h>

#define NB_JOUEURS 3
#define NB_CARACT 5
#define CARACT_MAX 32

double moyenneStat(int[NB_JOUEURS][NB_CARACT], int iCaract);
void afficherMoyenne(int[NB_JOUEURS][NB_CARACT], int iCaract, double moyenne);

void main(void) {

	char libelle[][CARACT_MAX] = {
		"Puissance",
		"Force",
		"Magie",
		"Bouclier",
		"Vitesse"
	};

	int statistiquesJoueurs[NB_JOUEURS][NB_CARACT] = {
		{10,15,20,25,30},
		{2,5,6,4,7},
		{10,12,15,16,17}
	};


}

