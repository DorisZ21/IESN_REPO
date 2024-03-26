#include <stdio.h>
#include <stdbool.h>

#define NB_SALLE_MAX_LARGEUR 10
#define NB_SALLE_MAX_HAUTEUR 10

typedef enum contenu{
    CONTENU_RIEN,
    CONTENU_TRESOR,
    CONTENU_KOBOLD,
    CONTENU_GOBELIN
}Contenus;

typedef enum connexion{
    CONNEXION_NORD = 1,
    CONNEXION_EST = 2,
    CONNEXION_SUD = 4,
    CONNEXION_OUEST = 8,
    CONNEXION_AUCUNE = 0
}Connexions;

typedef struct salle Salle;
struct salle{
    Connexions connexion;
    Contenus contenu;
};

typedef struct donjon Donjon;
struct donjon{
    int taille;
    Salle salles[NB_SALLE_MAX_LARGEUR][NB_SALLE_MAX_HAUTEUR];
};

void changeCouleurEnJaune(void);
void changeCouleurEnRouge(void);
void changeCouleurEnBleu(void);
void changeCouleurEnNormal(void);
char symboleContenu(Contenus);
void afficheConnexions(Connexions);
bool estDanger(Contenus);
bool estTresor(Contenus);
void afficheContenu(Contenus);
void afficheLigne1(Salle);
void afficheLigne2(Salle);
void afficheLigne3(Salle);
void afficheSalle(Salle);
void afficheDonjon(Donjon);
Donjon donjonVideCarre(int);
Donjon donjonAvecConnexions(Donjon,Connexions,int[],int);
Donjon donjonAvecContenu(Donjon,Contenus,int[],int);

int main() {
    /*
     * 0000 0010
     * 0000 0100
     * 0000 0110
     * => 6 // Avec un ou (|) bit à bit
     */
    Connexions connexions1 = CONNEXION_OUEST;
    Connexions connexions2 = CONNEXION_EST | CONNEXION_SUD;
    Connexions connexions3 = CONNEXION_NORD | CONNEXION_SUD | CONNEXION_OUEST;
    Connexions connexions4 = CONNEXION_AUCUNE;

    /*
     * Connexions 3 = 13
     * CONNEXION_NORD = 1
     * 0000 1101
     * 0000 0001
     * 0000 0001
     * => 1
     */

    /*
     * Connexions 3 = 13
     * CONNEXION_SUD = 4
     * 0000 1101
     * 0000 0100
     * 0000 0100
     * => 4
     */

    /*
     * Connexions 3 = 13
     * CONNEXION_EST = 2
     * 0000 1101
     * 0000 0010
     * 0000 0000
     * => 0
     */

    Salle salle1 = { CONNEXION_EST | CONNEXION_OUEST, CONTENU_TRESOR };
    Salle salle2 = { CONNEXION_NORD, CONTENU_GOBELIN };
    Salle salle3 = { CONNEXION_NORD | CONNEXION_EST | CONNEXION_SUD, CONTENU_RIEN };

    Donjon donjonTest = {
            3,
            {
                    {
                            { CONNEXION_EST | CONNEXION_SUD, CONTENU_RIEN },
                            { CONNEXION_OUEST | CONNEXION_EST, CONTENU_KOBOLD },
                            { CONNEXION_OUEST, CONTENU_TRESOR },
                    },
                    {
                            { CONNEXION_NORD | CONNEXION_SUD, CONTENU_RIEN },
                            { CONNEXION_EST, CONTENU_TRESOR },
                            { CONNEXION_OUEST | CONNEXION_SUD, CONTENU_GOBELIN }
                    },
                    {
                            { CONNEXION_EST | CONNEXION_NORD, CONTENU_KOBOLD },
                            { CONNEXION_OUEST | CONNEXION_EST, CONTENU_RIEN },
                            { CONNEXION_OUEST | CONNEXION_NORD, CONTENU_TRESOR }
                    }
            }
    };

 /**   afficheConnexions(salle1.connexion);
    printf("\n");
    afficheContenu(salle1.contenu);
    printf("\n"); **/
    // afficheDonjon(donjonTest);
   // afficheDonjon(donjonVideCarre(4));
    int sallesAvecSortieEst[] = { 0, 1, 2, 5, 8, 11, 13, 15, 16, 17, 20, 22, 23 };
    int sallesAvecSortieOuest[] = { 1, 2, 3, 6, 9, 12, 14, 16, 17, 18, 21, 23, 24 };
    int sallesAvecSortieNord[] = { 5, 7, 8, 9, 10, 12, 13, 15, 16, 19, 21, 22, 24 };
    int sallesAvecSortieSud[] = { 0, 2, 3, 4, 5, 7, 8, 10, 11, 14, 16, 17, 19 };
    int sallesAvecTresor[] = { 4, 6, 18, 20 };
    int sallesAvecKobold[] = { 5, 9, 17, 21 };
    int sallesAvecGobelin[] = { 2, 15, 24 };
    Donjon donjon = donjonVideCarre(5);
    donjon = donjonAvecConnexions(donjon, CONNEXION_EST, sallesAvecSortieEst, 13);
    donjon = donjonAvecConnexions(donjon, CONNEXION_OUEST, sallesAvecSortieOuest, 13);
    donjon = donjonAvecConnexions(donjon, CONNEXION_SUD, sallesAvecSortieSud, 13);
    donjon = donjonAvecConnexions(donjon, CONNEXION_NORD, sallesAvecSortieNord, 13);
    donjon = donjonAvecContenu(donjon, CONTENU_TRESOR, sallesAvecTresor, 4);
    donjon = donjonAvecContenu(donjon, CONTENU_KOBOLD, sallesAvecKobold, 4);
    donjon = donjonAvecContenu(donjon, CONTENU_GOBELIN, sallesAvecGobelin, 3);

    afficheDonjon(donjon);

    printf("%d",1/2);


}

