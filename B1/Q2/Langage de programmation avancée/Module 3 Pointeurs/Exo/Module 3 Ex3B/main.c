#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define NB_CARACT 100
#define NB_CARACT_TITRE 50
#define NB_CARACT_AUTEUR 40

typedef struct livre Livre;
struct livre{
    char titre[NB_CARACT_TITRE];
    char auteur[NB_CARACT_AUTEUR];
    int annee;
    int numTome;
    char titreSerie[NB_CARACT_TITRE];
    Livre* chainonLivre;
};


void majuscule(char*);
int tailleMotPlusLong(char*);


int main() {
    // EX1
    char phrase[NB_CARACT] = "Bonjour doriandfgt";
    majuscule(phrase);
    puts(phrase);

    // EX2

    int taille = tailleMotPlusLong(phrase);
    printf("\n taille : %d",taille);


}

void majuscule(char* chaine){
    while(*chaine != '\0'){
        *chaine = toupper(*chaine);
        chaine++;
    }
}


// Bonjour je suis dorian
int tailleMotPlusLong(char* chaine) {
    int tailleMot, tailleMax;
    tailleMax = 0;
    while (*chaine != '\0') {
        tailleMot = 0;
        while (*chaine != ' ' && *chaine != '\0') {
            tailleMot++;
            chaine++;
        }
        if (tailleMot > tailleMax) {
            tailleMax = tailleMot;
        }

        if (*chaine == ' ') { // Avancer le pointeur si l'espace est trouvé
            chaine++;
        }
    }
    return tailleMax;

    Livre* pBibliotheque = NULL;
}

