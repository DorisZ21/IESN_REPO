#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NB_CARACT 100
#define NB_CARACT_TITRE 50
#define NB_CARACT_AUTEUR 40

typedef struct livre Livre;
struct livre{
    char auteur[NB_CARACT_AUTEUR];
    char titre[NB_CARACT_TITRE];
    int annee;
    int numTome;
    char titreSerie[NB_CARACT_TITRE];
};

typedef struct chainonLivre ChainonLivre;
struct chainonLivre{
    Livre livre;
    ChainonLivre* pSuiv;
};

typedef enum menu Menu;
enum menu{
    AJOUTER_LIVRE,
    SUPPRIMER_LIVRE,
    AFFICHER_LIVRES,
    QUITTER
};

typedef enum codeMessage CodeMessage;
enum codeMessage{
    ERREUR_MEMOIRE,
    LIVRE_EXISTANT,
    LIVRE_INEXISTANT,
    AJOUT_EFFECTUE,
    SUPPRESSION_EFFECTUEE
};

void afficherMenu(void);
void afficherMessage(CodeMessage);
void afficherLivre(Livre);
CodeMessage ajouterLivre(Livre,ChainonLivre**);
ChainonLivre* rechercheLivre(Livre ,ChainonLivre*,ChainonLivre**);
void afficheBibliotheque(ChainonLivre*);
Livre obtenirLivre(void);

int main() {
    // Liste de livres pour le test des fonctions
    /* Livre livres[20] = {
             {"Antoine de Saint-Exupery", "Le Petit Prince", 1943, 0, ""},
             {"Christelle Dabos", "Les Fiances de l'hiver", 2013, 0, ""},
             {"Antoine de Saint-Exupery", "Le Petit Prince", 1943, 0, ""},
             {"Eoin Colfer", "Artemis Fowl", 2001, 0, ""},
             {"John Green", "Nos etoiles contraires", 2012, 0, ""},
             {"John Green", "Qui es-tu Alaska ?", 2005, 0, ""},
             {"J.R.R.Tolkien", "La Communaute de l'Anneau", 1954, 1, "Le Seigneur des anneaux"},
             {"J.R.R.Tolkien", "Les Deux Tours", 1954, 2, "Le Seigneur des anneaux"},
             {"J.R.R.Tolkien", "Le Retour du roi", 1955, 3, "Le Seigneur des anneaux"},
             {"J.R.R.Tolkien", "Bilbo le Hobbit", 1937, 0, ""},
             {"Lois Lowry", "Le Passeur", 1993, 0, ""},
             {"Pierre Bottero", "La Quete d'Ewilan - L'integrale", 2003, 0, ""},
             {"Suzanne Collins", "Hunger Games", 2008, 1, "Hunger Games"},
             {"Suzanne Collins", "L'embrasement", 2009, 2, "Hunger Games"},
             {"Suzanne Collins", "La revolte", 2010, 3, "Hunger Games"}
     }; */

    ChainonLivre* pBibliotheque = NULL;

    bool encoderANouveau;
    char choix;
    Livre livre;
    do {
        livre = obtenirLivre();
        CodeMessage message = ajouterLivre(livre,&pBibliotheque);
        afficherMessage(message);
        printf("\n");
        do {
            printf("Voulez vous encoder un nouveau livre (O/N) ?");
            scanf("%c",&choix);
            getchar();
            encoderANouveau = choix == 'O';
        }while(choix != 'O' && choix != 'N');
    } while (encoderANouveau);

    afficheBibliotheque(pBibliotheque);

}

void afficherMenu(void) {
    printf("%d. Ajouter un livre\n", AJOUTER_LIVRE);
    printf("%d. Supprimer un livre\n", SUPPRIMER_LIVRE);
    printf("%d. Afficher les livres\n", AFFICHER_LIVRES);
    printf("%d. Quitter\n", QUITTER);
}

void afficherMessage(CodeMessage codeMessage) {
    switch (codeMessage) {
        case ERREUR_MEMOIRE: puts("Plus de place memoire !"); break;
        case LIVRE_EXISTANT: puts("Le livre existe deja !"); break;
        case LIVRE_INEXISTANT: puts("Le livre n'existe pas !"); break;
        case AJOUT_EFFECTUE: puts("Le livre est ajoute !"); break;
        case SUPPRESSION_EFFECTUEE: puts("Le livre est supprime !"); break;
    }
}

void afficherLivre(Livre livre){
    printf("%s -> %s",livre.auteur,livre.titre);

    if(strcmp(livre.titreSerie,"") != 0){
        printf(" - Tome %d : %s",livre.numTome,livre.titreSerie);
    }

    printf(" (%d)",livre.annee);

}

CodeMessage ajouterLivre(Livre livre,ChainonLivre** ppBibliotheque){
    CodeMessage message;
    if(rechercheLivre(livre.titre,*ppBibliotheque)){
        message = LIVRE_EXISTANT;
    }else{
        ChainonLivre* pNouvLivre = malloc(sizeof(ChainonLivre));
        if(pNouvLivre == NULL){
            message = ERREUR_MEMOIRE;
        }else{
            strcpy(pNouvLivre->livre.titre,livre.titre);
            strcpy(pNouvLivre->livre.titreSerie,livre.titreSerie);
            strcpy(pNouvLivre->livre.auteur,livre.auteur);
            pNouvLivre->livre.annee = livre.annee;
            pNouvLivre->livre.numTome = livre.numTome;
            pNouvLivre->pSuiv = *ppBibliotheque;
            *ppBibliotheque = pNouvLivre;
            message = AJOUT_EFFECTUE;
        }
    }

    return message;
}

ChainonLivre* rechercheLivre(Livre livre,ChainonLivre* pBibliotheque,ChainonLivre** pLivreSauv){
    ChainonLivre* pLivre = pBibliotheque;
    while(pLivre != NULL && livre.auteur > pLivre->livre.auteur){
        *pLivreSauv = pLivre;
        pLivre = pLivre->pSuiv;
    }
    while(pLivre != NULL && livre.auteur == pLivre->livre.auteur && livre.annee > pLivre->livre.annee){
        *pLivreSauv = pLivre;
        pLivre = pLivre->pSuiv;
    }

    while (pLivre != NULL && livre.auteur == pLivre->livre.auteur && livre.annee == pLivre->livre.annee && livre.numTome > pLivre->livre.numTome){
        *pLivreSauv = pLivre;
        pLivre = pLivre->pSuiv;
    }

    if(pLivre == NULL && )
}

void afficheBibliotheque(ChainonLivre* pBibliotheque){
    while(pBibliotheque != NULL){
        afficherLivre(pBibliotheque->livre);
        printf("\n");
        pBibliotheque = pBibliotheque->pSuiv;
    }
}

Livre obtenirLivre(void){
    Livre nouveauLivre;
    printf("Entrez l auteur du livre : ");
    gets(nouveauLivre.auteur);
    printf("\n");
    printf("Entrez le titre du livre : ");
    gets(nouveauLivre.titre);
    printf("\n");
    printf("Entrez l annee du livre : ");
    scanf("%d",&nouveauLivre.annee);
    getchar();
    printf("\n");
    printf("Entrez le titre de la serie : ");
    gets(nouveauLivre.titreSerie);
    printf("\n");
    if(strcmp(nouveauLivre.titreSerie,"") != 0){
        printf("Entrez le numero du tome : ");
        scanf("%d",&nouveauLivre.numTome);
        getchar();
    }
    return nouveauLivre;
}
    