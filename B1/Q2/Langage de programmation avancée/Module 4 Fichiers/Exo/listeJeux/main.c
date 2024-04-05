#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define NB_CARACT_TITRE 100
#define NB_MAX_JEUX 20
#define FICHIER_JEUX "FiJeux.dat"

typedef struct jeux Jeux;
struct jeux{
    char titre[NB_CARACT_TITRE];
    int nbAvis;
    double moyenneNotes;
};


void sauverJeux(Jeux);
void lireJeux();
void enMajuscule(char[NB_CARACT_TITRE]);


int main() {
    char titre[NB_CARACT_TITRE];
    bool fin;
    Jeux monJeux = {"CSGO",0,0};
    do{
        printf("Entrez le nom du jeux :");
        gets(titre);
        fin = strcmp(titre,"") == 0;
        if(!fin){
            enMajuscule(titre);
            strcpy(monJeux.titre,titre);
            sauverJeux(monJeux);
        }
    } while (!fin);

    lireJeux();
}

void sauverJeux(Jeux monJeux){
    FILE *fiJeux;
    fopen_s(&fiJeux,FICHIER_JEUX,"ab");

    if(fiJeux == NULL){
        printf("Erreur lors de l'ouverture du fichier !");
    } else{
        fwrite(&monJeux,sizeof (Jeux),1,fiJeux);
        fclose(fiJeux);
    }

}


void enMajuscule(char titre[]){
    for (int iLettre = 0; iLettre < strlen(titre) ; iLettre++){
       titre[iLettre] = toupper(titre[iLettre]);
    }
}

void lireJeux(){
    FILE *fiJeux;
    Jeux jeux;
    fopen_s(&fiJeux,FICHIER_JEUX,"rb");

    if(fiJeux == NULL){
        printf("Erreur lors de l'ouverture du fichier !");
    } else{

        fread(&jeux,sizeof (Jeux),1,fiJeux);
        while(!feof(fiJeux)){
            printf("Titre : %s\n",jeux.titre);
            printf("Moyenne note : %lf\n",jeux.moyenneNotes);
            printf("Nb d avis : %d\n",jeux.nbAvis);
            fread(&jeux,sizeof (Jeux),1,fiJeux);
        }

        fclose(fiJeux);
    }
}