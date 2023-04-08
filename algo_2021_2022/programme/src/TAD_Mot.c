#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include "TAD_Mot.h"

MOT_Mot MOT_creerMot(char *CdC){
    MOT_Mot mot;
    char *data;
    data=(char*)malloc(sizeof(char)*(strlen(CdC)+1));
    mot.data = data;
    MOT_fixeData(&mot, CdC);
    MOT_fixeLongueur(&mot, strlen(CdC));
    return mot;
}

char *MOT_obtenirData(MOT_Mot mot){
    return mot.data;
}

void MOT_fixeData(MOT_Mot *mot, char *CdC){
    strcpy((*mot).data, CdC);
}

int MOT_longueur(MOT_Mot mot){
    return mot.longueur;
}

void MOT_fixeLongueur(MOT_Mot *mot, int l){
    (*mot).longueur=l;
}

MOT_Mot MOT_copieMot(MOT_Mot mot){
    char *copieData;
    char *data = MOT_obtenirData(mot);
    copieData = (char*)malloc(sizeof(char)*(strlen(data)+1));
    MOT_Mot copieMot;
    copieMot.data = (char*)malloc(sizeof(char) * (strlen(data) + 1));
    memcpy(copieData, data, sizeof(char)*(MOT_longueur(mot)+1));
    MOT_fixeData(&copieMot, copieData);
    MOT_fixeLongueur(&copieMot, MOT_longueur(mot));
    free(copieData);
    return copieMot;
}

bool MOT_estUnMot(char *CdC){
    bool mot=true;
    int i=0;
    while (mot && i<strlen(CdC)){
        bool estValide = MOT_estUnCaractereValide(CdC[i]);
        if (!(estValide)){
            mot=false;
        }
        i++;
    }
    return mot;
}

char MOT_iemeCaractere(MOT_Mot mot, int i){
    char *data = MOT_obtenirData(mot);
    return data[i];
}

void MOT_modifieiemeCaractere(MOT_Mot mot, char c, int i){
    mot.data[i]=c;
}

MOT_Mot MOT_remplaceLettre(MOT_Mot mot, char c, int i){
    MOT_Mot testMot=MOT_copieMot(mot);
    MOT_modifieiemeCaractere(testMot, c, i);
    return testMot;
}

MOT_Mot MOT_inverseLettres(MOT_Mot mot, int i){
    char ci1, ci2;
    MOT_Mot testMot=MOT_copieMot(mot);
    MOT_Mot resultat, temp;
    ci1 = MOT_iemeCaractere(testMot, i);
    ci2 = MOT_iemeCaractere(testMot, i+1);
    temp = MOT_remplaceLettre(testMot, ci2, i);
    resultat = MOT_remplaceLettre(temp, ci1, i+1);
    MOT_supprimerMot(&temp);
    MOT_supprimerMot(&testMot);
    return resultat;
}

MOT_Mot MOT_supprimeLettre(MOT_Mot mot, int i){
    char *data = MOT_obtenirData(mot);
    char *resultat;
    resultat = (char*)malloc(sizeof(char)*MOT_longueur(mot));
    for (int j=0; j<i; j++){
        resultat[j]=data[j];
    }
    for (int j=i+1; j<MOT_longueur(mot)+1; j++){
        resultat[j-1]=data[j];
    }
    MOT_Mot m = MOT_creerMot(resultat);
    free(resultat);
    return m;
}

MOT_Mot MOT_insereLettre(MOT_Mot mot, char c, int i){
    char *data = MOT_obtenirData(mot);
    char *resultat;
    resultat = (char*)malloc(sizeof(char)*(MOT_longueur(mot)+2));
    for (int j=0; j<i; j++){
        resultat[j]=data[j];
    }
    resultat[i]=c;
    for (int j=i+1; j<MOT_longueur(mot)+2; j++){
        resultat[j]=data[j-1];
    }
    MOT_Mot m = MOT_creerMot(resultat);
    free(resultat);
    return m;
}

void MOT_supprimerMot(MOT_Mot *mot){
    free((*mot).data);
}

MOT_Mot *MOT_decomposeMot(MOT_Mot mot, int i){
    MOT_Mot mot1, mot2;
    char *data;
    char data1[i+1];
    char data2[MOT_longueur(mot)-i+1];
    MOT_Mot *resultat;
    resultat=malloc(sizeof(MOT_Mot)*2);
    data=MOT_obtenirData(mot);
    for (int j=0; j<i; j++){
        data1[j]=data[j];
    }
    data1[i] = '\0';
    for (int j=i; j<MOT_longueur(mot)+1; j++){
        data2[j-i]=data[j];
    }

    mot1=MOT_creerMot(data1);
    mot2=MOT_creerMot(data2);
    resultat[0]=mot1;
    resultat[1]=mot2;
    return resultat;
}


bool MOT_estUnCaractereValide(char c){
    char *caracteresValides = "abcdefghijklmnopqrstuvwxyzéèàçù-'";
    int i=1;
    bool estValide=false;
    while ((!estValide)&&(i<=strlen(caracteresValides))){
        if (c==caracteresValides[i]){
            estValide=true;
        }
    }
    return estValide;
}
