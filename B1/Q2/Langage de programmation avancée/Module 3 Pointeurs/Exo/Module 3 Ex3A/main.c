#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define NB_REELS 25
#define NB_CARACT 25
#define NB_CARACT_NOM 50
#define NB_CARACT_DATE 15

typedef struct etudiant Etudiant;
struct etudiant{
    char nom[NB_CARACT_NOM];
    char date[NB_CARACT_DATE];
    Etudiant* pSuiv;
};



void echangeDeuxReels (double*, double*);

void main(void){
    double centiemes[NB_REELS];
    double* pCentieme = centiemes;
    int i;
    for(i = 0 ; i < NB_REELS ; i++){
        centiemes[i] = (double)i/100;
    }

    // pointé vers la 3ème cell du tab
    pCentieme += 2;
    printf("%.2lf",*pCentieme);

    printf("\n");

    // pointé vers la 6ème cell du tab en partant de la troisième (indice 2)
    pCentieme += 3;
    printf("%.2lf",*pCentieme);

    printf("\n");

    // ajouter 1 à la valeur de la 6ème cell du tab à partir du pointeur
    *pCentieme += 1;
    printf("%.2lf",*pCentieme);

    printf("\n");

    // ajouter 4 à la valeur de la 6ème cell du tab à partir du pointeur
    *pCentieme += 4;
    printf("%.2lf",*pCentieme);

    int entiers[] = {12, 23, 34, 45, 56, 67, 78};
    int *pEntier = entiers;
    printf("\n");
    printf("%d\n", *pEntier); // 12
    printf("%d\n", *++pEntier); // 23
    printf("%d\n", *(pEntier+3)); // 56
    printf("%d\n", *pEntier--); // 23
    printf("%d\n", --*pEntier); // 11

    int multiples100[ ] = { 100, 200, 300, 400, 500, 600 };
    int *pMultiples100 = multiples100 + 2;

    printf("%d\n", *pMultiples100); // 300
    printf("%p\n", pMultiples100); // L’adresse de la 3ème cell
    printf("%d\n", *++pMultiples100); // 400
    printf("%d\n", *(pMultiples100 - 1)); // 300
    printf("%d\n", *pMultiples100 + 70); // 470
    printf("%d\n", --*pMultiples100); // 399
    printf("%d\n", *--pMultiples100); // 300


    char option[] = "Informatique";
    char *pOption = option;
    char caract;

    caract = *(pOption + 3); // ‘o’
    printf("%c\n",caract);
    caract = *++pOption; // ‘n’
    printf("%c\n",caract);
    caract = *pOption++; // ‘n’
    printf("%c\n",caract);
    caract = ++(*pOption); // ‘g’
    printf("%c\n",caract);
    puts(option);



    double nombre1 = 100.5;
    double nombre2 = 20.3;
    // Passage en paramètre de l'adresse mémoire de nombre 1 et de nombre 2
    echangeDeuxReels(&nombre1,&nombre2);
    printf("nombre1 vaut %.1f, nombre2 vaut %.1f", nombre1, nombre2);


    char string[NB_CARACT];
    char* pSection;

    pSection = malloc(sizeof(char) * NB_CARACT);
    printf("\n%p\n", pSection);
    pSection = string;
    printf("%p", pSection);
    printf("\n");
    printf("%p",&string);
    strcpy(pSection,"Informatique de gestion");

    printf("\n");
    puts(pSection);

    printf("\n");
    printf("%c",pSection[0]);

    bool espaceDispo,fin;
    Etudiant* pDebEtudiant = NULL;

    do {
        Etudiant* pNouvEtudiant = malloc(sizeof(Etudiant));
        espaceDispo = pNouvEtudiant != NULL;
        if(espaceDispo){
            printf("\n");
            printf("Entrez le nom de l etudiant :");
            gets(pNouvEtudiant->nom);
            printf("\n");
            printf("Entrez la date de naissance de l etudiant (AAAAMMJJ) :");
            gets(pNouvEtudiant->date);
            fin = strcmp(pNouvEtudiant->nom,"") == 0;

            if(pDebEtudiant == NULL){
                pDebEtudiant = pNouvEtudiant;
                pDebEtudiant->pSuiv = NULL;
            }else{
                pNouvEtudiant->pSuiv = pDebEtudiant;
                pDebEtudiant = pNouvEtudiant;
            }

        }else{
            printf("\nplace memoire insufisante !");
        }
    } while (espaceDispo && !fin);


    puts(pDebEtudiant->nom);

}

void echangeDeuxReels (double* pNombre1, double* pNombre2)
{
double temp;
temp = *pNombre1;
*pNombre1 = *pNombre2;
*pNombre2 = temp;
}