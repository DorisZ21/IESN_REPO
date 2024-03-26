#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NB_CARACT 50
#define NB_CASES 9

typedef struct objet Objet;
struct objet{
    int reference;
    char nom[NB_CARACT];
    int poids;
};

typedef struct pileObjet PileObjet;
struct pileObjet{
    int reference;
    int nbObjets;
};

typedef struct inventaire Inventaire;
struct inventaire{
    int nbCasesRemplies;
    PileObjet tabCase[NB_CASES];
};

int rechercheIndiceObjet(Objet[],int,int);
void afficheInventaire(Inventaire,Objet[]);
PileObjet obtenirPile(Objet[]);
void ajouterPileInventaire(Inventaire,PileObjet,int);
int rechercheCaseVide(Inventaire,int);

int main() {
    int reference;
    int indiceObjetRecherche;
    Objet objets[NB_CASES] = {
            {117,"arc",1000},
            {135,"epee courte",1000},
            { 57, "fleche", 25 },
            { 10, "torche", 500 },
            { 215, "pelle", 4000 },
            { 202, "grappin", 2000 },
            { 194, "seau", 1000 }
    };

    Inventaire inventaire = {
            4,
            {
                    {117,1},
                    {10,7},
                    {135,1},
                    {57,32}
            }
    };

    printf("Entrez une reference :");
    scanf_s("%d",&reference);

    indiceObjetRecherche = rechercheIndiceObjet(objets,reference,NB_CASES);
    printf("%d",indiceObjetRecherche);
    printf("\n");
    afficheInventaire(inventaire,objets);
}

int rechercheIndiceObjet(Objet objet[],int reference, int nbCases){
    int iObjet = 0;
    while (iObjet < nbCases && objet[iObjet].reference != reference){
        iObjet++;
    }

    if(iObjet == nbCases && objet[iObjet].reference != reference){
        iObjet = -1;
    }

    return iObjet;
}

void afficheInventaire(Inventaire inventaire,Objet objet[]){
    int totalPoids = 0;
    for(int iCase = 0; iCase < inventaire.nbCasesRemplies;iCase++){
        int iObjet = rechercheIndiceObjet(objet,inventaire.tabCase[iCase].reference,NB_CASES);
        totalPoids += objet[iObjet].poids * inventaire.tabCase[iCase].nbObjets;
        printf("%d x %s",inventaire.tabCase[iCase].nbObjets,objet[iObjet].nom);
        printf("\n");
    }

    printf("%d g",totalPoids);
}

PileObjet obtenirPile(Objet objet[]){
    PileObjet nouvPile;
    do {
        printf("Entrez une reference d'objet :");
        scanf_s("%d",&nouvPile.reference);
        printf("\n");
        printf("Entrez le nombre d'objet :");
        scanf_s("%d",&nouvPile.nbObjets);
        printf("\n");
    } while (rechercheIndiceObjet(objet,nouvPile.reference,NB_CASES) != - 1 && nouvPile.nbObjets < 1);

    return nouvPile;
}

int rechercheCaseVide(Inventaire inventaire,int nbCases){
    int iCase = 0;
    while (iCase < nbCases && inventaire.tabCase[iCase].reference != 0){
        iCase++;
    }
    return iCase;
}



void ajouterPileInventaire(Inventaire inventaire, PileObjet pileObjet,int nbCases){
    if(inventaire.nbCasesRemplies < nbCases){
        rechercheCaseVide(inventaire,nbCases);
    }else{
        printf("Inventaire plein !");
    }
}