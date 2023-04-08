#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "TAD_Mot.h"
#include "TAD_Dictionnaire.h"
#include "TAD_Correcteur.h"
#include <stdbool.h>
#include <errno.h>

#define lettresTest "abcdefghijklmnopqrstuvwxyzéèàçù-'"

char *caracteresValides = lettresTest;

CO_CorrecteurOrthographique CO_creerCorrecteur(DICO_Dictionnaire d){
    CO_CorrecteurOrthographique c;
    c.dictionnaire=d;
    c.corrections=LC_listeChainee();
    return c;
}

void* CO_copierElement(void* mot){
    MOT_Mot* resultat;
    resultat=malloc(sizeof(MOT_Mot));
    memcpy((void*)resultat, mot, sizeof(MOT_Mot));
    return (void*)resultat;
}

bool CO_comparerElement(void* mot1,void* mot2){
    return (strcmp(MOT_obtenirData(*(MOT_Mot*)mot1), MOT_obtenirData(*(MOT_Mot*)mot2))==0);
}

DICO_Dictionnaire CO_obtenirDictionnaire(CO_CorrecteurOrthographique c){
    return c.dictionnaire;
}

LC_ListeChainee CO_obtenirCorrections(CO_CorrecteurOrthographique c){
    return c.corrections;
}

void CO_fixerCorrections(CO_CorrecteurOrthographique c, LC_ListeChainee corrections){
    c.corrections=corrections;
}

bool CO_estPresentDansDictionnaire(MOT_Mot mot, CO_CorrecteurOrthographique c){
    DICO_Dictionnaire d=CO_obtenirDictionnaire(c);
    return DICO_estPresent(d, mot);
}

void CO_ajouterCorrection(CO_CorrecteurOrthographique c, MOT_Mot mot){
    LC_ListeChainee corrections;
    corrections=LC_copier(CO_obtenirCorrections(c),CO_copierElement);
    LC_ajouter(&corrections, &mot, CO_copierElement);
    CO_fixerCorrections(c, corrections);
}

void CO_correctionParInversion(MOT_Mot mot, CO_CorrecteurOrthographique c){
    unsigned int i;
    MOT_Mot testMot;
    for (i=1; i<=MOT_longueur(mot)-1; i++){
        testMot=MOT_inverseLettres(mot, i);
        if (CO_estPresentDansDictionnaire(testMot, c)){
            CO_ajouterCorrection(c, testMot);
        }
    }
}

void CO_correctionParInsertion(MOT_Mot mot, CO_CorrecteurOrthographique c){
    unsigned int i, j;
    int nbLettresATester=strlen(caracteresValides);
    MOT_Mot testMot;
    for (i=1; i<=MOT_longueur(mot)+1; i++){
        for (j=1; j<=nbLettresATester; j++){
            testMot=MOT_insereLettre(mot, caracteresValides[j],i);
            if (CO_estPresentDansDictionnaire(testMot,c)){
                CO_ajouterCorrection(c, testMot);
            }
        }
    }
}

void CO_correctionParDecomposition(MOT_Mot mot, CO_CorrecteurOrthographique c){
    unsigned int i;
    MOT_Mot testMot1, testMot2;
    MOT_Mot *resultat;
    for (i=1; i<=MOT_longueur(mot)-1; i++){
        resultat=MOT_decomposeMot(mot, i);
        testMot1=resultat[0];
        testMot2=resultat[1];
        if (CO_estPresentDansDictionnaire(testMot1, c)){
            CO_ajouterCorrection(c, testMot1);
        }
        if (CO_estPresentDansDictionnaire(testMot2, c)){
            CO_ajouterCorrection(c, testMot2);
        }
    }
}

void CO_correctionParSuppression(MOT_Mot mot, CO_CorrecteurOrthographique c){
    unsigned int i;
    MOT_Mot testMot;
    for (i=1; i<=MOT_longueur(mot); i++){
        testMot=MOT_supprimeLettre(testMot, i);
	    if (CO_estPresentDansDictionnaire(testMot, c)){
            CO_ajouterCorrection(c, testMot);
        }
    }
}

void CO_correctionParRemplacement(MOT_Mot mot, CO_CorrecteurOrthographique c){
    unsigned i, j;
    MOT_Mot testMot;
    int nbLettresATester=strlen(caracteresValides);
    for (i=1; i<=MOT_longueur(mot); i++){
        for (j=1; j<=nbLettresATester; j++){
	        testMot=MOT_remplaceLettre(mot, caracteresValides[j], i);
            if (CO_estPresentDansDictionnaire(testMot, c)){
                CO_ajouterCorrection(c, testMot);
            }
        }
    }
}
