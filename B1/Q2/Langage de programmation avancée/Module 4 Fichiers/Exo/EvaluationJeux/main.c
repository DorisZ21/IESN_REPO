#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define NB_CARACT_TITRE 100
#define NB_MAX_JEUX 20
#define FICHIER_JEUX "FiJeux.dat"

typedef struct jeux Jeux;
struct jeux{
    char titre[NB_CARACT_TITRE];
    int nbAvis;
    double moyenneNotes;
};

void rechercheJeux(Jeux*,char[],int*);
void lireJeux();
void sauverJeux(Jeux,int);
void enMajuscule(char[NB_CARACT_TITRE]);

int main() {
    char titreJeux[NB_CARACT_TITRE];
    int note;
    int position;
    bool fin;
    Jeux monJeu;

    do{
        printf("\nEntrez le nom d'un jeux :");
        gets(titreJeux);
        fin = strcmp(titreJeux,"") == 0;
        if(!fin){
            printf("\n");
            enMajuscule(titreJeux);
            rechercheJeux(&monJeu,titreJeux,&position);
            if(strcmp(monJeu.titre,titreJeux) == 0){
                do {
                    printf("Entrez une note sur 5 : ");
                    scanf_s("%d",&note,sizeof(note));
                } while (note > 5 || note < 0);

                double sommeNotes = monJeu.moyenneNotes * monJeu.nbAvis;
                monJeu.nbAvis++;
                sommeNotes += note;
                monJeu.moyenneNotes = sommeNotes / monJeu.nbAvis;
                sauverJeux(monJeu,position);
                printf("\n");
                lireJeux();
                getchar();
            } else{
                printf("Le jeux que vous avez entre n'est pas present dans le fichier !");
            }

        }
    }while(!fin);
}

void rechercheJeux(Jeux *jeu,char titreJeux[],int *position){
    FILE *fiJeux;
    fopen_s(&fiJeux,FICHIER_JEUX,"rb");

    if(fiJeux == NULL){
        printf("Erreur lors de l'ouverture du fichier");
    }else{
        fread(jeu,sizeof(Jeux),1,fiJeux);
        while(!feof(fiJeux) && strcmp(titreJeux,jeu->titre) != 0){
            fread(jeu,sizeof(Jeux),1,fiJeux);
        }
        *position = ftell(fiJeux) - sizeof(Jeux);
    }

    fclose(fiJeux);
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

void sauverJeux(Jeux jeu,int position){
    FILE *fiJeux;

    fopen_s(&fiJeux,FICHIER_JEUX,"r+b");

    if(fiJeux == NULL){
        printf("Erreur lors de l'ouverture du fichier !");
    }else{
        fseek(fiJeux, position, SEEK_SET); // Se positionner à l'endroit où se trouve la structure
        fwrite(&jeu, sizeof(Jeux), 1, fiJeux); // Écrire la nouvelle structure à cet emplacement

    }

    fclose(fiJeux);
}

void enMajuscule(char titre[]){
    for (int iLettre = 0; iLettre < strlen(titre) ; iLettre++){
        titre[iLettre] = toupper(titre[iLettre]);
    }
}



