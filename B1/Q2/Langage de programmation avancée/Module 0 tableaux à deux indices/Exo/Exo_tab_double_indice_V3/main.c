#include <stdio.h>
#include <string.h>
#include <ctype.h>
// CONSTANTES
#define NB_SYMBOLES 6
#define NB_PLANETES 5000
#define NB_CARACT 40
#define LG_DATA 75


int remplirAdressesNoms(int [][NB_SYMBOLES], char[][NB_CARACT]);
void normaliseNoms(char[NB_CARACT]);
void transformeAdresse(char[NB_CARACT],int[NB_SYMBOLES], int);
int occurrencesSymbole(int [][NB_SYMBOLES], int[],int,int);
void afficheInfosAdressesOccurences(int[][NB_SYMBOLES], char[][NB_CARACT], int[],int,int,char[]);
void afficheAdresse(int[NB_SYMBOLES]);
int rechercheMotNoms(char[][NB_CARACT],char[],int[]);

void main(void) {

    int nbPlanetes;
	int nbOccurences;
    int nbOccurencesNoms;

    int adresseSG[NB_PLANETES][NB_SYMBOLES];
	char noms[NB_PLANETES][NB_CARACT];
    int indicesOccurrences[LG_DATA];
    char mot[NB_CARACT];
    int indiceOccurrenceNoms[LG_DATA];


   nbPlanetes = remplirAdressesNoms(adresseSG,noms);
   nbOccurences = occurrencesSymbole(adresseSG,indicesOccurrences,29,nbPlanetes);
   afficheInfosAdressesOccurences(adresseSG,noms,indicesOccurrences,nbOccurences,29,"");
   nbOccurencesNoms = rechercheMotNoms(noms,"do",indiceOccurrenceNoms);
    afficheInfosAdressesOccurences(adresseSG,noms,indiceOccurrenceNoms,nbOccurencesNoms,-1,"do");
}

int remplirAdressesNoms(int adressesSG[][NB_SYMBOLES], char noms[][NB_CARACT]){
    char data[][NB_CARACT] = {
            "ABYDOS", "aGOfLd",
            "Abythres", "GFIJKL",
            "Abythres2", "GBLIEF",
            "Ailurus Fulgens", "eNlBmc",
            "APOPHIS'S BASE", "TRKlJf",
            "Benzaar Primary", "dHSKeB",
            "Boanet", "DdRHQa",
            "Cassidy", "CdLebR",
            "Cassiopeia", "UNfECZ",
            "CASTIANA", "cCFILP",
            "Centauri Prime", "LSDNYa",
            "CHULAK", "IBWOkT",
            "CLAVA THESSARA INFINITAS", "NUPKdG",
            "CLAVA THESSARA INFINITAS2", "ZTifWD",
            "CoRoT 7b", "CORGTX",
            "Cyathea", "fIUdRc",
            "DESTINY", "FQUeiXEN",
            "DESTROYERS", "CfPHJL",
            "Dochia", "DRWkFQ",
            "EARTH", "bZEjKc",
            "EDORA", "bliIOC",
            "Estros", "GHTglUB",
            "EURONDA", "daIGRP",
            "eXos", "dgaKLl",
            "FINAL DESTINATION", "IRaOUj",
            "Fras Alpha Gate", "IVCNkF",
            "Gaia designated P3X-774", "ISZQVE",
            "Gallifrey", "EKakZb",
            "Hundoozelfra", "gIeEWC",
            "Jon Moyes", "LRZGhK",
            "Jon's Gate #2", "DEFGVU",
            "Jon's Staging Gate", "BDWdck",
            "Jon's Test Gate", "mEFGHI",
            "JUNA", "cHRVDY",
            "KALLANA", "FPHCZY",
            "KHEB", "ZiFHWN",
            "Kristian Tysse", "GETafU",
            "K'TAU", "RBdLZg",
            "LANTIA (ATLANTIS)", "SUBPOHT",
            "MARTIN LLOYD'S HOMEWORLD", "XLfGKh",
            "Nab-Yloo", "JWYGFQ",
            "New Horizon", "IFPLCH",
            "NID OFF-WORLD BASE", "lbOiCS",
            "OTHALA", "KaWPgCI",
            "P2X-555", "bHPgMe",
            "P34-353J", "lIbOiC",
            "P3W-451 (black hole)", "SHDkZP",
            "P3X-118", "IZhkQU",
            "P3X-562", "CbIiXO",
            "P9C-372", "YHRhDV",
            "Patitan", "LBFHZU",
            "PB5-926", "LjWRGa",
            "PBH-403", "LJaDBX",
            "Phoenix Planet (Phoenix Site)", "HeZgFL",
            "PRACLARUSH TAONAS", "iCecEQ",
            "Proxima Centauri B", "BQVadm",
            "PX1-767", "TBiHZO",
            "PX1-482 JonathanS Gate", "jLgCBY",
            "Roverius", "LPfbQm",
            "Rubito Prime", "WJIBUZ",
            "SAHAL", "cRSTUV",
            "SANGREAL PLANET", "dShIgR",
            "Sepa's Sanctum", "LEIWHm",
            "Serenity", "LCTJSV",
            "TARTARUS", "gbWZPe",
            "Terra Nova", "eEHTYC",
            "Tesseract", "ULSCWg",
            "The.Continuum", "mSQEcU",
            "TOLLAN", "FgakKR",
            "TOLLANA", "DhHVRY",
            "Tython", "GmPTfZ",
            "VAGON BREI", "CHBLSd",
            "Vasut's gate", "eWBdGP",
            "Vasut's second gate ", "fLFCRB",
            "Velma", "KJEFCV"
    };

    int nbPlanetes = 0;
    for(int iData = 0; iData < LG_DATA * 2; iData+=2){
        normaliseNoms(data[iData]);
        strcpy(noms[nbPlanetes], data[iData]);
        transformeAdresse(data[iData + 1], adressesSG[nbPlanetes],NB_SYMBOLES);

        nbPlanetes++;
    }

   return nbPlanetes;
}

