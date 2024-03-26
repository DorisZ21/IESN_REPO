#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define T_NOM 100
#define NB_MOTS_CLES 3
#define T_MOT_CLE 25
#define NB_CARTES_MAX 100

typedef struct carte Carte;
struct carte {
    char nom[T_NOM];
    int nbCasesHeuteur;
    int nbCasesLargeur;
    bool officielle;
    char motsCles[NB_MOTS_CLES][T_MOT_CLE];
    Carte* pSuiv;
};

void afficheCarte(Carte*);
void carteObtenue(Carte*);

int main() {
    int nbTorches = 20;
    int* pNbTorches = &nbTorches;

  /*  printf("%d (%p)",nbTorches,&nbTorches);
    printf("\n");
    printf("%p (%p)",pNbTorches,&pNbTorches); // Accès à l'adresse stocké dans le pointeur
                                                    // Mais aussi à l'adresse mémoire du pointeur
    printf("\n");
    printf("Valeur de *pNbTorches (%d)",*pNbTorches); // Accès à la valeur de la variable pointé depuis le pointeur
    printf("\n");
    *pNbTorches += 3; // Modification de la valeur depuis le pointeur
    printf("Valeur de nbTorches apres modif : %d",nbTorches); // Affichage de la valeur de la variable modifié depuis le pointeur
    printf("\n");
    printf("Valeur de *pNbTorchesSac %d\n", *pNbTorches); // Affichage de la valeur variable depuis le pointeur
                                                                // après modification
    */

  int caPersos[3] = {17,16,22};
  printf("caPersos est a l'adresse %p - %p.\n", caPersos, &caPersos[0]);
  printf("\n");

  // Première méthode habituelle parcourir chaque indice du tableau
  for(int i = 0; i < 3; i++){
      printf("caPersos[%d] = %d a l adresse = %p",i,caPersos[i],&caPersos[i]);
      // Dans ce cas la l'adresse est augmenté de 4 octets car chaque valeur se trouve
      // à une distance de 4 octets (32bits) car c'est un tableau d'entier
      printf("\n");
  }

    printf("\n");

  // Deuxième méthode en passant par un pointeur

  // Création du pointeur qui pointe sur le tableau caPersos[]
  int* pCaPersos = caPersos;

  for(int i = 0; i < 3;i++){
      // Affichage de la valeur pointé par le pointeur dans le tableau
      // Affichage de l'adresse du tableau pointé par le pointeur
      // Affichage de l'adresse du pointeur
      printf("pCaPersos[%d] = %d a l adresse = %p et adresse du pointeur %p",i,*pCaPersos,pCaPersos,&pCaPersos);
      printf("\n");
      pCaPersos++;
  }

    printf("\n");

  // Déclarer un pointeur qui ne pointe vers aucun type en particulier pour le moment
  void* pNombre; // Le pointeur pointe vers une adresse de n'importe quel type

  // Ici un int
  pNombre = &nbTorches;
  printf("%p",pNombre);
  printf("\n");

  // Ici un tableau
  pNombre = caPersos;
  printf("%p",pNombre);
  printf("\n");

  // Pour afficher la valeur d'une variable pointé par le pointeur il faut utiliser l'opérateur de casting
    printf("valeur de la premiere case du tableau --> %d",*(int *)pNombre);

    printf("\n");

  // La même chose si on veut modifier la valeur d'une variable pointé par le pointeur
  *(int *)pNombre += 4;
  printf("valeur de la premiere case du tableau --> %d",*(int *)pNombre);


    printf("\n");

  // Allocation dynamique d'un tableau en mémoire avec la fonction malloc

    int nbJoueurs;
    int* joueurs;
    printf("Entrez un nombre de joueurs :");
    scanf_s("%d",&nbJoueurs);

    // La fonction sizeof permet d'obtnir la taille en octet(bytes) d'un type primitif ou autres.
    joueurs = (int *)malloc(sizeof(int) * nbJoueurs);

    int* pJoueurs = joueurs;

    for(int i = 0; i < nbJoueurs; i++){
        printf("Entrez le score d'un joueur : ");
        scanf_s("%d",pJoueurs);
        printf("\n");
        pJoueurs++;
    }



    // Affichage des résultats

    // Repositionnement au début du tableau
    pJoueurs = joueurs;


    for (int i = 0; i < nbJoueurs; i++) {
        printf("joueurs %d ---> %d",i+1,*pJoueurs);
        printf("\n");
        pJoueurs++;
    }


    // Libérer l'espace alloué dans le tas
    free(joueurs);

    for (int i = 0; i < nbJoueurs; i++) {
        printf("joueurs %d ---> %d",i+1,*pJoueurs);
        printf("\n");
        pJoueurs++;
    }

    // Permet d'initialiser la taille nécessaire à la structure

    // Carte* pGrotte = (Carte *) malloc(sizeof(Carte));

   /* strcpy(pGrotte->nom,"Grottes pleines de rats");
    pGrotte->nbCasesLargeur = 25;
    pGrotte->nbCasesHeuteur = 15;
    strcpy(pGrotte->motsCles[0],"souterrain");
    strcpy(pGrotte->motsCles[1],"rats");
    strcpy(pGrotte->motsCles[2],"sombre"); */
   /* getchar();
   carteObtenue(pGrotte);
    afficheCarte(pGrotte); */

   getchar();
   Carte* pCartes = NULL;
   Carte* pCarte;
   bool placeDisponible, fin;

    do {
        pCarte = malloc(sizeof(Carte));
        placeDisponible = pCarte != NULL;
        if(placeDisponible){
            carteObtenue(pCarte);
            fin = strcmp(pCarte->nom, "") == 0;
            if(pCartes == NULL){
                pCartes = pCarte;
            }else{
                pCarte->pSuiv = pCartes;
                pCartes = pCarte;
            }
        }else{
            printf("Espace memoire indisponible");
        }
    } while (placeDisponible && !fin);

    pCarte = pCartes;
    while (pCarte != NULL) {
        afficheCarte(pCarte);
        pCarte = pCarte->pSuiv;
    }

}

void carteObtenue(Carte* pCarte){
    printf("Entrez le nom d'une carte :");
    gets(pCarte->nom);
    
    printf("\n");
    // != 0 veut dire "différent de égal"
    if(strcmp(pCarte->nom,"") != 0){
        printf("Entrez le nombre de case en largeur :");
        scanf("%d",&pCarte->nbCasesLargeur);
        printf("\n");
        printf("Entrez le nombre de case en Hauteur :");
        scanf("%d",&pCarte->nbCasesHeuteur);
        printf("\n");
        for (int i = 0; i < 3; i++) {
            printf("Mot cle %d :",i+1);
            scanf("%s",pCarte->motsCles[i]);
        }
        getchar();
    }
}

void afficheCarte(Carte* pCarte){
    printf("\n");
    puts(pCarte->nom);
    printf("\n");
    printf("Largeur : %d",pCarte->nbCasesLargeur);
    printf("\n");
    printf("Hauteur : %d",pCarte->nbCasesHeuteur);
    printf("\n");
    for(int i = 0; i < 3; i++){
        puts(pCarte->motsCles[i]);
        printf("\n");
    }
}
