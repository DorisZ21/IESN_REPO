#include <stdio.h>
#include <string.h>
// CONSTANTES
#define NB_SYMBOLES 6
#define NB_ADRESSES 5000
#define NB_CARACT 32

void adresseObtenue(int[NB_SYMBOLES], int);
void afficheAdresse(int[NB_SYMBOLES], int);
void remplirAdresse(int[NB_ADRESSES][NB_SYMBOLES], int[NB_ADRESSES], int, int);
void affichePlanetes(int[NB_ADRESSES][NB_SYMBOLES], int[][NB_CARACT], int);

void main(void) {

	char reponse;
	int adresse[NB_SYMBOLES];
	int adresseSG[NB_ADRESSES][NB_SYMBOLES];
	char noms[NB_ADRESSES][NB_CARACT];

	int iAdresse = 0;
	do {
		adresseObtenue(adresse, NB_SYMBOLES);
		afficheAdresse(adresse, NB_SYMBOLES);
		printf("\n");
		printf("Entrez un nom pour votre planete.");
		scanf_s("%s", noms[iAdresse], NB_CARACT);
		getchar();
		remplirAdresse(adresseSG, adresse, NB_SYMBOLES, iAdresse);
		printf("\n");
		printf("Avez vous visite une autre planete ?");
		scanf_s("%c", &reponse, 1);
		getchar();
		printf("%c", reponse);
		iAdresse++;
	} while (reponse == 'O');


}

void adresseObtenue(int adresse[NB_SYMBOLES], int nbSymboles) {
	for (int iSymbole = 0; iSymbole < nbSymboles; iSymbole++) {
		printf("Entrez un symbole : ");
		scanf_s("%d", &adresse[iSymbole]);
	}
	getchar();
}

void afficheAdresse(int adresse[NB_SYMBOLES], int nbSymboles) {
	for (int iSymbole = 0; iSymbole < nbSymboles; iSymbole++) {
		printf("%2d ", adresse[iSymbole]);
	}
}

void remplirAdresse(int adresseSG[NB_ADRESSES][NB_SYMBOLES], int adresse[NB_SYMBOLES], int nbSymboles, int iAdresse) {
	for (int iSymbole = 0; iSymbole < nbSymboles; iSymbole++) {
		adresseSG[iAdresse][iSymbole] = adresse[iSymbole];
	}
}


void affichePlanetes(int adresseSG[NB_ADRESSES][NB_SYMBOLES], int noms[][NB_CARACT], int nbPlanetes) {
	
}