void changeCouleurEnJaune(void) { printf("\033[1;33m"); }
void changeCouleurEnRouge(void) { printf("\033[1;31m"); }
void changeCouleurEnBleu(void) { printf("\033[1;34m"); }
void changeCouleurEnNormal(void) { printf("\033[1;0m"); }

char symboleContenu(Contenus contenuSalle){
    switch (contenuSalle) {
        case 0: return ' ';
            break;
        case 1: return 'T';
            break;
        case 2: return 'K';
            break;
        case 3: return 'G';
            break;
    }
}

void afficheConnexions(Connexions connexion){
    if(connexion == 0){
        printf("Aucune connexions !");
    } else{
        if((connexion & CONNEXION_NORD) == 1){
            printf("NORD ");
        }
        if((connexion & CONNEXION_SUD) == 4){
            printf("SUD ");
        }
        if((connexion & CONNEXION_OUEST) == 8){
            printf("OUEST ");
        }
        if((connexion & CONNEXION_EST) == 2){
            printf("EST ");
        }
    }

}

bool estDanger(Contenus contenu){
    return contenu == 2 || contenu == 3;
}

bool estTresor(Contenus contenu){
    return contenu == 1;
}

void afficheContenu(Contenus contenu){
    if(estDanger(contenu)){
        if(contenu == 2){
            printf("K");
        }else{
            printf("G");
        }
    } else if(estTresor(contenu)){
        printf("T");
    }
}

void afficheLigne1(Salle salle){
    printf("/");
    if((salle.connexion & CONNEXION_NORD) == 1){
        printf("   ");
    }else{
        printf("---");
    }
    printf("\\");
}

void afficheLigne2(Salle salle){
    if((salle.connexion & CONNEXION_OUEST) == 8){
        printf(" ");
    } else{
        printf("|");
    }

    printf(" %c ", symboleContenu(salle.contenu));

    if((salle.connexion & CONNEXION_EST) == 2){
        printf(" ");
    }else{
        printf("|");
    }
}

void afficheLigne3(Salle salle){
    printf("\\");
    if((salle.connexion & CONNEXION_SUD) == 4){
        printf("   ");
    }else{
        printf("---");
    }
    printf("/");
}


void afficheSalle(Salle salle){
    afficheLigne1(salle);
    printf("\n");
    afficheLigne2(salle);
    printf("\n");
    afficheLigne3(salle);

}

void afficheDonjon(Donjon donjon){

    for(int iLigne = 0; iLigne < donjon.taille;iLigne++){
        for(int iSalle = 0;iSalle < donjon.taille; iSalle++){
            afficheLigne1(donjon.salles[iLigne][iSalle]);
        }
        printf("\n");
        for(int iSalle = 0;iSalle < donjon.taille; iSalle++){
            afficheLigne2(donjon.salles[iLigne][iSalle]);
        }
        printf("\n");
        for(int iSalle = 0;iSalle < donjon.taille; iSalle++){
            afficheLigne3(donjon.salles[iLigne][iSalle]);
        }
        printf("\n");
    }


}

Donjon donjonVideCarre(int taille){

    Salle salles[taille][taille];
    Donjon donjonVide;
    donjonVide.taille = taille;

    for (int i = 0; i < taille; ++i) {
        for (int j = 0; j < taille; ++j) {
            Salle salle = {CONNEXION_AUCUNE,CONTENU_RIEN};
            salles[i][j] = salle;
            donjonVide.salles[i][j] = salle;
        }
    }
    return donjonVide;
}

Donjon donjonAvecConnexions(Donjon donjon,Connexions connexion,int sallesAvecSorties[],int taille){

    for(int iSalleModif = 0; iSalleModif < taille; iSalleModif++){
       int ligne;
       int colonne;
        if(sallesAvecSorties[iSalleModif] == 0){
            ligne = 0;
            colonne = 0;
        }else{
            ligne = sallesAvecSorties[iSalleModif] / donjon.taille;
            colonne = sallesAvecSorties[iSalleModif] % donjon.taille;

        }
        donjon.salles[ligne][colonne].connexion = connexion;    
    }

    return donjon;
}

Donjon donjonAvecContenu(Donjon donjon,Contenus contenu,int sallesAvecContenu[],int taille){
    for(int iSalleModif = 0; iSalleModif < taille; iSalleModif++){
        int ligne = sallesAvecContenu[iSalleModif] / donjon.taille;
        int colonne = sallesAvecContenu[iSalleModif] % donjon.taille;
        donjon.salles[ligne][colonne].contenu = contenu;
    }

    return donjon;
}