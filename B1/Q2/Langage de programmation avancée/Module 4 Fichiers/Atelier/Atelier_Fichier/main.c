// INCLUDE

#include "stdio.h"
#include "stdbool.h"
#include "string.h"

// CONSTANTES

#define T_NOM 100
#define NB_MOTS_CLES 3
#define T_MOT_CLE 25
#define NB_CARTES_MAX 100
#define FICHIER_CARTE  "cartes.dat"

// STRUCT

typedef struct carte Carte;
struct carte {
    char nom[T_NOM];
    int nbCasesHeuteur;
    int nbCasesLargeur;
    bool officielle;
    char motsCles[NB_MOTS_CLES][T_MOT_CLE];
};

// SIGNATURE

void afficheInfosCarte(Carte carte);
Carte obtenirFiche();
void garnirTab(Carte[NB_CARTES_MAX]);
void afficheCartesTab(Carte[NB_CARTES_MAX]);
void afficheCarteMotCle(Carte[NB_CARTES_MAX], char[T_MOT_CLE]);
void sauverCartes(Carte[], int);
int lireCartes(Carte[]);

// MAIN

void main(void){
    //char motCleRecherche[T_MOT_CLE];
    Carte nouvelleCarte;
    Carte cartes[NB_CARTES_MAX];
    int nbCartes;

    nbCartes = lireCartes(cartes);

    printf("%d",nbCartes);

    if(nbCartes < NB_CARTES_MAX){
        bool fin;
        do {
            nouvelleCarte = obtenirFiche();
            fin = strcmp(nouvelleCarte.nom,"") == 0;
            if(!fin){
                cartes[nbCartes] = nouvelleCarte;
                nbCartes++;
            }
        } while (!fin && nbCartes < NB_CARTES_MAX);

    }

    sauverCartes(cartes,nbCartes);
    /* garnirTab(cartes);
      afficheCartesTab(cartes);

    printf("Entrez un mot cle à rechercher :");
    gets(motCleRecherche);

    afficheCarteMotCle(cartes,motCleRecherche);
    */


}


// FONCTIONS

void garnirTab(Carte cartes[NB_CARTES_MAX]){
    Carte carte;
    int iCarte = 0;
    carte = obtenirFiche();
    while (strcmp(carte.nom,"") != 0 && iCarte < NB_CARTES_MAX){
        cartes[iCarte] = carte;
        iCarte++;
        carte = obtenirFiche();
    }
}

void afficheCartesTab(Carte cartes[NB_CARTES_MAX]){
    int iCarte = 0;
    while(strcmp(cartes[iCarte].nom,"") != 0 && iCarte < NB_CARTES_MAX){
        afficheInfosCarte(cartes[iCarte]);
        iCarte++;
    }
}

Carte obtenirFiche(){
    Carte carte;
    char reponse;

    printf("Entrez le nom de la carte : ");
    gets(carte.nom);
    printf("\n");
    if(strcmp(carte.nom,"") != 0){
        printf("Entrez le nombre de cases en hauteur : ");
        scanf_s("%d",&carte.nbCasesHeuteur);
        printf("\n");
        printf("Entrez le nombre de cases en largeur : ");
        scanf_s("%d",&carte.nbCasesLargeur);
        getchar();
        printf("\n");
        printf("La carte est elle une carte officielle O/N ? ");
        scanf_s("%c",&reponse);
        carte.officielle = reponse == 'O';
        printf("\n");
        for (int iMotCle = 0; iMotCle < NB_MOTS_CLES; iMotCle++){
            printf("Mot cle %d : ", iMotCle);
            scanf_s("%s",carte.motsCles[iMotCle]);
            printf("\n");

        }
        getchar();
    }

    return carte;

}

void afficheInfosCarte(Carte uneCarte){
    printf("Nom : %s",uneCarte.nom);
    printf("\n");
    printf("Nombre de cases en hauteur : %d",uneCarte.nbCasesHeuteur);
    printf("\n");
    printf("Nombre de cases en largeur : %d", uneCarte.nbCasesLargeur);
    printf("\n");
    printf("La carte est t'elle une carte officielle : %s", (uneCarte.officielle) ? "Oui" : "Non");
    printf("\n");
    for(int iMotCle = 0; iMotCle < NB_MOTS_CLES; iMotCle++){
        printf("Mot cle %d : %s",iMotCle + 1,uneCarte.motsCles[iMotCle]);
        printf("\n");
    }
}

void afficheCarteMotCle(Carte cartes[NB_CARTES_MAX], char motCleRecherche[T_MOT_CLE]){
    for(int iCarte = 0; iCarte < NB_CARTES_MAX; iCarte++){
        int iMot = 0;
        while(iMot < NB_MOTS_CLES && strcmp(cartes[iCarte].motsCles[iMot], motCleRecherche) != 0){
            iMot++;
        }
        if(iMot < NB_MOTS_CLES){
            puts(cartes[iCarte].nom);
        }
    }
}

void sauverCartes(Carte cartes[], int nbCartes){
    FILE * ficartes; // Création du pointeur pour le fichier
    fopen_s(&ficartes,FICHIER_CARTE,"wb");

    if(ficartes == NULL){
        printf("Erreur lors de l'ouverture du fichier.\n");
    }else{
        for(int iCarte = 0; iCarte < nbCartes; iCarte++){
            fwrite(&cartes[iCarte],sizeof (Carte),1,ficartes);
        }
        fclose(ficartes);
    }
}

int lireCartes(Carte cartes[]){
    FILE *fiCartes;
    Carte carte;
    int iCarte = 0;

    fopen_s(&fiCartes,FICHIER_CARTE,"rb");

    if(fiCartes == NULL){
        printf("Erreur lors de l'ouverture du fichier.\n");
    }else{
        fread(&carte, sizeof(Carte), 1, fiCartes);

        while (!feof(fiCartes)) {
            cartes[iCarte] = carte;
            iCarte++;
            fread(&carte, sizeof(Carte), 1, fiCartes);
        }
        fclose(fiCartes);
    }

    return iCarte;
}