void normaliseNoms(char noms[NB_CARACT]){
    noms[0] = toupper(noms[0]);
    int iLettre = 1;
    while(iLettre < NB_CARACT && noms[iLettre] != '\0'){
        noms[iLettre] = tolower(noms[iLettre]);
        iLettre++;
    }
}

void transformeAdresse(char adresse[NB_CARACT], int adressesSG[NB_SYMBOLES],int nbSymboles){
    for(int iCaract = 0; iCaract < nbSymboles; iCaract++){
       adressesSG[iCaract] = isupper(adresse[iCaract]) ? adresse[iCaract] - 64 : adresse[iCaract] - 70;
    }
}

int occurrencesSymbole(int adressesSG[][NB_SYMBOLES], int indicesOccurrences[], int symbole, int nbPlanetes){
    int iIndiceOccurrence = 0;
    for(int iAdresse = 0; iAdresse < nbPlanetes; iAdresse++){
        for(int iSymbole = 0; iSymbole < NB_SYMBOLES; iSymbole++){
            if(adressesSG[iAdresse][iSymbole] == symbole){
                indicesOccurrences[iIndiceOccurrence] = iAdresse;
                iIndiceOccurrence++;
            }
        }
    }

    return iIndiceOccurrence;
}

void afficheInfosAdressesOccurences(int adressesSG[][NB_SYMBOLES],char noms[][NB_CARACT],int indicesOccurrences[],int nbOccurrrences,int symbole,char mot[]){
    if(nbOccurrrences > 0){
        if(strcmp(mot,"") != 0){
            printf("Le mot %s apparait %d fois.", mot,nbOccurrrences);
        }else{
            printf("Le symbole %d apparait %d fois.", symbole,nbOccurrrences);
        }
        printf("\n");
        printf("\n");

        for(int iAdresse = 0; iAdresse < nbOccurrrences; iAdresse++){
            printf_s("planete #%2d : ", indicesOccurrences[iAdresse]);
            afficheAdresse(adressesSG[indicesOccurrences[iAdresse]]);
            puts(noms[indicesOccurrences[iAdresse]]);

            printf("\n");
        }
    }else{
        printf("Aucun résultat.");
    }

}

void afficheAdresse(int adressesSG[NB_SYMBOLES]){
    for(int iSymbole = 0; iSymbole < NB_SYMBOLES; iSymbole++){
        printf("%d ",adressesSG[iSymbole]);
    }

}

int rechercheMotNoms(char noms[][NB_CARACT],char mot[],int indiceOccurrenceNoms[]){
    int iIndiceOccurrence = 0;
    for(int iNom = 0; iNom < NB_PLANETES; iNom++){
        if(strstr(noms[iNom],mot) != NULL){
            indiceOccurrenceNoms[iIndiceOccurrence] = iNom;
            iIndiceOccurrence++;
        }
    }

    return iIndiceOccurrence;
}