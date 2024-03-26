#include <stdio.h>

#define NB_PERSOS 3
#define NB_CARACTERISTIQUE 6
#define NB_CHARMAX 13



void afficherobtenirNumPersoNumCaractValide(int[NB_PERSOS][NB_CARACTERISTIQUE]);
void afficherCaractPerso(int[NB_PERSOS][NB_CARACTERISTIQUE]);


void main(void) {

	int numPerso;
	
	char libelleCaracteristique[][NB_CHARMAX] = {
		"force","dexterite","constitution","intelligence","sagesse","charisme"
	};


	int caracteristiquePersos[NB_PERSOS][NB_CARACTERISTIQUE] = {
		{8,14,12,10,13,18},
		{16,16,12,13,8,10},
		{13,8,14,10,18,12}
	};

	caracteristiquePersos[1][4] = 10;

	afficherobtenirNumPersoNumCaractValide(caracteristiquePersos);
	printf("\n");
	afficherCaractPerso(caracteristiquePersos);
}



void afficherobtenirNumPersoNumCaractValide(int caracteristiquePersos[NB_PERSOS][NB_CARACTERISTIQUE]) {
	int iPerso;
	int iCaract;

	do {
		printf("Entrez un numero de perso :");
		scanf_s("%d", &iPerso);
		printf("Entrez un numero de caract :");
		scanf_s("%d", &iCaract);
	
	}while ( iPerso > NB_PERSOS || iCaract > NB_CARACTERISTIQUE);

	printf("%d", caracteristiquePersos[iPerso - 1][iCaract - 1]);
}

void afficherCaractPerso(int caracteristiquePersos[NB_PERSOS][NB_CARACTERISTIQUE]) {
	for (int iPersonnage = 0; iPersonnage < NB_PERSOS; iPersonnage++) {
		printf("Personnage : %d", iPersonnage+1);
		for (int iCaract = 0; iCaract < NB_CARACTERISTIQUE; iCaract++) {
			printf("\t%d", caracteristiquePersos[iPersonnage][iCaract]);
		}
	}
}